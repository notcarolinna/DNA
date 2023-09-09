#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <chrono>
#include <iomanip>

std::string getLetraComplementar(char letraConsecutiva, char letraAnalisada) {
	if (letraConsecutiva == 'A') {
		if (letraAnalisada == 'D') return "N";
		else if (letraAnalisada == 'N') return "D";
	}
	else if (letraConsecutiva == 'D') {
		if (letraAnalisada == 'A') return "N";
		else if (letraAnalisada == 'N') return "A";
	}
	else if (letraConsecutiva == 'N') {
		if (letraAnalisada == 'A') return "D";
		else if (letraAnalisada == 'D') return "A";
	}
	throw std::invalid_argument("letraConsecutiva ou letraAnalisada invalida.");
}

int main() {

	std::ifstream inputFile("teste.txt");
	if (!inputFile) {
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
		return 1;
	}

	std::string cadeiaDNA;

	auto start = std::chrono::high_resolution_clock::now();

	if (std::getline(inputFile, cadeiaDNA)) {
		inputFile.close();
		char letraConsecutiva = cadeiaDNA[0];
		int repeticoes = 1;

		for (size_t i = 1; i < cadeiaDNA.length(); i++) { // percorre toda a cadeia de DNA

			std::string simplificacao = ""; // armazena o resultado da simplificação

			for (int j = 0; j < repeticoes; j++) {
				simplificacao += letraConsecutiva;
			}

			// A linha abaixo mostra todo o processo de simplificação da cadeia de DNA
			std::cout << simplificacao << " " << cadeiaDNA.substr(i) << std::endl;

			char letraAnalisada = cadeiaDNA[i];

			if (letraAnalisada == letraConsecutiva) {
				repeticoes += 1;
			}
			else {
				std::string letraComplementar = getLetraComplementar(letraConsecutiva, letraAnalisada);
				letraConsecutiva = (pow(-1, repeticoes) == 1) ? letraAnalisada : letraComplementar[0];

				// Verifica se o número de repetições é par ou ímpar
				repeticoes = 1;
			}
		}

		// exibição do resultado da simplificação
		std::string result = "";
		for (int i = 0; i < repeticoes; i++) {
			result += letraConsecutiva;
		}
		std::cout << result << std::endl;
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
