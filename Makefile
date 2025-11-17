CC = gcc
CFLAGS = -Wall -I./include -g
SRCS = src/game.c
OBJS = $(SRCS:.c=.o)
TARGET = twixt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
