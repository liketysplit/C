message_hider: message_hider.o decrypt.o encrypt.o
	gcc message_hider.o decrypt.o encrypt.o -o message_hider

message_hider.o: message_hider.c decrypt.h encrypt.h
	gcc -g -c message_hider.c -o message_hider.o

decrypt.o: decrypt.c decrypt.h encrypt.h
	gcc -g -c decrypt.c -o decrypt.o

encrypt.o: encrypt.c encrypt.h
	gcc -g -c encrypt.c -o encrypt.o
