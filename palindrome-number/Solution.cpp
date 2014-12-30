
class Solution
{
public:
	int calcDigit(int x)
	{
		int cnt = 1;
		while (x >= 10)
		{
			x = x / 10;
			cnt++;
		}
		return cnt;
	}

	bool isPalindrome(int x)
	{

		if (x < 0)
		{
			return false;
		}
		int max_digit = calcDigit(x);
		while (max_digit > 0)
		{

			if (max_digit == 1)
			{
				return true;
			}

			int power = std::pow(10, max_digit - 1);
			int max_value = x / power;
			int min_value = x % 10;
			if (max_value != min_value)
			{
				return false;
			}
			x = (x - max_value * power) / 10;
			max_digit -= 2;
		}
		return true;
	}
};