
#define MAX_ROOT 46340
#define MAX_SQR 2147395600

class Solution {
public:
int sqrt(int x)
{
	if(x >= MAX_SQR)
	{
		return MAX_ROOT;
	}
	int min = 0;
	int max = MAX_ROOT;


	while(true)
	{
		if(max == min + 1 && (min * min <= x && max * max >= x))
		{
			return min;
		}
		int p = (min + max)/2;
		int tmp = p * p;
		if(tmp == x)
		{
			return p;
		}
		else if(tmp > x)
		{
			max = p;
		}
		else
		{
			min = p;
		}
	}
}