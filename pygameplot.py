import math
import numpy as np
import pygame
from pygame.color import THECOLORS
import time

times = 30

pygame.init()
f = open('PlotDefault.plt', 'r')
shape = tuple(map(lambda x: int(float(x)*times), f.readline().split(':')))


# (times*20, times*20)
screen = pygame.display.set_mode(shape)
pygame.display.set_caption("RoboMaster")

background = pygame.Surface(screen.get_size())
background = background.convert()
background.fill(THECOLORS['black'])


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
    life = float(life)
    team, name, boundary = info[idx]
    if 'Hero' in name:
        life /= 400
    elif 'Inf' in name:
        life /= 200
    # print(ts, name, life)
    ps = [conv(loc, phi, each) for each in boundary]
    return (ts, team, name, ps, life, (loc[0]*times, loc[1]*times))


def praseAmmo(line):
    ts, tp, loc = line.split('&')
    # ts = float(ts)
    loc = tuple(map(lambda x: int(float(x)*times), loc.split(':')))
    return (ts, tp, loc)


def drawLife(surf, loc, lif):
    pygame.draw.rect(surf, THECOLORS['green'],
                     (loc[0]-times*0.5, loc[1] - times*0.5, times, times*0.2))
    pygame.draw.rect(surf, THECOLORS['red'],
                     (loc[0]-times*0.5, loc[1] - times*0.5, times - lif * times, times*0.2))



while True:
    line = f.readline()
    if '########' in line:
        break
    praseInfo(line)

fps = 24
lastts = '-1'
for line in f.readlines():
    if '$' in line:
        ts, team, name, ps, life, cent = praseRobo(line)
        if ts != lastts:
            screen.blit(background, (0, 0))
            pygame.display.flip()
            background.fill(THECOLORS['black'])
            lastts = ts
            time.sleep(1/fps)
        if life > 1e-6:
            drawLife(background, cent, life)
            pygame.draw.polygon(
                background, THECOLORS["red" if team == '0' else 'blue'], ps)
        else:
            pygame.draw.polygon(background, THECOLORS["gray"], ps)

    elif '&' in line:
        ts, tp, loc = praseAmmo(line)
        if ts != lastts:
            screen.blit(background, (0, 0))
            pygame.display.flip()
            background.fill((255, 255, 255))
            lastts = ts
            time.sleep(1/fps)
        pygame.draw.circle(
            background, THECOLORS['mediumpurple2' if tp == '0' else 'deeppink1'], loc, int(0.1*times))


f.close()
