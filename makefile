program: main.cpp int_buffer.cpp int_sorted.cpp
	g++ -o buffer main.cpp int_buffer.cpp int_sorted.cpp -g

run: program
	./buffer
