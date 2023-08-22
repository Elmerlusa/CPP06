NAME = convert

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

CPPF = main.cpp Converter.cpp
CPPO = ${CPPF:.cpp=.o}

RM = rm -rf
########################################################
.PHONY: all test re fclean clean
########################################################
all:		${NAME}

test:		${NAME}
		@echo -------------------------Error
		./${NAME}
		./${NAME} 1 2
		./${NAME} 12fa
		./${NAME} ja
		./${NAME} 3.3.3
		@echo -------------------------Char
		./${NAME} a
		./${NAME} .
		./${NAME} +
		@echo -------------------------Integer
		./${NAME} 0
		./${NAME} 145
		./${NAME} -42
		./${NAME} 42
		@echo -------------------------Float
		./${NAME} 0.0f
		./${NAME} -3.6f
		./${NAME} 7.2f
		./${NAME} 89.0f
		./${NAME} -inff
		./${NAME} +inff
		./${NAME} nanf
		@echo -------------------------Double
		./${NAME} 0.0
		./${NAME} -33.73
		./${NAME} 7.88
		./${NAME} 4.0
		./${NAME} -inf
		./${NAME} +inf
		./${NAME} nan

t:			${NAME}
		@echo Integer
		./${NAME} 0
		./${NAME} 145
		./${NAME} -42
		./${NAME} 42

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