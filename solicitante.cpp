#include "Solicitante.h"
#include <iostream>
#include <sstream>

void Solicitante::mostrarInfo() const {
    std::cout << "Solicitante: " << nombre << "\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Tipo sangre requerido: " << tipoSangreNecesita << "\n";
    std::cout << "Unidades necesarias: " << unidadesRequeridas << "\n\n";
}

Solicitante Solicitante::parseLine(const std::string& line) {
    Solicitante s;
    std::stringstream ss(line);
    std::getline(ss, s.nombre, ',');
    std::getline(ss, s.id, ',');
    std::getline(ss, s.tipoSangreNecesita, ',');
    ss >> s.unidadesRequeridas;
    return s;
}