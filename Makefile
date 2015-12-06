CC=gcc
CFLAGS=-I. -Wall -g
DEPS = mathstest.h
OBJ = mathstest.o mtestcsv.o  

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mathstest: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

teacher: mtestcsv.o mtestsort.o  mtestteacher.o
	gcc -o $@ $^ $(CFLAGS)


clean:
	rm *.o
