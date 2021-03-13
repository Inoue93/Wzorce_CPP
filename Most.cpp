#include <QCoreApplication>
#include <iostream>

using namespace std;

class DrawingApi
{
public:
    virtual void DrawCircle(const double x, const double y, const double radius) = 0;
    virtual void DrawSquare(const double x, const double y) = 0;
    virtual void DrawTriangle(const double x, const double y, const double z) = 0;
    virtual ~DrawingApi(){}

};

class OpenGL : public DrawingApi
{
    public:
    void DrawCircle(const double x, const double y, const double radius)
    {
        cout<<"OpenGL based circle drawn at "<<x<<":"<<y<<" radius: "<<radius<<endl;
    }
    void DrawSquare(const double x, const double y)
    {
        cout<<"OpenGL based square drawn at "<<x<<":"<<y<<endl;
    }
    void DrawTriangle(const double x, const double y, const double z)
    {
        cout<<"OpenGL based triangle drawn at "<<x<<":"<<y<<":"<<z<<endl;
    }
};

class DirectX : public DrawingApi
{
    public:
    void DrawCircle(const double x, const double y, const double radius)
    {
        cout<<"DirectX based circle drawn at "<<x<<":"<<y<<" radius: "<<radius<<endl;
    }
    void DrawSquare(const double x, const double y)
    {
        cout<<"DirectX based square drawn at "<<x<<":"<<y<<endl;
    }
    void DrawTriangle(const double x, const double y, const double z)
    {
        cout<<"DirectX based triangle drawn at "<<x<<":"<<y<<":"<<z<<endl;
    }
};

class WebGL : public DrawingApi
{
public:
    void DrawCircle(const double x, const double y, const double radius)
    {
        cout<<"WebGL based circle drawn at "<<x<<":"<<y<<" radius: "<<radius<<endl;
    }
    void DrawSquare(const double x, const double y)
    {
        cout<<"WebGL based square drawn at "<<x<<":"<<y<<endl;
    }
    void DrawTriangle(const double x, const double y, const double z)
    {
        cout<<"WebGL based triangle drawn at "<<x<<":"<<y<<":"<<z<<endl;
    }
};

class Shape
{
    public:
        Shape(double x, double y, double radius, DrawingApi* da):
            m_xPos(x), m_yPos(y), m_radius(radius), m_drawingApi(da)
        {}
        Shape(double x, double y, DrawingApi* da):
            m_xPos(x), m_yPos(y), m_drawingApi(da)
        {}
        Shape(DrawingApi* da,double x, double y, double z):
            m_drawingApi(da), m_xPos(x), m_yPos(y), m_zPos(z)
        {}

    virtual void Draw() = 0;
        virtual ~Shape(){}


    protected:

    void DrawCirlce()
    {
        m_drawingApi->DrawCircle(m_xPos, m_yPos, m_radius);
    }
    void DrawSquare()
    {
        m_drawingApi->DrawSquare(m_xPos, m_yPos);
    }
    void DrawTriangle()
    {
        m_drawingApi->DrawTriangle( m_xPos, m_yPos, m_zPos);
    }
    double m_xPos, m_yPos, m_zPos, m_radius;
    DrawingApi *m_drawingApi;
};

class Circle : public Shape
{
    public:
    Circle(double x, double y, double radius, DrawingApi* drawinApi):
        Shape(x, y, radius, drawinApi)
    {}

    void Draw()
    {
        DrawCirlce();
    }
};
class Square : public Shape
{
    public:
    Square(double x, double y, DrawingApi* drawinApi):
        Shape(x, y, drawinApi)
    {}

    void Draw()
    {
        DrawSquare();
    }
};
class Triangle : public Shape
{
    public:
    Triangle(double x, double y, double z, DrawingApi* drawinApi):
        Shape(x, y, z, drawinApi)
    {}

    void Draw()
    {
        DrawTriangle();
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Shape* p_shapes[9];
    DrawingApi* p_drawingApiOpenGL = new OpenGL();
    DrawingApi* p_drawingApiDirectX = new DirectX();
    DrawingApi* p_drawingApiWebGL = new WebGL();

    p_shapes[0] = new Circle(1,2,7.5, p_drawingApiOpenGL);
    p_shapes[0]->Draw();

    p_shapes[1] = new Circle(5,7,27.5, p_drawingApiDirectX);
    p_shapes[1]->Draw();

    p_shapes[6] = new Circle(2,4,15, p_drawingApiWebGL);
    p_shapes[6]->Draw();

    p_shapes[2] = new Square(10,14, p_drawingApiOpenGL);
    p_shapes[2]->Draw();

    p_shapes[3] = new Square(2.9, 80, p_drawingApiDirectX);
    p_shapes[3]->Draw();

    p_shapes[7] = new Square(5, 14.5, p_drawingApiWebGL);
    p_shapes[7]->Draw();

    p_shapes[4] = new Triangle(2.5,3,4,p_drawingApiOpenGL);
    p_shapes[4]->Draw();

    p_shapes[5] = new Triangle(5,6,8,p_drawingApiDirectX);
    p_shapes[5]->Draw();

    p_shapes[8] = new Triangle(10,12,16,p_drawingApiWebGL);
    p_shapes[8]->Draw();


    return a.exec();
}
