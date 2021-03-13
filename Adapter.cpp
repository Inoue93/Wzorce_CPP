#include <QCoreApplication>
#include <iostream>

using namespace std;

class Animal
{
    public:
    virtual void giveVoice() = 0;
    virtual void doSomething() = 0;
    virtual void sleep() = 0;
    virtual void eat() = 0;
    virtual void runs() = 0;
    virtual ~Animal(){}
};

class Wolf : public Animal
{
    public:
    void giveVoice(){ cout << "Wolf gives voice"<< endl;}
    void doSomething(){ cout << "Wolf does something"<< endl;}
    void sleep(){ cout << "Wolf go sleep"<< endl;}
    void eat(){ cout << "Wolf eat"<< endl;}
    void runs(){ cout<<"Wolf runs"<< endl; }

};

//zewnetrzna biblioteka
class Cat
{
    public:
    void catGivesVoice(){cout <<"Cat gives voice"<< endl;}
    void catDoesSomething(){cout << "Cat does something"<< endl;}
    void catSleep(){ cout << "Cat go sleep"<< endl;}
    void catEat(){ cout << "Cat eat"<< endl;}
    void catRuns(){ cout<<"Cat runs"<< endl;}
};

//adapter
class CatAnimalAdapter : private Cat, public Animal
{
    public:
    void giveVoice(){catGivesVoice();}
    void doSomething(){catDoesSomething();}
    void sleep(){catSleep();}
    void eat(){catEat();}
    void runs(){catRuns();}
};




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Animal* pAnimal = new Wolf();
    pAnimal->giveVoice();
    pAnimal->doSomething();
    pAnimal->sleep();
    pAnimal->eat();
    pAnimal->runs();


    Animal *pAnimal2 = new CatAnimalAdapter();
    pAnimal2->giveVoice();
    pAnimal2->doSomething();
    pAnimal2->sleep();
    pAnimal2->eat();
    pAnimal2->runs();

    delete pAnimal;
    delete pAnimal2;

    return a.exec();
}
