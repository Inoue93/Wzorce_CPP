#include "weather.h"

Weather::Weather()
{

}
Weather::Weather(string newWeather, string newTemp, string newWind, string newHumidity)
{
    weatherState = newWeather;
    tempState = newTemp;
    windState = newWind;
    humidityState = newHumidity;
}

void Weather::setWeather(string q)
{
    weatherState = q;
}
string Weather::getWeather()
{
    return weatherState;
}

void Weather::setTemp(string q)
{
    tempState = q;
}
string Weather::getTemp()
{
    return tempState;
}

void Weather::setWind(string q)
{
    windState = q;
}
string Weather::getWind()
{
    return windState;
}

void Weather::setHumidity(string q)
{
    humidityState = q;
}
string Weather::getHumidity()
{
    return humidityState;
}
