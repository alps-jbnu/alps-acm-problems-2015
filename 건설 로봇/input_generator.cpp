#include <iostream>
#include <random>
#include <chrono>
#include <string>
using namespace std;

#define VAR_CNT 10

// cases, w_from, w_to, k_from, k_to, l_from, l_to, n_from, n_to, weight(0~100)
int datas[][VAR_CNT] = {
    {5, 3, 6, 3, 6, 10, 100, 10, 100, 50},
    {10, 10, 20, 10, 20, 100, 1000, 100, 1000, 30},
    {10, 30, 50, 30, 50, 1000, 10000, 1000, 10000, 15},
    {5, 45, 50, 45, 50, 9000, 10000, 9000, 10000, 10}
};

default_random_engine generator;

int rand_int(int from, int to) {
    uniform_int_distribution<int> d(from, to);
    return d(generator);
}

int edge(double weight) {
    double x = rand_int(0, 999) / 1000.0;
    if (x < weight)
        return 1;
    else
        return 0;
}

void print_case(int data[VAR_CNT]) {
    int cases = data[0];
    int w_from = data[1];
    int w_to = data[2];
    int k_from = data[3];
    int k_to = data[4];
    int l_from = data[5];
    int l_to = data[6];
    int n_from = data[7];
    int n_to = data[8];
    double weight = data[9] / 100.0;

    for (int tc = 0; tc < cases; tc++) {
        int w = rand_int(w_from, w_to);
        int k = rand_int(k_from, k_to);
        cout << w << ' ' << k << endl;

        for (int i = 0; i < w; i++) {
            int l = rand_int(l_from, l_to);
            cout << l;
            if (i == w - 1)
                cout << endl;
            else
                cout << ' ';
        }

        for (int j = 0; j < k; j++) {
            int n = rand_int(n_from, n_to);
            cout << n;
            for (int i = 0; i < w; i++) {
                int c = edge(weight);
                cout << ' ' << c;
            }
            cout << endl;
        }
    }
}

int main() {
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    generator.seed(seed);

    int data_cnt = sizeof(datas) / (VAR_CNT * sizeof(int));
    int cases = 0;
    for (int d_num = 0; d_num < data_cnt; d_num++)
        cases += datas[d_num][0];
    cout << cases << endl;

    for (int d_num = 0; d_num < data_cnt; d_num++)
        print_case(datas[d_num]);

    return 0;
}