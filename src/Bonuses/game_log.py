# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    game_log.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:56:35 by dsandshr          #+#    #+#              #
#    Updated: 2019/10/24 18:40:24 by dsandshr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

log = open('game.log', 'w')
while 1:
	line = input()
	log.write(line + '\n')
	if line.find("== X fin:") != -1:
		break
log.close()