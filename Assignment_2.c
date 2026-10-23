#include <stdio.h>

int main() {
    int a[100][3], b[100][3], t[100][3], f[100][3];
    int r, c, n, i, j, k, count[100] = {0}, pos[100];

    printf("Enter rows, columns and non-zero elements: ");
    scanf("%d%d%d", &r, &c, &n);

    a[0][0] = r;
    a[0][1] = c;
    a[0][2] = n;

    printf("Enter row, column and value of each non-zero element:\n");
    for (i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);

    printf("Sparse matrix in triplet form:\n");
    for (i = 0; i <= n; i++)
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);

    t[0][0] = c;
    t[0][1] = r;
    t[0][2] = n;
    k = 1;

    for (i = 0; i < c; i++)
        for (j = 1; j <= n; j++)
            if (a[j][1] == i) {
                t[k][0] = a[j][1];
                t[k][1] = a[j][0];
                t[k][2] = a[j][2];
                k++;
            }

    printf("Simple transpose:\n");
    for (i = 0; i <= n; i++)
        printf("%d %d %d\n", t[i][0], t[i][1], t[i][2]);

    for (i = 1; i <= n; i++)
        count[a[i][1]]++;

    pos[0] = 1;
    for (i = 1; i < c; i++)
        pos[i] = pos[i - 1] + count[i - 1];

    f[0][0] = c;
    f[0][1] = r;
    f[0][2] = n;

    for (i = 1; i <= n; i++) {
        j = pos[a[i][1]]++;
        f[j][0] = a[i][1];
        f[j][1] = a[i][0];
        f[j][2] = a[i][2];
    }

    printf("Fast transpose:\n");
    for (i = 0; i <= n; i++)
        printf("%d %d %d\n", f[i][0], f[i][1], f[i][2]);

    return 0;
}