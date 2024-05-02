## DNA Simplifier
This program aims to simplify DNA strings, providing the result of the fusion process, where different bases deteriorate and form a new, smaller base. The problem resolution was achieved through string manipulation.

### Functionality
The program reads an input file containing a DNA string and then starts the simplification process. At each step, two adjacent letters are selected for comparison. If these letters are different, a function is called to determine the resulting letter from the fusion. The DNA string is then updated with the new letter resulting from the fusion.
The process continues until all adjacent letters in the DNA string are the same. The program prints the simplified DNA string as the result.

### Implementation
The resultadoFusao function determines the resulting letter from the fusion between two DNA letters. Then, the program iterates over the DNA string, applying the fusion and updating the string accordingly.
To optimize memory, a temporary variable (tempstr) can be used to store the fusions before updating the DNA string. This reduces the number of copy operations.

### Execution and Performance
The program reads a DNA string from a input file. After simplification, the execution time of the process is measured and displayed in seconds.
To run the program, simply compile and execute the file. It is necessary to have g++ installed and compile using the following command line in the terminal:

```
g++ DNA.cpp -o DNA
./DNA
```





