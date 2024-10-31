CFLAGS = -Wall -Wextra -fsanitize=leak -fsanitize=address

main: *.o
	g++ -o main *.o  $(CFLAGS)

*.o: *.cpp
	g++ -c *.cpp $(CFLAGS)

run: main
	./main

clean:
	rm *.o

valgrind:
	valgrind --leak-check=full ./main

gcov:
	g++ --coverage *.cpp -o main
	./main
	gcov -f -m -r -j main