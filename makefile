CFLAGS=-Wall -Wextra
OBJS=cut.c
TEST=test.c

cut: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o cut -lpthread

test: $(TEST)
		$(CC) $(CFLAGS) $(TEST) -o test -lpthread
clean:
		rm -f *.o
