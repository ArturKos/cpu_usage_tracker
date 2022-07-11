CFLAGS=-Wall -Wextra
OBJS=cut.c

cut: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o cut -lpthread

clean:
		rm -f *.o
