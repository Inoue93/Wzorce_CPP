#include "weatherinformer.h"

WeatherInformer::WeatherInformer()
{

}

void WeatherInformer::add(Listener *o)
{
    listeners.push_back(o);
}

void WeatherInformer::remove(Listener *o)
{
    listeners.remove(o);
}
void WeatherInformer::informListeners()
{
    std::list<Listener*>::iterator it;
    for(it = listeners.begin(); it!= listeners.end(); it++)
    {
        (*it)->updateWeather();
        (*it)->updateTemp();
        (*it)->updateWind();
        (*it)->updateHumidity();
    }
}
//dodane:
//weatcher:
void WeatherInformer::add(Weather2 *o)
{
    weather2.push_back(o);
}

void WeatherInformer::remove(Weather2 *o)
{
    weather2.remove(o);
}

void WeatherInformer::informWeather()
{
    std::list<Weather2*>::iterator it;
    for(it = weather2.begin(); it!= weather2.end(); it++)
    {
        (*it)->updateWeather2();
    }
}
//temp:
void WeatherInformer::add(Temp *o)
{
    temp.push_back(o);
}

void WeatherInformer::remove(Temp *o)
{
    temp.remove(o);
}

void WeatherInformer::informTemp()
{
    std::list<Temp*>::iterator it;
    for(it = temp.begin(); it!= temp.end(); it++)
    {
        (*it)->updateTemp();
    }
}
//wind:
void WeatherInformer::add(Wind *o)
{
    wind.push_back(o);
}

void WeatherInformer::remove(Wind *o)
{
    wind.remove(o);
}
void WeatherInformer::informWind()
{
    std::list<Wind*>::iterator it;
    for(it = wind.begin(); it!= wind.end(); it++)
    {
        (*it)->updateWind();
    }
}
//humidity:
void WeatherInformer::add(Humidity *o)
{
    humidity.push_back(o);
}

void WeatherInformer::remove(Humidity *o)
{
    humidity.remove(o);
}
void WeatherInformer::informHumidity()
{
    std::list<Humidity*>::iterator it;
    for(it = humidity.begin(); it!= humidity.end(); it++)
    {
        (*it)->updateHumidity();
    }
}
