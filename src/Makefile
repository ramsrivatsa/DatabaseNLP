CC = g++

CFLAGS = -Wall -g

INCLUDES = -I . 

# define the C source files
SRCS = NaLIRSystem.cpp

OBJS = $(SRCS:.c=.o)

# define the executable file 
MAIN = NaLIR


.PHONY: depend clean

all:    $(MAIN)

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

run: NaLIR
	./NaLIR

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
