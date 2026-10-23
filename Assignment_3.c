#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[100], temp;
    int n, i, j, ch, key, low, high, mid, found;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter roll, name and marks: ");
        scanf("%d %49s %f", &s[i].roll, s[i].name, &s[i].marks);
    }

    printf("1.Linear Search 2.Binary Search 3.Insertion Sort 4.Selection Sort 5.Shell Sort\n");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("Enter roll number: ");
        scanf("%d", &key);
        found = 0;

        for (i = 0; i < n; i++)
            if (s[i].roll == key) {
                printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
                found = 1;
                break;
            }

        if (!found)
            printf("Student not found\n");
    } else if (ch >= 3 && ch <= 5) {
        if (ch == 3) {
            for (i = 1; i < n; i++) {
                temp = s[i];
                j = i - 1;
                while (j >= 0 && s[j].roll > temp.roll) {
                    s[j + 1] = s[j];
                    j--;
                }
                s[j + 1] = temp;
            }
        } else if (ch == 4) {
            for (i = 0; i < n - 1; i++) {
                j = i;
                for (int k = i + 1; k < n; k++)
                    if (s[k].roll < s[j].roll)
                        j = k;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        } else {
            for (int gap = n / 2; gap > 0; gap /= 2)
                for (i = gap; i < n; i++) {
                    temp = s[i];
                    j = i;
                    while (j >= gap && s[j - gap].roll > temp.roll) {
                        s[j] = s[j - gap];
                        j -= gap;
                    }
                    s[j] = temp;
                }
        }

        for (i = 0; i < n; i++)
            printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    } else if (ch == 2) {
        for (i = 1; i < n; i++) {
            temp = s[i];
            j = i - 1;
            while (j >= 0 && s[j].roll > temp.roll) {
                s[j + 1] = s[j];
                j--;
            }
            s[j + 1] = temp;
        }

        printf("Enter roll number: ");
        scanf("%d", &key);
        low = 0;
        high = n - 1;
        found = 0;

        while (low <= high) {
            mid = (low + high) / 2;
            if (s[mid].roll == key) {
                printf("%d %s %.2f\n", s[mid].roll, s[mid].name, s[mid].marks);
                found = 1;
                break;
            } else if (s[mid].roll < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (!found)
            printf("Student not found\n");
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}