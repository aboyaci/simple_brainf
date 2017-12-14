C_FLAGS := -Wall

all : bf

bf: bf.c
	gcc $(C_FLAGS) -o $@ $<

clean:
	rm -f bf