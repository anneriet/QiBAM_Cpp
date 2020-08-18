/**
 * @file   gen_unitary.h
 * @date   8/2020
 * @author Anneriet Krol
 * @brief  QiBAM matrix generation
 */

#ifndef _GEN_UNITARY_H
#define _GEN_UNITARY_H


#include <complex>
#include <string>
#include <vector>
#include <iostream>

class Qibam
{
private:
//	std::vector<std::string> AS;
//	int A;
//	int Qa;
//	std::string R;
//	int N;
//	std::string P;
	int hamming_distance(int p, int x);
	int test_save(int qubits, std::vector<float> data);
public:
	void generate(int Qd, float gamma, int Pb);
	Qibam();
};

#endif //_GEN_UNITARY_H
