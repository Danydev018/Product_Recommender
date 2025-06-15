#include "../include/productos.h"
#include "./config/seed_productos.h"   
#include <string>

void cargarSeedProductos(Catalogo& catalogo) {
    inicializarCatalogo(catalogo, 50);
    agregarProducto(catalogo, {1,   "Smart TV 50'' 4K",           "Samsung",   499.99, 5, "Electrónica"});
    agregarProducto(catalogo, {2,   "Smartphone Redmi 12",        "Xiaomi",    199.99, 4, "Telefonía"});
    agregarProducto(catalogo, {3,   "Notebook Inspiron 14",       "Dell",      799.99, 5, "Computación"});
    agregarProducto(catalogo, {4,   "Auriculares WH-1000XM4",     "Sony",       89.99, 5, "Audio"});
    agregarProducto(catalogo, {5,   "Smartwatch Band 7",          "Xiaomi",    119.99, 4, "Accesorios"});
    agregarProducto(catalogo, {6,   "Cafetera Espresso",          "Oster",      59.99, 3, "Hogar"});
    agregarProducto(catalogo, {7,   "Tablet Galaxy Tab A8",       "Samsung",   299.99, 4, "Electrónica"});
    agregarProducto(catalogo, {8,   "Mouse inalámbrico M185",     "Logitech",   39.99, 4, "Computación"});
    agregarProducto(catalogo, {9,   "Monitor 24'' IPS",           "LG",        179.99, 4, "Computación"});
    agregarProducto(catalogo, {10,  "Parlante portátil Go 3",     "JBL",        49.99, 3, "Audio"});
    agregarProducto(catalogo, {11,  "Heladera No Frost 300L",     "Whirlpool", 799.00, 5, "Electrodomésticos"});
    agregarProducto(catalogo, {12,  "Cámara deportiva Hero 9",    "GoPro",     299.99, 5, "Fotografía"});
    agregarProducto(catalogo, {13,  "Licuadora PowerMax",         "Philips",    44.99, 3, "Hogar"});
    agregarProducto(catalogo, {14,  "Plancha a vapor Serie 3000", "Philips",    29.99, 4, "Hogar"});
    agregarProducto(catalogo, {15,  "Router WiFi 6 AX50",         "TP-Link",    59.99, 4, "Redes"});
    agregarProducto(catalogo, {16,  "Teclado mecánico Kumara",    "Redragon",   69.99, 5, "Computación"});
    agregarProducto(catalogo, {17,  "TV Box Android Mi Box",      "Xiaomi",     79.99, 3, "Electrónica"});
    agregarProducto(catalogo, {18,  "Disco SSD 1TB A400",         "Kingston",   99.99, 5, "Almacenamiento"});
    agregarProducto(catalogo, {19,  "Impresora multifunción 2775","HP",        119.99, 4, "Computación"});
    agregarProducto(catalogo, {20,  "Microondas digital 20L",     "Samsung",   149.99, 4, "Electrodomésticos"});
    agregarProducto(catalogo, {21,  "Lámpara LED de escritorio",  "Xiaomi",     24.99, 4, "Hogar"});
    agregarProducto(catalogo, {22,  "Batería externa 20000mAh",   "Anker",      39.99, 5, "Accesorios"});
    agregarProducto(catalogo, {23,  "Cámara IP WiFi",             "TP-Link",    44.99, 4, "Seguridad"});
    agregarProducto(catalogo, {24,  "Silla gamer",                "Cougar",    249.99, 5, "Muebles"});
    agregarProducto(catalogo, {25,  "Teclado inalámbrico K380",   "Logitech",   49.99, 4, "Computación"});
    agregarProducto(catalogo, {26,  "Freidora de aire 3.5L",      "Philips",   139.99, 4, "Hogar"});
    agregarProducto(catalogo, {27,  "Aspiradora robot",           "Xiaomi",    299.99, 5, "Hogar"});
    agregarProducto(catalogo, {28,  "Bicicleta urbana",           "Venzo",     399.99, 5, "Deportes"});
    agregarProducto(catalogo, {29,  "Set mancuernas 20kg",        "Everlast",   69.99, 4, "Deportes"});
    agregarProducto(catalogo, {30,  "Guitarra criolla",           "Yamaha",    159.99, 4, "Instrumentos"});
    agregarProducto(catalogo, {31,  "Cámara instantánea Mini",    "Fujifilm",   89.99, 3, "Fotografía"});
    agregarProducto(catalogo, {32,  "Proyector portátil",         "Xiaomi",    299.99, 4, "Electrónica"});
    agregarProducto(catalogo, {33,  "Auriculares In-Ear T110",    "JBL",        19.99, 3, "Audio"});
    agregarProducto(catalogo, {34,  "Smartwatch Galaxy Watch 5",  "Samsung",   299.99, 5, "Accesorios"});
    agregarProducto(catalogo, {35,  "Cámara réflex EOS 4000D",    "Canon",     399.99, 5, "Fotografía"});
    agregarProducto(catalogo, {36,  "Monitor 27'' Gaming",        "AOC",       249.99, 5, "Computación"});
    agregarProducto(catalogo, {37,  "Celular Moto G32",           "Motorola",  179.99, 4, "Telefonía"});
    agregarProducto(catalogo, {38,  "Balanza digital",            "Xiaomi",     34.99, 4, "Hogar"});
    agregarProducto(catalogo, {39,  "Tablet iPad 9th Gen",        "Apple",     329.99, 5, "Electrónica"});
    agregarProducto(catalogo, {40,  "Auricular gamer G733",       "Logitech",  129.99, 5, "Audio"});
    agregarProducto(catalogo, {41,  "Teclado Magic Keyboard",     "Apple",     249.99, 5, "Computación"});
    agregarProducto(catalogo, {42,  "Mouse Magic Mouse",          "Apple",      99.99, 5, "Computación"});
    agregarProducto(catalogo, {43,  "Monitor 32'' 4K",            "Samsung",   449.99, 5, "Computación"});
    agregarProducto(catalogo, {44,  "Celular iPhone 13",          "Apple",     799.99, 5, "Telefonía"});
    agregarProducto(catalogo, {45,  "Parlante Echo Dot",          "Amazon",     49.99, 4, "Audio"});
    agregarProducto(catalogo, {46,  "Smartwatch Amazfit Bip",     "Amazfit",    59.99, 4, "Accesorios"});
    agregarProducto(catalogo, {47,  "Cámara de acción",           "SJCAM",      59.99, 3, "Fotografía"});
    agregarProducto(catalogo, {48,  "Notebook MacBook Air",       "Apple",    1099.99, 5, "Computación"});
    agregarProducto(catalogo, {49,  "Microondas Grill",           "LG",        189.99, 4, "Electrodomésticos"});
    agregarProducto(catalogo, {50,  "Bicicleta de montaña",       "TopMega",   499.99, 4, "Deportes"});
}