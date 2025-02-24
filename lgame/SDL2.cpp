/*
** EPITECH PROJECT, 2022
** eér"e
** File description:
** e"ref
*/

#include <SDL2/SDL.h>
#include <ncurses.h>
#include "../lib/SDL2.hpp"
#include <SDL2/SDL_ttf.h>
#include <cstring>
#include <sstream> 
#include <string>
#include <iostream>

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

    while (tab[i] != NULL)
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
            tab[x][y] = '\n';
            y++;
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

char *load(std::string d)
{
    int i = 0;
    std::ifstream t(d);
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    char *c = const_cast<char *>(str.c_str());
    return c;
}

SDL2::SDL2()
{
}

SDL2::~SDL2()
{
}

void SDL2::create_win()
{
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto Width = DM.w;
    auto Height = DM.h;
    SDL_RenderClear(renderer);
    SDL_CreateWindowAndRenderer(Width, Height, 0, &menu, &renderer);
    text.font = TTF_OpenFont("ress/space.ttf", 15);
    text1.font = TTF_OpenFont("ress/space.ttf", 15);
    text2.font = TTF_OpenFont("ress/space.ttf", 15);
    text4.font = TTF_OpenFont("ress/game.ttf", 10);
    text5.font = TTF_OpenFont("ress/game.ttf", 10);
    text6.font = TTF_OpenFont("ress/game.ttf", 10);
    text7.font = TTF_OpenFont("ress/game.ttf", 10);
}

void SDL2::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_StartTextInput();
    TTF_Init();
}

void SDL2::close_win()
{
    // is_free(buff);
    SDL_DestroyWindow(menu);
    SDL_Quit();
    // SDL_DestroyWindow(menu);
    // SDL_Quit();
    TTF_CloseFont(text.font);
    TTF_CloseFont(text1.font);
    TTF_CloseFont(text2.font);
    TTF_Quit();
}

void SDL2::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void set_text(SDL_Surface **Surface, SDL_Texture **Texture, SDL_Rect *Rect, TTF_Font **font, SDL_Color *color, std::string s, SDL_Renderer *renderer, int a, int b, int c, int d, int e, int f)
{
    *Surface = TTF_RenderText_Solid(*font, s.c_str(), *color);
    *Texture = SDL_CreateTextureFromSurface(renderer, *Surface);
    SDL_QueryTexture(*Texture, NULL, NULL, &a, &b);
    *Rect = {c, d, e, f};
}

void SDL2::print_menu(std::vector<std::string> buff, int z)
{
    int i = 0, e = 200;
    int j = 2;
    int v = 0, p = 0;
    int v1 = 0, p1 = 0;
    int v2 = 0, p2 = 0;
    int v3 = 173, p3 = 15;
    text.color = {255, 255, 255};
    text1.color = {255, 0, 0};
    text2.color = {255, 255, 255};
    text3.color = {0, 255, 0};
    std::string s;
    set_text(&text.Surface, &text.Texture, &text.Rect, &text.font, &text.color, "ARCADE", renderer, v, p, 200, 0, 1000, 200);
    if (z == 1)
    {
        text1.color = {255, 0, 0};
        text2.color = {255, 255, 255};
    }
    if (z == 2)
    {
        text1.color = {255, 255, 255};
        text2.color = {255, 0, 0};
    }
    set_text(&text1.Surface, &text1.Texture, &text1.Rect, &text1.font, &text1.color, "-> Snake", renderer, v1, p1, 550, 300, 175, 15);
    set_text(&text2.Surface, &text2.Texture, &text2.Rect, &text2.font, &text2.color, "-> Pacman", renderer, v2, p2, 550, 320, 175, 15);
    text3.Surface = TTF_RenderText_Solid(text2.font, name.c_str(), text3.color);
    text3.Texture = SDL_CreateTextureFromSurface(renderer, text3.Surface);
    SDL_QueryTexture(text3.Texture, NULL, NULL, &v3, &p3);
    text3.Rect = {550, 380, v3, p3};
    SDL_RenderCopy(renderer, text.Texture, NULL, &text.Rect);
    SDL_RenderCopy(renderer, text1.Texture, NULL, &text1.Rect);
    SDL_RenderCopy(renderer, text2.Texture, NULL, &text2.Rect);
    SDL_RenderCopy(renderer, text3.Texture, NULL, &text3.Rect);
    SDL_DestroyTexture(text.Texture);
    SDL_FreeSurface(text.Surface);
    SDL_DestroyTexture(text1.Texture);
    SDL_FreeSurface(text1.Surface);
    SDL_DestroyTexture(text2.Texture);
    SDL_FreeSurface(text2.Surface);
    SDL_DestroyTexture(text3.Texture);
    SDL_FreeSurface(text3.Surface);
    SDL_RenderPresent(renderer);
}

