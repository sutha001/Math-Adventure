#include <SFML\Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Enemy.h"
#include <stdio.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "ef.h"
#include <SFML/Audio.hpp>


using namespace std;

int main()
{
srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 600), "MATH ADVENTURE", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	sf::RectangleShape enemy1(sf::Vector2f(100.0f, 150.0f));
	sf::RectangleShape playerat(sf::Vector2f(100.0f, 150.0f));
	sf::RectangleShape blood(sf::Vector2f(100.0f, 150.0f));

	player.setPosition(65.0f, 320.0f);
	enemy1.setPosition(600.0f, 320.0f);
	playerat.setPosition(650.0f, 320.0f);
	blood.setPosition(600.0f, 320.0f);

	sf::Texture playerTexture;
	sf::Texture enemyTexture;
	sf::Texture playerattackTexture;
	sf::Texture bloodTexture;

	playerTexture.loadFromFile("image/test.png");
	enemyTexture.loadFromFile("image/enemy_1.png");
	playerattackTexture.loadFromFile("image/playattack.png");
	bloodTexture.loadFromFile("image/blood_hit_01.png");
	player.setTexture(&playerTexture);
	enemy1.setTexture(&enemyTexture);
	playerat.setTexture(&playerattackTexture);

	class Animation animation(&playerTexture, sf::Vector2u(10, 10), 0.2f);
	class Animation animationattack(&playerattackTexture, sf::Vector2u(10, 10), 0.2f);
	class EF bloodall(&bloodTexture, sf::Vector2u(3, 9), 0.1f);
	class Enemy enemy(&enemyTexture, sf::Vector2u(10, 10), 0.2f);

	float deltaTime = 0.0f;

	sf::Clock clock;
	sf::Texture BackgroundTexture;
	sf::Sprite background;
	sf::Clock clock2;
	sf::Texture MenuTexture;
	sf::Sprite menu;
	sf::Clock clock3;
	sf::Texture WinTexture;
	sf::Sprite win;
	sf::Clock clock4;
	sf::Texture LoseTexture;
	sf::Sprite lose;

	if (!WinTexture.loadFromFile("image/WIN.png"))
	{
		return -1;
	}
	else
	{
		win.setTexture(WinTexture);
	}
	if (!LoseTexture.loadFromFile("image/LOSE.png"))
	{
		return -1;
	}
	else
	{
		lose.setTexture(LoseTexture);
	}


	if (!BackgroundTexture.loadFromFile("image/bg.png"))
	{
		return -1;
	}
	else
	{
		background.setTexture(BackgroundTexture);
	}
	int state = 0;

	if (!MenuTexture.loadFromFile("image/menu.png"))
	{
		return -1;
	}
	else
	{
		menu.setTexture(MenuTexture);
		state = 1;
	}

	sf::Font font;

	if (!font.loadFromFile("Font/PressStart2P.ttf"))
	{
		// error...
	}
	sf::Text textx;
	sf::Text texty;
	sf::Text emblemtext;
	sf::Text text1;
	sf::Text HPP;
	sf::Text HPE;
	int x = rand() % 50;
	int y = rand() % 50;
	int playerHP = 100;
	int enemyHP = 500;
	int result;
	string emblem = "";

	while (y > x)
	{
		y = rand() % 50;
	}


	int number = 0;
	int z = rand() % 2;

	if (z == 0)
	{
		number = x + y;
		emblem = "+";
	}
	else if (z == 1)
	{
		number = x - y;
		emblem = "-";
	}
	else if (z == 2)
	{
		number = x * y;
		emblem = "X";
	}

	string numx;
	string numy;
	string display = "";
	string HPplayer = "";
	string HPenemy = "";

	numx = to_string(x);
	numy = to_string(y);
	HPplayer = to_string(playerHP);
	HPenemy = to_string(enemyHP);

	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer2;



	if (!MenuTexture.loadFromFile("image/menu.png"))
	{
		return -1;
	}
	else
	{
		menu.setTexture(MenuTexture);
	}

	sf::Sound sound;
	sf::Sound sound2;
	sound.setBuffer(buffer);
	sound2.setBuffer(buffer2);
	if (!buffer.loadFromFile("Sound/player.wav"))
	{
		return -1;
	}
	if (!buffer2.loadFromFile("Sound/enemy.wav"))
	{
		return -1;
	}
	sf::Music music;

	if (!music.openFromFile("Sound/background.wav")) {
		std::cout << "Error...";
	}
	else {
		music.setLoop(true);
		music.setVolume(50);
		music.play();
	}

	int stateat = 0;
	int stateaten = 0;
	int stateef = 0;

	int give = 0;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				if (evnt.key.code == sf::Keyboard::Numpad0)
				{
					display = display + "0";
					
				}
				if (evnt.key.code == sf::Keyboard::Numpad1)
				{
					display = display + "1";
				}
				if (evnt.key.code == sf::Keyboard::Numpad2)
				{
					display = display + "2";
				}
				if (evnt.key.code == sf::Keyboard::Numpad3)
				{
					display = display + "3";
				}
				if (evnt.key.code == sf::Keyboard::Numpad4)
				{
					display = display + "4";
				}
				if (evnt.key.code == sf::Keyboard::Numpad5)
				{
					display = display + "5";
				}
				if (evnt.key.code == sf::Keyboard::Numpad6)
				{
					display = display + "6";
				}
				if (evnt.key.code == sf::Keyboard::Numpad7)
				{
					display = display + "7";
				}
				if (evnt.key.code == sf::Keyboard::Numpad8)
				{
					display = display + "8";
				}
				if (evnt.key.code == sf::Keyboard::Numpad9)
				{
					display = display + "9";
				}
				if (evnt.key.code == sf::Keyboard::Num0)
				{
					display = display + "0";
				}
				if (evnt.key.code == sf::Keyboard::Num1)
				{
					display = display + "1";
				}
				if (evnt.key.code == sf::Keyboard::Num2)
				{
					display = display + "2";
				}
				if (evnt.key.code == sf::Keyboard::Num3)
				{
					display = display + "3";
				}
				if (evnt.key.code == sf::Keyboard::Num4)
				{
					display = display + "4";
				}
				if (evnt.key.code == sf::Keyboard::Num5)
				{
					display = display + "5";
				}
				if (evnt.key.code == sf::Keyboard::Num6)
				{
					display = display + "6";
				}
				if (evnt.key.code == sf::Keyboard::Num7)
				{
					display = display + "7";
				}
				if (evnt.key.code == sf::Keyboard::Num8)
				{
					display = display + "8";
				}
				if (evnt.key.code == sf::Keyboard::Num9)
				{
					display = display + "9";
				}
				if (evnt.key.code == sf::Keyboard::BackSpace)
				{
					display = "";
				}
				if (evnt.key.code == sf::Keyboard::Space)
				{
					give++;
				}
				if (evnt.key.code == sf::Keyboard::Return)
				{
					if (display != "")
					{
						result = stoi(display);
						if (result == number)
						{
							stateat = 3;
							sound.play();
							enemyHP = stoi(HPenemy);
							enemyHP = enemyHP - 20;
							HPenemy = to_string(enemyHP);
							x = rand() % 50;
							y = rand() % 50;
							emblem = "";
							numx;
							numy;
							while (y > x)
							{
								y = rand() % 50;
							}

							numx = to_string(x);
							numy = to_string(y);

							int zz = rand() % 2;
							number = 0;

							if (zz == 0)
							{
								number = x + y;
								emblem = "+";
							}
							else if (zz == 1)
							{
								number = x - y;
								emblem = "-";
							}
							else if (zz == 2)
							{
								number = x * y;
								emblem = "X";
							}
							display = "";
						}
						else
						{
							stateaten = 3;
							sound2.play();
							playerHP = stoi(HPplayer);
							playerHP = playerHP - 20;
							HPplayer = to_string(playerHP);
							enemyHP = stoi(HPenemy);
							enemyHP = enemyHP - 20;
							HPenemy = to_string(enemyHP);
							x = rand() % 50;
							y = rand() % 50;
							emblem = "";
							numx;
							numy;
							while (y > x)
							{
								y = rand() % 50;
							}

							numx = to_string(x);
							numy = to_string(y);

							int zz = rand() % 2;
							number = 0;

							if (zz == 0)
							{
								number = x + y;
								emblem = "+";
							}
							else if (zz == 1)
							{
								number = x - y;
								emblem = "-";
							}
							else if (zz == 2)
							{
								number = x * y;
								emblem = "X";
							}
							display = "";
						}
					}
					else
					{
					}

				}
				break;
			default:
				break;
			}
		}


		textx.setFont(font);
		textx.setString(numx);
		textx.setCharacterSize(70);
		textx.setFillColor(sf::Color::Black);
		textx.setStyle(sf::Text::Bold);
		textx.setPosition(150.0f, 100.0f);

		texty.setFont(font);
		texty.setString(numy);
		texty.setCharacterSize(70);
		texty.setFillColor(sf::Color::Black);
		texty.setStyle(sf::Text::Bold);
		texty.setPosition(550.0f, 100.0f);


		emblemtext.setFont(font);
		emblemtext.setString(emblem);
		emblemtext.setCharacterSize(50);
		emblemtext.setFillColor(sf::Color::Black);
		emblemtext.setStyle(sf::Text::Bold);
		emblemtext.setPosition(380.0f, 120.0f);

		text1.setString(display);
		text1.setFont(font);
		text1.setPosition(250, 520);
		text1.setCharacterSize(50);
		text1.setFillColor(sf::Color::Black);
		text1.setStyle(sf::Text::Bold);

		HPP.setString(HPplayer);
		HPP.setFont(font);
		HPP.setPosition(50, 250);
		HPP.setCharacterSize(50);
		HPP.setFillColor(sf::Color::Black);
		HPP.setStyle(sf::Text::Bold);

		HPE.setString(HPenemy);
		HPE.setFont(font);
		HPE.setPosition(600, 250);
		HPE.setCharacterSize(50);
		HPE.setFillColor(sf::Color::Black);
		HPE.setStyle(sf::Text::Bold);

		stateef = bloodall.Update(stateef, deltaTime, stateef);
		stateat = animation.Update(stateat, deltaTime, stateat);
		stateaten = enemy.Update(stateaten, deltaTime, stateaten);

		player.setTextureRect(animation.uvRect);
		enemy1.setTextureRect(enemy.evRect);
		blood.setTextureRect(bloodall.evRect);

		window.clear();

		window.draw(background);
		window.draw(player);
		window.draw(enemy1);
		window.draw(textx);
		window.draw(texty);
		window.draw(text1);
		window.draw(emblemtext);
		window.draw(HPP);
		window.draw(HPE);

		if (give == 0)
		{
			window.draw(menu);
		}
		if (playerHP == 0)
		{
			window.draw(lose);
		}
		else if (enemyHP == 0)
		{
			window.draw(win);
		}

		window.display();
	}

	return 0;
}