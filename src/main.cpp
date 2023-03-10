#include <iostream>

#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Sudoku.h"

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(640, 500),
        "Solving the sudoku");

     sf::RectangleShape rectangle(sf::Vector2f(128.0f,128.0f));
  	rectangle.setFillColor(sf::Color::Red);
 	rectangle.setPosition(320,240);
  	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

    SudokuField Field;

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

    auto th = std::thread(
        [&Field]()
        {
            
            while (true)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                Field.SetEntropy();
                Field.FillGaps();
            }
            
        }
    );

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
    th.join();
}