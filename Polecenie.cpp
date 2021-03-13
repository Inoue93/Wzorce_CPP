#include <iostream>
#include <string>

using namespace std;
class Person;

class Command
{
    Person *object;
    void(Person::*method)();
  public:
    Command(Person *obj = nullptr, void(Person::*meth)() = nullptr)
    {
        object = obj;
        method = meth;
    }
    void execute()
    {
        (object->*method)();
    }
};

class Person
{
    string name;
    string person;
    Command cmd;
  public:
    Person(string n, Command c, string p)
    {
        name = n;
        cmd = c;
        person = p;
    }
    void talk()
    {
        cout << name << " is talking" << endl;
        cmd.execute();
    }
    void passOn()
    {
        cout << name << " is passing on with " << person << endl;
        cmd.execute();
    }
    void gossip()
    {
        cout << name << " is gossiping with " << person << endl;
        cmd.execute();
    }
    void listen()
    {
        cout << name << " is listening with " << person << endl;
    }

    void laugh()
    {
        cout << name << " is laughing with " << person << endl;
        cmd.execute();
    }
};

int main()
{
  // Fred will "execute" Barney which will result in a call to passOn()
  // Barney will "execute" Betty which will result in a call to gossip()
  // Betty will "execute" Wilma which will result in a call to listen()
  Person wilma("Wilma", Command(), "Pebbles ");
  Person betty("Betty", Command(&wilma, &Person::listen), "Dino");
  Person barney("Barney", Command(&betty, &Person::gossip), "Bamm-Bamm");
  Person fred("Fred", Command(&barney, &Person::passOn), "Slaghoople");
  Person gazoo("Gazoo", Command(&fred, &Person::laugh), "...");
  gazoo.talk();
}
