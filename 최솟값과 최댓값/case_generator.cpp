#include <iostream>
#include <random>
#include <chrono>
#include <string>
using namespace std;

default_random_engine generator;

int rand_int(int from = 0, int to = 1) {
    uniform_int_distribution<int> d(from, to);
    return d(generator);
}

double rand_double(int from = 0.0, int to = 1.0) {
    uniform_real_distribution<double> d(from, to);
    return d(generator);
}


bool first_out;
void make_expression(double depth, double delta, int num_from, int num_to) {
    if (first_out)
        first_out = false;
    else
        cout << ' ';

    double prob = depth;

    if (rand_double() < prob) {  // MIN or MAX
        if (rand_int())
            cout << "MIN";
        else
            cout << "MAX";
        make_expression(depth - delta, delta, num_from, num_to);
        make_expression(depth - delta, delta, num_from, num_to);
    }
    else {  // Number
        cout << rand_int(num_from, num_to);
    }
}

int main() {
    generator.seed(chrono::system_clock::now().time_since_epoch().count());

    // TODO: 길이를 예상하여 케이스를 생성하기 조금 어렵습니다.
    // 특정 길이를 갖는 수열을 어떻게 구할 수 있을까요?

    for (int i = 0; i < 10; i++) {
        first_out = true;
        make_expression(1.0, 0.2, 1, 100);
        cout << endl;
    }

    for (int i = 0; i < 20; i++) {
        first_out = true;
        make_expression(1.0, 0.15, 1, 10000);
        cout << endl;
    }

    return 0;
}