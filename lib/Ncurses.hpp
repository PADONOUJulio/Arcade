/*
** EPITECH PROJECT, 2022
** zer
** File description:
** ezr
*/

#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <fstream>
#include "ILib.hpp"
#include <ncurses.h>
#pragma once


class Ncurses : public ILib
{
private:
    bool state = true;
    WINDOW *menu = NULL;
    int menuin = 0;
    bool change = false;
    int i = 16;
    int v = 2;
    bool close = false;
    std::string player;
    std::string game_name;
    IGame *game = NULL;
    std::vector<std::string> buff;
public:
    Ncurses();
    ~Ncurses();
    void create_win();
    void close_win();
    void clear();
    void init();
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