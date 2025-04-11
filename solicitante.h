/*
================================================================================
CLASE: Solicitante
================================================================================
PROPÓSITO:
Representa a personas que requieren transfusiones de sangre. Almacena información
crítica para el matching con donantes compatibles.

INTERACCIÓN PRINCIPAL:
- BloodDatabase: Persistencia en solicitantes.txt
- PasarelaSangre: Verificación de compatibilidad

ATRIBUTOS:
- nombre, id: Identificación básica
- tipoSangreNecesita: Grupo sanguíneo requerido
- unidadesRequeridas: Cantidad de unidades solicitadas

MÉTODOS PRINCIPALES:
- mostrarInfo(): Despliega datos en formato tabular
- parseLine(): Factory method para crear objetos desde archivo
================================================================================
*/

#ifndef SOLICITANTE_H
#define SOLICITANTE_H

#include <string>

class Solicitante {
public:
    std::string nombre, id, tipoSangreNecesita;
    int unidadesRequeridas;

    static Solicitante parseLine(const std::string& line);
    void mostrarInfo() const;
};

#endif