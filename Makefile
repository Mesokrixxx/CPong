EXEC = pong.out

CC = gcc
CFLAGS = -I${PONG_INCLUDES} -IGL/include -lglfw -lm

PONG_INCLUDES = src/include/
SRCS = ${wildcard ./src/*.c}
SRCS += ${wildcard ./GL/src/*.c}
OBJS = ${SRCS:.c=.o} 

all: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${EXEC}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${EXEC}

re: fclean all