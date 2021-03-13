#include <QCoreApplication>
#include <iostream>
#include "polishweather.h"
#include "weatherlistenerstation.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PolishWeather todaysPolishWeather ("Sunny", "23", "South", "60%");

    Listener *station1 = new WeatherListenerStation(&todaysPolishWeather, 1);
    Listener *station2 = new WeatherListenerStation(&todaysPolishWeather, 2);

    std::cout << "Polish weather: "<<todaysPolishWeather.getWeather() << std::endl;
    std::cout << "Polish temp: "<<todaysPolishWeather.getTemp() << std::endl;
    std::cout << "Polish wind: "<<todaysPolishWeather.getWind() << std::endl;
    std::cout << "Polish humidity: "<<todaysPolishWeather.getHumidity() << std::endl;


    todaysPolishWeather.add(station1);
    todaysPolishWeather.add(station2);

    todaysPolishWeather.setWeatherState("Cloudy");
    todaysPolishWeather.setPolishTemp("16");
    todaysPolishWeather.setPolishWindDirection("East");
    todaysPolishWeather.setPolishAirHumidity("55%");


    std::cout << "Polish weather after: "<<todaysPolishWeather.getWeather() << std::endl;
    std::cout << "Polish temp: "<<todaysPolishWeather.getTemp() << std::endl;
    std::cout << "Polish wind: "<<todaysPolishWeather.getWind() << std::endl;
    std::cout << "Polish humidity: "<<todaysPolishWeather.getHumidity() << std::endl;

    return a.exec();
}
