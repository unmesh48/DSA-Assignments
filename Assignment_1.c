#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10], r, col, i, j, k, ch;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &col);

    printf("Enter first matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &a[i][j]);

    printf("Enter second matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &b[i][j]);

    printf("1.Addition 2.Subtraction 3.Multiplication 4.Transpose\n");
    scanf("%d", &ch);

    if (ch == 1 || ch == 2) {
        for (i = 0; i < r; i++)
            for (j = 0; j < col; j++)
                c[i][j] = (ch == 1) ? a[i][j] + b[i][j] : a[i][j] - b[i][j];

        for (i = 0; i < r; i++) {
            for (j = 0; j < col; j++)
                printf("%d ", c[i][j]);
            printf("\n");
        }
    } else if (ch == 3) {
        if (r != col) {
            printf("Multiplication requires compatible dimensions\n");
            return 0;
        }

        for (i = 0; i < r; i++)
            for (j = 0; j < r; j++) {
                c[i][j] = 0;
                for (k = 0; k < r; k++)
                    c[i][j] += a[i][k] * b[k][j];
            }

        for (i = 0; i < r; i++) {
            for (j = 0; j < r; j++)
                printf("%d ", c[i][j]);
            printf("\n");
        }
    } else if (ch == 4) {
        for (i = 0; i < r; i++)
            for (j = 0; j < col; j++)
                c[j][i] = a[i][j];

        for (i = 0; i < col; i++) {
            for (j = 0; j < r; j++)
                printf("%d ", c[i][j]);
            printf("\n");
        }
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}