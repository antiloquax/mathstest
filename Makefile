CC=gcc
CFLAGS=-I. -Wall -g
DEPS = mtestcsv.h 
OBJ = mathstest.o mtestcsv.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mtest: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

teacher: mtestcsv.o mtestsort.o  mtestteacher.o
	gcc -o $@ $^ $(CFLAGS)


clean:
	rm *.o
