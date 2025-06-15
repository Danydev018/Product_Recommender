#include "../include/productos.h"
#include <iostream>

int main() {
    Catalogo catalogo;
    inicializarCatalogo(catalogo, 5);

    // Agregar productos al catálogo
    agregarProducto(catalogo, {1, "Smart TV 50 pulgadas 4K", "Samsung", 499.99, 5, "Electrónica"});
    agregarProducto(catalogo, {2, "Celular gama media", "Xiaomi", 249.99, 4, "Telefonía"});
    agregarProducto(catalogo, {3, "Laptop ultraliviana", "Dell", 899.99, 5, "Computación"});
    agregarProducto(catalogo, {4, "Auriculares Bluetooth", "Sony", 79.99, 4, "Accesorios"});
    agregarProducto(catalogo, {5, "Smartwatch deportivo", "Xiaomi", 129.99, 3, "Accesorios"});

    // Buscar productos por categoría
    std::cout << "\n=== Buscar por Categoría ===\n";
    listarPorCategoria(catalogo, "Accesorios");

    // Buscar productos por rango de precios
    std::cout << "\n=== Buscar por Rango de Precios ===\n";
    listarPorRangoPrecios(catalogo, 100, 500);

    // Buscar productos por marca
    std::cout << "\n=== Buscar por Marca ===\n";
    listarPorMarca(catalogo, "Xiaomi");

    // Buscar productos por palabra clave en la descripción
    std::cout << "\n=== Buscar por Descripción ===\n";
    listarPorDescripcion(catalogo, "ultrali");

    // Liberar la memoria del catálogo
    liberarCatalogo(catalogo);
    return 0;
}