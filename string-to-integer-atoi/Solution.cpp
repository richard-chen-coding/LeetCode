
#define MAX_INT 0x7fffffff

class Solution
{
public:
	const char * trim(const char * str)
	{
		while (true)
		{
			char c = *str;
			if (c == ' ')
			{
				str++;
			}
			else
			{
				return str;
			}
		}

	}

	int lastDigit;
	int preCheck;

	Solution()
	{
		preCheck = MAX_INT / 10;
		lastDigit = MAX_INT - (MAX_INT / 10) * 10;
	}

	int atoi(const char *str)
	{
		if (str == NULL || strlen(str) == 0)
		{
			return 0;
		}
		str = trim(str);
		int isPositive = true;
		if (*str == '-')
		{
			isPositive = false;
			str++;
		}
		else if (*str == '+')
		{
			str++;
		}

		int ret = 0;

		while (*str >= '0' && *str <= '9')
		{
			int val = *str - '0';

			if (ret > preCheck || (ret == preCheck  & (val > lastDigit)))
			{
				ret = MAX_INT;
				if (!isPositive)
				{
					ret = ~ret;
				}
				return ret;
			}

			ret = ret * 10 + val;
			str++;
		}
		if (!isPositive)
		{
			ret = -1 * ret ;

		}
		return ret;
	}
};