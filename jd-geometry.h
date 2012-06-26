#ifndef JD_GEOMETRY_H
#define JD_GEOMETRY_H

class Point {
protected:
    double coords[3];

public:
    Point(double x, double y, double z) {
        setX(x);
        setY(y);
        setZ(z);
    };
    Point() {
        setX(0);
        setY(0);
        setZ(0);
    }
    ~Point() {};
    double x() {return coords[0];};
    double y() {return coords[1];};
    double z() {return coords[2];};
    void setX(double x) {
        coords[0] = x;
    };
    void setY(double y) {
        coords[1] = y;
    };
    void setZ(double z) {
        coords[2] = z;
    };
    double &operator[](unsigned int x) {
        return coords[x];
    }
    bool operator==(const Point &rhs) {
        return coords[0] == rhs.coords[0] && coords[1] == rhs.coords[1] && coords[2] == rhs.coords[2];
    }
};


class Vector: public Point {

public:
    Vector(double x, double y, double z);
    Vector();
    ~Vector() {};
    double norm();
    void normalize();
    static Vector crossProduct(Vector u, Vector v);
    static Vector crossProduct(Point a, Point b, Point c);
    static double dotProduct(Vector u, Vector v);
};


class Quaternion {    
public:
    double w,x,y,z;

    Quaternion(double aw, double ax, double ay, double az) {
        w=aw;
        x=ax;
        y=ay;
        z=az;
    }
    Quaternion() {
        w=x=y=z=0;
    }
    ~Quaternion() {};
    double norm();
    void normalize();
    friend Quaternion operator*(Quaternion q, Quaternion r);
    Quaternion conjugate();
};


#endif
