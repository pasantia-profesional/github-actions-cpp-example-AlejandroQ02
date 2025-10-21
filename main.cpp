#include "Tienda.h"
#include <iostream>
#include <limits>

int main() {
    Tienda tienda;
    tienda.inicializarProductos();
    int opcion;

inicio_menu:
    std::cout << "\n=== Menú de la Tienda ===" << std::endl;
    std::cout << "1. Agregar producto" << std::endl;
    std::cout << "2. Buscar producto" << std::endl;
    std::cout << "3. Actualizar producto" << std::endl;
    std::cout << "4. Eliminar producto" << std::endl;
    std::cout << "5. Mostrar todos los productos" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Ingrese su opción: ";
    
    if (!(std::cin >> opcion)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Por favor ingrese un número." << std::endl;
        goto inicio_menu;
    }

    switch (opcion) {
        case 1: {
            int id, cantidad;
            double precio;
            std::string nombre;
            
            std::cout << "Ingrese ID: ";
            std::cin >> id;
            std::cout << "Ingrese nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Ingrese precio: ";
            std::cin >> precio;
            std::cout << "Ingrese cantidad: ";
            std::cin >> cantidad;
            
            tienda.crearProducto(id, nombre, precio, cantidad);
            goto inicio_menu;
        }
        case 2: {
            int id;
            std::cout << "Ingrese ID del producto a buscar: ";
            std::cin >> id;
            Producto* producto = tienda.leerProducto(id);
            if (producto != nullptr) {
                producto->mostrarInfo();
            } else {
                std::cout << "Producto no encontrado." << std::endl;
            }
            goto inicio_menu;
        }
        case 3: {
            int id, cantidad;
            double precio;
            std::string nombre;
            
            std::cout << "Ingrese ID del producto a actualizar: ";
            std::cin >> id;
            std::cout << "Ingrese nuevo nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Ingrese nuevo precio: ";
            std::cin >> precio;
            std::cout << "Ingrese nueva cantidad: ";
            std::cin >> cantidad;
            
            tienda.actualizarProducto(id, nombre, precio, cantidad);
            goto inicio_menu;
        }
        case 4: {
            int id;
            std::cout << "Ingrese ID del producto a eliminar: ";
            std::cin >> id;
            tienda.eliminarProducto(id);
            goto inicio_menu;
        }
        case 5: {
            tienda.mostrarTodosProductos();
            goto inicio_menu;
        }
        case 6: {
            std::cout << "¡Gracias por usar el sistema!" << std::endl;
            return 0;
        }
        default: {
            std::cout << "Opción inválida." << std::endl;
            goto inicio_menu;
        }
    }
    return 0;
}