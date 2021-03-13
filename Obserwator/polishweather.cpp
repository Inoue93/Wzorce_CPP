#include "polishweather.h"

PolishWeather::PolishWeather()
{

}
PolishWeather::PolishWeather(string weather, string temp, string wind, string humidity):
    Weather(weather, temp, wind, humidity)
{}

std::string PolishWeather::getPolishWeatherState()
{
    return getWeather();
}

void PolishWeather::setWeatherState(const std:: string & newState)
{
    setWeather(newState);
    std::cout << "New weather state: "<< weatherState << " - start to inform listeners."<< std::endl;
    informWeather();
}

std::string PolishWeather::getPolishTemp()
{
    return getTemp();
}

void PolishWeather::setPolishTemp(const std::string &newState)
{
    setTemp(newState);
    std::cout << "New temp state: "<< tempState << " - start to inform listeners."<< std::endl;
    informTemp();
}

std::string PolishWeather::getPolishWindDirection()
{
    return getWind();
}

void PolishWeather::setPolishWindDirection(const std::string &newState)
{
    setWind(newState);
    std::cout << "New wind state: "<< windState << " - start to inform listeners."<< std::endl;
    informWind();
}

std::string PolishWeather::getPolishAirHumidity()
{
    return getHumidity();
}
void PolishWeather::setPolishAirHumidity(const std:: string & newState)
{
    setHumidity(newState);
    std::cout << "New wind state: "<< humidityState << " - start to inform listeners."<< std::endl;
    informHumidity();
}
