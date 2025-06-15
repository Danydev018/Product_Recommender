#include "../include/productos.h"

#include <iostream>
#include <algorithm>
#include <cctype>

// Inicializar el catálogo
void inicializarCatalogo(Catalogo& catalogo, int capacidadInicial) {
    catalogo.productos = new Producto[capacidadInicial];
    catalogo.cantidad = 0;
    catalogo.capacidad = capacidadInicial;
}

// Agregar un producto
void agregarProducto(Catalogo& catalogo, const Producto& producto) {
    if (catalogo.cantidad == catalogo.capacidad) {
        redimensionarCatalogo(catalogo);
    }
    catalogo.productos[catalogo.cantidad] = producto;
    catalogo.cantidad++;
}

// Redimensionar catálogo dinámicamente
void redimensionarCatalogo(Catalogo& catalogo) {
    int nuevaCapacidad = catalogo.capacidad * 2;
    Producto* nuevosProductos = new Producto[nuevaCapacidad];
    for (int i = 0; i < catalogo.cantidad; ++i) {
        nuevosProductos[i] = catalogo.productos[i];
    }
    delete[] catalogo.productos;
    catalogo.productos = nuevosProductos;
    catalogo.capacidad = nuevaCapacidad;
}

// Listar productos por categoría
void listarPorCategoria(const Catalogo& catalogo, const std::string& categoria) {
    std::cout << "Productos en la categoría: " << categoria << std::endl;
    for (int i = 0; i < catalogo.cantidad; ++i) {
        if (catalogo.productos[i].categoria == categoria) {
            std::cout << "- " << catalogo.productos[i].descripcion
                      << " (Marca: " << catalogo.productos[i].marca
                      << ", Precio: $" << catalogo.productos[i].precio << ")\n";
        }
    }
}

// Listar productos por rango de precios
void listarPorRangoPrecios(const Catalogo& catalogo, float minPrecio, float maxPrecio) {
    std::cout << "Productos en el rango de precios: $" << minPrecio << " - $" << maxPrecio << std::endl;
    for (int i = 0; i < catalogo.cantidad; ++i) {
        if (catalogo.productos[i].precio >= minPrecio && catalogo.productos[i].precio <= maxPrecio) {
            std::cout << "- " << catalogo.productos[i].descripcion
                      << " (Marca: " << catalogo.productos[i].marca
                      << ", Precio: $" << catalogo.productos[i].precio << ")\n";
        }
    }
}

// Listar productos por marca
void listarPorMarca(const Catalogo& catalogo, const std::string& marca) {
    std::cout << "Productos de la marca: " << marca << std::endl;
    for (int i = 0; i < catalogo.cantidad; ++i) {
        if (catalogo.productos[i].marca == marca) {
            std::cout << "- " << catalogo.productos[i].descripcion
                      << " (Categoría: " << catalogo.productos[i].categoria
                      << ", Precio: $" << catalogo.productos[i].precio << ")\n";
        }
    }
}


// Listar productos por palabra clave en descripción
void listarPorDescripcion(const Catalogo& catalogo, const std::string& palabraClave) {
    std::cout << "Productos que contienen \"" << palabraClave << "\" en la descripción:" << std::endl;
    for (int i = 0; i < catalogo.cantidad; ++i) {
        if (contienePalabra(catalogo.productos[i].descripcion, palabraClave)) {
            std::cout << "- " << catalogo.productos[i].descripcion
                      << " (Marca: " << catalogo.productos[i].marca
                      << ", Precio: $" << catalogo.productos[i].precio << ")\n";
        }
    }
}

// Liberar la memoria del catálogo
void liberarCatalogo(Catalogo& catalogo) {
    if (catalogo.productos) {
        delete[] catalogo.productos;
        catalogo.productos = nullptr;
        catalogo.cantidad = 0;
        catalogo.capacidad = 0;
    }
}