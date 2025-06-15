#pragma once
#include "./usuarios.h"
#include "./productos.h" // Debes separar structs de usuario en un header

#ifndef RECOMENDACIONES_H
#define RECOMENDACIONES_H

struct Recomendacion {
    Producto* producto;
    Recomendacion* siguiente;
};

Recomendacion* generarRecomendaciones(const PerfilUsuario* usuario, const Catalogo& catalogo, int cantidadMaxima);
void liberarRecomendaciones(Recomendacion* cabeza);
bool esMarcaPreferida(const PerfilUsuario* usuario, const std::string& marca);
bool productoEnHistorial(const PerfilUsuario* usuario, int productoID);
void añadirRecomendacion(Recomendacion*& cabeza, Producto* producto);

#endif