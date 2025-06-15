#include "../include/interfaz.h"
#include "../include/usuarios.h"
#include "../include/recomendaciones.h"

#include <iostream>
#include <string>
#include <cstdlib>

// Variables externas de interfaz.h definidas aqui
Catalogo catalogo;
NodoArbol* usuarios = nullptr;
PerfilUsuario* usuarioLogueado = nullptr;

void mostrarMenuPrincipal(Catalogo& catalogo, NodoArbol*& usuarios, PerfilUsuario*& usuarioLogueado) {
    int opcion;

    do {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Crear usuario\n";
        std::cout << "2. Iniciar sesión\n";
        std::cout << "3. Agregar producto\n";
        std::cout << "4. Buscar productos\n";
        std::cout << "5. Ver recomendaciones\n";
        std::cout << "6. Mostrar todos los usuarios\n";
        std::cout << "7. Mostrar catálogo de productos\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch(opcion) {
            case 1: menuCrearUsuario(); break;
            case 2: menuIniciarSesion(); break;
            case 3: menuAgregarProducto(); break;
            case 4: menuBuscarProductos(); break;
            case 5: menuVerRecomendaciones(); break;
            case 6: menuMostrarUsuarios(); break;
            case 7: menuMostrarCatalogo(); break;
            case 8: 
                liberarCatalogo(catalogo);
                liberarArbol(usuarios);
                std::cout << "Memoria liberada. Saliendo...\n"; 
                break;
            default:
                std::cout << "Opcion invalida.\n";
                std::cin.get();
                #ifdef _WIN32
                    std::system("cls"); // Para Windows
                #else
                    std::system("clear"); // Para sistemas tipo Unix
                #endif
                std::cout<<"\npulse enter para continuar...\n";
        }
    } while (opcion != 8);

}

// Crear usuario
void menuCrearUsuario() {
    PerfilUsuario* nuevo = new PerfilUsuario;
    std::cout << "Nombre: "; std::getline(std::cin, nuevo->nombre);
    std::cout << "Apellido: "; std::getline(std::cin, nuevo->apellido);
    std::cout << "ID: "; std::cin >> nuevo->id; std::cin.ignore();
    std::cout << "Usuario: "; std::getline(std::cin, nuevo->usuario);
    std::cout << "Contraseña: "; std::getline(std::cin, nuevo->contrasena);
    nuevo->preferencias = nullptr;
    nuevo->historial = nullptr;

    // VALIDACIÓN
    if (existeIdONombreUsuario(usuarios, nuevo->id, nuevo->usuario)) {
        std::cout << "ERROR: Ya existe un usuario con ese ID o username. Intente con otros datos.\n";
        delete nuevo;
        return;
    }
    usuarios = insertarUsuario(usuarios, nuevo);
    std::cout << "Usuario creado!\n";
    std::cout<<"\npulse enter para continuar...\n";
    std::cin.get();
    #ifdef _WIN32
        std::system("cls"); // Para Windows
    #else
        std::system("clear"); // Para sistemas tipo Unix
    #endif
}

// Iniciar sesión
void menuIniciarSesion() {
    std::string user, pass;
    std::cout << "Usuario: "; std::getline(std::cin, user);
    std::cout << "Contraseña: "; std::getline(std::cin, pass);
    // Busca recursivamente en el árbol
    PerfilUsuario* encontrado = buscarUsuarioPorUsername(usuarios, user);
    if (encontrado && encontrado->contrasena == pass) {
        usuarioLogueado = encontrado;
        std::cout << "Bienvenido/a, " << usuarioLogueado->nombre << "!\n";
    } else {
        std::cout << "Usuario o contraseña incorrectos.\n";
        std::cout<<"\npulse enter para continuar...\n";
        std::cin.get();
        #ifdef _WIN32
            std::system("cls"); // Para Windows
        #else
            std::system("clear"); // Para sistemas tipo Unix
        #endif
    }
}

// Agregar producto
void menuAgregarProducto() {
    Producto p;
    std::cout << "ID: "; std::cin >> p.id; std::cin.ignore();
    std::cout << "Descripcion: "; std::getline(std::cin, p.descripcion);
    std::cout << "Marca: "; std::getline(std::cin, p.marca);
    std::cout << "Precio: "; std::cin >> p.precio; std::cin.ignore();
    std::cout << "Calidad (1-5): "; std::cin >> p.calidad; std::cin.ignore();
    std::cout << "Categoria: "; std::getline(std::cin, p.categoria);
    agregarProducto(catalogo, p);
    std::cout << "Producto agregado!\n";
    std::cout<<"\npulse enter para continuar...\n";
    std::cin.get();
    #ifdef _WIN32
        std::system("cls"); // Para Windows
    #else
        std::system("clear"); // Para sistemas tipo Unix
    #endif
}

// Buscar productos
void menuBuscarProductos() {
    int op;
    std::cout << "Buscar por:\n1. Categoria\n2. Precio\n3. Marca\n4. Palabra clave\nOpcion: ";
    std::cin >> op; std::cin.ignore();
    if (op == 1) {
        std::string cat;
        std::cout << "Categoria: "; std::getline(std::cin, cat);
        listarPorCategoria(catalogo, cat);
    } else if (op == 2) {
        float min, max;
        std::cout << "Precio minimo: "; std::cin >> min;
        std::cout << "Precio maximo: "; std::cin >> max; std::cin.ignore();
        listarPorRangoPrecios(catalogo, min, max);
    } else if (op == 3) {
        std::string marca;
        std::cout << "Marca: "; std::getline(std::cin, marca);
        listarPorMarca(catalogo, marca);
    } else if (op == 4) {
        std::string clave;
        std::cout << "Palabra clave: "; std::getline(std::cin, clave);
        listarPorDescripcion(catalogo, clave);
    }
}

// Ver recomendaciones
void menuVerRecomendaciones() {
    if (!usuarioLogueado) {
        std::cout << "Primero inicie sesión.\n";
        return;
    }
    Recomendacion* recs = generarRecomendaciones(usuarioLogueado, catalogo, 5);
    std::cout << "Recomendaciones para " << usuarioLogueado->usuario << ":\n";
    for (Recomendacion* r = recs; r; r = r->siguiente) {
        std::cout << "- " << r->producto->descripcion << " (Marca: " << r->producto->marca << ")\n";
    }
    liberarRecomendaciones(recs);
}

// Mostrar usuarios
void mostrarUsuariosRec(NodoArbol* nodo) {
    if (!nodo) return;
    mostrarUsuariosRec(nodo->izquierda);
    std::cout << "ID: " << nodo->perfil->id << " - " << nodo->perfil->usuario << "\n";
    mostrarUsuariosRec(nodo->derecha);
}
void menuMostrarUsuarios() {
    std::cout << "Usuarios registrados:\n";
    mostrarUsuariosRec(usuarios);
    std::cout<<"\npulse enter para continuar...\n";
    std::cin.get();
    #ifdef _WIN32
        std::system("cls"); // Para Windows
    #else
        std::system("clear"); // Para sistemas tipo Unix
    #endif
}

// Mostrar catálogo
void menuMostrarCatalogo() {
    std::cout << "Catalogo de productos:\n";
    for (int i = 0; i < catalogo.cantidad; ++i) {
        std::cout << "- " << catalogo.productos[i].descripcion << " ($" << catalogo.productos[i].precio << ")\n";
    }
    std::cout<<"\npulse enter para continuar...\n";
    std::cin.get();
}