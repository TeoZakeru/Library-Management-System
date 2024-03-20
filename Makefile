CC = gcc
CFLAGS = -Wall -g
OBJS = main.o sort.o filter.o book.o borrower.o date.o

all: myprogram

myprogram: $(OBJS)
	$(CC) $(CFLAGS) -o myprogram $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c

filter.o: filter.c
	$(CC) $(CFLAGS) -c filter.c

book.o: book.c
	$(CC) $(CFLAGS) -c book.c

borrower.o: borrower.c
	$(CC) $(CFLAGS) -c borrower.c

date.o: date.c
	$(CC) $(CFLAGS) -c date.c

clean:
	rm -f *.o myprogram
