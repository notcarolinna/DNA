#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

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
    throw std::invalid_argument("letraConsecutiva ou letraConsecutiva atual invalida.");
}

int main() {
    std::ifstream inputFile("teste.txt"); 
    if (!inputFile) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    std::string cadeiaDNA;

    if (std::getline(inputFile, cadeiaDNA)) {
        inputFile.close();
        char letraConsecutiva = cadeiaDNA[0];
        int repeticoes = 1;

        for (size_t i = 1; i < cadeiaDNA.length(); i++) {
            std::string log = "";
            for (int j = 0; j < repeticoes; j++) {
                log += letraConsecutiva;
            }

            // A linha abaixo mostra todo o processo de simplificação da cadeia de DNA
            // std::cout << log << " " << cadeiaDNA.substr(i) << std::endl;

            char letraAnalisada = cadeiaDNA[i];

            if (letraAnalisada == letraConsecutiva) {
                repeticoes += 1;
            }
            else {
                std::string letraComplementar = getLetraComplementar(letraConsecutiva, letraAnalisada);
                letraConsecutiva = (pow(-1, repeticoes) == 1) ? letraAnalisada : letraComplementar[0];
                repeticoes = 1;
            }
        }

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

    return 0;
}
