#ifndef tanque_h
#define tanque_h

class tanque
{
private:

    int capR;
    int capP;
    int capE;
    int cantR;
    int cantP;
    int cantE;

public:

    tanque();

    int getCapR();
    int getCapP();
    int getCapE();

    int getCantR();
    int getCantP();
    int getCantE();

    void setCantR(int nuevaCantR);
    void setCantP(int nuevaCantP);
    void setCantE(int nuevaCantE);
};

#endif // TANQUE_H
