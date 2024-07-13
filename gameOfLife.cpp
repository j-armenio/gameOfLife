#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void cursor_to(int row, int col) {
    printf("\033[%d;%dH", row, col);
}

void print_random_m() {
    int r = 40;
    int c = 180;

    std::srand(std::time(0));

    std::vector<std::vector<int>> m(r, std::vector<int>(c, 0));

    // Inicializa matriz
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = rand() % 2;
        }
    }

    // Limpa a tela
    printf("\033[2J\033[H");

    // Imprime a matriz usando █
    for (int i = 0; i < r; i++) {
        cursor_to(6 + i, 16);
        for (int j = 0; j < c; j++) {
            if (m[i][j] == 0) {
                printf("\033[90m█");
            } else if (m[i][j] == 1) {
                printf("\033[97m█");
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    // OBJETIVO: Desenhar na tela
    // 1. Limpar a tela
    // 2. Criar uma matriz, preencher com 0s
    // 3. Pesquisar como desenhar na tela

    int r = 40;
    int c = 180;

    std::vector<std::vector<int>> m(r, std::vector<int>(c, 0));

    // Inicializa matriz
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = 0;
        }
    }

    bool runing = true;
    while (runing) {
        // Limpa a tela
        printf("\033[2J\033[H");

        // Imprime a matriz usando █
        for (int i = 0; i < r; i++) {
            cursor_to(6 + i, 16);
            for (int j = 0; j < c; j++) {
                if (m[i][j] == 0) {
                    printf("\033[90m█");
                } else if (m[i][j] == 1) {
                    printf("\033[97m█");
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        
        std::cin.get();
    }

    return 0;
}