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

    void setCapR (int nuevacap);
    void setCapP (int nuevacap);
    void setCapE (int nuevacap);

    void setCantR(int nuevaCantR);
    void setCantP(int nuevaCantP);
    void setCantE(int nuevaCantE);

    void restarCantR(int CR);
    void restarCantP(int CP);
    void restarCantE(int CE);

};

#endif // TANQUE_H
