#include <QCoreApplication>

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>
#include <ctime>
#include <typeinfo>

using namespace std;

///// converter:
string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

/////// reszta kodu:

class Memento
{
    public:
    virtual string getState() const = 0;
    //virtual char getState2() const = 0;
    virtual ~Memento(){}

};

class ConcreteMemento : public Memento
{
    private:
        string m_state;

    public:
        ConcreteMemento(string state):
            m_state(state)
        {}

        string getState() const{
            return m_state;
        }

};

class Originator
{
    public:
        Originator(string state) :
            m_state(state) {
            cout << "Initial string is: " << m_state << "\n";
            }

        void generateSomething() {
            cout << "Generating random string and date.\n";
            m_state = generateRandomString(20);
            cout << "Generated string and time: " << m_state << "\n";

            }


        void generateTime() //<<- nieudana próba
        {
            cout << "Generating time.\n";
            time_t rawtime;
            struct tm * timeinfo;
            char buffer[80];

            time (&rawtime);
            timeinfo = localtime(&rawtime);

            strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
            string m_state(buffer);
            cout << "Actual time: " << m_state << "\n";
            //cout << typeid(m_state).name() << endl;
            }

        void restore(Memento *memento) {
            m_state = memento->getState();
            //m_state = memento->getState2();
            cout << "Restore changed state to: " << m_state << "\n";
            }
        Memento *mementoSave() {
            return new ConcreteMemento(m_state);
            }

    private:
        string m_state;

        string generateRandomString(int length = 10)
        {
            const char signsContainer[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
            int stringLength = sizeof(signsContainer) - 5;

            string random_string;
            for (int i = 0; i < length; i++) {
              random_string += signsContainer[rand() % stringLength] ;
            }
            time_t rawtime;
            struct tm * timeinfo;
            char buffer[80];

            time (&rawtime);
            timeinfo = localtime(&rawtime);

            strftime(buffer,sizeof(buffer),", %d-%m-%Y %H:%M:%S",timeinfo);
            string time(buffer);

            random_string += time;
            return random_string;
        }


};

class Caretaker
{
    private:
     vector<Memento *> m_mementos;

     Originator *m_originator;

    public:
     Caretaker(Originator *originator) :
         m_originator(originator) {
     }

     void save() {
       cout << "\nSaving state.\n";
       m_mementos.push_back(m_originator->mementoSave());
     }

     void undo() {
       if (!m_mementos.size()) {
         return;
       }
       Memento *memento = m_mementos.back();
       m_mementos.pop_back();
       cout << "Restore state to: " << memento->getState() << "\n";

       m_originator->restore(memento);
     }

     void showHistory() const {
       cout << "Mementos history:\n";
       for (Memento *memento : m_mementos) {
         cout << memento->getState() << "\n";
       }
     }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Originator *originator = new Originator("Initial text!!!!!!!");
    Caretaker *caretaker = new Caretaker(originator);
    caretaker->save();
    originator->generateSomething();
    caretaker->save();
    originator->generateSomething();
    caretaker->save();
    originator->generateSomething();
    caretaker->save();
    originator->generateSomething();
    caretaker->save();



    caretaker->showHistory();

    cout << "Switch back!\n";
    caretaker->undo();
    cout << "Switch back!\n";
    caretaker->undo();
    cout << "Switch back!\n";
    caretaker->undo();
    cout << "Switch back!\n";
    caretaker->undo();


    delete originator;
    delete caretaker;

    return a.exec();
}