void *SDL2::keymenu(int *i, int *v, std::vector<std::string> *buff, int c, int *tab)
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            // printf("%d///\n", event.key.keysym.sym);
            if (event.key.keysym.sym == SDLK_DOWN)
            {
                if (*v == 1)
                    *v = 2;
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                if (*v == 2)
                    *v = 1;
            }
            else if ((event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z) || event.key.keysym.sym == SDLK_SPACE)
            {
                if (*i == 16)
                    break;
                name += event.key.keysym.sym;
                *i = *i + 1;
            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE)
            {
                if (*i <= 6)
                    break;
                name.resize(name.size() - 1);
                *i = *i - 1;
            }
            else if (event.key.keysym.sym == SDLK_KP_PLUS)
            {
                change = true;
            }
            else if (event.key.keysym.sym == 13)
            {
                if (*v == 1)
                    game_name = "lib/arcade_nibbler.so";
                else
                    game_name = "lib/arcade_pacman.so";
                state = false;
            }
            else
                break;
        }
    }
    if (event.type == SDL_QUIT)
        return ((void *)(-1));
    return ((void *)(1));
}

int *seach(std::vector<std::string> av)
{

    int *tab = NULL;
    return tab;
}

void SDL2::get_menu_inp()
{
}

bool SDL2::get_change() const
{
    return (change);
}

bool SDL2::get_close() const
{
    return close;
}

std::string SDL2::get_game_name() const
{
    return game_name;
}

std::string SDL2::get_player() const
{
    return player;
}

bool SDL2::get_state() const
{
    return state;
}

IGame *SDL2::set_game(IGame *g)
{
    game = g;
    return (g);
}

void *SDL2::keygame()
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            // printf("%d///\n", event.key.keysym.sym);
            if (event.key.keysym.sym == SDLK_DOWN)
            {
                game->set_dir(0, 1);
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                game->set_dir(0, -1);
            }
            else if (event.key.keysym.sym == SDLK_RIGHT)
            {
                game->set_dir(1, 0);
            }
            else if (event.key.keysym.sym == SDLK_LEFT)
            {
                game->set_dir(-1, 0);
            }
            else if (event.key.keysym.sym == SDLK_KP_PLUS)
            {
                change = true;
            }
            else if (event.key.keysym.sym == 13)
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
            }
            else
                break;
        }
    }
    if (event.type == SDL_QUIT)
        return ((void *)(-1));
    return ((void *)(1));
}

int len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void SDL2::set_state(bool a)
{
    state = a;
}

