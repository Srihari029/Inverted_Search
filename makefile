OBJ=$(patsubst %.c,%.o,$(wildcard *.c))
is.out : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o *.out
