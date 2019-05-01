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

	sf::Texture enemybar1Texture;
	sf::Sprite enemybar1;
	sf::Texture enemybar2Texture;
	sf::Sprite enemybar2;
	sf::Texture enemybar3Texture;
	sf::Sprite enemybar3;
	sf::Texture enemybar4Texture;
	sf::Sprite enemybar4;

	sf::Texture playerbar1Texture;
	sf::Sprite playerbar1;
	sf::Texture playerbar2Texture;
	sf::Sprite playerbar2;
	sf::Texture playerbar3Texture;
	sf::Sprite playerbar3;
	sf::Texture playerbar4Texture;
	sf::Sprite playerbar4;

	enemybar1.setPosition(620.0f, 270.0f);
	enemybar2.setPosition(620.0f, 270.0f);
	enemybar3.setPosition(620.0f, 270.0f);
	enemybar4.setPosition(620.0f, 270.0f);

	playerbar1.setPosition(80.0f, 270.0f);
	playerbar2.setPosition(80.0f, 270.0f);
	playerbar3.setPosition(80.0f, 270.0f);
	playerbar4.setPosition(80.0f, 270.0f);

	if (!playerbar1Texture.loadFromFile("image/player_bar1.png"))
	{
		return -1;
	}
	else
	{
		playerbar1.setTexture(playerbar1Texture);
	}
	if (!playerbar2Texture.loadFromFile("image/player_bar2.png"))
	{
		return -1;
	}
	else
	{
		playerbar2.setTexture(playerbar2Texture);
	}
	if (!playerbar3Texture.loadFromFile("image/player_bar3.png"))
	{
		return -1;
	}
	else
	{
		playerbar3.setTexture(playerbar3Texture);
	}
	if (!playerbar4Texture.loadFromFile("image/player_bar4.png"))
	{
		return -1;
	}
	else
	{
		playerbar4.setTexture(playerbar4Texture);
	}

	if (!enemybar1Texture.loadFromFile("image/enemy_bar1.png"))
	{
		return -1;
	}
	else
	{
		enemybar1.setTexture(enemybar1Texture);
	}
	if (!enemybar2Texture.loadFromFile("image/enemy_bar2.png"))
	{
		return -1;
	}
	else
	{
		enemybar2.setTexture(enemybar2Texture);
	}
	if (!enemybar3Texture.loadFromFile("image/enemy_bar3.png"))
	{
		return -1;
	}
	else
	{
		enemybar3.setTexture(enemybar3Texture);
	}
	if (!enemybar4Texture.loadFromFile("image/enemy_bar4.png"))
	{
		return -1;
	}
	else
	{
		enemybar4.setTexture(enemybar4Texture);
	}


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
	sf::Text texta;
	sf::Text textb;
	sf::Text emblemtext;
	sf::Text text1;
	sf::Text HPP;
	sf::Text HPE;
	int x = rand() % 50;
	int y = rand() % 50;
	int a = rand() % 13;
	int b = rand() % 13;

	int playerHP = 100;
	int enemyHP = 300;

	int result;
	string emblem = "";

	while (y > x)
	{
		y = rand() % 50;
	}


	int number = 0;
	int z = rand() % 3;

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
		number = a * b;
		emblem = "X";
	}

	string numx;
	string numy;
	string numa;
	string numb;
	string display = "";
	string HPplayer = "";
	string HPenemy = "";

	numx = to_string(x);
	numy = to_string(y);
	numa = to_string(a);
	numb = to_string(b);
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
				if (evnt.key.code == sf::Keyboard::R)
				{
					if (display != "" || playerHP == 0 || enemyHP == 0)
					{
						playerHP = stoi(HPplayer);
						playerHP = 100;
						HPplayer = to_string(playerHP);
						enemyHP = stoi(HPenemy);
						enemyHP = 300;
						HPenemy = to_string(enemyHP);

					}
					else
					{
					}
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
							a = rand() % 13;
							b = rand() % 13;
							emblem = "";
							numx;
							numy;
							while (y > x)
							{
								y = rand() % 50;
							}

							numx = to_string(x);
							numy = to_string(y);
							numa = to_string(a);
							numb = to_string(b);

							z = rand() % 3;
							number = 0;

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
								number = a * b;
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
							x = rand() % 50;
							y = rand() % 50;
							a = rand() % 13;
							b = rand() % 13;
							emblem = "";
							numx;
							numy;
							while (y > x)
							{
								y = rand() % 50;
							}

							numx = to_string(x);
							numy = to_string(y);
							numa = to_string(a);
							numb = to_string(b);

							z = rand() % 3;
							number = 0;

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
								number = a * b;
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
		textx.setPosition(200.0f, 30.0f);

		texta.setFont(font);
		texta.setString(numa);
		texta.setCharacterSize(70);
		texta.setFillColor(sf::Color::Black);
		texta.setStyle(sf::Text::Bold);
		texta.setPosition(200.0f, 30.0f);

		texty.setFont(font);
		texty.setString(numy);
		texty.setCharacterSize(70);
		texty.setFillColor(sf::Color::Black);
		texty.setStyle(sf::Text::Bold);
		texty.setPosition(480.0f, 30.0f);

		textb.setFont(font);
		textb.setString(numb);
		textb.setCharacterSize(70);
		textb.setFillColor(sf::Color::Black);
		textb.setStyle(sf::Text::Bold);
		textb.setPosition(480.0f, 30.0f);


		emblemtext.setFont(font);
		emblemtext.setString(emblem);
		emblemtext.setCharacterSize(50);
		emblemtext.setFillColor(sf::Color::Black);
		emblemtext.setStyle(sf::Text::Bold);
		emblemtext.setPosition(360.0f, 40.0f);

		text1.setString(display);
		text1.setFont(font);
		text1.setPosition(300, 530);
		text1.setCharacterSize(50);
		text1.setFillColor(sf::Color::Black);
		text1.setStyle(sf::Text::Bold);

		HPP.setString(HPplayer);
		HPP.setFont(font);
		HPP.setPosition(90, 250);
		HPP.setCharacterSize(20);
		HPP.setFillColor(sf::Color::Black);

		HPE.setString(HPenemy);
		HPE.setFont(font);
		HPE.setPosition(620, 250);
		HPE.setCharacterSize(20);
		HPE.setFillColor(sf::Color::Black);

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
		if (z == 2)
		{
			window.draw(texta);
			window.draw(textb);
		}
		else
		{
			window.draw(textx);
			window.draw(texty);
		}

		window.draw(text1);
		window.draw(emblemtext);
		window.draw(HPP);
		window.draw(HPE);

		if (enemyHP == 300 || enemyHP == 280 || enemyHP == 260 || enemyHP == 240 || enemyHP == 220)
		{
			window.draw(enemybar1);
		}
		else if (enemyHP == 200 || enemyHP == 180 || enemyHP == 160 || enemyHP == 140 || enemyHP == 120)
		{
			window.draw(enemybar2);
		}
		else if (enemyHP == 100 || enemyHP == 80 || enemyHP == 60 || enemyHP == 40)
		{
			window.draw(enemybar3);
		}
		else if (enemyHP == 20)
		{
			window.draw(enemybar4);
		}

		if (playerHP == 100 && playerHP > 80)
		{
			window.draw(playerbar1);
		}
		else if (playerHP == 80 && playerHP > 60)
		{
			window.draw(playerbar2);
		}
		else if (playerHP == 60 && playerHP > 20)
		{
			window.draw(playerbar3);
		}
		else if (playerHP = 20 && playerHP > 0)
		{
			window.draw(playerbar4);
		}

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