void SDL2::print_game(std::vector<std::string> buf)
{
    int i = 0;
    int e = 0;
    int v = 0;
    int p = 0;
    text4.color = {255, 0, 255};
    text5.color = {255, 0, 255};
    text6.color = {255, 0, 255};
    int v3 = 173, p3 = 15;
    /* while (i < 38)
     {
         std::string d = std::string(buf[i]);
         d.pop_back();
         d += '\n';
         // printf("%s\n",d.c_str());*/
    text4.Surface = TTF_RenderText_Solid(text4.font, "Score: ", text4.color);
    text4.Texture = SDL_CreateTextureFromSurface(renderer, text4.Surface);
    // SDL_QueryTexture(text4.Texture, NULL, NULL, &v3, &p3);
    // printf("%d %d %d\n",v3,p3,i);
    text4.Rect = {1000, 50, 50, 20};
    set_text(&text5.Surface, &text5.Texture, &text5.Rect, &text5.font, &text5.color, name.c_str(), renderer, v, p, 1000, 0, 90, 30);
    set_text(&text6.Surface, &text6.Texture, &text6.Rect, &text6.font, &text6.color, (std::to_string(game->get_score())).c_str(), renderer, v, p, 1090, 50, 20, 20);
    //set_text(&text3.Surface, &text3.Texture, &text3.Rect, &text3.font, &text3.color, "ARCADE", renderer, v, p, 1020, 1, 70, 20);
    SDL_RenderCopy(renderer, text4.Texture, NULL, &text4.Rect);
    SDL_DestroyTexture(text4.Texture);
    SDL_FreeSurface(text4.Surface);
    SDL_RenderCopy(renderer, text5.Texture, NULL, &text5.Rect);
    SDL_DestroyTexture(text5.Texture);
    SDL_FreeSurface(text5.Surface);
    SDL_RenderCopy(renderer, text6.Texture, NULL, &text6.Rect);
    SDL_DestroyTexture(text6.Texture);
    SDL_FreeSurface(text6.Surface);
    /* SDL_RenderCopy(renderer, text3.Texture, NULL, &text3.Rect);
    SDL_DestroyTexture(text3.Texture);
    SDL_FreeSurface(text3.Surface);*/
    /// SDL_RenderPresent(renderer);
    i = 0;
    // SDL_Rect rect;
    int j = 0;
    // SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);
    while (i < buf.size())
    {
        while (buf[i][j] != '\0')
        {
            if (buf[i][j] == 'X')
            {
                SDL_Rect rect;
                rect = {j * 12, i * 12, 10, 10};
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &rect);
                // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else if (buf[i][j] == '.')
            {
                SDL_Rect rectp;
                rectp = {j * 12, i * 12, 2, 2};
                SDL_SetRenderDrawColor(renderer, 29, 255, 255, 1);
                SDL_RenderDrawRect(renderer, &rectp);
                // SDL_SetRenderDrawColor(renderer, 29, 255, 255, 1);
            }
            else if (buf[i][j] == 'o')
            {
                SDL_Rect rect;
                rect = {j * 12, i * 12, 5, 5};
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &rect);
                // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else if (buf[i][j] == '#')
            {
                SDL_Rect rect;
                rect = {j * 12, i * 12, 5, 5};
                SDL_SetRenderDrawColor(renderer, 26, 193, 26, 1);
                SDL_RenderDrawRect(renderer, &rect);
                // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
            }
            else if (buf[i][j] == 'O')
            {
                SDL_Rect rects;
                rects = {j * 12, i * 12, 7, 7};
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
                SDL_RenderDrawRect(renderer, &rects);
                // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else if (buf[i][j] == 'P')
            {
                SDL_Rect rects;
                rects = {j * 12, i * 12, 7, 7};
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &rects);
                // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else if (buf[i][j] == 'G' || buf[i][j] == 'V')
            {
                SDL_Rect rects;
                rects = {j * 12, i * 12, 9, 9};
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
                SDL_RenderDrawRect(renderer, &rects);
                // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            j++;
        }
        j = 0, i++;
    }
    // printf("%d\n", i);
    //  SDL_RenderCopy(renderer, text.Texture, NULL, &text.Rect);
    SDL_RenderPresent(renderer);
}

void SDL2::gameloop()
{
    std::string d = "ress/julio.txt";
    std::vector<std::string> buff = loadfil(d);
    int z = 1;
    int i = 6;
    init();
    create_win();
    int *tab = seach(buff);
    while (1)
    {
        if (state == true)
        {
            print_menu(buff, z);
            get_menu_inp();
            if (keymenu(&i, &z, &buff, menuin, tab) == (void *)(-1))
            {
                close = true;
                break;
                // close = true;
            }
            if (change == true)
            {
                break;
            }
            clear();
        }
        else if (state == false)
        {
            // printf("mol1\n");
            if (game == NULL)
            {
                break;
            }
            // printf("mol2\n");
            //  clear();
            int y = static_cast<int>(reinterpret_cast<std::uintptr_t>(keygame()));
            if (y == -1)
            {
                printf("close\n");
                close = true;
                state = true;
                SDL_DestroyWindow(menu);
                SDL_Quit();
                // break;
            }
            else if (y == -2)
            {
                // printf("here\n");
                game = NULL;
                // SDL_DestroyWindow(menu);
                // SDL_Quit();
                break;
            }
            if (change == true)
                break;
            print_game(game->get_map());
            clear();
            game->game_loop();
        }
    }
    close_win();
    // buff = NULL;
}

extern "C" ILib *create()
{
    return new SDL2();
}

extern "C" void destroy(ILib *p)
{
    delete p;
}

/*int main()
{
    ILib *ju = new SDL2();
    ju->gameloop();
}*/