all:
	gcc -g atomic.c -lpthread -fPIC -DATOMIC_TEST -o atomic_test
	gcc -g fifo_ring.c -lpthread -fPIC -DFIFO_RING_TEST -o fifo_ring_test 
	gcc -g swmr_dlist.c dlist.c -lpthread -fPIC -DSWMR_DLIST_TEST -o swmr_dlist_test 

clean:
	rm -f *test 
