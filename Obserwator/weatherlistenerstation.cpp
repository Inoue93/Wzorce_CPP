#include "weatherlistenerstation.h"

WeatherListenerStation::WeatherListenerStation()
{

}
WeatherListenerStation::WeatherListenerStation(PolishWeather *h, int id)
{
    pWeather = h;
    stationId = id;
}

void WeatherListenerStation::updateWeather()
{
    std::cout << "Weather station: "<<stationId <<" -weather is: "<<pWeather->getPolishWeatherState()<<std::endl;
}
void WeatherListenerStation::updateTemp()
{
    std::cout << "Weather station: "<<stationId <<" -temp is: "<<pWeather->getPolishTemp()<<std::endl;
}

void WeatherListenerStation::updateWind()
{
    std::cout << "Weather station: "<<stationId <<" -wind is: "<<pWeather->getPolishWindDirection()<<std::endl;
}
void WeatherListenerStation::updateHumidity()
{
     std::cout << "Weather station: "<<stationId <<" -humidity is: "<<pWeather->getPolishAirHumidity()<<std::endl;
}
