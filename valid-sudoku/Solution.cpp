
class Solution 
{
public:
	Solution():vec(9,0),column_matrix(9, vec),row_matrix(9, vec),blk_matrix(9, vec)
	{

		
	}
	vector<int> vec;
	vector<vector<int> > column_matrix;
	vector<vector<int> > row_matrix;
	vector<vector<int> > blk_matrix;


	bool isValid(vector<vector<int> > & matrix, int idx, int val)
	{
		int v = matrix[idx][val];
		if( v == 0)
		{
			matrix[idx][val] = 1;
			return true;
		}
		else
		{
			return false;
		}

	}

    bool isValidSudoku(vector<vector<char> > &board) 
	{
		for(int rowIdx = 0; rowIdx < 9; ++rowIdx)
		{
			auto row = board[rowIdx];
			for(int colIdx = 0; colIdx < 9; ++colIdx)
			{
				char valueChar = row[colIdx];
				if(valueChar >= '1' && valueChar <= '9')
				{
					int value = valueChar - '0' - 1;

					if(!isValid(row_matrix, rowIdx, value))
					{
						return false;
					}

					
					if(!isValid(column_matrix, colIdx, value))
					{
						return false;
					}

					int blkNum = rowIdx/3 * 3 + colIdx / 3;

					if(!isValid(blk_matrix, blkNum, value))
					{
						return false;
					}

				}
				else if(valueChar != '.')
				{
					return false;
				}
			}
		}

        
		return true;
    }
};