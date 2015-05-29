#include <iostream>

using namespace std;

int main()
{
	int N,even=0,odd=0;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		if (N%i == 0)
		{
			if (i % 2 == 0)
				even++;
			else if (i % 2 == 1)
				odd++;
		}
	}
	cout << odd << " " << even;
}
