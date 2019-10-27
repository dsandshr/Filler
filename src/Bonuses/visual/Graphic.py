# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Graphic.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 18:10:22 by dsandshr          #+#    #+#              #
#    Updated: 2019/10/26 17:06:30 by dsandshr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pygame, sys
from pygame.locals import *
from pygame import *

BG_COLOR = [30, 30, 30]
WIN_WIDTH = 800
WIN_HEIGHT = 680
DISPLAY_SIZE = (WIN_WIDTH, WIN_HEIGHT)

def init_window():

	pygame.init()
	screen = pygame.display.set_mode(DISPLAY_SIZE)
	pygame.display.set_caption("Filler Graphic by Dsandshr")
	screen.fill(BG_COLOR)
	pygame.display.flip()

def start(events):

    for event in events:
        if (event.type == QUIT) or (event.type == KEYDOWN and event.key == K_ESCAPE):
            sys.exit(0)
        elif (event.type == KEYDOWN and event.key == K_SPACE):
            sys.exit(0)
        else:
            pass

def action():

    while 1:
        start(pygame.event.get())

def init_game(func):

	if (func == "player1"):
		while 1:
			line = input()
			if line.find("$$$ exec p1 :") != -1:
				func = line
				return (func)
	elif (func == "player2"):
		while 1:
			line = input()
			if line.find("$$$ exec p2 :") != -1:
				func = line
				return (func)
	elif (func == "map_size_x"):
		while 1:
			line = input()
			if line.find("Plateau") != -1:
				line = line.split(" ")
				return (int(line[2]))
	elif (func == "map_size_y"):
			while 1:
				line = input()
				if line.find("Plateau") != -1:
					line = line.split(" ")
					return (int(line[1]))
	elif (func == "map_read"):
		y = 0
		while 1:
			line = input()
			if line.find("Plateau") != -1:
				while line.find("Piece") != -1:
					line[y] = input()
					y += 1
				return (line)
	elif (func == "figure_size_y"):
		while 1:
			line = input()
			if line.find("Piece") != -1:
				line = line.split(" ")
				return(int(line[1]))
	elif (func == "figure_size_x"):
		while 1:
			line = input()
			if line.find("Piece") != -1:
				line = line.split(" ")
				return(int(line[2]))
	elif (func == "figure"):
		y = 0
		while 1:
			line = input()
			if line.find("Piece") != -1:
				while line.find("<got") != -1:
					line[y] = input()
					y += 1
			return(line)
def main():

    init_window()
    action()

if __name__ == "__main__":
	main()