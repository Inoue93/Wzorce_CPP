#include <iostream>
#include <string>
using namespace std;

class Drink {
    protected:
    string typeOfDrinks;
    string additives;
    int value;

    public:
    Drink(){
    typeOfDrinks = "Bazowy napoj";
    additives = "Bazowe dodatki";
    value=0;
    }
    virtual~Drink(){}

    virtual string getInfoDrinks(){
        return typeOfDrinks;
    }

    virtual int price(){
        return value;
    }
};

/* abstrakcyjny dekorator */
class Decorator : public Drink {
    public:
    virtual string getInfoDrinks(){
    return "nothing";
    }
};

/* rodzaje kawy */
class Coffee : public Drink {
    public:
    Coffee():Drink(){
    typeOfDrinks = "Kawa";
    value=10;
}

};

class Espresso : public Drink {
    public:
    Espresso():Drink(){
    typeOfDrinks = "Espresso";
    value=9;
}

};

/* dodatki */
class Milk : public Decorator {
    Drink *cof;
    int milkPrice = 4;

    public: Milk(Drink *coffee):Decorator(){
    cof = coffee;
    }

    string getInfoDrinks(){
    return cof->getInfoDrinks() + " + Mleko";
    }

    int price(){
    return cof->price()+milkPrice;
    }
};

class WhippedCream : public Decorator {
    Drink *cof;
    int creamPrice = 3;

    public: WhippedCream(Drink *coffee):Decorator(){
    cof = coffee;
    }

    string getInfoDrinks(){
    return cof->getInfoDrinks() + " + Bita smietana";
    }

    int price(){
    return cof->price()+creamPrice;
    }
};

class Roasted : public Decorator {
    Drink *cof;
    int roastedPrice = 3;

    public: Roasted(Drink *coffee):Decorator(){
    cof = coffee;
    }

    string getInfoDrinks(){
    return cof->getInfoDrinks() + " + Mocno palona";
    }

    int price(){
    return cof->price()+roastedPrice;
    }
};

class Decaffeinated : public Decorator {
    Drink *cof;
    int decaffeinatedPrice = 5;

    public: Decaffeinated(Drink *coffee):Decorator(){
    cof = coffee;
    }

    string getInfoDrinks(){
    return cof->getInfoDrinks() + " + Bezkofeinowa";
    }

    int price(){
    return cof->price()+decaffeinatedPrice;
    }
};





int main()
{
    Drink *kawa = new Coffee;
    Drink *espresso = new Espresso;

    cout<<"\nBez dodatkow"<<endl;
    cout<<kawa->getInfoDrinks()<<" "<<kawa ->price()<<endl;
    cout<<espresso->getInfoDrinks()<<" "<<espresso->price()<<endl;

    //dodatki
    kawa = new Milk(kawa);
    espresso = new Milk(espresso);
    cout<<"\nZ mlekiem"<<endl;
    cout<<kawa->getInfoDrinks()<<" "<<kawa->price()<<endl;
    cout<<espresso->getInfoDrinks()<<" "<<espresso->price()<<endl;


    kawa = new WhippedCream(kawa);
    espresso = new WhippedCream(espresso);
    cout<<"\nZ bita smietana"<<endl;
    cout<<kawa->getInfoDrinks()<<" "<<kawa->price()<<endl;
    cout<<espresso->getInfoDrinks()<<" "<<espresso->price()<<endl;

    kawa = new Roasted(kawa);
    espresso = new Roasted(espresso);
    cout<<"\nMocno palona"<<endl;
    cout<<kawa->getInfoDrinks()<<" "<<kawa->price()<<endl;
    cout<<espresso->getInfoDrinks()<<" "<<espresso->price()<<endl;

    kawa = new Decaffeinated(kawa);
    espresso = new Decaffeinated(espresso);
    cout<<"\nBezkofeinowa"<<endl;
    cout<<kawa->getInfoDrinks()<<" "<<kawa->price()<<endl;
    cout<<espresso->getInfoDrinks()<<" "<<espresso->price()<<endl;

    cout<<"\nKawa mocno palona"<<endl;
    Drink *roastedcoffe =  new Roasted(new WhippedCream( new Milk( new Coffee())));
    cout<<roastedcoffe->getInfoDrinks()<<" "<<roastedcoffe->price()<<endl;

    return 0;
}

