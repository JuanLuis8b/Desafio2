#include <iostream>
#include "tanque.h"
#include <random>
using namespace std;

int randomCap(){
    random_device x;
    uniform_int_distribution<> distrib(100,200);
    return distrib(x);
}

tanque::tanque() {
    capR = randomCap();
    capP = randomCap();
    capE = randomCap();
    cantR = capR;
    cantP = capP;
    cantE = capE;
}

int tanque::getCapR() {
    return capR;
}

int tanque::getCapP() {
    return capP;
}

int tanque::getCapE()  {
    return capE;
}

int tanque::getCantR()  {
    return cantR;
}

int tanque::getCantP() {
    return cantP;
}

int tanque::getCantE()  {
    return cantE;
}

void tanque::setCantR(int nuevaCantR) {
    if (nuevaCantR <= capR) {
        cantR = nuevaCantR;
    } else {
        cout << "Error: La cantidad excede la capacidad de combustible Regular.\n";
    }
}

void tanque::setCantP(int nuevaCantP) {
    if (nuevaCantP <= capP) {
        cantP = nuevaCantP;
    } else {
        cout << "Error: La cantidad excede la capacidad de combustible Premium.\n";
    }
}

void tanque::setCantE(int nuevaCantE) {
    if (nuevaCantE <= capE) {
        cantE = nuevaCantE;
    } else {
        cout << "Error: La cantidad excede la capacidad de combustible EcoExtra.\n";
    }
}

void tanque::restarCantR(int CR){
    cantR = cantR - CR;
}

void tanque::restarCantP(int CP){
    cantP = cantP - CP;
}

void tanque::restarCantE(int CE){
    cantE = cantE - CE;
}

