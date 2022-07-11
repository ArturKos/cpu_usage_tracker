CFLAGS=-Wall -Wextra
OBJS=cut.c

cut: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o cut

clean:
		rm -f *.o
