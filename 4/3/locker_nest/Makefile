CFILES=dlist.c locker_pthread.c locker_nest.c

all:
	gcc -g -shared -lpthread -fPIC $(CFILES) -o libdlist.so
	gcc -g -DDLIST_TEST -lpthread -fPIC $(CFILES) -o dlist_test 

clean:
	rm -f *test *.exe *.so
	
