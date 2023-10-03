//
// Created by Jan Heil on 03.10.2023.
//

#ifndef COFFEECAT_VIRTUALCAT_H
#define COFFEECAT_VIRTUALCAT_H

#include <string>
#include <vector>

class VirtualCat {
private:
    std::string name;
    int age;
    int hunger;
    int happiness;
    int energy;
    std::vector<std::string> visits;

public:
    VirtualCat(std::string nameIO) : name(nameIO), age(1), hunger(50), happiness(50), energy(50) {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    int getHunger() const {
        return hunger;
    }

    int getHappiness() const {
        return happiness;
    }

    int getEnergy() const {
        return energy;
    }

    const std::vector<std::string> &getVisits() const {
        return visits;
    }
};


#endif //COFFEECAT_VIRTUALCAT_H
