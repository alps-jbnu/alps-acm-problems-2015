#include <iostream>
#include <random>
#include <chrono>
#include <string>
using namespace std;

const int cases = 30;

const int min_boundary_cases = 2;
const int min_str_len_from = 2;
const int min_str_len_to = 2;
const int min_str_alphabets = 2;

const int max_boundary_cases = 3;
const int max_str_len_from = 100;
const int max_str_len_to = 100;
const int max_str_alphabets = 26;

const int easy_cases = 5;
const int easy_str_len_from = 10;
const int easy_str_len_to = 30;
const int easy_str_alphabets = 3;

const int normal_cases = 10;
const int normal_str_len_from = 31;
const int normal_str_len_to = 60;
const int normal_str_alphabets = 6;

const int hard_cases = 10;
const int hard_str_len_from = 61;
const int hard_str_len_to = 100;
const int hard_str_alphabets = 10;


default_random_engine generator;

int rand_int(int from, int to) {
    uniform_int_distribution<int> d(from, to);
    return d(generator);
}

char rand_alphabet(int from, int to) {
    return (char)('a' + rand_int(from, to));
}

void print_case(int str_len_from, int str_len_to, int alphabets) {
    int s_len = rand_int(str_len_from, str_len_to);
    int t_len = rand_int(str_len_from, str_len_to);

    string s;
    for (int i = 0; i < s_len; i++) {
        s.push_back(rand_alphabet(0, alphabets-1));
    }

    string t;
    for (int i = 0; i < t_len; i++) {
        t.push_back(rand_alphabet(0, alphabets-1));
    }

    cout << s << endl;
    cout << t << endl;
}


int main() {
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    generator.seed(seed);

    cout << cases << endl;

    for (int i = 0; i < min_boundary_cases; i++)
        print_case(min_str_len_from, min_str_len_to, min_str_alphabets);

    for (int i = 0; i < max_boundary_cases; i++)
        print_case(max_str_len_from, max_str_len_to, max_str_alphabets);

    for (int i = 0; i < easy_cases; i++)
        print_case(easy_str_len_from, easy_str_len_to, easy_str_alphabets);

    for (int i = 0; i < normal_cases; i++)
        print_case(normal_str_len_from, normal_str_len_to, normal_str_alphabets);

    for (int i = 0; i < hard_cases; i++)
        print_case(hard_str_len_from, hard_str_len_to, hard_str_alphabets);
    
    return 0;
}
