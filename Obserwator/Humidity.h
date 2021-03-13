#ifndef HUMIDITY_H
#define HUMIDITY_H

class Humidity
{
    public:
        virtual void updateHumidity() = 0;
        virtual ~Humidity(){}
};

#endif // HUMIDITY_H
