/*
** EPITECH PROJECT, 2022
** er
** File description:
** ezf
*/

#include "IGame.hpp"
#include "ILib.hpp"

class Pacman : public IGame {
private:
    std::vector<std::vector<int>> body;
    std::string libname;
    std::string playname;
    bool state = true;
    std::vector<int> headpos;
    std::vector<int> last_headpos;
    float speed;
    std::vector<int> winsize;
    std::vector<std::string> map;
    std::vector<int> direction;
    int life;
    int score = 0;
    bool game_over = false;
public:
    Pacman() {
         direction.push_back(-1);
         direction.push_back(0);
    }
    ~Pacman();
    bool get_state() const;
    float get_speed() const;
    std::string get_library() const;
    std::string get_playname() const;
    void set_length();
    std::vector<int> get_head() const;
    int get_life() const;
    std::vector<int> get_winsize() const;
    void set_life();
    std::vector<int> get_direction() const;
    void set_headpos();
    void set_state(bool a);
    void set_speed(float a);
    void game_loop();
    void seach_body_pos();
    void set_bodypos();
    std::vector<std::string> get_map() const;
    void set_map(std::vector<std::string> str);
    void set_dir(int i, int j); 
    void bodypos();
    void set_eat();
    void set_score();
    int get_score() const;
    void set_over(bool over);
    bool get_over() const;
};