#include <cstdio>
#include <cstdlib>
#include <ctime>
#define sudokusize 9
class Sudoku
{
	public:
		Sudoku();
		void ReadIn();
		int Solve();
		int find(int i,int j);
		void GiveQuestion();
	private:
	int map[sudokusize][sudokusize];
	int res[sudokusize][sudokusize];
	int givequestion[sudokusize][sudokusize];
	int zero;		
	int depth;
	int Answer;
	struct BT 
	{
		int x;
		int y;
	}record[81];
	int lx;
	int ly;
};
