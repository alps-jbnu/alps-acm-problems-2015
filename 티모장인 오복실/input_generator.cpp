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

void print_case(int n_from, int n_to, int k_from, int k_to,
               int a_diff_from, int a_diff_to, int a_from,
               int b_diff_from, int b_diff_to, int b_from) {
   int n = rand_int(n_from, n_to);
   int k = rand_int(k_from, k_to);

   cout << n << ' ' << k << endl;

   int a_val = a_from;
   bool a_first = true;
   for (int i = 0; i < n; i++) {
       if (a_first)
           a_first = false;
       else
           cout << ' ';
       cout << a_val;
       a_val += rand_int(a_diff_from, a_diff_to);
   }
   cout << endl;

   int b_val = b_from;
   bool b_first = true;
   for (int i = 0; i < k; i++) {
       if (b_first)
           b_first = false;
       else
           cout << ' ';
       cout << b_val;
       b_val += rand_int(b_diff_from, b_diff_to);
   }
   cout << endl;
}

int main() {
   generator.seed(chrono::system_clock::now().time_since_epoch().count());

   int n_from, n_to, k_from, k_to;

   cout << "<case>" << endl;
   n_from = 5;
   n_to = 10;
   k_from = 5;
   k_to = 10;
   print_case(n_from, n_to, k_from, k_to, 3, 6, 10, 3, 6, 10);
   cout << "</case>" << endl;

   cout << "<case>" << endl;
   n_from = 500;
   n_to = 500;
   k_from = 500;
   k_to = 500;
   print_case(n_from, n_to, k_from, k_to, 1, 100, 50, 1, 100, 50);
   cout << "</case>" << endl;

   cout << "<case>" << endl;
   n_from = 100000;
   n_to = 100000;
   k_from = 50000;
   k_to = 50000;
   print_case(n_from, n_to, k_from, k_to, 1, 2, 50000, 3, 6, 10);
   cout << "</case>" << endl;

   cout << "<case>" << endl;
   n_from = 50000;
   n_to = 50000;
   k_from = 100000;
   k_to = 100000;
   print_case(n_from, n_to, k_from, k_to, 3, 6, 10, 1, 2, 50000);
   cout << "</case>" << endl;

   return 0;
}
