CFLAGS := -g
INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm
# If you are compiling this to run on CISC210,
# uncomment the below line
#LDFLAGS := $(LDFLAGS) -lncurses




all: main.o output.o input.o 
	cc -o project main.o output.o input.o $(LDFLAGS)

clean:
	rm -f *.o inputtest outputtest project
main.o: main.c project.h
	cc -c main.c -I ~/include
output.o: output.c
	cc -c output.c -I ~/include
input.o: input.c
	cc -c input.c -I ~/include

inputtest: inputtest.o input.o project.h
	cc -o inputtest inputtest.o input.o -I/home/pi/include -L/home/pi/lib -l sense $(LDFLAGS)

outputtest: outputtest.o output.o project.h
	cc -o outputtest outputtest.o output.o -I/home/pi/include -L/home/pi/lib -l sense $(LDFLAGS)
	

%.o: %.c
	cc -g -c $< -I ~/include
