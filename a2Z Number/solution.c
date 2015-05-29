#include <stdio.h>
#include <string.h>

int main() {
    char s[32];
    int i, T, x;
    scanf("%d", &T);
    while (T--) {
        int sum = 0, p = 1;
        scanf("%d %s", &x, s);
        for (i = strlen(s) - 1; i >= 0; --i, p *= x)
            sum += p * (s[i] - (s[i] < 'A' ? '0' : (s[i] < 'a' ? 55 : 49)));
        printf("%d\n", sum);
    }
    return 0;
}
