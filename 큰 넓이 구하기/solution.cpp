#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double triangle = c * d / 2.0;
    double rectangle = a * b - triangle;

    cout.setf(ios::fixed);
    cout.precision(1);
    if (triangle > rectangle)
        cout << triangle;
    else
        cout << rectangle;
    cout << endl;
}
