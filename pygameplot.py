import math
import numpy as np
import pygame
from pygame.color import THECOLORS
import time

pygame.init()

times = 30

shape = (times*20, times*20)
screen = pygame.display.set_mode(shape)
pygame.display.set_caption("RoboMaster")

background = pygame.Surface(screen.get_size())
background = background.convert()
background.fill((255, 255, 255))



def conv(gloc, grot, loc):
    cosOfAngle = math.cos(grot)
    sinOfAngle = math.sin(grot)
    return (times*(gloc[0]+loc[0] * cosOfAngle - loc[1] * sinOfAngle),
            times*(gloc[1]+loc[0] * sinOfAngle + loc[1] * cosOfAngle))


info = dict()


def praseInfo(line):
    idx, team, name, boundary = line.split('$')
    boundary = [tuple(map(float, x.split(':'))) for x in boundary.split('|')]
    info[idx] = (team, name, boundary)
    return (idx, team, name, boundary)


def praseRobo(line):
    ts, idx, loc, phi, life = line.split('$')
    # ts = float(ts)
    loc = tuple(map(float, loc.split(':')))
    phi = float(phi)
    life = int(life)
    team, name, boundary = info[idx]
    ps = [conv(loc, phi, each) for each in boundary]
    return (ts, team, name, ps, life)


def praseAmmo(line):
    ts, tp, loc = line.split('&')
    # ts = float(ts)
    loc = tuple(map(lambda x: int(float(x)*times), loc.split(':')))
    return (ts, tp, loc)


f = open('PlotDefault.plt', 'r')


while True:
    line = f.readline()
    if '########' in line:
        break
    praseInfo(line)

fps = 24
lastts = '-1'
for line in f.readlines():
    if '$' in line:
        ts, team, name, ps, life = praseRobo(line)
        if ts != lastts:
            screen.blit(background, (0, 0))
            pygame.display.flip()
            background.fill((255, 255, 255))
            lastts = ts
            time.sleep(1/fps)
        if life!=0:
            pygame.draw.polygon(background, THECOLORS["green"], ps)
        else:
            pygame.draw.polygon(background, THECOLORS["red"], ps)

    elif '&' in line:
        ts, tp, loc = praseAmmo(line)
        if ts != lastts:
            screen.blit(background, (0, 0))
            pygame.display.flip()
            background.fill((255, 255, 255))
            lastts = ts
            time.sleep(1/fps)
        pygame.draw.circle(background, (0, 0, 255), loc, int(0.1*times))


f.close()
