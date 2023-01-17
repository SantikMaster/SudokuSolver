#include "sudoku.h"

#include <iostream>

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
	for (int X = 0; X < 9; X++)
	{
		for (int Y = 0; Y < 9; Y++)
		{
			int i_Cont, i_Cell;
			i_Cont = X / 3;
			i_Cell = X % 3;

			int j_Cont, j_Cell;
			j_Cont = Y / 3;
			j_Cell = Y % 3;

			Container[i_Cont][j_Cont].Cells[i_Cell][j_Cell].i = X;
			Container[i_Cont][j_Cont].Cells[i_Cell][j_Cell].j = Y;
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

void SudokuField::GetLine(int L, std::set<int>& Line)
{
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
			Line.insert(Val);
		}
		
	}
}

void SudokuField::GetColumn(int N, std::set<int>& Col)
{
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
			Col.insert(Val);
		}

	}
}

void SudokuField::GetContainer(int L, int N, std::set<int>& Cont)
{	
	int Y, X;

	int i_Cont = N / 3;
	int j_Cont = L / 3;
	for (int X = 0; X < 3; X++)
	{
		for (int Y = 0; Y < 3; Y++)
		{
			int Val = Container[i_Cont][j_Cont].Cells[X][Y].get();
			if (Val != -1)
			{
				Cont.insert(Val);
			}

		}
	}
}

//function that for given X, Y shows what numbers are not avaible
void SudokuField::GetNotAvaibleStates(int X, int Y, std::set<int>& Cont)
{

	GetContainer(Y, X, Cont);
	GetLine(Y, Cont);
	GetColumn(X, Cont);
}

void SudokuField::GetAvaibleStates(int X, int Y, std::set<int>& Cont)
{
	std::set<int> Unavaible;
	GetNotAvaibleStates( X, Y, Unavaible);
	
	int i;
	for (i = 1; i < 10; i++)
	{
		auto pos = Unavaible.find(i);
		if (pos == Unavaible.end());
		{
			Cont.insert(i);
		}
	}

}

//finds first avaible state
int SudokuField::GetFirstAvaibleState(int X, int Y)
{
	std::set<int> Unavaible;
	GetNotAvaibleStates(X, Y, Unavaible);

	int i;
	for (i = 1; i < 10; i++)
	{
		auto pos = Unavaible.find(i);
		if (pos == Unavaible.end())
		{
			return i;
		}
	}
	return -1;
}

void SudokuField::SetEntropy()
{
	int Y, X;

	map_Cell.clear();
	for (int X = 0; X < 9; X++)
	{
		for (int Y = 0; Y < 9; Y++)
		{
			int i_Cont, i_Cell;
			i_Cont = X / 3;
			i_Cell = X % 3;

			int j_Cont, j_Cell;
			j_Cont = Y / 3;
			j_Cell = Y % 3;			
			
			int Val = Container[i_Cont][j_Cont].Cells[i_Cell][j_Cell].get();
			if (Val != -1)
			{
				Container[i_Cont][j_Cont].Cells[i_Cell][j_Cell].SetEntropy(10);

				continue;
			}

			std::set<int> Cont;
			GetNotAvaibleStates(X, Y, Cont);


			Container[i_Cont][j_Cont].Cells[i_Cell][j_Cell].SetEntropy(9- Cont.size());	
			map_Cell.insert(std::make_pair<int, Cell*>(Cont.size() ,&Container[i_Cont][j_Cont].Cells[i_Cell][j_Cell]));

		}
	}
}

void SudokuField::FillGaps()
{
	for (int rg = 8; rg >= 0; rg--)
	{
		auto ret = map_Cell.equal_range(rg);
		for (auto it = ret.first; it != ret.second; ++it)
		{
//			std::cout << ' ' << it->second->X << ' ' << it->second->Y << ' ' << it->second->GetEntropy() << '\n';
			if (rg == 8)
			{
				int i = it->second->i;
				int j = it->second->j;

				int NewState = GetFirstAvaibleState(i, j);
				it->second->set(NewState);
//				std::cout <<" State: " << NewState << '\n';
			}
		}
		

	}
}