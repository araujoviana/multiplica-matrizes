// Matheus Gabriel Viana Araujo - 10420444
// Lucas Akio Funada Tsukamoto - 10425346
// Fellipe Jardanovski - 10395847

/*
    Nesse código em C++, há uma classe chamada MulMatrix que possui
    os métodos necessários para calcular a multiplicação de duas matrizes
    m1 e m2, gerando uma matriz resultante m3. Mais precisamente, a classe
    contém os atributos e o construtor para incializar as matrizes. Além disso
    ela contém os métodos para inserir a ordem das matrizes, inserir o tamanho
    das matrizes e seus respectivos valores
*/

#include <iostream>
#include <vector>

// Classe para multiplicar as matrizes
class MulMatrix {

  // Atributos da classe, com as duas matrizes m1 e m2 e a matriz resultante m3,
  // além da ordem, número de linhas e colunas
private:
  std::vector<std::vector<int>> m1; // Matriz A
  std::vector<std::vector<int>> m2; // Matriz B
  std::vector<std::vector<int>> m3; // Matriz resultado

  int ordem; // Número de colunas de A e número de linhas de B
  int m;     // Número de linhas da matriz A
  int p;     // Número de linhas da matriz B
public:
  // Construtor da classe inicializa matrizes quadradas com 0
  MulMatrix(int n) : ordem(n) {
    m1.resize(n, std::vector<int>(n, 0));
    m2.resize(n, std::vector<int>(n, 0));
    m3.resize(n, std::vector<int>(n, 0));
  }

  // Método para inserir os valores da matriz A
  void setMatrizA() {
    std::cout << "Digite os valores da matriz A:" << std::endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < ordem; j++) {
        std::cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
        std::cin >> m1[i][j];
      }
    }
  }

  // Método para inserir os valores da matriz B
  void setMatrizB() {
    std::cout << "Digite os valores da matriz B:" << std::endl;
    for (int i = 0; i < ordem; i++) {
      for (int j = 0; j < p; j++) {
        std::cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
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

  // Realiza a multiplicação m1 x m2 e armazena em m3
  void multiplicarMatrizes() {
    // Zera a matriz resultado antes de usar
    for (auto &linha : m3)
      for (auto &elemento : linha)
        elemento = 0;

    // Loop triplo padrão de multiplicação de matrizes:
    // m1[i][k] * m2[k][j] soma no m3[i][j]
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < p; j++) {
        for (int k = 0; k < ordem; k++) {
          m3[i][j] += m1[i][k] * m2[k][j];
        }
      }
    }
  }

  // Método para imprimir a matriz resultante
  void result() {
    std::cout << "Matriz resultante:\n";
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < p; j++) {
        std::cout << m3[i][j] << " ";
      }
      std::cout << "\n";
    }
  }
};

// Função principal
int main(void) {
  int ordem;
  std::cout << ""
               "Digite a ordem (n) das matrizes: ";
  std::cin >> ordem;

  if (std::cin.fail() || ordem <= 0) {
    std::cout << "Erro: valor ordem inválido\n";
    return 1;
  }

  MulMatrix mulmatrix(ordem);

  mulmatrix.tamanhoMatrizes();     // Define m e p
  mulmatrix.setMatrizA();          // Lê matriz A
  mulmatrix.setMatrizB();          // Lê matriz B
  mulmatrix.multiplicarMatrizes(); // Faz multiplicação
  mulmatrix.result();              // Exibe resultado
}