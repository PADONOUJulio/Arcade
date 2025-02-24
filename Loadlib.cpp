/*
** EPITECH PROJECT, 2022
** edz
** File description:
** dz
*/

#include <dlfcn.h>
#include <iostream>
#include "ILib.hpp"
#include "Ncurses.hpp"
#include "SDL2.hpp"

void *libopen(std::string path)
{
    void *handle;
    ILib* (*create)();
    //void (*destroy)(ILib*);
    //printf("%s",path.c_str()),
    std::string d = "./";
    d += path;
    handle = dlopen(d.c_str(),RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        exit(EXIT_FAILURE);
    }
    return (handle);
}
 
ILib *Libload(void *handle) 
{
    ILib* (*create)();
    create = (ILib* (*)())dlsym(handle, "create");
    //destroy = (void (*)(ILib*))dlsym(handle, "destroy");
    if (create == NULL) {
        std::cerr << "dlsym : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }
    ILib* classe = (ILib*)create();
    return (classe);
    //classe->gameloop();
    //destroy(classe);
}

void libclose(void *handle, ILib *classe)
{
    void (*destroy)(ILib*);
    destroy = (void (*)(ILib*))dlsym(handle, "destroy");
}

/*int main(int ac, char **av)
{
    void *handle = libopen(av[1]);
    ILib *classe = Libload(handle);
    classe->gameloop();
    libclose(handle, classe);
}*/