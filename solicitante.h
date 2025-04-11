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