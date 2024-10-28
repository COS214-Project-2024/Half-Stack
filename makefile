main:
	g++ -g -std=c++11 *cpp -o main

run:
	 ./main

clean:
	rm -f *o main

clear:
	clear

valgrind:
	valgrind --leak-check=full ./main