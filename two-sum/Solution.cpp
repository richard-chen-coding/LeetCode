#include<vector>
#include<algorithm>




class Solution 
{
public:
	vector<pair<int, int> > dict;
	int idx;

	
	vector<int> twoSum(vector<int> &numbers, int _target)
	{		
		this->idx = 1;

		std::for_each(numbers.begin(), numbers.end(), [this](int i)
		{ 
			auto pair = std::make_pair(i, this->idx);
			this->dict.push_back(pair);
			this->idx++;
		});
		
		std::sort(dict.begin(), dict.end(), [](pair<int, int>  a, pair<int, int>  b)->bool
		{
			return a.first < b.first;
		});

		auto min_itr = dict.begin();
		auto max_itr = dict.end() - 1;
		while (true)
		{
			int min_val = min_itr->first;
			int max_val = max_itr->first;
			int sum = min_val + max_val;
			if (sum == _target)
			{
				vector<int> ret = { min_itr->second, max_itr->second };
				std::sort(ret.begin(), ret.end());
				return ret;
			}
			else if (sum > _target)
			{
				max_itr--;
			}
			else
			{
				min_itr++;
			}
		}

	}
};