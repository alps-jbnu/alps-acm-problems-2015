#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int s[1000100];

int main() {
    int i, n, k;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i)
        scanf("%d", &s[i]);
    int l=0, r=n-1, p;
    for (i = 0; i < k; ++i){
        scanf("%d", &p);
        l=0, r=n-1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (s[mid] > p)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (abs(p - s[l]) >= abs(p - s[r]))
            printf("%c%d ", p > s[r] ? '-' : '+', (int)abs(p - s[r]));
        else
            printf("%c%d ", p > s[l] ? '-' : '+', (int)abs(p - s[l]));
    }
    return 0;
}
