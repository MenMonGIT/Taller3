#include "PasarelaSangre.h"
#include <map>

bool PasarelaSangre::esCompatible(const std::string& donante, const std::string& receptor) {
    if (receptor == "O-") return donante == "O-";
    if (receptor == "O+") return donante == "O-" || donante == "O+";
    if (receptor == "A-") return donante == "O-" || donante == "A-";
    if (receptor == "A+") return donante == "O-" || donante == "O+" || donante == "A-" || donante == "A+";
    if (receptor == "B-") return donante == "O-" || donante == "B-";
    if (receptor == "B+") return donante == "O-" || donante == "O+" || donante == "B-" || donante == "B+";
    if (receptor == "AB-") return donante == "O-" || donante == "A-" || donante == "B-" || donante == "AB-";
    if (receptor == "AB+") return true;
    return false;
}

std::vector<std::string> PasarelaSangre::sugerirAlternativas(const std::string& tipoRequerido) {
    std::map<std::string, std::vector<std::string>> alternativas = {
        {"A+", {"A-", "O+", "O-"}},
        {"B+", {"B-", "O+", "O-"}},
        {"AB+", {"A+", "A-", "B+", "B-", "AB-", "O+", "O-"}},
        {"O+", {"O-"}},
        {"A-", {"O-"}},
        {"B-", {"O-"}},
        {"AB-", {"A-", "B-", "O-"}}
    };
    return alternativas[tipoRequerido];
}