#CFLAGS=-DHAVE_CONFIG_H -DREADLINE_LIBRARY -DRL_LIBRARY_VERSION='"5.1"' -I. -I.. -g -O
CFLAGS=-DRL_LIBRARY_VERSION='"5.1"' -I. -I.. -g -o
all:
	gcc $(CFLAGS) jdbshell.c -lreadline -ltermcap -o jdbshell 

clean:
	rm -f jdbshell *.o
