# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 13:37:49 by javmarti          #+#    #+#              #
#    Updated: 2023/08/25 13:37:50 by javmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

CPPF = main.cpp Serializer.cpp
CPPO = ${CPPF:.cpp=.o}

RM = rm -rf
########################################################
.PHONY: all test re fclean clean
########################################################
all:		${NAME}

test:		${NAME}
		./${NAME}

${NAME}:	${CPPO}
		@${CPP} ${FLAGS} ${CPPO} -o ${NAME}

%.o: 		%.cpp
		@$(CPP) $(FLAGS) -c $< -o $@

re:			fclean all

fclean:		clean
		@${RM} ${NAME}

clean:
		@${RM} ${CPPO}
########################################################
