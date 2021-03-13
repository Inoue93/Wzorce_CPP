#ifndef WEATHERLISTENERSTATION_H
#define WEATHERLISTENERSTATION_H

#include "Listener.h"
#include "polishweather.h"


class WeatherListenerStation : public Listener
{
protected:
    int stationId;
    PolishWeather* pWeather;
public:
    WeatherListenerStation();
    WeatherListenerStation(PolishWeather *h, int id);

    void updateWeather();
    void updateTemp();
    void updateWind();
    void updateHumidity();
};

#endif // WEATHERLISTENERSTATION_H
