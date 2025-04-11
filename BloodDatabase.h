/*
**********************************************************************************
CLASE: BloodDatabase
**********************************************************************************
PROPÓSITO:
Gestiona toda la lógica de persistencia y operaciones complejas del sistema.
Coordina entre entidades (Donor/Solicitante) y archivos de almacenamiento.

INTERACCIÓN PRINCIPAL:
- main.cpp: Recibe solicitudes del menú principal
- Donor/Solicitante: Manipula instancias de estas clases
- Archivos .txt: Persistencia de datos (data.txt, solicitantes.txt, entregas.txt)

MÉTODOS DESTACADOS (NUEVOS):
1. registrarSolicitante():
   - Flujo: Interacción usuario → validación → almacenamiento

2. procesarEntrega():
   - Flujo: Verifica stock → chequea compatibilidad → registra entrega

3. mostrarHistoriales():
   - Variantes: Donaciones/Solicitudes/Entregas
   - Tecnología: Lectura de archivos con filtrado

FUNCIONALIDADES BASE:
- Manejo de donantes (CRUD)
- Búsquedas geográficas
- Validación de entradas
**********************************************************************************
*/
#ifndef BLOODDATABASE_H
#define BLOODDATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"
#include "Solicitante.h"
#include "PasarelaSangre.h"

class BloodDatabase {
private:
    const std::string fileName = "data.txt";
    const std::string solicitantesFile = "solicitantes.txt";
    const std::string entregasFile = "entregas.txt";
    std::vector<Donor> donors;

    static void displayProvinces();
    bool existeSangre(const std::string& tipo);

public:
    static void clearConsole();
    static void waitForKeyPress();
    static int getValidatedInput(const std::string& prompt);

    void getDonorDetails();
    void writeDataToFile();
    void searchAndDisplay() const;
    void deleteDonor(const std::string& donorName);
    
    void registrarSolicitante();
    void procesarEntrega();
    void mostrarHistorialDonaciones();
    void mostrarHistorialSolicitudes();
    void mostrarHistorialEntregas();
};

#endif