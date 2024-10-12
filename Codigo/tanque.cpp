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

int getCapR() const { return capR; }
int getCapP() const { return capP; }
int getCapE() const { return capE; }

int getCantR() const { return cantR; }
int getCantP() const { return cantP; }
int getCantE() const { return cantE; }

void setCantR(int nuevaCantR) {
    if (nuevaCantR <= capR) {
        cantR = nuevaCantR;
    } else {
        cout << "Error: La cantidad excede la capacidad de combustible Regular.\n";
    }
}

void setCantP(int nuevaCantP) {
    if (nuevaCantP <= capP) {
        cantP = nuevaCantP;
    } else {
        cout << "Error: La cantidad excede la capacidad de combustible Premium.\n";
    }
}

void setCantE(int nuevaCantE) {
    if (nuevaCantE <= capE) {
        cantE = nuevaCantE;
    } else {
        cout << "Error: La cantidad excede la capacidad de combustible EcoExtra.\n";
    }
}
