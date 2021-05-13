#include <iostream>;
#include <stdio.h>;

int main () {
    int n;
    std::cin >> n;
    int matrix1[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            matrix1[i][j] = x;
        }
    }
    int matrix2[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            matrix2[i][j] = x;
        }
    }
    int matrix3[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
                matrix3[i][j] = 0;
                for (int k = 0; k < n; k++){
                    matrix3[i][j] = matrix3[i][j] + (matrix1[i][k])*(matrix2[k][j]);
                }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix3[i][j];
            std ::cout << " ";
        }
        std::cout << "\n";
    }
}

