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
#pragma once

class IGame
{
public:
    virtual ~IGame() = default;
    virtual std::vector<int> get_head() const = 0;
    virtual std::vector<int> get_winsize() const = 0;
    virtual std::string get_library() const = 0;
    virtual std::string get_playname() const = 0;
    virtual std::vector<int> get_direction() const = 0;
    virtual bool get_state() const = 0;
    virtual int get_life() const = 0;
    virtual float get_speed() const = 0;
    virtual void set_life() = 0;
    virtual void set_length() = 0;
    virtual void set_headpos() = 0;
    virtual void set_state(bool a) = 0;
    virtual void set_speed(float a) = 0;
    virtual std::vector<std::string> get_map() const = 0;
    virtual void set_bodypos() = 0;
    virtual void seach_body_pos() = 0;
    virtual void set_map(std::vector<std::string> str) = 0;
    virtual void game_loop() = 0;
    virtual void set_dir(int i, int j) = 0;
    virtual void bodypos() = 0;
    virtual void set_eat() = 0;
    virtual void set_score() = 0;
    virtual int get_score() const = 0;
    virtual bool get_over() const = 0;
    virtual void set_over(bool over) = 0;
};