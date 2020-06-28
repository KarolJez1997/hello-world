SHELL=/bin/bash
.ONESHELL:

all: files

files: *.o
	a=$$(ls | grep ".o" | cut -f 1 -d '.' | tr ' ' '\n')
	b=$$(ls | grep ".o" | tr ' ' '\n')

	a=($$a)
	b=($$b)

	c=$${#a[*]}
	c=$$(($$c-1))
	for i in $$(seq 0 $$c);
	do
		gcc $${b[$$i]} -o $${a[$$i]}
	done


*.o: *.c
	gcc -c *.c
clean:
	r=$$(ls | grep ".o" | cut -f 1 -d '.' | tr ' ' '\n')
	rm -rf *.o
	rm -rf $$r
