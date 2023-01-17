#include "cell.h"
#include <string>
#include <set>
#include <map>
class SudokuField
{
public:
	CellContainer Container[3][3];
	std::multimap<int, Cell*>  map_Cell;

	SudokuField();

	void draw(sf::RenderWindow* Window);
	void Set(const std::string field[9]);
	void GetLine(int L, std::string& Line);
	void GetColumn(int N, std::string& Col);

	void GetLine(int L, std::set<int>& Line);
	void GetColumn(int N, std::set<int>& Col);
	void GetContainer(int L, int N, std::set<int>& Cont);
	void GetNotAvaibleStates(int X, int Y, std::set<int>& Cont);
	void GetAvaibleStates(int X, int Y, std::set<int>& Cont);
	int GetFirstAvaibleState(int X, int Y);


	void SetEntropy();
	void FillGaps();
};