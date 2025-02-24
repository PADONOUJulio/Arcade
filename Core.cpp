/*
** EPITECH PROJECT, 2022
** eret
** File description:
** retg
*/

#include <dlfcn.h>
#include <iostream>
#include "lib/ILib.hpp"
#include "lib/Ncurses.hpp"
#include "lib/SDL2.hpp"
#include "lib/Core.hpp"

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

    while (i < 38)
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
            // tab[x][y] = '\n';
            // y++;
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

void *libopen(std::string path)
{
    void *handle;
    ILib *(*create)();
    std::string d = "./";
    d += path;
    handle = dlopen(d.c_str(), RTLD_LAZY);
    if (!handle)
    {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        exit(EXIT_FAILURE);
    }
    return (handle);
}

ILib *Libload(void *handle)
{
    ILib *(*create)();
    create = (ILib * (*)()) dlsym(handle, "create");
    if (create == NULL)
    {
        std::cerr << "dlsym : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }
    ILib *classe = (ILib *)create();
    return (classe);
}

IGame *Gameload(void *handle)
{
    IGame *(*create)();
    create = (IGame * (*)()) dlsym(handle, "create");
    if (create == NULL)
    {
        std::cerr << "dlsym : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }
    IGame *classe = (IGame *)create();
    return (classe);
}

void libclose(void *handle, ILib *classe)
{
    void (*destroy)(ILib *);
    destroy = (void (*)(ILib *))dlsym(handle, "destroy");
}

int Core::findinx_lib(std::string lib)
{
    int i = 0;
    while (tab_lib[i] != lib)
    {
        i++;
    }
    return i;
}

void Core::handle_lib_inx()
{
    if (change == true)
    {
        libclose(handle_lib, obj_lib);
        current_lib_i += 1;
        if (current_lib_i > 2)
            current_lib_i = 0;
        printf("%s\n", tab_lib[current_lib_i]);
        // printf("here1\n");
        handle_lib = libopen(tab_lib[current_lib_i]);
        obj_lib = Libload(handle_lib);
        if (obj_game != NULL)
            obj_lib->set_game(obj_game);
        change = false;
    }
    change = false;
    // printf("here2\n");
}

void Core::handle_game_inx()
{
    if (obj_lib->get_game_name() == "lib/arcade_nibbler.so")
    {
        std::vector<std::string> buff = loadfil("ress/Snake.txt");
        // printf("here1\n");
        handle_game = libopen(obj_lib->get_game_name());
        // printf("here2\n");
        obj_game = Gameload(handle_game);
        // printf("here3\n");
        obj_game->set_map(buff);
        // printf("here4\n");
        obj_lib->set_game(obj_game);
        // printf("quit\n");
    }
    else
    {
        std::vector<std::string> buff = loadfil("ress/kom.txt");
        handle_game = libopen(obj_lib->get_game_name());
        obj_game = Gameload(handle_game);
        obj_game->set_map(buff);
        obj_lib->set_game(obj_game);
    }
}

void Core::gameloop()
{
    // printf("here\n");
    while (1)
    {
        obj_lib->set_state(state);
        obj_lib->gameloop();
        // printf("state = %d change = %d close = %d\n",obj_lib->get_state(),obj_lib->get_change(),obj_lib->get_close());
        if ((obj_lib->get_state() == false && obj_lib->get_change() == false))
        {
            handle_game_inx();
            state = false;
        }
        else if (obj_lib->get_change() == true)
        {
            state = obj_lib->get_state();
            change = true;
            handle_lib_inx();
        }
        else if (obj_lib->get_close() == true)
            break;
        // printf("miaou2\n");
    }
}

int main(int ac, char **av)
{
    std::string d(av[1]);
    d.find('.');
    // printf("miaou1\n");
    Core core(d);
    //printf("miaou2\n");
    core.handle_lib = libopen(d);
    //return 0;
     //printf("miaou3\n");
    core.obj_lib = Libload(core.handle_lib);
    // printf("miaou4\n");
    core.gameloop();
    // printf("miaou5\n");
    libclose(core.handle_lib, core.obj_lib);
}