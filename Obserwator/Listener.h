#ifndef LISTENER_H
#define LISTENER_H
class Listener
{
    public:
        virtual void updateWeather() = 0;
        virtual void updateWind() = 0;
        virtual void updateTemp() = 0;
        virtual void updateHumidity() = 0;
        virtual ~Listener(){}

};

#endif // LISTENER_H
