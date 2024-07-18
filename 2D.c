#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1000000

int cnt = 0;  // グローバルカウンタ

// 挿入ソートを特定の間隔で行う関数
void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
}

// シェルソートを行う関数
void shellSort(int A[], int n) {
    // Knuthの間隔列を生成
    int G[MAX_N];
    int m = 0;
    for (int h = 1; h <= n; h = 3 * h + 1) {
        G[m++] = h;
    }

    for (int i = m - 1; i >= 0; i--) {
        insertionSort(A, n, G[i]);
    }

    // 結果の出力
    printf("%d\n", m);
    for (int i = m - 1; i >= 0; i--) {
        if (i != m - 1) printf(" ");
        printf("%d", G[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int A[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    shellSort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}
