#include "../include/productos.h"
#include "../include/usuarios.h"
#include "../include/recomendaciones.h"
#include <iostream>

int main() {
    // 1. Crear catálogo y agregar productos
    Catalogo catalogo;
    inicializarCatalogo(catalogo, 5);
    agregarProducto(catalogo, {1, "Smart TV", "Samsung", 500, 5, "Electrónica"});
    agregarProducto(catalogo, {2, "Celular", "Xiaomi", 200, 4, "Telefonía"});
    agregarProducto(catalogo, {3, "Notebook", "Dell", 800, 5, "Computación"});
    agregarProducto(catalogo, {4, "Auriculares", "Sony", 80, 4, "Accesorios"});
    agregarProducto(catalogo, {5, "Smartwatch", "Xiaomi", 120, 3, "Accesorios"});

    // 2. Crear usuario y agregar preferencias y/o historial
    PerfilUsuario* usuario = new PerfilUsuario;
    usuario->id = 1;
    usuario->nombre = "Juan";
    usuario->apellido = "Pérez";
    usuario->usuario = "juanp";
    usuario->contrasena = "1234";
    usuario->preferencias = nullptr;
    usuario->historial = nullptr;

    // Preferencia de marca "Xiaomi"
    Preferencias* pref = new Preferencias;
    pref->categoria = "";
    pref->marca = "Xiaomi";
    pref->siguiente = nullptr;
    usuario->preferencias = pref;

    // Historial: ha visto el producto 1 (Smart TV)
    HistorialInteracciones* hist = new HistorialInteracciones;
    hist->productoID = 1;
    hist->siguiente = nullptr;
    usuario->historial = hist;

    // 3. Generar y mostrar recomendaciones
    Recomendacion* recs = generarRecomendaciones(usuario, catalogo, 5);
    std::cout << "Recomendaciones para " << usuario->usuario << ":\n";
    for (Recomendacion* r = recs; r; r = r->siguiente) {
        std::cout << "- " << r->producto->descripcion << " (Marca: " << r->producto->marca << ")\n";
    }
    liberarRecomendaciones(recs);

    // 4. Liberar memoria
    delete pref;
    delete hist;
    delete usuario;
    liberarCatalogo(catalogo);

    return 0;
}