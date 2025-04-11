/*
**********************************************************************************
SISTEMA DE GESTIÓN DE DONANTES Y SOLICITANTES DE SANGRE - CRUZ ROJA
**********************************************************************************
Este sistema fue extendido como parte del taller de Programación Orientada a Objetos,
incorporando nuevos requerimientos como gestión de solicitantes, compatibilidad
sanguínea y historiales. Mantiene el enfoque en encapsulamiento y modularidad.

**********************************************************************************
AUTOR DEL ARCHIVO: Victor Bucheli
**********************************************************************************

Resuelto por:

- Valentina Montezuma Gonzalez (202242058)
- Julian Meneses Moncada (2042970)
- Joan Sebastian Rivera Henk (2222936)
- Oriana Pajaro (2438031)


================================================================================
DESCRIPCIÓN:
================================================================================

Punto de entrada principal del sistema. Gestiona el menú interactivo y coordina
las operaciones entre módulos. Las nuevas funcionalidades implementadas incluyen:

- Registro de solicitantes
- Procesamiento de entregas con validación de compatibilidad
- Visualización de historiales integrados

Interactúa con: BloodDatabase (gestión de datos), Donor y Solicitante (entidades)

================================================================================
FECHA ÚLTIMA MODIFICACIÓN: 10/04/25
================================================================================
*/

#include "BloodDatabase.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    BloodDatabase database;
    int choice;

    while (true) {
        BloodDatabase::clearConsole();

        cout << " ░█████╗░██████╗░██╗░░░██╗███████╗  ██████╗░░█████╗░░░░░░██╗░█████╗░\n"
                " ██╔══██╗██╔══██╗██║░░░██║╚════██║  ██╔══██╗██╔══██╗░░░░░██║██╔══██╗\n"
                " ██║░░╚═╝██████╔╝██║░░░██║░░███╔═╝  ██████╔╝██║░░██║░░░░░██║███████║\n"
                " ██║░░██╗██╔══██╗██║░░░██║██╔══╝░░  ██╔══██╗██║░░██║██╗░░██║██╔══██║\n"
                " ╚█████╔╝██║░░██║╚██████╔╝███████╗  ██║░░██║╚█████╔╝╚█████╔╝██║░░██║\n"
                " ░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░╚═╝\n\n";

        cout << "1. Registrar donante\n";
        cout << "2. Buscar donante\n";
        cout << "3. Eliminar donante\n";
        cout << "4. Registrar solicitante\n";
        cout << "5. Procesar entrega de sangre\n";
        cout << "6. Mostrar historiales\n";
        cout << "7. Salir\n";
        cout << "Ingrese su elección: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                database.getDonorDetails();
                database.writeDataToFile();
                break;
            case 2:
                database.searchAndDisplay();
                break;
            case 3: {
                string nombre;
                cout << "Nombre del donante a eliminar: ";
                getline(cin, nombre);
                database.deleteDonor(nombre);
                break;
            }
            case 4:
                database.registrarSolicitante();
                break;
            case 5:
                database.procesarEntrega();
                break;
            case 6: {
                int subChoice;
                cout << "1. Historial donaciones\n2. Historial solicitudes\n3. Historial entregas\n";
                cin >> subChoice;
                cin.ignore();
                switch (subChoice) {
                    case 1: database.mostrarHistorialDonaciones(); break;
                    case 2: database.mostrarHistorialSolicitudes(); break;
                    case 3: database.mostrarHistorialEntregas(); break;
                    default: cout << "Opción inválida.\n";
                }
                break;
            }
            case 7:
                cout << "Saliendo del sistema...\n";
                return 0;
            default:
                cout << "Opción no válida.\n";
                BloodDatabase::waitForKeyPress();
        }
    }
}