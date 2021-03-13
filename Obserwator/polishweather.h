#ifndef POLISHWEATHER_H
#define POLISHWEATHER_H
#include "weather.h"
#include "weatherinformer.h"
#include <string>
#include <iostream>


class PolishWeather: public Weather, public WeatherInformer
{
public:
    PolishWeather();
    PolishWeather(string weather, string temp, string wind, string humidity);

    std::string getPolishWeatherState();
    void setWeatherState(const std:: string & newState);

    std::string getPolishTemp();
    void setPolishTemp(const std:: string & newState);

    std::string getPolishWindDirection();
    void setPolishWindDirection(const std:: string & newState);

    std::string getPolishAirHumidity();
    void setPolishAirHumidity(const std:: string & newState);

};

#endif // POLISHWEATHER_H
