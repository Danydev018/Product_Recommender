#include "../include/usuarios.h"
#include <iostream>
#include <string>


int main() {
    // Ejemplo de uso
    NodoArbol* raiz = nullptr;

    // Crear perfiles de usuario
    PerfilUsuario* perfil1 = crearPerfilUsuario(1, "Juan", "Perez", "juanp", "1234");
    PerfilUsuario* perfil2 = crearPerfilUsuario(2, "Maria", "Lopez", "marial", "abcd");
    PerfilUsuario* perfil3 = crearPerfilUsuario(3, "Carlos", "Sanchez", "carloss", "5678");

    // Insertar perfiles en el árbol
    raiz = insertarUsuario(raiz, perfil1);
    raiz = insertarUsuario(raiz, perfil2);
    raiz = insertarUsuario(raiz, perfil3);

    // Mostrar perfiles
    std::cout << "Perfiles en el sistema:" << std::endl;
    mostrarUsuarios(raiz);

    // Buscar un usuario
    int idBuscado = 2;
    PerfilUsuario* encontrado = buscarUsuario(raiz, idBuscado);
    if (encontrado) {
        std::cout << "Usuario encontrado: " << encontrado->usuario << std::endl;
    } else {
        std::cout << "Usuario con ID " << idBuscado << " no encontrado." << std::endl;
    }

    // Liberar memoria
    liberarArbol(raiz);

    return 0;
}