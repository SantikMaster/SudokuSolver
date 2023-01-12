
#include <memory>

namespace sf
{
	class RenderWindow;
	class Text;
	class Font;
	class Event;
	class RectangleShape;
}
class Cell
{
	int Number;
	int Entropy;

	std::shared_ptr<sf::Font> p_myFont;
	std::shared_ptr<sf::Text> p_Text;

	std::shared_ptr <sf::RectangleShape> rectangle;

public:
	static const int Size = 55;
	int X, Y;

	Cell();

	void set(int);
	int get();


	void draw(sf::RenderWindow* Window);

};

class CellContainer
{
public:
	Cell Cells[3][3];
	int X, Y;

	CellContainer();
	void SetPostion(int x, int y);

	void draw(sf::RenderWindow* Window);

};