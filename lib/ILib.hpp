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
#include <SDL2/SDL.h>
#include "IGame.hpp"

#pragma once

class ILib
{
public:
    virtual ~ILib() = default;
    virtual void create_win() = 0;
    virtual void close_win() = 0;
    virtual void init() = 0;
    virtual void clear() = 0;
    virtual void gameloop() = 0;
    virtual void print_menu(std::vector<std::string> buff, int z) = 0;
    virtual void *keymenu(int *i, int *v, std::vector<std::string> *buff, int c, int *tab) = 0;
    virtual void get_menu_inp() = 0;
    virtual bool get_change() const = 0;
    virtual bool get_close() const = 0;
    virtual std::string get_player() const = 0;
    virtual std::string get_game_name() const = 0;
    virtual void print_game(std::vector<std::string> buf) = 0;
    virtual bool get_state() const = 0;
    virtual IGame *set_game(IGame *g) = 0;
    virtual void *keygame() = 0;
    virtual void set_state(bool a) = 0;
};