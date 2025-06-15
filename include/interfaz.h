#include <iostream>
#include <string>
#include "./productos.h"
#include "./usuarios.h"
#include "./recomendaciones.h"

#ifndef INTERFAZ_H
#define INTERFAZ_H

// Variables externas
extern Catalogo catalogo;
extern NodoArbol* usuarios;
extern PerfilUsuario* usuarioLogueado;

// Funciones auxiliares para el menú
void mostrarMenuPrincipal(Catalogo& catalogo, NodoArbol*& usuarios, PerfilUsuario*& usuarioLogueado);
void menuCrearUsuario();
void menuIniciarSesion();
void menuAgregarProducto();
void menuBuscarProductos();
void menuVerRecomendaciones();
void menuMostrarUsuarios();
void menuMostrarCatalogo();

#endif