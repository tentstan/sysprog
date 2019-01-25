CFILES=darray.c
all:
	gcc -g -shared -fPIC -lpthread $(CFILES) -o libdarray.so
	gcc -g -DDARRAY_TEST -lpthread $(CFILES) -o darray_test 

clean:
	rm -rf *test *.exe *.so 
