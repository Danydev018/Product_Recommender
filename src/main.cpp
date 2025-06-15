#include <iostream>
#include "productos.h"
#include "usuarios.h"
#include "../data/config/seed_productos.h"
#include "../data/config/seed_usuarios.h"
#include "../data/config/seed_historial_preferencias.h"
#include "interfaz.h" // Tu header para las funciones del menú

int main() {

    // Mensaje de bienvenida
    std::cout << "=== Bienvenido al sistema de gestión de productos ===\n";
    std::cout << "Catálogo y usuarios cargados desde datos iniciales.\n";
    // Inicializar Catalogo y Cargar datasets (seeds) antes de mostrar el menú
    inicializarCatalogo(catalogo, 55);

    cargarSeedProductos(catalogo);
    cargarSeedUsuarios(usuarios);
    cargarSeedHistorialYPreferencias(usuarios);
    // Ejecutar menú principal
    mostrarMenuPrincipal(catalogo, usuarios, usuarioLogueado);

    // Liberar memoria antes de salir
    liberarCatalogo(catalogo);
    liberarArbol(usuarios);

    std::cout << "Memoria liberada. ¡Hasta luego!\n";
    return 0;
}