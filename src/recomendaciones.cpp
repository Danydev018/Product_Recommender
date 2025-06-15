#include "../include/recomendaciones.h"
#include <cmath>

// Función auxiliar: verificar si una marca es preferida
bool esMarcaPreferida(const PerfilUsuario* usuario, const std::string& marca) {
    Preferencias* pref = usuario->preferencias;
    while (pref) {
        if (pref->marca == marca)
            return true;
        pref = pref->siguiente;
    }
    return false;
}

// Función auxiliar: verifica si un producto está en el historial
bool productoEnHistorial(const PerfilUsuario* usuario, int productoID) {
    HistorialInteracciones* hist = usuario->historial;
    while (hist) {
        if (hist->productoID == productoID)
            return true;
        hist = hist->siguiente;
    }
    return false;
}

// Añadir producto a la lista de recomendaciones
void añadirRecomendacion(Recomendacion*& cabeza, Producto* producto) {
    Recomendacion* nuevo = new Recomendacion{producto, nullptr};
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Recomendacion* tmp = cabeza;
        while (tmp->siguiente) tmp = tmp->siguiente;
        tmp->siguiente = nuevo;
    }
}

// Lógica de recomendaciones
Recomendacion* generarRecomendaciones(const PerfilUsuario* usuario, const Catalogo& catalogo, int cantidadMaxima) {
    Recomendacion* recomendaciones = nullptr;
    int count = 0;

    // 1. Productos de marcas preferidas (prioridad)
    for (int i = 0; i < catalogo.cantidad && count < cantidadMaxima; ++i) {
        if (esMarcaPreferida(usuario, catalogo.productos[i].marca) &&
            !productoEnHistorial(usuario, catalogo.productos[i].id)) {
            añadirRecomendacion(recomendaciones, &catalogo.productos[i]);
            count++;
        }
    }

    // 2. Productos similares al historial (categoría, marca, calidad)
    if (count < cantidadMaxima) {
        HistorialInteracciones* hist = usuario->historial;
        while (hist && count < cantidadMaxima) {
            Producto* visto = buscarProductoPorID(catalogo, hist->productoID);
            if (visto) {
                for (int i = 0; i < catalogo.cantidad && count < cantidadMaxima; ++i) {
                    Producto& candidato = catalogo.productos[i];
                    if (candidato.id == visto->id || productoEnHistorial(usuario, candidato.id))
                        continue;
                    // Misma categoría o marca, o calidad similar (diferencia <=1)
                    bool similar = (candidato.categoria == visto->categoria) ||
                                   (candidato.marca == visto->marca) ||
                                   (std::abs(candidato.calidad - visto->calidad) <= 1);
                    if (similar) {
                        añadirRecomendacion(recomendaciones, &candidato);
                        count++;
                    }
                }
            }
            hist = hist->siguiente;
        }
    }
    return recomendaciones;
}

// Liberar memoria
void liberarRecomendaciones(Recomendacion* cabeza) {
    while (cabeza) {
        Recomendacion* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}