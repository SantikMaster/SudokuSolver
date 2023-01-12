#include "sudoku.h"


SudokuField::SudokuField()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			Container[i][j].SetPostion(3 * i * Cell::Size + 2 * i, 3 * j * Cell::Size + 2 * j);
		}
	}

}
void SudokuField::Set(const std::string field[9])
{
	int X, Y;

	for (Y = 0; Y < 9; Y++)
	{
		for (X = 0; X < field[Y].length(); X++)
		{
			int i_Cont, i_Cell;
	//		X = i_cont * i_Cell;
			i_Cont = X / 3;
			i_Cell = X % 3;

			int j_Cont, j_Cell;
			j_Cont = Y / 3;
			j_Cell = Y % 3;

			char symb = field[Y][X] - 48;
			Container[i_Cont][j_Cont].Cells[i_Cell][j_Cell].set(symb);
		}
	}
}

void SudokuField::draw(sf::RenderWindow* Window)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			Container[i][j].draw(Window);
		}
	}

}

void SudokuField::GetLine(int L, std::string &Line)
{
	Line = "";

	int X;
	for (X = 0; X < 9; X++)
	{
		int i_Cont, i_Cell;
		i_Cont = X / 3;
		i_Cell = X % 3;

		int j_Cont, j_Cell;
		j_Cont = L / 3;
		j_Cell = L % 3;

		int Val = Container[i_Cont][j_Cont].Cells[i_Cell][j_Cell].get();
		if (Val != -1)
		{
			Line += std::to_string(Val);
		}		
		else
			Line += " ";
	}
}

void SudokuField::GetColumn(int N, std::string& Col)
{
	Col = "";

	int Y;
	for (Y = 0; Y < 9; Y++)
	{
		int i_Cont, i_Cell;
		i_Cont = N / 3;
		i_Cell = N % 3;

		int j_Cont, j_Cell;
		j_Cont = Y / 3;
		j_Cell = Y % 3;

		int Val = Container[i_Cont][j_Cont].Cells[i_Cell][j_Cell].get();
		if (Val != -1)
		{
			Col += std::to_string(Val);
		}
		else
			Col += " ";
	}
}