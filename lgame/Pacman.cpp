/*
** EPITECH PROJECT, 2022
** ezf
** File description:
** zefd
*/

#include "../lib/ILib.hpp"
#include "../lib/IGame.hpp"
#include "../lib/Pacman.hpp"
#include <unistd.h>

void Pacman::set_headpos()
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

Pacman::~Pacman()
{
}

bool Pacman::get_state() const
{
    return state;
}

float Pacman::get_speed() const
{
    return 1.2;
}

std::string Pacman::get_library() const
{
    return (libname);
}

std::string Pacman::get_playname() const
{
    return playname;
}

std::vector<int> Pacman::get_direction() const
{
    return direction;
}

int Pacman::get_life() const
{
    return life;
}

std::vector<int> Pacman::get_winsize() const
{
    return headpos;
}

void Pacman::set_life()
{
}

void Pacman::set_length()
{
}

void Pacman::set_state(bool a)
{
}

void Pacman::set_speed(float a)
{
}

void Pacman::seach_body_pos()
{
    int i = 0;
    int j = 0;
    int z = 0;
    body.clear();
    while (i < map.size())
    {
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'G')
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
    i = 0, j = 0;
    while (i < map.size())
    {
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'V')
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

void Pacman::bodypos()
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

std::vector<int> Pacman::get_head() const
{
    return headpos;
}

std::vector<std::string> Pacman::get_map() const
{
    return map;
}

void Pacman::set_map(std::vector<std::string> str)
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

void Pacman::set_bodypos()
{
    // usleep(50000);
    int j = 0;
    srand(time(NULL)); // Seed the time
    int x = rand() % (4 - (0) + 1) - 0;
    int i = 0;
    if (x % 2 == 0)
    {
        i = rand() % (1 - (-1) + 1) - 1;
        if (i == 0)
            j = rand() % (1 - (-1) + 1) - 1;
        if (map[(body[0][0] + i)][(body[0][1] + j)] == '.')
        {
            char c = map[(body[0][0] + i)][(body[0][1] + j)];
            map[(body[0][0] + i)][(body[0][1] + j)] = 'G';
            map[(body[0][0])][(body[0][1])] = c;
        } /*else {
            set_bodypos();
        }*/
        i = rand() % (1 - (-1) + 1) - 1;
        if (i == 0)
            j = rand() % (1 - (-1) + 1) - 1;
        if (map[(body[1][0] + i)][(body[1][1] + j)] == '.')
        {
            char c = map[(body[1][0] + i)][(body[1][1] + j)];
            map[(body[1][0] + i)][(body[1][1] + j)] = 'V';
            map[(body[1][0])][(body[1][1])] = c;
        } /*else {
            set_bodypos();
        }*/
    }
    else
    {
        j = rand() % (1 - (-1) + 1) - 1;
        if (j == 0)
            i = rand() % (1 - (-1) + 1) - 1;
        if (map[(body[0][0] + i)][(body[0][1] + j)] == '.')
        {
            char c = map[(body[0][0] + i)][(body[0][1] + j)];
            map[(body[0][0] + i)][(body[0][1] + j)] = 'G';
            map[(body[0][0])][(body[0][1])] = c;
        } /*else {
            set_bodypos();
        }*/
        j = rand() % (1 - (-1) + 1) - 1;
        if (j == 0)
            i = rand() % (1 - (-1) + 1) - 1;
        if (map[(body[1][0] + i)][(body[1][1] + j)] == '.')
        {
            char c = map[(body[1][0] + i)][(body[1][1] + j)];
            map[(body[1][0] + i)][(body[1][1] + j)] = 'V';
            map[(body[1][0])][(body[1][1])] = c;
        }
    }
}

void Pacman::set_eat()
{
    // printf("big\n");
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

void Pacman::set_dir(int i, int j)
{
    direction.clear();
    direction.push_back(i);
    direction.push_back(j);
}

void Pacman::set_score()
{
    score += 1;
}

int Pacman::get_score() const
{
    return score;
}

void Pacman::set_over(bool over)
{
    game_over = over;
}

bool Pacman::get_over() const
{
    return game_over;
}

void Pacman::game_loop()
{
    // printf("%d %d..\n", direction[0], direction[1]);
    if ((map[headpos[0] + direction[1]][headpos[1] + direction[0]] == ' '))
    {
        usleep(50000);
        map[headpos[0]][headpos[1]] = ' ';
        map[headpos[0] + direction[1]][headpos[1] + direction[0]] = 'O';
        // last_headpos = headpos;
        //  headpos[0] += direction[1];
        //  headpos[1] += direction[0];
        set_headpos();
        //  printf("%d %d\n",headpos[0],headpos[1]);
        /*set_headpos();*/
        /*   set_bodypos();
           bodypos();
           int i = 0;*/
        /* for (; i < body.size(); i++)
         {
             printf("%d %d\n",body[i][0],body[i][1]);
         }*/
        // set_bodypos();
        // printf("%d\n",body[0][0]);//set_bodypos();
        set_bodypos();
        seach_body_pos();
    }
    if ((map[headpos[0] + direction[1]][headpos[1] + direction[0]] == '.'))
    {
        usleep(50000);
        map[headpos[0]][headpos[1]] = ' ';
        map[headpos[0] + direction[1]][headpos[1] + direction[0]] = 'O';
        // last_headpos = headpos;
        //  headpos[0] += direction[1];
        //  headpos[1] += direction[0];
        set_headpos();
        set_score();
        //  printf("%d %d\n",headpos[0],headpos[1]);
        /*set_headpos();*/
        /*   set_bodypos();
           bodypos();
           int i = 0;*/
        /* for (; i < body.size(); i++)
         {
             printf("%d %d\n",body[i][0],body[i][1]);
         }*/
        // set_bodypos();
        // printf("%d\n",body[0][0]);//set_bodypos();
        set_bodypos();
        seach_body_pos();
    }
    
    /* if (map[headpos[0] + direction[1]][headpos[1] + direction[0]] == '#')
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
         int i = 0;
     }*/
}

extern "C" IGame *create()
{
    return new Pacman();
}

extern "C" void destroy(IGame *p)
{
    delete p;
}