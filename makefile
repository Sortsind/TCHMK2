all:
	g++ -c long_class.cpp long_numeric.cpp -fPIC
	g++ -shared -o long_class.so long_class.o long_numeric.o
	g++ main.cpp long_class.so -I. -Wl,-rpath,. -L. -o TCHMK2 -w
	rm -rf *.o