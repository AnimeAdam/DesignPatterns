#pragma once

#include <iostream>
#include <string>
#include "CarBattery.h"

class Automobile {
private:
    int numberOfTires;
    std::string bodyType;
    std::string engineType;
    int fuelTankSizeInGallons;
    bool airConditioned;
    int odometerMiles;
    CarBattery carBattery;

public:

    class Builder {
    public:
        int numTires = 0;
        std::string body = "";
        std::string engine = "";
        int fuelTankSize = 0;
        bool airCondition = false;
        int odometer = 0;
        CarBattery carBat;

        Builder* numberOfTires(int numberOfTires) {
            this->numTires = numberOfTires;
            return this;
        }

        Builder* bodyType(std::string bodyType) {
            this->body = bodyType;
            return this;
        }

        Builder* engineType(std::string engineType) {
            this->engine = engineType;
            return this;
        }

        Builder* fuelTankSizeInGallons(int fuelTankSizeInGallons) {
            this->fuelTankSize = fuelTankSizeInGallons;
            return this;
        }

        Builder* airConditioned(bool airConditioned) {
            this->airCondition = airConditioned;
            return this;
        }

        Builder* odometerMiles(int odometerMiles) {
            this->odometer = odometerMiles;
            return this;
        }

        Builder* carBattery(CarBattery carBattery) {
            this->carBat = carBattery;
            return this;
        }

        Automobile build() {
            return Automobile(*this);
        }
    };

    int getNumberOfTires() { return numberOfTires; }

    Automobile(Builder builder)
        : numberOfTires(builder.numTires), bodyType(builder.body), engineType(builder.engine),
        fuelTankSizeInGallons(builder.fuelTankSize), airConditioned(builder.airCondition),
        odometerMiles(builder.odometer) {}
};