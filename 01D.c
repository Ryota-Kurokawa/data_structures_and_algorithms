#include <stdio.h>

int main() {
    int n;
    int maxv = -1000000000;
    int x = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (i == 0) {
            x = a;
        } else {
            if (maxv < a - x) {
                maxv = a - x;
            }
            if (x > a) {
                x = a;
            }
        }
    }
    printf("%d\n", maxv);
    return 0;
}