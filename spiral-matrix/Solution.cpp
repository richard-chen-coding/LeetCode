#include<vector>

using namespace std;

struct Element
{
	int x;
	int y;
	Element(int _x, int _y) : x(_x), y(_y){}
};
enum Direction
{
	None = -1,
	Right = 0,
	Down = 1,
	Left = 2,
	Up = 3
};


typedef bool(*MoveFtr) (Element &e);


class Solution
{
public:
	static bool MoveRight(Element &e)
	{
		int max_x = Solution::columns - Solution::cycle;
		if (max_x <= e.x)
		{
			return false;
		}
		else
		{
			e.x++;
			return true;
		}
	}

	static bool MoveDown(Element &e)
	{
		int max_y = Solution::rows - Solution::cycle;
		if (max_y <= e.y)
		{
			return false;
		}
		else
		{
			e.y++;
			return true;
		}
	}

	static bool MoveLeft(Element &e)
	{
		int min_x = Solution::cycle;
		if (min_x >= e.x)
		{
			return false;
		}
		else
		{
			e.x--;
			return true;
		}
	}

	static bool MoveUp(Element &e)
	{
		int min_y = Solution::cycle;
		if (min_y >= e.y)
		{
			return false;
		}
		else
		{
			e.y--;
			return true;
		}
	}
	static size_t rows;
	static size_t columns;
	static int cycle;

	vector<MoveFtr> FuncTbl;


	vector<int> matrix_out;



	Direction TryNext(Direction enterDir, Element &e)
	{
		vector<int> vce_step = { 0, 1 };

		int idx = (int)enterDir;

		for (auto step = vce_step.begin(); step != vce_step.end(); ++step)
		{
			int i = (idx + *step) % 4;
			if (enterDir == Direction::Left && i == Direction::Up)
			{
				Solution::cycle++;
			}
			if (FuncTbl[i](e))
			{

				return (Direction)i;
			}
		}

		return Direction::None;
	}

	vector<int> spiralOrder(vector<vector<int> > &matrix)
	{


		rows = matrix.size();
		if (rows == 0)
		{
			return vector<int>();
		}
		rows--;

		columns = matrix[0].size();
		if (columns == 0)
		{
			return vector<int>();
		}
		columns--;

		Element e(0, 0);
		Direction dir = Direction::Right;

		while (true)
		{
			int x = e.x;
			int y = e.y;
			int v = matrix[y][x];
			matrix_out.push_back(v);

			dir = TryNext(dir, e);
			if (dir == Direction::None)
			{
				break;
			}
		}
		return matrix_out;
	}

	Solution()
	{
		FuncTbl.push_back(Solution::MoveRight);
		FuncTbl.push_back(Solution::MoveDown);
		FuncTbl.push_back(Solution::MoveLeft);
		FuncTbl.push_back(Solution::MoveUp);
		cycle = 0;
		rows = 0;
		columns = 0;
	}
};

int Solution::cycle = 0;
size_t Solution::rows = 0;
size_t Solution::columns = 0;
