#ifndef LIGHTS_H
#define LIGHTS_H


class Lights
{
public:
    Lights();
    void turnOnLights(int dimmingState);
    void turnOffLights();
    int getDimmingState();

    int m_dimmingState;
};

#endif // LIGHTS_H
