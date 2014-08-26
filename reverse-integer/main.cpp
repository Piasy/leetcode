#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

int reverse(int x);

int main()
{
	int i = rand();
	cout << i << endl;
	cout << reverse(i) << endl;
}

int reverse(int x)
{//spoilers: end with 0(don't output); overflow(not considered);...
	int ret = 0;
	bool neg = x < 0;
	int p = x;
	if (neg)
	{
		p = -p;
	}
	queue<int> q;
	while (p != 0)
	{
		q.push(p % 10);
		p /= 10;
	}
	while (!q.empty())
	{
		ret += q.front();
		ret *= 10;
		q.pop();
	}
	ret /= 10;

	if (neg)
	{
		ret = -ret;
	}

	return ret;
}
