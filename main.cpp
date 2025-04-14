#include <iostream>
#include <stdexcept>
#include <vector>

class MulMatrix {
private:
    std::vector<std::vector<int>> m1;
    std::vector<std::vector<int>> m2;
    std::vector<std::vector<int>> m3;

    int dimension;
public:
    MulMatrix(int n) : dimension(n) {
        m1.resize(n, std::vector<int>(n, 0));
        m2.resize(n, std::vector<int>(n, 0));
        m3.resize(n, std::vector<int>(n, 0));
        
    }

    void setMatrizA(const std::vector<std::vector<int>>& valores) {
        m1 = valores;
    }

    void setMatrizB(const std::vector<std::vector<int>>& valores) {
        m2 = valores;
    }


    void mul() {
        for(auto& linha : m3)
            for(auto& elemento : linha)
                elemento = 0;

        for(int i = 0; i < dimension; i++) {
            for(int k = 0; k < dimension; k++) {
                for(int j = 0; j < dimension; j++) {
                    m3[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
    }

    void result() {
        std::cout << "Matriz resultante:\n";
        for(const auto& linha : m3) {
            for(int valor : linha) {
                std::cout << valor << " ";
            }
            std::cout << "\n";
        }
    }
};    

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
    
}