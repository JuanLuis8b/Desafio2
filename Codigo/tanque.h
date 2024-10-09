#ifndef tanque_h
#define tanque_h

class tanque
{
private:

    int cantRegular;
    int cantPremium;
    int cantEcoExtra;

    bool disponibleRegular;
    bool disponiblePremium;
    bool disponibleEco;

    bool verificarDispo(int cantidad){
        if (cantidad <= 0){
            return false;
        }
        return true;
    }

public:
    tanque(int cR, int cP, int cX){//Valores bool por defecto

        cantRegular = cR;
        cantPremium = cP;
        cantEcoExtra = cX;

        disponibleRegular = verificarDispo(cR);
        disponiblePremium = verificarDispo(cP);
        disponibleEco = verificarDispo(cX);
    }

    int getcantRegular(){
        return cantRegular;
    }
    int getcantPremium(){
        return cantPremium;
    }
    int getcantEco(){
        return cantEcoExtra;
    }
    void setCantRegular(int cant){
        cantRegular = cant;//vertificar funcionalidad
    }
    // bool isdisponibleRegular...return isdisponible

    void actualizarCap(int cantidad, string categoria){

        switch (categoria){

            case "Regular":{
                cantRegular -= cantidad;
            }
            case "Premium":{
                cantPremium -= cantidad;
            }
            case "EcoExtra":{
                cantEcoExtra -= cantidad;
            }
        }
        //que hacer cuando sea negativo
        // verificar el atributo bool_disponibilidad
    }
};

#endif // TANQUE_H
