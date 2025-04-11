#ifndef PASARELA_SANGRE_H
#define PASARELA_SANGRE_H

#include <vector>
#include <string>

class PasarelaSangre {
public:
    static bool esCompatible(const std::string& donante, const std::string& receptor);
    static std::vector<std::string> sugerirAlternativas(const std::string& tipoRequerido);
};

#endif