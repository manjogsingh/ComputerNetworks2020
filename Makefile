CC = clang++ -std=c++11

tag = -i

ifdef linux
tag = -n
endif

main: ActualMessage.o Client.o Server.o HeaderMessage.o logger.o
	$(CC) -o main.o ActualMessage.o Client.o Server.o HeaderMessage.o logger.o

main.o: src/main.cpp
	$(CC) -g -c src/main.cpp

ActualMessage.o: src/ActualMessage.cpp
	$(CC) -g -c src/ActualMessage.cpp

Client.o: src/Client.cpp
	$(CC) -g -c src/Client.cpp

Server.o: src/Server.cpp
	$(CC) -g -c src/Server.cpp

HeaderMessage.o: src/HeaderMessage.cpp
	$(CC) -g -c src/HeaderMessage.cpp

logger.o: src/logger.cpp
	$(CC) -g -c src/logger.cpp

clean:
	rm -f *.o
	rm -f *.out