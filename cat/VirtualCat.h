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
    long hunger;
    int happiness;
    int energy;
    bool alive = true;
    std::vector<std::string> visits;

public:
    VirtualCat(std::string nameIO) : name(nameIO), age(1), hunger(50.00), happiness(50), energy(50) {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    long getHunger() const {
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

    void setName(const std::string &name) {
        VirtualCat::name = name;
    }

    void setAge(int age) {
        VirtualCat::age = age;
    }

    void setHunger(long hunger) {
        VirtualCat::hunger = hunger;
    }

    void setHappiness(int happiness) {
        VirtualCat::happiness = happiness;
    }

    void setEnergy(int energy) {
        VirtualCat::energy = energy;
    }

    void setVisits(const std::vector<std::string> &visits) {
        VirtualCat::visits = visits;
    }

    bool isAlive() const {
        return alive;
    }

    void setAlive(bool alive) {
        VirtualCat::alive = alive;
    }
};


#endif //COFFEECAT_VIRTUALCAT_H
