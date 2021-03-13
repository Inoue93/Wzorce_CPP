#ifndef AIRCONDITION_H
#define AIRCONDITION_H


class AirCondition
{
    int m_airTemp;
public:
    AirCondition();
    void turnAirConditionON();
    void setAirTemp(int newTemp);
    int getAirTemp();
};

#endif // AIRCONDITION_H
