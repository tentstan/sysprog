CFILES=dlist.c

all:
	gcc -g -shared -lpthread -fPIC $(CFILES) -o libdlist.so
	gcc -g -DDLIST_TEST -lpthread -fPIC $(CFILES) -o dlist_test
	gcc -g -DHASH_TABLE_TEST hash_table.c $(CFILES) -o hash_table_test 

clean:
	rm -f *test *.exe *.so 
