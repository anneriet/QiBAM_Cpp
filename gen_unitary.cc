/**
 * @file   gen_unitary.cc
 * @date   8/2020
 * @author Anneriet Krol
 * @brief  QiBAM matrix generation
 */
#include <iostream>
#include <complex>
#include <string>
#include <vector>
#include "gen_unitary.h"
#include "../libnpy/npy.hpp"

Qibam::Qibam(){
}

void Qibam::generate(int Qd, float gamma, int Pb)
{
  //  int Qd = 1; // Number of qubits to encode the quantum genomic database
    int SS = 1<<Qd; // 2^Qd (Space State matrix, of size 2^Qd
    
    //int Pb = 0; // Some binary representation of the search pattern
    
    //float gamma = 0.25;
    
    int hd;
    std::vector<float> bp(SS);
    for (int i = 0; i < SS; i++){
    	hd = hamming_distance(Pb,i);
    	bp[i] = std::pow((std::pow(gamma, hd)*std::pow(1-gamma, Qd-hd)), 0.5);
    }
 
    std::vector<float> BO;
    for (int i = 0; i < SS; i++){
    	for (int j = 0; j < SS; j++){
    		if(i == j){
    			BO.push_back(1 - 2*bp[i]*bp[j]); // BO = I(SS) - 2*bp'*bp;
    		}
    		else
    		{
    			BO.push_back(-2*bp[i]*bp[j]);
    		}
    	}
    }
    test_save(Qd, BO);    
}

// from https://www.geeksforgeeks.org/number-of-mismatching-bits-in-the-binary-representation-of-two-integers/

int Qibam::hamming_distance(int p, int x){
   // since, the numbers are less than 2^31 run the loop from '0' to '31' only 
    int count = 0;
    for (int i = 0; i < 32; i++) { 
        // right shift both the numbers by 'i' and 
        // check if the bit at the 0th position is different 
        if (((p >> i) & 1) != ((x >> i) & 1)) { 
            count++; 
        }         
    } 
    return count;
}

int Qibam::test_save(int qubits, std::vector<float> data) {
  const long unsigned leshape [1] = {data.size()};
  std::string name="../data/out_" + std::to_string(qubits) + ".npy";
  npy::SaveArrayAsNumpy(name, false, 1, leshape, data);
  return 0;
};

