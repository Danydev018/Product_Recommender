#include "../include/usuarios.h"
#include "./config/seed_usuarios.h"
#include <string>

// NOTA: El árbol se arma con IDs únicos y usernames únicos, para evitar duplicados (¡ya lo validas!)
// Contraseñas son simples para pruebas.

void cargarSeedUsuarios(NodoArbol*& raiz) {
    PerfilUsuario* u1 = new PerfilUsuario{"Juan", "Pérez", 1, "juanp", "1234", nullptr, nullptr};
    PerfilUsuario* u2 = new PerfilUsuario{"Ana", "Gómez", 2, "anag", "abcd", nullptr, nullptr};
    PerfilUsuario* u3 = new PerfilUsuario{"Luis", "Martínez", 3, "luism", "pass", nullptr, nullptr};
    PerfilUsuario* u4 = new PerfilUsuario{"María", "Fernández", 4, "maryf", "qwerty", nullptr, nullptr};
    PerfilUsuario* u5 = new PerfilUsuario{"Sofía", "Ramírez", 5, "sofiar", "zxcv", nullptr, nullptr};
    PerfilUsuario* u6 = new PerfilUsuario{"Carlos", "Sánchez", 6, "carloss", "asdf", nullptr, nullptr};
    PerfilUsuario* u7 = new PerfilUsuario{"Valentina", "López", 7, "valel", "9876", nullptr, nullptr};
    PerfilUsuario* u8 = new PerfilUsuario{"Martín", "Díaz", 8, "martind", "mypass", nullptr, nullptr};
    PerfilUsuario* u9 = new PerfilUsuario{"Lucía", "Moreno", 9, "luciam", "123abc", nullptr, nullptr};
    PerfilUsuario* u10 = new PerfilUsuario{"Pablo", "Torres", 10, "pablot", "torres", nullptr, nullptr};

    raiz = nullptr;
    raiz = insertarUsuario(raiz, u1);
    raiz = insertarUsuario(raiz, u2);
    raiz = insertarUsuario(raiz, u3);
    raiz = insertarUsuario(raiz, u4);
    raiz = insertarUsuario(raiz, u5);
    raiz = insertarUsuario(raiz, u6);
    raiz = insertarUsuario(raiz, u7);
    raiz = insertarUsuario(raiz, u8);
    raiz = insertarUsuario(raiz, u9);
    raiz = insertarUsuario(raiz, u10);
}