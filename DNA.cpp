#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <chrono>
#include <iomanip>

char resultadoFusao(char primeiraLetra, char segundaLetra) {
	if (primeiraLetra == 'A') {
		if (segundaLetra == 'D') return 'N';
		else if (segundaLetra == 'N') return 'D';
	}
	else if (primeiraLetra == 'D') {
		if (segundaLetra == 'A') return 'N';
		else if (segundaLetra == 'N') return 'A';
	}
	else if (primeiraLetra == 'N') {
		if (segundaLetra == 'A') return 'D';
		else if (segundaLetra == 'D') return 'A';
	}
	throw std::invalid_argument("primeiraLetra ou segundaLetra invalida.");
}

int main() {

	std::ifstream inputFile("caso30000k.txt");

	if (!inputFile) {
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
		return 1;
	}

	std::string cadeiaDNA;

	auto start = std::chrono::high_resolution_clock::now();

	if (inputFile >> cadeiaDNA) {
		inputFile.close();

		int i = 0;

		while (i < cadeiaDNA.length() - 1) {
			char primeiraLetra = cadeiaDNA[i];
			i++;
			char segundaLetra = cadeiaDNA[i];

			if (primeiraLetra != segundaLetra) {
				char fusao = resultadoFusao(primeiraLetra, segundaLetra);
				cadeiaDNA.erase(i - 1, 2);

				if (i < 2)
					i = 0;
				else
					i = i - 2;

				cadeiaDNA += fusao;
			}
		}
		std::cout << cadeiaDNA << std::endl;
	}

	else {
		std::cerr << "Erro ao ler o arquivo." << std::endl;
		inputFile.close();
		return 1;
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

	std::cout << std::fixed << std::setprecision(1) << duration.count() << " segundos." << std::endl;

	return 0;
}
