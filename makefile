program: main.cpp int_buffer.cpp int_sorted.cpp
	g++ -O3 -o buffer main.cpp int_buffer.cpp int_sorted.cpp -g

run: program
	./buffer
