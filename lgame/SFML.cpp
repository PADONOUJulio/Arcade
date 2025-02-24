/*
** EPITECH PROJECT, 2022
** eér"e
** File description:
** e"ref
*/

#include "../lib/SFML.hpp"

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

SFML::SFML()
{
}

SFML::~SFML()
{
}

void SFML::create_win()
{
    this->menu = std::make_shared<sf::RenderWindow>(sf::VideoMode(1024, 728), "Arcade", sf::Style::Default);
}

void SFML::init()
{
    this->font.loadFromFile("ress/space.ttf");
    this->font2.loadFromFile("ress/arial.ttf");
    fontu.loadFromFile("ress/arial.ttf");
    this->text.setString("ARCADE");
    this->text1.setString("Name: ");
    this->text2.setString(d.c_str());
    this->text3.setString("Score: ");
    this->snake.setString("-> SNAKE");
    this->pacman.setString("-> PACMAN");
    this->YourName.setString("Name: ");
    this->text.setCharacterSize(50);
    this->text1.setCharacterSize(20);
    this->text2.setCharacterSize(20);
    this->text3.setCharacterSize(20);
    this->text4.setCharacterSize(20);
    this->YourName.setCharacterSize(20);
    this->snake.setCharacterSize(40);
    this->pacman.setCharacterSize(40);
    //text.setCharacterSize(20);
    this->text.setFillColor(sf::Color::Blue);
    this->text1.setFillColor(sf::Color::Red);
    this->text2.setFillColor(sf::Color::Red);
    this->text3.setFillColor(sf::Color::Red);
    this->text4.setFillColor(sf::Color::Red);
    this->pacman.setFillColor(sf::Color::Red);
    this->YourName.setFillColor(sf::Color::Yellow);
    this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->YourName.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->text.setFont(this->font);
    this->text1.setFont(this->fontu);
    this->text2.setFont(this->fontu);
    this->text3.setFont(this->fontu);
    this->text4.setFont(this->fontu);
    this->snake.setFont(this->font);
    this->pacman.setFont(this->font);
    this->YourName.setFont(this->font2);
    this->text.setPosition(sf::Vector2f{350, 70});
    this->text1.setPosition(sf::Vector2f{850, 0});
    this->text2.setPosition(sf::Vector2f{920, 0});
    this->text3.setPosition(sf::Vector2f{850, 50});
    this->text4.setPosition(sf::Vector2f{920, 50});
    this->pacman.setPosition(sf::Vector2f{350, 230});
    this->snake.setPosition(sf::Vector2f{350, 270});
    this->YourName.setPosition(sf::Vector2f{200, 500});
    this->Text.setFont(this->font);
    this->Text.setFillColor(sf::Color::Yellow);
    this->Text.setPosition(sf::Vector2f{299, 492});
}

void SFML::close_win()
{
    if (this->event.type == sf::Event::Closed)
    {
        this->menu->close();
    }
}

void SFML::clear()
{
    this->menu->clear(sf::Color::Black);
}

void SFML::print_menu(std::vector<std::string> buff, int z)
{
    this->menu->draw(this->text);
    this->menu->draw(this->pacman);
    this->menu->draw(this->snake);
    this->menu->draw(this->YourName);
    this->Text.setString(this->d);
    this->menu->draw(this->Text);
}

void *SFML::keymenu(int *i, int *v, std::vector<std::string> *buff, int c, int *tab)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->snake.setFillColor(sf::Color::Red);
        this->pacman.setFillColor(sf::Color::White);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->snake.setFillColor(sf::Color::White);
        this->pacman.setFillColor(sf::Color::Red);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && d.size() >= 1)
    {
        if (snake.getFillColor() == sf::Color::Red)
        {
            game_name = "lib/arcade_nibbler.so";
        }
        else
            game_name = "lib/arcade_pacman.so";
        state = false;
    }
    else if (this->event.type == sf::Event::EventType::KeyPressed)
    {
        if (this->event.key.code >= sf::Keyboard::A && this->event.key.code <= sf::Keyboard::Z)
            this->d += (this->event.key.code + 97);
        if (this->event.key.code == sf::Keyboard::Backspace)
        {
            if (d.size() >= 1)
                this->d.pop_back();
        }

        if (this->event.key.code == sf::Keyboard::Add)
            this->change = true;
    }
    return (0);
}

void SFML::get_menu_inp()
{
}

bool SFML::get_change() const
{
    return (this->change);
}

bool SFML::get_close() const
{
    return (this->close);
}

std::string SFML::get_game_name() const
{
    return game_name;
}

std::string SFML::get_player() const
{
    return player;
}

bool SFML::get_state() const
{
    return state;
}

IGame *SFML::set_game(IGame *g)
{
    game = g;
    return (g);
}

