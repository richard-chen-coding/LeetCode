class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {

	int str_len = s.length();

	int max_len = 0;
	int cur_len = 0;
	int beg_idx = 0;

	int c_tbl[256];
	memset(&c_tbl[0], -1, sizeof(c_tbl));


	int idx = 0;
	for(idx = 0; idx < str_len; ++idx)
	{
		char c = s[idx];
		int offset = (int)c;
		if(c_tbl[offset] != -1)
		{
			cur_len = idx - beg_idx;
			max_len = max(max_len, cur_len);
			beg_idx = c_tbl[offset] + 1;

			memset(&c_tbl[0], -1, sizeof(c_tbl));
			idx = beg_idx - 1;
		}
		else
		{
			c_tbl[offset] = idx;
		}
	}
	
	cur_len = idx - beg_idx;
	max_len = max(max_len, cur_len);
	return max_len;
    }
};