#include <iostream>
#include <fstream>
#include <string>
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
		
		std::cout << cadeiaDNA.length() << std::endl;

		inputFile.close();

		int i = 0;
		int inicioString = 0;
		std::string tempstr;

		//std::cout << cadeiaDNA.substr(inicioString) << std::endl;

		while (i < cadeiaDNA.length() - 1) {

			// Seleciona as letras para comparação
			char primeiraLetra = cadeiaDNA[i];
			i++;
			char segundaLetra = cadeiaDNA[i];

			// Processo de simplificação
			if (primeiraLetra != segundaLetra) {

				// Chamada da função para retornar a letra resultante
				char fusao = resultadoFusao(primeiraLetra, segundaLetra);

				if (i < inicioString + 2) { // Caso não tenha letras repetidas antes do sinalizador
					inicioString += 2;
					i = inicioString; // Reinicia a iteração  a partir do ponto onde a próxima fusão será aplicada
				}
				else { // Caso tenha letras repetidas antes do sinalizador
					inicioString += 2;
					cadeiaDNA[i] = primeiraLetra;
				}

				cadeiaDNA += fusao;

				// Para otimizar a memória gasta, descomentar a linha abaixo e o bloco if seguinte e comentar a linha acima.
				// tempstr += fusao;
				//std::cout << cadeiaDNA.substr(inicioString) << std::endl;
			}

			/*if ((i >= cadeiaDNA.length() - 1) && !tempstr.empty()) {
				cadeiaDNA.erase(0, inicioString);
				cadeiaDNA += tempstr;
				tempstr.clear();
				i -= inicioString;
				inicioString = 0;
			}*/

		}
		std::cout << cadeiaDNA.substr(inicioString) << std::endl;
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