void *SFML::keygame()
{
    if (event.type == sf::Event::Closed)
        return ((void *)(-1));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        game->set_dir(0, 1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        game->set_dir(0, -1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        game->set_dir(-1, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        game->set_dir(1, 0);
    }
    else if (this->event.type == sf::Event::EventType::KeyPressed)
    {
        if (this->event.key.code == sf::Keyboard::Add)
        {
            this->change = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if (game_name == "lib/arcade_nibbler.so")
        {
            game_name = "lib/arcade_pacman.so";
        }
        else
        {
            game_name = "lib/arcade_nibbler.so";
        }
        return ((void *)(-2));
    }
    return ((void *)1);
}

void SFML::set_state(bool a)
{
    state = a;
}

void SFML::print_game(std::vector<std::string> buff)
{
    int i = 0;
    int j = 0;
    int e = 0;
    int v = 0;
    this->menu->draw(this->text1);
    this->menu->draw(this->text2);
    this->menu->draw(this->text3);
    this->text4.setString((std::to_string(game->get_score())).c_str());
    this->menu->draw(this->text4);
    sf::RectangleShape rect;
    while (i < buff.size())
    {
        while (buff[i][j] != '\0')
        {
            if (buff[i][j] == 'X')
            {
                // printf("%s\n",buff[0]);
                sf::Vector2f pos(v, e);
                rect.setPosition(pos);
                rect.setSize(sf::Vector2f(2, 2));
                rect.setFillColor(sf::Color::Red);
                rect.setScale(sf::Vector2f(2, 2));
                menu->draw(rect);
            }
            if (buff[i][j] == 'o')
            {
                sf::Vector2f pos(v, e);
                rect.setPosition(pos);
                rect.setSize(sf::Vector2f(2, 2));
                rect.setFillColor(sf::Color::Blue);
                rect.setScale(sf::Vector2f(2, 2));
                menu->draw(rect);
            }
            if (buff[i][j] == 'O')
            {
                sf::Vector2f pos(v, e);
                rect.setPosition(pos);
                rect.setSize(sf::Vector2f(4, 4));
                rect.setFillColor(sf::Color::Yellow);
                rect.setScale(sf::Vector2f(2, 2));
                menu->draw(rect);
            }
            if (buff[i][j] == 'G' || buff[i][j] == 'V')
            {
                sf::Vector2f pos(v, e);
                rect.setPosition(pos);
                rect.setSize(sf::Vector2f(5, 4));
                rect.setFillColor(sf::Color::White);
                rect.setScale(sf::Vector2f(2, 2));
                menu->draw(rect);
            }
            if (buff[i][j] == '#')
            {
                sf::Vector2f pos(v, e);
                rect.setPosition(pos);
                rect.setSize(sf::Vector2f(2, 2));
                rect.setFillColor(sf::Color::Green);
                rect.setScale(sf::Vector2f(2, 2));
                menu->draw(rect);
            }
            if (buff[i][j] == '.')
            {
                sf::Vector2f pos(v, e);
                rect.setPosition(pos);
                rect.setSize(sf::Vector2f(1, 1));
                rect.setFillColor(sf::Color::Blue);
                rect.setScale(sf::Vector2f(2, 2));
                menu->draw(rect);
            }
            j++;
            v = v + 10;
        }
        j = 0, i++, e += 10, v = 0;
    }
}

void SFML::gameloop()
{
    int *i;
    int *v;
    std::vector<std::string> *buff;
    std::vector<std::string> buf;
    int c;
    int *tab;
    init();
    create_win();
    while (this->menu->isOpen())
    {
        if (state == true)
        {
            clear();
            print_menu(buf, c);
            while (this->menu->pollEvent(event))
            {
                this->close = true;
                close_win();
                // this->close = true;
                keymenu(i, v, buff, c, tab);
            }
            if (this->change == true)
                break;
            this->menu->display();
        }
        else if (state == false)
        {
            // printf("babière\n");
            if (game == NULL)
            {
                close = false;
                break;
            }
            int y = 0;
            // printf("babière1\n");
            clear();
            // menu->clear(sf::Color(200, 0, 0));
            print_game(game->get_map());
            // keygame();
            if (change == true)
                break;
            // printf("babière2\n");
            game->game_loop();
            while (this->menu->pollEvent(event))
            {
                // this->close = true;
                // close_win(buf);
                y = static_cast<int>(reinterpret_cast<std::uintptr_t>(keygame()));

                // this->close = true;
                // keymenu(i, v, buff, c, tab);
            }
            if (y == -2)
            {
                close = true;
                game = NULL;
                break;
            }
            if (y == -1)
            {
                close = true;
                state = true;
                break;
            }
            if (change == true)
                break;
            menu->display();
        }
    }
    menu->close();
    close_win();
}

extern "C" ILib *create()
{
    return new SFML();
}

extern "C" void destroy(ILib *p)
{
    delete p;
}

/*int main()
{
    ILib *ju = new SFML();
    ju->gameloop();
}*/
