#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    int total;
    std::cout << "Digite o numero de caracteres: ";
    std::cin >> total;

    char letras[] = { 'D', 'N', 'A' };

    std::ofstream arquivo("teste0200.txt"); 

    if (!arquivo.is_open()) {
        std::cerr << "Erro." << std::endl;
        return 1;
    }

    for (int i = 0; i < total; i++) {
        char caracter = letras[rand() % 3];
        arquivo << caracter;
    }

    arquivo.close();
    std::cout << "Arquivo gerado." << std::endl;

    return 0;
}
