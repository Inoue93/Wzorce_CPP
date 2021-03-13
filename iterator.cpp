#include <QCoreApplication>
#include <iostream>

using namespace std;

class ObjectsIterator;

class ObjectsTable
{
    int count[10];
    int index;
  public:
    friend class ObjectsIterator;
    ObjectsTable()
    {
        index = -1;
    }
    void add(int in)
    {
        count[++index] = in;
    }
    int rem()
    {
        return count[index--];
    }

    bool isEmpty()
    {
        return (index == -1);
    }

     ObjectsIterator *createIter() const;


};

class ObjectsIterator
{
    const ObjectsTable * objPtr;
    int index;

    public:

    ObjectsIterator(const ObjectsTable *s)
    {
        objPtr = s;
    }
    void first()
    {
        index = 0;
    }
    int currentIndex()
    {
        return index;
    }

    void next()
    {
        index++;
    }
    void prev()
    {
        index--;
    }
    bool isDone()
    {
        return index == objPtr->index + 1; //index dla pointera jes zawsze o 1 mniejszy, bo zaczynamy od -1
    }
    int currentItem()
    {
        return objPtr->count[index];
    }

};

ObjectsIterator *ObjectsTable::createIter() const
{
    return new ObjectsIterator(this);
}

bool operator == (const ObjectsTable &l,  const ObjectsTable &r)
{
    ObjectsIterator *itl = l.createIter();
    ObjectsIterator *itr = r.createIter();

    for(itl->first(), itr->first(); !itl->isDone(); itl->next(), itr->next())
    {
        if(itl->currentItem() != itr->currentItem())
            break;
    }

    bool ret = itl->isDone() && itr->isDone();
    delete itl;
    delete itr;
    return ret;
}

bool operator != (const ObjectsTable &l,  const ObjectsTable &r)
{
    ObjectsIterator *itl = l.createIter();
    ObjectsIterator *itr = r.createIter();

    for(itl->first(), itr->first(); !itl->isDone() or !itr->isDone(); itl->next(), itr->next())
    {
        if(itl->currentItem() != itr->currentItem())
            break;
    }

    bool ret = !(itl->isDone() && itr->isDone());
    delete itl;
    delete itr;
    return ret;
}

bool operator >= (const ObjectsTable &l,  const ObjectsTable &r) //porównanie długości
{
    ObjectsIterator *itl = l.createIter();
    ObjectsIterator *itr = r.createIter();

    itl->first(), itr->first();

    while(!itl->isDone() and !itr->isDone())
    {
        itl->next();
        itr->next();
    }

    bool ret = !(itl->isDone() && !itr->isDone()) ;
    delete itl;
    delete itr;
    return ret;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ObjectsTable s1;
    for(int i=1; i<5; i++)
        s1.add(i);

    ObjectsTable s2(s1), s3(s1), s4(s1), s5(s1);
    s3.rem();
    s5.rem();
    s4.add(2);
    s5.add(9);


    cout << "1 != 2 is "<<(s1 != s2)<<endl;
    cout << "1 != 3 is "<<(s1 != s3)<<endl;
    cout << endl;
    cout << "1 == 2 is "<<(s1 == s2)<<endl;
    cout << "1 == 3 is "<<(s1 == s3)<<endl;
    cout << endl;
    cout << "3 >= 1 is "<<(s3 >= s1)<<endl;
    cout << "1 >= 3 is "<<(s1 >= s3)<<endl;
    cout << "1 >= 2 is "<<(s2 >= s1)<<endl;



    return a.exec();
}
