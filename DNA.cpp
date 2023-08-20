#include <iostream>
#include <string>

/*
letraConsecutiva -> é a letra que possui um número x de repetições consecutivas na cadeia e é atualizada
sempre que a sequência for interrompida.
letraAnalisada -> guarda a letra que está sendo analisada no momento, é utilizada para comparar com a 'letraConsecutiva'
com a finalidade de determinar se há repetições consecutivas ou se a sequência foi interrompida. 
*/


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
    std::string cadeiaDNA = "DNANDANDANDANADNDDDAN";
    char letraConsecutiva = cadeiaDNA[0];
    int repeticoes = 1;

    for (size_t i = 1; i < cadeiaDNA.length(); i++) {
        std::string log = "";
        for (int j = 0; j < repeticoes; j++) {
            log += letraConsecutiva;
        }
        std::cout << log << " " << cadeiaDNA.substr(i) << std::endl;

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

    return 0;
}
