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