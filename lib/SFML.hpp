/*
** EPITECH PROJECT, 2022
** zer
** File description:
** ezr
*/

//#include <SFML/Keyboard.hpp>
#include <bits/stdc++.h>
//#include <String.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include "ILib.hpp"
#include <ncurses.h>
#include <SDL2/SDL.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma once

class SFML : public ILib
{
private:
    bool state = true;
    std::shared_ptr<sf::RenderWindow> menu;
    sf::Event event;
    sf::Text text;
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    sf::Text text4;
    sf::Text snake;
    sf::Text pacman;
    sf::Text YourName;
    sf::Text UserName;
    sf::Font font;
    sf::Font fontu;
    sf::Font font2;
    sf::Text Text;
    std::string d;
    std::string string;
    std::vector<std::string> vec;
    std::string player;
    std::string game_name;
    bool change = false;
    bool close = false;
    IGame *game = NULL;
public:
    SFML();
    ~SFML();
    void add_name();
    void create_win();
    void close_win();
    void init();
    void clear();
    void gameloop();
    void print_menu(std::vector<std::string> buff, int z);
    void *keymenu(int *i, int *v, std::vector<std::string> *buff, int c, int *tab);
    void get_menu_inp();
    bool get_change() const;
    bool get_close() const;
    std::string get_player() const;
    std::string get_game_name() const;
    void print_game(std::vector<std::string> buff);
    bool get_state() const;
    IGame *set_game(IGame *g);
    void *keygame();
    void set_state(bool a);
};
