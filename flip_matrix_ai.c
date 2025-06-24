#include <stdio.h>

#define MAX 256

int max(int a, int b) {
    return a > b ? a : b;
}

int max4(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

int main() {
    int q;
    scanf("%d", &q);  // number of queries/matrices

    while (q--) {
        int n;
        scanf("%d", &n);  // half size of matrix
        int size = 2 * n;
        int matrix[MAX][MAX];

        // Read matrix
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                scanf("%d", &matrix[i][j]);

        int sum = 0;

        // For top-left quadrant, choose max from 4 symmetric positions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = matrix[i][j];
                int b = matrix[i][size - j - 1];
                int c = matrix[size - i - 1][j];
                int d = matrix[size - i - 1][size - j - 1];
                sum += max4(a, b, c, d);
		printf("%d %d %d %d\n", a, b, c, d);
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}

