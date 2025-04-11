#include "Donor.h"
#include <sstream>
#include <iostream>
#include <algorithm>

void Donor::donorDetails() const {
    std::cout << "Nombre: " << name << "\n";
    std::cout << "Dirección: " << address << "\n";
    std::cout << "Departamento: " << district << "\n";
    std::cout << "Tipo de sangre: " << bloodType << "\n";
    std::cout << "Teléfono: " << number << "\n\n";
}

Donor Donor::parseLine(const std::string& line) {
    Donor d;
    std::stringstream ss(line);
    std::string token;

    getline(ss, token, ','); d.donorId = std::stoi(trim(token));
    getline(ss, token, ','); d.name = trim(token);
    getline(ss, token, ','); d.address = trim(token);
    getline(ss, token, ','); d.district = std::stoi(trim(token));
    getline(ss, token, ','); d.bloodType = trim(token);
    getline(ss, token, ','); d.number = std::stoi(trim(token));

    return d;
}

std::string Donor::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}