/*
** EPITECH PROJECT, 2022
** rzefgr
** File description:
** eézref
*/

#include <menu.h>
#include <ncurses.h>
#include <streambuf>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <curses.h>
#include "../lib/Ncurses.hpp"
#include <cstdlib>
#include "unistd.h"

int count_word(char *c)
{
    int e = 0, i = 0;

    while (c[i] != '\0')
    {
        if (c[i] == '\n')
        {
            e++;
        }
        i++;
    }
    e = e + 1;
    return (e);
}

Ncurses::Ncurses()
{
}

Ncurses::~Ncurses()
{
}

void my_malloc(char *str, char **tab)
{
    int i = 0, j = 0, y = 0, e = 0, v = 0, k = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            v++;
            tab[y] = new char[j + 1];
            e = e + j;
            j = 0;
            i++;
            y++;
        }
        i++;
        j++;
    }
    k = i - (e + v);
    tab[y] = new char[k + 1];
}

void is_free(char **tab)
{
    int i = 0;

    while (i <= 22)
    {
        delete[] tab[i];
        i++;
    }
    delete[] tab;
}

void is_tab(char *str, char **tab)
{
    int i = 0, y = 0, x = 0;

    while (str[i] != '\0')
    {
        tab[x][y] = str[i];
        y++;
        i++;
        if (str[i] == '\n')
        {
            tab[x][y] = '\0';
            x++;
            y = 0;
            i++;
        }
    }
}

char **str_tab(char *c)
{
    int h = count_word(c);
    char **t;
    t = new char *[h + 1];
    my_malloc(c, t);
    is_tab(c, t);
    t[h] = NULL;
    return (t);
}

void Ncurses::create_win()
{
    menu = newwin(70, 1000, 0, 0);
    box(menu, 0, 0);
}

void Ncurses::print_menu(std::vector<std::string> buff, int z)
{
    int i = 0;
    int j = 2;
    while (i < buff.size())
    {
        if (i == z)
        {
            wattron(menu, A_REVERSE);
        }
        else
        {
            wattroff(menu, A_REVERSE);
        }
        mvwprintw(menu, j, 11, "%s\n", buff[i].c_str());
        i++;
        j++;
        // wattroff(menu, A_VERTICAL);
    }
}

void Ncurses::print_game(std::vector<std::string> buff)
{
    int i = 0;
    int j = 2;
    while (i < buff.size())
    {
        mvwprintw(menu, j, 5, "%s\n", buff[i].c_str());
        i++;
        j++;
        // wattroff(menu, A_VERTICAL);
    }
    mvwprintw(menu, 2,87,"Name: %s",player.c_str());
    mvwprintw(menu, 3,87,"Score: %d",game->get_score());   
}

std::vector<std::string> loadfil(std::string d)
{
    int i = 0;
    std::vector<std::string> v;
    std::string filename(d);
    std::string line;
    std::ifstream t(filename);
    while (getline(t, line))
    {
        v.push_back(line);
    }
    return (v);
}

int *seach(std::vector<std::string> av)
{
    int i = 0;
    int j = 0;
    int v = 0;
    int *tab = new int[2];
    while (i < av.size())
    {
        while (av[i][j] != '\0')
        {
            if (av[i][j] == ':')
            {
                tab[0] = i, tab[1] = j;
                // break;
                v = 1;
            }
            j++;
        }
        if (v == 1)
            break;
        j = 0, i++;
    }
    return (tab);
}

void Ncurses::init()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    nonl();
    nodelay(menu, TRUE);
}

void *Ncurses::keymenu(int *i, int *v, std::vector<std::string> *buff, int c, int *tab)
{
    //std::vector<std::string> d = (*buff);
    if (c == 65)
    {
        if (*i == 17)
            ;
        else
            *i = 17;
    }
    if (c == 66)
    {
        if (*i == 19)
            *i = 17;
        else
            *i = 19;
    }
    // printf("miaou\n");
    if (c >= 97 && c <= 122)
    {
        if (*v != 12)
        {
            mvprintw(0,2,"%d\n",tab[1] + *v);
            this->buff[tab[0]][tab[1] + *v] = ((c - 97) + 65);
            *v = *v + 1;
            player += ((c - 97) + 65);
        }
    }
    if (c == 32)
    {
        if (*v != 12)
        {
            this->buff[tab[0]][tab[1] + *v] = ' ';
            *v = *v + 1;
            player += ' ';
        }
    }
    if (c == 127)
    {
        if (*v >= 3)
        {
            this->buff[tab[0]][(tab[1] + *v) - 1] = ' ';
            *v = *v - 1;
            player.pop_back();
        }
    }
    // return ((void *) -1);
    //(*buff) = d;
    // printf("%s\n",player.c_str());
    if (c == 13 && player.length() > 0)
    {
        if (*i == 17)
        {
            game_name = "lib/arcade_nibbler.so";
            // is_free(*buff);
            //(*buff) = NULL;
            // (*buff) = loadfil("ress/Snake.txt");
        }
        else
        {
            game_name = "lib/arcade_pacman.so";
            // is_free(*buff);
            // (*buff) = NULL;
            // (*buff) = loadfil("ress/Pacman.txt");
        }
        state = false;
    }
    if (c == 43)
    {
        change = true;
    }
    if (c == 72)
        return ((void *)-1);
    else
        return ((void *)1);
}

