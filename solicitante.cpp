#include "Solicitante.h"
#include <iostream>
#include <sstream>

/**
 * Muestra en consola la información del solicitante.
 *
 * Imprime el nombre, ID, tipo de sangre requerido y
 * unidades necesarias para el solicitante actual.
 */

void Solicitante::mostrarInfo() const {
    std::cout << "Solicitante: " << nombre << "\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Tipo sangre requerido: " << tipoSangreNecesita << "\n";
    std::cout << "Unidades necesarias: " << unidadesRequeridas << "\n\n";
}

/**
 * Crea un objeto Solicitante a partir de una línea CSV.
 *
 * La línea debe tener el formato: nombre,id,tipoSangre,unidades
 * Ejemplo: "Juan Perez,1234,O+,2"
 *
 * @param line Línea de texto con los datos separados por comas.
 * @return Solicitante Objeto construido con los datos extraídos.
 */

Solicitante Solicitante::parseLine(const std::string& line) {
    Solicitante s;
    std::stringstream ss(line);
    std::getline(ss, s.nombre, ',');
    std::getline(ss, s.id, ',');
    std::getline(ss, s.tipoSangreNecesita, ',');
    ss >> s.unidadesRequeridas;
    return s;
}
