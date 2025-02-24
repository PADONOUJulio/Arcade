/*
** EPITECH PROJECT, 2022
** erf
** File description:
** ezre
*/

#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <fstream>
#include "ILib.hpp"
#include "IGame.hpp"

#pragma once

class Core {
public:
    char tab_lib[3][32] = {"lib/arcade_ncurses.so", "lib/arcade_sdl2.so", "lib/arcade_sfml.so"};
    char tab_game[2][32] = {"lib/arcade_nibbler.so","lib/arcade_pacman.so"};
    int current_lib_i = 0;
    int current_game_i = 0;
    std::string path_lib = tab_lib[current_lib_i];
    std::string path_game = tab_game[current_game_i];
    void *handle_lib;
    void *handle_game;
    ILib *obj_lib = NULL;
    IGame *obj_game = NULL;
    bool change = false;
    bool state = true;
    Core(std::string startlib) {
        current_lib_i = findinx_lib(startlib);
        std::cout << current_lib_i << std::endl;
    }
    ~Core() {

    }
    int findinx_lib(std::string lib);
    int findinx_game(std::string game);
    void gameloop();
    void handle_lib_inx();
    void handle_game_inx();
};
