//Private Class Data pattern is for encapsulating complex data for a main class

class Color
{
public:
    Color();
};

class Point
{
public:
    Point();
};

class CircleData {
private:
    double radius;
    Color color;
    Point origin;
public:
    CircleData();
    CircleData(double radius, Color color, Point origin) {
        radius = radius;
        color = color;
        origin = origin;
    }
    double Radius() { return radius; }
    Color Color() { return color; }
    Point Origin() { return origin; }
};

class Circle {
private:
    CircleData circleData;
public:
    Circle(double radius, Color color, Point origin) { circleData = CircleData(radius, color, origin); }
    double Circumference() { return (circleData.Radius() * 3.1416f); }
    void Draw() {
        //...
    }
};