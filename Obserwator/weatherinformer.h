#ifndef WEATHERINFORMER_H
#define WEATHERINFORMER_H
#include "Listener.h"
#include "Weather2.h"
#include "Temp.h"
#include "Wind.h"
#include "Humidity.h"
#include <list>


class WeatherInformer
{
protected:
    std::list <Listener *> listeners;
    std::list <Weather2 *> weather2;
    std::list <Temp*> temp;
    std::list <Wind*> wind;
    std::list <Humidity*> humidity;

public:
    WeatherInformer();
    void add(Listener *o);
    void remove(Listener *o);
    //dodane
    void add(Weather2 *o);
    void remove(Weather2 *o);
    void add(Temp *o);
    void remove(Temp *o);
    void add(Wind *o);
    void remove(Wind *o);
    void add(Humidity *o);
    void remove(Humidity *o);


    void informListeners();
    void informWeather();
    void informTemp();
    void informWind();
    void informHumidity();

};

#endif // WEATHERINFORMER_H
