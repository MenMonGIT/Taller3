/*
================================================================================
CLASE: Donor
================================================================================
PROPÓSITO:
Representa a un donante de sangre con sus datos personales y médicos esenciales.
Encapsula la lógica de parsing/trimming para el manejo de archivos.

INTERACCIÓN PRINCIPAL:
- BloodDatabase: Es utilizada para almacenamiento y recuperación de datos
- Donor.cpp: Implementa los métodos declarados aquí

ATRIBUTOS:
- donorId: Identificador único
- name, address: Datos personales
- district: Ubicación geográfica (número asociado a departamento)
- bloodType: Grupo sanguíneo (+ factor Rh)
- number: Contacto telefónico

MÉTODOS PRINCIPALES:
- donorDetails(): Muestra información formateada del donante
- parseLine(): Convierte línea de archivo a objeto Donor (static)
- trim(): Elimina espacios innecesarios (private static)
================================================================================
*/

#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor {
public:
    int donorId, district, number;
    std::string name, address, bloodType;

    void donorDetails() const;
    static Donor parseLine(const std::string& line);

private:
    static std::string trim(const std::string& str);
};

#endif