/*
** EPITECH PROJECT, 2022
** ezf
** File description:
** zefd
*/

#include "../lib/ILib.hpp"
#include "../lib/IGame.hpp"
#include "../lib/Snake.hpp"
#include <unistd.h>

void Snake::set_headpos()
{
    int i = 0;
    int j = 0;
    headpos.clear();
    while (i < map.size())
    {
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'O')
            {
                headpos.push_back(i);
                headpos.push_back(j);
                break;
            }
            j++;
        }
        j = 0, i++;
    }
}

Snake::~Snake()
{
}

bool Snake::get_state() const
{
    return state;
}

float Snake::get_speed() const
{
    return 1.2;
}

std::string Snake::get_library() const
{
    return (libname);
}

std::string Snake::get_playname() const
{
    return playname;
}

std::vector<int> Snake::get_direction() const
{
    return direction;
}

int Snake::get_life() const
{
    return life;
}

std::vector<int> Snake::get_winsize() const
{
    return headpos;
}

void Snake::set_life()
{
}

void Snake::set_length()
{
}

void Snake::set_state(bool a)
{
}

void Snake::set_speed(float a)
{
}

void Snake::seach_body_pos()
{
    int i = 0;
    int j = 0;
    int z = 0;
    body.clear();
    while (i < map.size())
    {
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'o')
            {
                std::vector<int> in;
                in.push_back(i);
                in.push_back(j);
                body.push_back(in);
            }
            j++;
        }
        i++, j = 0;
    }
}

void Snake::bodypos()
{
    int i = 1;
    std::vector<std::vector<int>> d = body;
    body[0][0] = last_headpos[0];
    body[0][1] = last_headpos[1];
    while (i < body.size())
    {
        body[i][0] = d[i - 1][0];
        body[i][1] = d[i - 1][1];
        i++;
    }
}

std::vector<int> Snake::get_head() const
{
    return headpos;
}

std::vector<std::string> Snake::get_map() const
{
    return map;
}

void Snake::set_map(std::vector<std::string> str)
{
    int i = 0;
    map = str;
    set_headpos();
    seach_body_pos();
}

int find(int e, std::vector<std::vector<int>> body)
{
    int i = 0;
    for (; i < (body.size() - 1); i++)
    {
        if (body[i][3] == e)
        {
            break;
        }
    }
    return i;
}

int lenn(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void Snake::set_bodypos()
{
    srand(time(NULL)); // Seed the time
    // printf("big\n");
    int z = 0, b = 0, l = 0;
    while (z < map.size())
    {
        while (map[z][b] != '\0')
        {
            if (map[z][b] == '#')
                l++;
            b++;
        }
        b = 0, z++;
    }
    if (l < 2)
    {
        int x = rand() % ((lenn(map[0].c_str()) - 2) - (0) + 1) - 1, y = rand() % (37 - (1) + 1) - 1, v = 0, g = 0;
        if (map[y][x] != 'X' && map[y][x] != 'O' && map[y][x] != 'o')
        {
            map[y][x] = '#';
        }
    }
    int i = 1;
    int j = 1;
    /* std::vector<int> d;
     int f = body[body.size()][0] + direction[1];
     d.push_back(f + direction[0]);
     d.push_back(body[body.size()][1]);
     body.push_back(d);
     /*map[d[0]][d[1]] = 'o';*/
    map[last_headpos[0]][last_headpos[1]] = map[body[0][0]][body[0][1]];

    for (; i < (body.size() - 1); i++)
    {
        map[body[i][0]][body[i][1]] = map[body[i - 1][0]][body[i - 1][1]];
    }
    map[body[i][0]][body[i][1]] = ' ';
}

void Snake::set_eat()
{
    // printf("food\n");
    srand(time(NULL)); // Seed the time
    // printf("big\n");
    int z = 0, b = 0, l = 0;
    while (z < map.size())
    {
        while (map[z][b] != '\0')
        {
            if (map[z][b] == '#')
                l++;
            b++;
        }
        b = 0, z++;
    }
    if (l < 2)
    {
        int x = rand() % ((lenn(map[0].c_str()) - 2) - (0) + 1) - 1;
        int y = rand() % (37 - (1) + 1) - 1;
        int v = 0, g = 0;
        if (map[y][x] != 'X' && map[y][x] != 'O' && map[y][x] != 'o')
        {
            map[y][x] = '#';
        }
    }
    int i = 1;
    int j = 1;
    std::vector<int> d;
    int f = body[body.size() - 1][0] + direction[1];
    int n = body[body.size() - 1][0] + direction[0];
    d.push_back(f);
    d.push_back(n);
    body.push_back(d);
    map[d[0]][d[1]] = 'o';
    map[last_headpos[0]][last_headpos[1]] = map[body[0][0]][body[0][1]];
    for (; i < (body.size() - 1); i++)
    {
        map[body[i][0]][body[i][1]] = map[body[i - 1][0]][body[i - 1][1]];
    }
    map[body[i][0]][body[i][1]] = ' ';
    // printf("end\n");
}

void Snake::set_dir(int i, int j)
{
    if ((direction[0] == -i) || (direction[1] == -j))
        ;
    else
    {
        direction.clear();
        direction.push_back(i);
        direction.push_back(j);
    }
}

void Snake::set_score()
{
    score += 1;
}

int Snake::get_score() const
{
    return score;
}

void Snake::set_over(bool over)
{
    game_over = over;
}

bool Snake::get_over() const
{
    return game_over;
}

void Snake::game_loop()
{
    // printf("%d %d..\n", direction[0], direction[1]);
    if (map[headpos[0] + direction[1]][headpos[1] + direction[0]] != 'X' && game_over == false)
    {
        usleep(50000);
        map[headpos[0]][headpos[1]] = ' ';
        map[headpos[0] + direction[1]][headpos[1] + direction[0]] = 'O';
        last_headpos = headpos;
        // headpos[0] += direction[1];
        // headpos[1] += direction[0];
        set_headpos();
        //  printf("%d %d\n",headpos[0],headpos[1]);
        /*set_headpos();*/
        set_bodypos();
        bodypos();
        int i = 0;
        /* for (; i < body.size(); i++)
         {
             printf("%d %d\n",body[i][0],body[i][1]);
         }*/
        // set_bodypos();²
        // printf("%d\n",body[0][0]);//set_bodypos();
    }
    if (map[headpos[0] + direction[1]][headpos[1] + direction[0]] == '#' && game_over == false)
    {
        usleep(5000);
        map[headpos[0]][headpos[1]] = ' ';
        map[headpos[0] + direction[1]][headpos[1] + direction[0]] = 'O';
        last_headpos = headpos;
        // headpos[0] += direction[1];
        // headpos[1] += direction[0];
        set_headpos();
        //  printf("%d %d\n",headpos[0],headpos[1]);
        // set_headpos();
        set_eat();
        bodypos();
        set_score();
        int i = 0;
    }
    if (map[headpos[0] + direction[1]][headpos[1] + direction[0]] == 'X' || map[headpos[0] + direction[1]][headpos[1] + direction[0]] == 'o') {
        game_over = true;
    }   
}

extern "C" IGame *create()
{
    return new Snake();
}

extern "C" void destroy(IGame *p)
{
    delete p;
}