app:tcp_server.o tcp_client.o
	gcc tcp_client.o -o client
	gcc tcp_server.o -o server

tcp_client.o:tcp_client.c
	gcc tcp_client.c -c

tcp_server.o:tcp_server.c
	gcc tcp_server.c -c

.PHONY:clean
clean:
	-rm *.o client server -f
