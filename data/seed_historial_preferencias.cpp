#include "../include/usuarios.h"
#include "./config/seed_historial_preferencias.h"
#include <string>

// Asigna historial/preferencias a cada usuario según su ID/username.
// Puedes personalizar según tus productos y estructura.

void cargarSeedHistorialYPreferencias(NodoArbol* raiz) {
    // Recorrido in-order para asignar datos (puedes adaptar a tus necesidades)
    if (!raiz) return;
    cargarSeedHistorialYPreferencias(raiz->izquierda);

    PerfilUsuario* u = raiz->perfil;
    // Preferencias (máx 2 por usuario)
    if (u->usuario == "juanp") {
        u->preferencias = new Preferencias{"Electrónica", "Samsung", nullptr};
        u->preferencias->siguiente = new Preferencias{"Telefonía", "Xiaomi", nullptr};
        u->historial = new HistorialInteracciones{1, new HistorialInteracciones{2, nullptr}};
    }
    if (u->usuario == "anag") {
        u->preferencias = new Preferencias{"Computación", "Dell", nullptr};
        u->historial = new HistorialInteracciones{3, new HistorialInteracciones{9, nullptr}};
    }
    if (u->usuario == "luism") {
        u->preferencias = new Preferencias{"Audio", "Sony", nullptr};
        u->historial = new HistorialInteracciones{4, nullptr};
    }
    if (u->usuario == "maryf") {
        u->preferencias = new Preferencias{"Accesorios", "Xiaomi", nullptr};
        u->preferencias->siguiente = new Preferencias{"Electrodomésticos", "Whirlpool", nullptr};
        u->historial = new HistorialInteracciones{5, nullptr};
    }
    if (u->usuario == "sofiar") {
        u->preferencias = new Preferencias{"Hogar", "Philips", nullptr};
        u->historial = new HistorialInteracciones{13, nullptr};
    }
    if (u->usuario == "carloss") {
        u->preferencias = new Preferencias{"Redes", "TP-Link", nullptr};
        u->historial = new HistorialInteracciones{15, nullptr};
    }
    if (u->usuario == "valel") {
        u->preferencias = new Preferencias{"Deportes", "Venzo", nullptr};
        u->historial = new HistorialInteracciones{28, nullptr};
    }
    if (u->usuario == "martind") {
        u->preferencias = new Preferencias{"Fotografía", "GoPro", nullptr};
        u->historial = new HistorialInteracciones{12, nullptr};
    }
    if (u->usuario == "luciam") {
        u->preferencias = new Preferencias{"Telefonía", "Apple", nullptr};
        u->historial = new HistorialInteracciones{44, nullptr};
    }
    if (u->usuario == "pablot") {
        u->preferencias = new Preferencias{"Computación", "Apple", nullptr};
        u->preferencias->siguiente = new Preferencias{"Audio", "JBL", nullptr};
        u->historial = new HistorialInteracciones{48, new HistorialInteracciones{40, nullptr}};
    }

    cargarSeedHistorialYPreferencias(raiz->derecha);
}