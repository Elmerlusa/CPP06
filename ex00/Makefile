# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 13:38:32 by javmarti          #+#    #+#              #
#    Updated: 2023/08/27 15:30:14 by javmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

CPPF = main.cpp ScalarConverter.cpp
CPPO = ${CPPF:.cpp=.o}

RM = rm -rf
########################################################
.PHONY: all test re fclean clean
########################################################
all:		${NAME}

test:		${NAME}
		clear
		@echo -------------------------Error
		./${NAME}
		./${NAME} 1 2
		./${NAME} 12fa
		./${NAME} ja
		./${NAME} 3.3.3
		./${NAME} 3.
		@read a
		clear
		@echo -------------------------Char
		./${NAME} a
		./${NAME} .
		./${NAME} +
		./${NAME} t
		@read a
		clear
		@echo -------------------------Integer
		./${NAME} 0
		./${NAME} 23
		./${NAME} 145
		./${NAME} -42
		./${NAME} 42
		./${NAME} 2147483647
		./${NAME} +2147483648
		./${NAME} -2147483648
		./${NAME} -2147483649
		@read a
		clear
		@echo -------------------------Float
		./${NAME} 0.0f
		./${NAME} -3.6f
		./${NAME} 7.2f
		./${NAME} 89.0f
		./${NAME} -2147483648.0f
		./${NAME} -2147483649.0f
		./${NAME} 2147483647.0f
		./${NAME} +2147483648.0f
		./${NAME} 641864456840985098524358098.2f
		@read a
		clear
		@echo -------------------------Double
		./${NAME} 0.0
		./${NAME} -33.73
		./${NAME} 7.88
		./${NAME} 641864456840985098524358098.0
		@read a
		clear
		@echo -------------------------Pseudoliterals
		./${NAME} -inff
		./${NAME} +inff
		./${NAME} inff
		./${NAME} nanf
		./${NAME} -inf
		./${NAME} +inf
		./${NAME} inf
		./${NAME} nan

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
