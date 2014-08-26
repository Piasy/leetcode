#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
	int max = 0;
	int last_v, next_p;
	int i = 1;
	while (i < prices.size())
	{
		if (prices[i - 1] < prices[i])
		{
			last_v = prices[i - 1];
			while (i < prices.size())
			{
				if (prices[i - 1] < prices[i])
				{
					i ++;
				}
				else
				{
					break;
				}
			}
			next_p = prices[i - 1];
			max += (next_p - last_v);
		}
		i ++;
	}
	return max;
}

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	cout << maxProfit(v) << endl;
}