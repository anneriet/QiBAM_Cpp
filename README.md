# gen_unitary

This set of files generates random matrices using Quantum indexed Bidirectional Associative Memory (QiBAM) from https://arxiv.org/pdf/1909.05563.pdf and stores them as [.npy files](https://docs.scipy.org/doc/numpy/neps/npy-format.html) in a directory called "data".

## Dependencies

It uses [libnpy](https://github.com/llohse/libnpy) to write the .npy files. Just clone the repository and place it in the same directory as this gen_unitary one. (So main folders in the same directory) 

This is also where the data folder with the .npy files gets placed. 

## Usage

The number of qubits and the value of gamma can be changed in the "main.cc" file. A random search pattern is generated for each run using the time in milliseconds since the Epoch as seed. 

To compile and execute the code, do `make && ./gen_unitary` in this folder. 
