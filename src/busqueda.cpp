#include "../include/productos.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>


// Buscar producto por ID
Producto* buscarProductoPorID(const Catalogo& catalogo, int id) {
    for (int i = 0; i < catalogo.cantidad; ++i) {
        if (catalogo.productos[i].id == id) {
            return &catalogo.productos[i];
        }
    }
    return nullptr;
}

// Función auxiliar para búsqueda insensible a mayúsculas/minúsculas
bool contienePalabra(const std::string& texto, const std::string& palabra) {
    auto it = std::search(
        texto.begin(), texto.end(),
        palabra.begin(), palabra.end(),
        [](char ch1, char ch2) { return std::tolower(static_cast<unsigned char>(ch1)) == std::tolower(static_cast<unsigned char>(ch2)); }
    );
    return (it != texto.end());
}


