#include "../include/usuarios.h"

#include <iostream>
#include <string>


// Función para crear un nuevo perfil de usuario
PerfilUsuario* crearPerfilUsuario(int id, const std::string& nombre, const std::string& apellido, 
                                  const std::string& usuario, const std::string& contrasena) {
    PerfilUsuario* nuevoPerfil = new PerfilUsuario();
    nuevoPerfil->id = id;
    nuevoPerfil->nombre = nombre;
    nuevoPerfil->apellido = apellido;
    nuevoPerfil->usuario = usuario;
    nuevoPerfil->contrasena = contrasena;
    nuevoPerfil->preferencias = nullptr; // Inicialmente sin preferencias
    nuevoPerfil->historial = nullptr;    // Inicialmente sin historial
    return nuevoPerfil;
}

bool existeIdONombreUsuario(NodoArbol* raiz, int id, const std::string& username) {
    if (!raiz) return false;
    if (raiz->perfil->id == id || raiz->perfil->usuario == username)
        return true;
    // Busca en ambos subárboles porque puede estar en cualquier lado
    return existeIdONombreUsuario(raiz->izquierda, id, username)
        || existeIdONombreUsuario(raiz->derecha, id, username);
}

// Función para insertar un perfil en el árbol binario de búsqueda
NodoArbol* insertarUsuario(NodoArbol* raiz, PerfilUsuario* nuevoPerfil) {
    if (raiz == nullptr) {
        NodoArbol* nodo = new NodoArbol();
        nodo->perfil = nuevoPerfil;
        nodo->izquierda = nullptr;
        nodo->derecha = nullptr;
        return nodo;
    }

    if (nuevoPerfil->id < raiz->perfil->id) {
        raiz->izquierda = insertarUsuario(raiz->izquierda, nuevoPerfil);
    } else {
        raiz->derecha = insertarUsuario(raiz->derecha, nuevoPerfil);
    }

    return raiz;
}

// Función para buscar un perfil por ID
PerfilUsuario* buscarUsuario(NodoArbol* raiz, int id) {
    if (raiz == nullptr || raiz->perfil->id == id) {
        return raiz == nullptr ? nullptr : raiz->perfil;
    }

    if (id < raiz->perfil->id) {
        return buscarUsuario(raiz->izquierda, id);
    } else {
        return buscarUsuario(raiz->derecha, id);
    }
}

PerfilUsuario* buscarUsuarioPorUsername(NodoArbol* raiz, const std::string& username) {
    if (!raiz) return nullptr;
    if (raiz->perfil->usuario == username) {
        return raiz->perfil;
    }
    // Buscar en ambos subárboles porque el árbol está ordenado por ID, no por username
    PerfilUsuario* found = buscarUsuarioPorUsername(raiz->izquierda, username);
    if (found) return found;
    return buscarUsuarioPorUsername(raiz->derecha, username);
}

// Función para liberar memoria del árbol binario
void liberarArbol(NodoArbol* raiz) {
    if (!raiz) return;
    liberarArbol(raiz->izquierda);
    liberarArbol(raiz->derecha);

    // Libera listas de historial y preferencias de cada perfil
    HistorialInteracciones* h = raiz->perfil->historial;
    while (h) {
        HistorialInteracciones* temp = h;
        h = h->siguiente;
        delete temp;
    }
    Preferencias* p = raiz->perfil->preferencias;
    while (p) {
        Preferencias* temp = p;
        p = p->siguiente;
        delete temp;
    }

    delete raiz->perfil; // Si la creaste con new
    delete raiz;
}

// Función para mostrar los perfiles en el árbol (ordenado por ID)
void mostrarUsuarios(NodoArbol* raiz) {
    if (raiz != nullptr) {
        mostrarUsuarios(raiz->izquierda);
        std::cout << "ID: " << raiz->perfil->id << ", Usuario: " << raiz->perfil->usuario << std::endl;
        mostrarUsuarios(raiz->derecha);
    }
}

