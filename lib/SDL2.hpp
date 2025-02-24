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
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#pragma once



class SDL2 : public ILib
{
private:
    struct ttf {
        TTF_Font *Font;
        SDL_Surface *Surface;
        SDL_Texture *Texture;
        SDL_Rect Rect;
        TTF_Font *font;
        TTF_Font *font1;
        TTF_Font *font2;
        SDL_Color color;
    };
    ttf text;
    ttf text1;
    ttf text2;
    ttf text3;
    ttf text4;
    ttf text5;
    ttf text6;
    ttf text7;
    std::string name = "NAME :";
    bool state = true;
    SDL_Window *menu = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;
    std::string lib;
    bool change = false;
    int menuin = 0;
    int i = 6;
    int v = 1;
    bool close = false;
    IGame *game = NULL;  
    std::string player;
    std::string game_name;
public:

    SDL2();
    ~SDL2();
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