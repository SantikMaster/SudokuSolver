#include <iostream>


#include <SFML/Graphics.hpp>

//#include "Cell.h"
#include "Sudoku.h"

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(640, 500),
        "Rendering the rectangle.");

     sf::RectangleShape rectangle(sf::Vector2f(128.0f,128.0f));
  	rectangle.setFillColor(sf::Color::Red);
 	rectangle.setPosition(320,240);
  	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

 //   CellContainer Cell_cont(0,0);
    SudokuField Field;

/*    std::string field_str[9] =
    {
        "123456789",
        "123456789",
        "123456789",

        "123456789",
        "123456789",
        "123456789",

        "123456789",
        "123456789",
        "123456789"
    };*/


    std::string field_str[9] =
    {
         "53 " " 7 " "   ",
         "6  " "195" "   ",
         " 98" "   " " 6 ",

         "8  " " 6 " "  3",
         "4  " "8 3" "  1",
         "7  " " 2 " "  6",

         " 6 " "   " "28 ",
         "   " "419" "  5",
         "   " " 8 " " 79",
    };

    Field.Set(field_str);
    std::string TestLine;
    Field.GetColumn(3, TestLine);

    std::cout << TestLine;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // Close window button clicked.
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        Field.draw(&window);

        window.display();
    }
}