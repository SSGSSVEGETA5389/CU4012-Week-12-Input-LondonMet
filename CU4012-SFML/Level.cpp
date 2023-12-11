#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	
	circle.setRadius(20);
	circle.setFillColor(sf::Color::Red); 



	// initialise game objects

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{

	if (input->isKeyDown(sf::Keyboard::W))

	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W was pressed.\n";


	}

	if (input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::L))

	{
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::L);

	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();


	}

	sf::Vector2i MousePos = sf::Vector2i(input->getMouseX(), input->getMouseY());
	std::string MousePosString = std::to_string(MousePos.y);
	MousePosString.append(":");
	MousePosString.append(std::to_string(MousePos.y));
	mousePosition.setString(MousePosString);

	if (input->isMouseLDown())

	{

		if (!dragging)
		{
			dragging = true;
			InitalMousePosition = sf::Vector2i(input->getMouseX(), input->getMouseY());


		}
		else
		{
			FinalMousePosition = sf::Vector2i(input->getMouseX(), input->getMouseY());

			float dx = float(FinalMousePosition.x - InitalMousePosition.x);
			float dy = float(FinalMousePosition.y - InitalMousePosition.y);
			float distance = std::sqrt(dx * dy * dy);

			std::cout << "Distance: " << distance << std::endl;

		}
	}
 

else 

{
	dragging = false;

}

	if (input->isMouseRDown())
	{

		circle.setPosition(input->getMouseX(), input->getMouseY()); 

	}

}










// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}