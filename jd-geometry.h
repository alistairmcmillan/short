#ifndef JD_GEOMETRY_H
#define JD_GEOMETRY_H

namespace JD {
    class Point;
    class Vector;
    class Quaternion;

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
        double &x() {return coords[0];};
        double &y() {return coords[1];};
        double &z() {return coords[2];};
        double x() const {return coords[0];};
        double y() const {return coords[1];};
        double z() const {return coords[2];};
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
        friend Point operator*(Point a, double f);
        friend Point operator*(double f, Point a);
        Point &operator*=(const double f);
        friend Point operator+(Point a, Point b);
        friend Point operator-(Point a, Point b);
        Point &operator+=(const Point other);
        Point &operator-=(const Point other);
        static double distance(Point a, Point b);
        static Point midpoint(Point a, Point b);
        Point translate(Vector v);
    };
    
    
    class Vector: public Point {

    public:
        Vector(double x, double y, double z);
        Vector(Point p);
        Vector();
        ~Vector() {};
        double norm();
        void normalize();
        Vector &rotate(JD::Vector axis, double angle);
        Vector &rotate(Quaternion q);
        Vector perpendicular(JD::Vector axis);
        Vector parallel(JD::Vector axis);
        static Vector crossProduct(Vector u, Vector v);
        static Vector crossProduct(Point a, Point b, Point c);
        static double dotProduct(Vector u, Vector v);
        static double cosineSimilarity(Vector u, Vector v);
        Vector &operator+=(const Vector other);
        Vector &operator-=(const Vector other);
        friend Vector operator+(Vector u, Vector v);
        friend Vector operator-(Vector u, Vector v);
        friend Vector operator*(Vector v, double d);
        friend Vector operator*(double d, Vector v);
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
        static Quaternion getRotationTo(JD::Vector src, JD::Vector dest);
        Quaternion conjugate();
    };
    
}

#endif
