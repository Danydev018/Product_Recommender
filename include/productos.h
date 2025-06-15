#include <string>

#ifndef PRODUCTOS_H
#define PRODUCTOS_H

// Estructura para producto
struct Producto {
    int id;
    std::string descripcion;
    std::string marca;
    float precio;
    int calidad; // 1 a 5
    std::string categoria;
};

// Estructura para el catálogo
struct Catalogo {
    Producto* productos;
    int cantidad;
    int capacidad;
};

void inicializarCatalogo(Catalogo& catalogo, int capacidadInicial);
void redimensionarCatalogo(Catalogo& catalogo);
void agregarProducto(Catalogo& catalogo, const Producto& producto);
void listarPorCategoria(const Catalogo& catalogo, const std::string& categoria);
void listarPorRangoPrecios(const Catalogo& catalogo, float minPrecio, float maxPrecio);
void listarPorMarca(const Catalogo& catalogo, const std::string& marca);
void listarPorDescripcion(const Catalogo& catalogo, const std::string& palabraClave);
void liberarCatalogo(Catalogo& catalogo);

//Definicion de funciones implementadas en el archivo busqueda.cpp
bool contienePalabra(const std::string& texto, const std::string& palabra);
Producto* buscarProductoPorID(const Catalogo& catalogo, int id);

#endif