void Ncurses::clear()
{
    refresh();
    wrefresh(menu);
}

void Ncurses::close_win()
{
    // is_free(buff);
    delwin(menu);
    endwin();
    //is_free(buff);
}

void Ncurses::get_menu_inp()
{
    // printf("io\n");
    menuin = wgetch(menu);
    /*if (menuin == KEY_RIGHT)
    {
        game->set_dir(1, 0);
    }
    if (menuin == KEY_DOWN)
    {
        game->set_dir(0, 1);
    }
    if (menuin == KEY_UP)
    {
        game->set_dir(0, -1);
    }
    if (menuin == KEY_LEFT)
    {
        game->set_dir(-1, 0);
    }*/
}

bool Ncurses::get_change() const
{
    return (change);
}

bool Ncurses::get_close() const
{
    return close;
}

std::string Ncurses::get_game_name() const
{
    return game_name;
}

std::string Ncurses::get_player() const
{
    return player;
}

bool Ncurses::get_state() const
{
    return state;
}

IGame *Ncurses::set_game(IGame *g)
{
    game = g;
    return (g);
}

void *Ncurses::keygame()
{
    // mvprintw(0,0,"%d\n",menuin);
    // std::vector<int> d = game->get_direction();
    if (menuin == KEY_RIGHT)
    {
        game->set_dir(1, 0);
    }
    if (menuin == KEY_DOWN)
    {
        game->set_dir(0, 1);
    }
    if (menuin == KEY_UP)
    {
        game->set_dir(0, -1);
    }
    if (menuin == KEY_LEFT)
    {
        game->set_dir(-1, 0);
    }
    if (menuin == 43)
    {
        change = true;
    }
    if (menuin == 13)
    {
        if (game_name == "lib/arcade_nibbler.so")
        {
            game_name = "lib/arcade_pacman.so";
            // is_free(*buff);
            //(*buff) = NULL;
            // (*buff) = loadfil("ress/Snake.txt");
        }
        else
        {
            game_name = "lib/arcade_nibbler.so";
            // is_free(*buff);
            // (*buff) = NULL;
            // (*buff) = loadfil("ress/Pacman.txt");
        }
        return ((void *)(-2));
        // game = NULL;
    }
    return ((void *)1);
}

void Ncurses::set_state(bool a)
{
    state = a;
}

void Ncurses::gameloop()
{
    // printf("%d\n",0);
    std::string d = "ress/julio.txt";
    buff = loadfil(d);
    //printf("%s\n",buff[0]);
    // char **buf = loadfil("ress/Snake.txt");
    init();
    create_win();
    clear();
    int i = 17;
    int v = 2;
    int *tab = seach(buff);
    // printf("%d\n",1);
    while (1)
    {
        if (state == true)
        {
            print_menu(buff, i);
            get_menu_inp();
            // printf("%d\n", i);
            if (keymenu(&i, &v, &buff, menuin, tab) == (void *)(-1))
            {
                close = true;
                break;
            }
            if (change == true)
                break;

            clear();
        }
        else if (state == false)
        {
            // menuin = getch();
            // keygame();
            if (game == NULL)
            {
                break;
            }
            // close = true;
            // break;
            // game->game_loop();
            if (change == true)
                break;
            print_game(game->get_map());
            timeout(2);
            // printf("d\n",menuin);
            // get_menu_inp();
            menuin = getch();
            // printf("%d\n",menuin);
            if (static_cast<int>(reinterpret_cast<std::uintptr_t>(keygame())) == -2)
            {
                // mvprintw(1,1,"here\n");
                game = NULL;
                break;
            }
            clear();
            game->game_loop();
        }
    }
    // printf("ko\n");
    delete[] tab;
    tab = NULL;
    close_win();
    //buff = NULL;
}

extern "C" ILib *create()
{
    return new Ncurses();
}

extern "C" void destroy(ILib *p)
{
    delete p;
}

/*int main()
{
    ILib *ju = new Ncurses();
    ju->gameloop();
}*/
