#include <iostream>
#include "gen_unitary.h"
#include <stdlib.h>
#include <time.h> 
#include <chrono>


int main()
{
	int n = 4;
	float gamma = 0.25;
	
	
	// Time in milliseconds since the Epoch
	unsigned int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	
	// Seed of the random number generator
	srand(now);
	
	// The search pattern
	int Pb = rand() %(1<<n);
	
    std::cout << "[gen_unitary] Generating " << n << " qubit QiBAM unitary for search pattern: " << Pb << std::endl;
    Qibam test;
    test.generate(n, gamma, Pb);
    return 0;
}
