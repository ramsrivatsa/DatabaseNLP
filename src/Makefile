CC = g++

CFLAGS = -Wall -g

INCLUDES = -I ../include/ 

# define the CXX source files
SRCS = NaLIRSystem.cpp Sentence.cpp TurboParser.cpp

OBJS = $(SRCS:.c=.o)

# define the executable file 
MAIN = NaLIR
#LFLAGS = -L../../deps/local/lib -lad3 -lgflags -lglog

.PHONY: depend clean

all:    $(MAIN)

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

run: NaLIR
	./NaLIR

clean:
	$(RM) *.o *~ $(MAIN) ../data/*

depend: $(SRCS)
	makedepend $(INCLUDES) $^
