#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int expression() {
    string input;
    cin >> input;

    if (input.compare("MAX") == 0) {
        return max(expression(), expression());
    } else if (input.compare("MIN") == 0) {
        return min(expression(), expression());
    } else {
        int number = atoi(input.c_str());
        return number;
    }
}

int main() {
    cout << expression() << endl;
    return 0;
}