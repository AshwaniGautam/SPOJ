SRCS=$(wildcard *.cpp)

OBJS=$(SRCS:.cpp=.o)

all: $(OBJS)

clean:
	rm -f *.o




