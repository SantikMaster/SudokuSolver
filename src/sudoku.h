#include "cell.h"
#include <string>
class SudokuField
{
public:
	CellContainer Container[3][3];

	SudokuField();


	void draw(sf::RenderWindow* Window);
	void Set(const std::string field[9]);
	void GetLine(int L, std::string& Line);
	void GetColumn(int N, std::string& Col);
};