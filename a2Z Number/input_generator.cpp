#include <cstdio>
#include <cstdlib>
#include <ctime>

void f(int k, int len) {
    printf("%d ", k);

    for (int i = 0; i < len; ++i) {
        // 현재 자릿수
        int p = rand() % k;

        // 첫 번째 자리 0 방지
        if (i == 0)
            while (p == 0)
                p = rand() % k;

        if (p < 10)
            p = '0' + p;
        else if (p < 36)
            p = 'A' + (p - 10);
        else
            p = 'a' + (p - 36);

        printf("%c", p);
    }

    printf("\n");
}

int main() {
    int i, k, len;
    srand(time(NULL));

    for (i = 0; i < 50; ++i) {
        int k, len;
        k = rand() % 60 + 2;

        if (k <= 8)
            len = rand() % 9 + 1;
        else if (k <= 15)
            len = rand() % 6 + 1;
        else if (k <= 31)
            len = rand() % 5 + 1;
        else
            len = rand() % 4 + 1;

        f(k, len);
    }

    return 0;
}