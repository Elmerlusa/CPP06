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
		@echo Error
		./${NAME}
		./${NAME} 1 2
		@echo Integer
		./${NAME} 0
		./${NAME} 1
		./${NAME} -42
		# ./${NAME} nan
		# @echo Float
		# ./${NAME} 0.0f
		# ./${NAME} -3.6f
		# ./${NAME} 7.2f
		# ./${NAME} -inff
		# ./${NAME} +inff
		# ./${NAME} nanf


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