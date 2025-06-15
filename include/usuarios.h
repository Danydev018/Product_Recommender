#include <string>

#ifndef USUARIOS_H
#define USUARIOS_H

// Estructura para las preferencias del usuario (lista enlazada simple)
struct Preferencias {
    std::string categoria;
    std::string marca;
    Preferencias* siguiente; // Puntero al siguiente elemento
};

// Estructura para el historial de interacciones (lista enlazada simple)
struct HistorialInteracciones {
    int productoID; // ID del producto
    HistorialInteracciones* siguiente; // Puntero al siguiente elemento
};

// Estructura para almacenar el perfil de usuario
struct PerfilUsuario {
    std::string nombre;
    std::string apellido;
    int id; // Identificador único
    std::string usuario; // Nombre de usuario para inicio de sesión
    std::string contrasena;
    Preferencias* preferencias; // Lista enlazada de categorías y marcas preferidas
    HistorialInteracciones* historial; // Lista enlazada de productos interactuados
};

// Nodo para el árbol binario de búsqueda
struct NodoArbol {
    PerfilUsuario* perfil;
    NodoArbol* izquierda; // Subárbol izquierdo
    NodoArbol* derecha;   // Subárbol derecho
};

PerfilUsuario* crearPerfilUsuario(int id, const std::string& nombre, const std::string& apellido, const std::string& usuario, const std::string& contrasena);
NodoArbol* insertarUsuario(NodoArbol* raiz, PerfilUsuario* nuevoPerfil);
PerfilUsuario* buscarUsuario(NodoArbol* raiz, int id);
void liberarArbol(NodoArbol* raiz);
void mostrarUsuarios(NodoArbol* raiz);
PerfilUsuario* buscarUsuarioPorUsername(NodoArbol* raiz, const std::string& username);
bool existeIdONombreUsuario(NodoArbol* raiz, int id, const std::string& username);

#endif