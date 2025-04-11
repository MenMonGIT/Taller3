/*
================================================================================
CLASE: PasarelaSangre
================================================================================
PROPÓSITO:
Implementa las reglas médicas de compatibilidad entre tipos sanguíneos y provee
sugerencias cuando no hay disponibilidad exacta.

INTERACCIÓN PRINCIPAL:
- BloodDatabase: Consultada durante procesamiento de entregas
- Solicitante: Valida contra tipoSangreNecesita

MÉTODOS ESTÁTICOS:
1. esCompatible():
   - Entrada: 2 strings (tipo donante, tipo receptor)
   - Salida: bool (true si son compatibles)
   - Lógica: Implementa matriz de compatibilidad médica

2. sugerirAlternativas():
   - Entrada: string (tipo requerido)
   - Salida: vector<string> con tipos aceptables
   - Ejemplo: Para "A+" → ["A-", "O+", "O-"]
================================================================================
*/
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