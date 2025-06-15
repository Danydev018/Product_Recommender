#include "../include/productos.h"
#include <iostream>

int main() {
    Catalogo catalogo;
    inicializarCatalogo(catalogo, 10);

    // Agregar productos
    Producto prod1 = {1, "Smart TV 50\"", "Samsung", 500.0, 5, "Electrónica"};
    Producto prod2 = {2, "Celular Gama Media", "Xiaomi", 250.0, 4, "Telefonía"};
    Producto prod3 = {3, "Laptop Ultraliviana", "Dell", 900.0, 5, "Computación"};

    agregarProducto(catalogo, prod1);
    agregarProducto(catalogo, prod2);
    agregarProducto(catalogo, prod3);

    // Listar productos por categoría
    listarPorCategoria(catalogo, "Electrónica");

    // Buscar producto por ID
    Producto* buscado = buscarProductoPorID(catalogo, 2);
    if (buscado) {
        std::cout << "Encontrado: " << buscado->descripcion << " de " << buscado->marca << std::endl;
    }

    liberarCatalogo(catalogo);
    return 0;
}