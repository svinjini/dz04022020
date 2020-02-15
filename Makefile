all: clean
	g++ -g --std=c++11 *.cpp -o list

clean:
	rm -f list
