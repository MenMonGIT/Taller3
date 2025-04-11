#include "BloodDatabase.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <algorithm>

using namespace std;

void BloodDatabase::displayProvinces() {
    cout << "Departamentos disponibles:\n";
    cout << "1. Putumayo\n2. Cauca\n3. Valle del Cauca\n";
    cout << "4. Amazonas\n5. Risaralda\n6. Antioquia\n7. Norte de Santander\n";
}

void BloodDatabase::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void BloodDatabase::waitForKeyPress() {
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

int BloodDatabase::getValidatedInput(const std::string& prompt) {
    int value;
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            value = stoi(input);
            break;
        } catch (...) {
            cout << "Entrada inválida. Intente nuevamente.\n";
        }
    }
    return value;
}

void BloodDatabase::getDonorDetails() {
    clearConsole();
    cout << "Registro de donante:\n";

    Donor newDonor;
    newDonor.donorId = getValidatedInput("ID: ");
    cout << "Nombre: ";
    getline(cin, newDonor.name);
    cout << "Dirección: ";
    getline(cin, newDonor.address);

    displayProvinces();
    newDonor.district = getValidatedInput("Departamento (número): ");
    cout << "Tipo de sangre: ";
    getline(cin, newDonor.bloodType);
    newDonor.number = getValidatedInput("Teléfono: ");

    donors.push_back(newDonor);
}

void BloodDatabase::writeDataToFile() {
    ofstream outfile(fileName, ios::app);
    if (!outfile) {
        cout << "Error al abrir archivo.\n";
        return;
    }

    Donor newDonor = donors.back();
    outfile << newDonor.donorId << "," << newDonor.name << ","
            << newDonor.address << "," << newDonor.district << ","
            << newDonor.bloodType << "," << newDonor.number << endl;

    outfile.close();
    cout << "Donante registrado exitosamente!\n";
    waitForKeyPress();
}

void BloodDatabase::searchAndDisplay() const {
    clearConsole();
    displayProvinces();
    int provincia = getValidatedInput("Departamento a buscar (número): ");

    ifstream inFile(fileName);
    if (!inFile) {
        cout << "No hay donantes registrados.\n";
        waitForKeyPress();
        return;
    }

    string line;
    bool encontrado = false;
    while (getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        if (d.district == provincia) {
            d.donorDetails();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron donantes en ese departamento.\n";
    }
    waitForKeyPress();
}

void BloodDatabase::deleteDonor(const std::string& donorName) {
    ifstream inFile(fileName);
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cerr << "Error al abrir archivos.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        if (d.name == donorName) {
            found = true;
            cout << "Donante encontrado:\n";
            d.donorDetails();
            cout << "¿Eliminar? (s/n): ";
            char opcion;
            cin >> opcion;
            cin.ignore();
            if (tolower(opcion) != 's') {
                tempFile << line << endl;
            }
        } else {
            tempFile << line << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove(fileName.c_str());
    rename("temp.txt", fileName.c_str());

    if (!found) {
        cout << "Donante no encontrado.\n";
    }
    waitForKeyPress();
}

void BloodDatabase::registrarSolicitante() {
    clearConsole();
    cout << "Registro de solicitante:\n";

    Solicitante s;
    cout << "Nombre: "; getline(cin, s.nombre);
    cout << "ID: "; getline(cin, s.id);
    cout << "Tipo sangre requerido: "; getline(cin, s.tipoSangreNecesita);
    s.unidadesRequeridas = getValidatedInput("Unidades requeridas: ");

    ofstream file(solicitantesFile, ios::app);
    if (file) {
        file << s.nombre << "," << s.id << "," 
             << s.tipoSangreNecesita << "," << s.unidadesRequeridas << endl;
        cout << "Solicitante registrado!\n";
    } else {
        cout << "Error al guardar.\n";
    }
    waitForKeyPress();
}

bool BloodDatabase::existeSangre(const std::string& tipo) {
    ifstream file(fileName);
    if (!file) return false;

    string line;
    while (getline(file, line)) {
        Donor d = Donor::parseLine(line);
        if (d.bloodType == tipo) return true;
    }
    return false;
}

void BloodDatabase::procesarEntrega() {
    clearConsole();
    string tipoRequerido;
    cout << "Tipo de sangre requerido: ";
    getline(cin, tipoRequerido);

    if (!existeSangre(tipoRequerido)) {
        cout << "No hay disponibilidad. Alternativas compatibles:\n";
        vector<string> alternativas = PasarelaSangre::sugerirAlternativas(tipoRequerido);
        for (const auto& alt : alternativas) {
            if (existeSangre(alt)) {
                cout << "- " << alt << " (disponible)\n";
            } else {
                cout << "- " << alt << " (no disponible)\n";
            }
        }
    } else {
        int unidades = getValidatedInput("Unidades a entregar: ");
        
        ofstream file(entregasFile, ios::app);
        if (file) {
            file << tipoRequerido << "," << unidades << ",ENTREGADO" << endl;
            cout << "Entrega registrada!\n";
        } else {
            cout << "Error al guardar.\n";
        }
    }
    waitForKeyPress();
}

void BloodDatabase::mostrarHistorialDonaciones() {
    ifstream file(fileName);
    if (!file) {
        cout << "No hay donaciones registradas.\n";
        waitForKeyPress();
        return;
    }

    string nombre;
    cout << "Nombre del donante: ";
    getline(cin, nombre);

    string line;
    bool encontrado = false;
    while (getline(file, line)) {
        Donor d = Donor::parseLine(line);
        if (d.name == nombre) {
            d.donorDetails();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron donaciones.\n";
    }
    waitForKeyPress();
}

void BloodDatabase::mostrarHistorialSolicitudes() {
    ifstream file(solicitantesFile);
    if (!file) {
        cout << "No hay solicitudes.\n";
        waitForKeyPress();
        return;
    }

    string id;
    cout << "ID del solicitante: ";
    getline(cin, id);

    string line;
    bool encontrado = false;
    while (getline(file, line)) {
        Solicitante s = Solicitante::parseLine(line);
        if (s.id == id) {
            s.mostrarInfo();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron solicitudes.\n";
    }
    waitForKeyPress();
}

void BloodDatabase::mostrarHistorialEntregas() {
    ifstream file(entregasFile);
    if (!file) {
        cout << "No hay entregas registradas.\n";
        waitForKeyPress();
        return;
    }

    cout << "=== HISTORIAL DE ENTREGAS ===\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    waitForKeyPress();
}