// Matheus Gabriel Viana Araujo - 10420444
// Lucas Akio Funada Tsukamoto - 10425346
// Fellipe Jardanovski - 10395847

/*
    Nesse código em C++, o programa 
*/

#include <iostream>
#include <stdexcept>
#include <vector>

// Classe para multiplicar as matrizes
class MulMatrix {

// Atributos da classe, com as duas matrizes m1 e m2 e a matriz resultante m3, além da ordem, número de linhas e colunas
private:
    std::vector<std::vector<int>> m1;
    std::vector<std::vector<int>> m2;
    std::vector<std::vector<int>> m3;

    int ordem;
    int m; // Número de linhas da matriz A
    int p; // Número de linhas da matriz B
public:

    // Construtor da classe
    MulMatrix(int n) : ordem(n) {
        m1.resize(n, std::vector<int>(n, 0));
        m2.resize(n, std::vector<int>(n, 0));
        m3.resize(n, std::vector<int>(n, 0));
        
    }
    
    // Método para inserir os valores da matriz A
    void setMatrizA() {
        std::cout << "Digite os valores da matriz A:" << std::endl;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < ordem; j++) {
                std::cout << "Elemento ["<<i+1<<"]["<<j+1<<"]: ";
                std::cin >> m1[i][j];
            }
        }
    }


    // Método para inserir os valores da matriz B
    void setMatrizB() {
        std::cout << "Digite os valores da matriz B:" << std::endl;
        for(int i = 0; i < ordem; i++) {
            for(int j = 0; j < p; j++) {
                std::cout << "Elemento ["<<i+1<<"]["<<j+1<<"]: ";
                std::cin >> m2[i][j];
            }
        }
    }

    // Método para inserir os valores m e p das matrizes
    void tamanhoMatrizes() {
        std::cout << "Digite o número de linhas (m) para a matriz A: ";
        std::cin >> m;
        std::cout << "Digite o número de colunas (p) para a matriz B: ";
        std::cin >> p;
    }

    // Método para realizar a multiplicação
    void multiplicarMatrizes() {
        for(auto& linha : m3)
            for(auto& elemento : linha)
                elemento = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < p; j++) {
                for(int k = 0; k < ordem; k++) {
                    m3[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
    }

    // Método para imprimir a matriz resultante
    void result() {
        std::cout << "Matriz resultante:\n";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < p; j++) {
                std::cout << m3[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};    

// Função principal
int main(void) {
    int ordem;
    try {
        std::cout << """Digite a ordem (n) das matrizes: ";
        std::cin >> ordem;
    } catch (std::invalid_argument &e) {
        std::cout << "Erro: ordem inválida!";
        return 1;
    }

    MulMatrix mulmatrix(ordem);

    mulmatrix.tamanhoMatrizes();
    mulmatrix.setMatrizA();
    mulmatrix.setMatrizB();
    mulmatrix.multiplicarMatrizes();
    mulmatrix.result();
}