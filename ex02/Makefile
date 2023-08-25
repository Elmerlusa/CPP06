# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 13:38:13 by javmarti          #+#    #+#              #
#    Updated: 2023/08/25 13:48:44 by javmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify

CPP = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

CPPF = main.cpp Base.cpp
CPPO = ${CPPF:.cpp=.o}

RM = rm -rf
########################################################
.PHONY: all test re fclean clean
########################################################
all:		${NAME}

test:		${NAME}
		for i in {1..15}; do ./${NAME}; sleep 1; done;

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
