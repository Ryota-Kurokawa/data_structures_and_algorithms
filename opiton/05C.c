#include <stdio.h>
#include <math.h>

// 2Dベクトル構造体の定義
typedef struct {
    double x;
    double y;
} Point;

// 再帰関数でコッホ曲線を描く
void koch(int n, Point a, Point b) {
    if (n == 0) {
        printf("%.8f %.8f\n", a.x, a.y);
        return;
    }

    // 3等分する点
    Point s, t, u;
    double th = M_PI / 3; // 60度

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    // 再帰呼び出し
    koch(n - 1, a, s);
    koch(n - 1, s, u);
    koch(n - 1, u, t);
    koch(n - 1, t, b);
}

int main() {
    int n;
    scanf("%d", &n);

    Point a = {0.0, 0.0};
    Point b = {100.0, 0.0};

    koch(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);

    return 0;
}
