#include <iostream>
#include <string>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int tc = 0; tc < cases; tc++) {
        int x;
        string n;
        cin >> x >> n;

        int sum = 0;
        int digit_size = 1;
        for (int i = n.size() - 1; i >= 0; i--) {
            char c = n[i];
            int val;

            if ('0' <= c && c <= '9')
                val = c - '0';
            else if ('A' <= c && c <= 'Z')
                val = (c - 'A') + 10;
            else if ('a' <= c && c <= 'z')
                val = (c - 'a') + 36;

            sum += val * digit_size;

            digit_size *= x;
        }

        cout << sum << endl;
    }
    return 0;
}
