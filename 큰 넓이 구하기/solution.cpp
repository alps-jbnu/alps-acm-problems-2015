#include <iostream>

using namespace std;

int main()
{
	int x, y,y1,x1;
	float trangle,rect;
	cin >> x >> y;
	cin >> y1;
	cin >> x1;
	trangle = (y1*x1) / 2;
	rect = x*y;
	if ((rect - trangle) >= trangle)
		cout << rect - trangle << endl;
}
