#ifndef WEATHER_H
#define WEATHER_H
#include <string>

using namespace std;


class Weather
{
protected:
    string weatherState;
    string tempState;
    string windState;
    string humidityState;

public:
    Weather();
    Weather(string newWeather, string newTemp, string newWind, string newHumidity);

    string getWeather();
    void setWeather(string q);

    string getTemp();
    void setTemp(string q);

    string getWind();
    void setWind(string q);

    string getHumidity();
    void setHumidity(string q);
};

#endif // WEATHER_H
