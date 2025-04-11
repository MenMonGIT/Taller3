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