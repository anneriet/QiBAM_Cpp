gen_unitary: gen_unitary.cc gen_unitary.h main.cc
	g++ -o gen_unitary gen_unitary.cc main.cc -std=c++11
clean:
	rm gen_unitary
