#include <iostream>

#include <SFML/Graphics.hpp>

#include "Cell.h"


Cell::Cell() 
{
	Number = -1;
	X = 0;
	Y = 0;

	rectangle = std::make_shared<sf::RectangleShape> (sf::Vector2f(Size-4, Size-4));

	std::string myfontFileName = "../Textures/Arial.ttf";
	p_myFont = std::make_shared<sf::Font>();
	p_Text = std::make_shared<sf::Text>();
	auto text = p_Text.get();

	if (!p_myFont.get()->loadFromFile(myfontFileName))
	{
		std::cout << "Could not find the font " << myfontFileName << std::endl;
	}

	text->setFont(*p_myFont.get());
	text->setCharacterSize(48);
	text->setColor(sf::Color::Red);
};
void Cell::set(int num)
{
	Number = num;
	auto text = p_Text.get();
	switch (num)
	{
		case 0:  text->setColor(sf::Color::Blue);     break;
		case 1:  text->setColor(sf::Color::Green);     break;
		case 2:  text->setColor(sf::Color::Yellow);     break;
		case 3:  text->setColor(sf::Color::Magenta);     break;
		case 4:  text->setColor(sf::Color::Blue);     break;
		case 5:  text->setColor(sf::Color::Red);     break;
		case 6:  text->setColor(sf::Color::Cyan);     break;
		case 7:  text->setColor(sf::Color::Red);     break;
		case 8:  text->setColor(sf::Color::Green);     break;
		case 9:  text->setColor(sf::Color::Black);     break;
	}
}
int Cell::get()
{
	if (Number < 0 || Number >9) return -1;
	return Number;
}

void Cell::SetEntropy(int val)
{
	Entropy = val;
}

int Cell::GetEntropy()
{
	return Entropy;
}

void Cell::draw(sf::RenderWindow* Window)
{
	rectangle->setFillColor(sf::Color::White);
	rectangle->setPosition(X + 2, Y + 2);

	Window->draw(*rectangle); // Drawing our shape.

	if (Number < 0 || Number > 9) return;

	std::string str = std::to_string(Number);
	p_Text.get()->setString(str);
	p_Text.get()->setPosition(15+X, 0+Y);
	Window->draw(*p_Text.get());
}


//-----------------------------------------------------------------------------------------
CellContainer::CellContainer()
{

	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			Cells[i][j].X =  i * Cell::Size;
			Cells[i][j].Y =  j * Cell::Size;
		}
	}
}

void CellContainer::SetPostion(int x, int y) 
{
	X = x;
	Y = y;

	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			Cells[i][j].X = x + i * Cell::Size;
			Cells[i][j].Y = y + j * Cell::Size;
		}
	}
}
void CellContainer::draw(sf::RenderWindow* Window)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			Cells[i][j].draw(Window);
		}
	}
}