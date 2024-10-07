EXEC = pong.out

CC = gcc
CFLAGS = -I${INCLUDES}

INCLUDES = ./include/
SRCS = ${wildcard ./src/*.c}
OBJS = ${SRCS:.c=.o} 

all: ${OBJS}
	${CC} ${CFLAGS} -o ${EXEC} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: fclean
	rm -f ${EXEC}

re: fclean all