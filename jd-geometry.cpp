#include <math.h>
#include "jd-geometry.h"

namespace JD {

    double Point::distance(Point a, Point b) {
        return sqrt(pow(a[0]-b[0],2)+
                    pow(a[1]-b[1],2)+
                    pow(a[2]-b[2],2));
    }


    Point Point::translate(Vector v) {
        return Point(this->x() + v.x(),
                     this->y() + v.y(),
                     this->z() + v.z());
    }


    Point operator*(Point a, double f) {
        a *= f;
        return a;
    }


    Point operator*(double f, Point a) {
        return a * f;
    }


    Point &Point::operator*=(double f) {
        this->x() *= f;
        this->y() *= f;
        this->z() *= f;
        return *this;
    }

    Vector::Vector(double x, double y, double z):Point(x,y,z) {
    }
    
    
    Vector::Vector():Point() {
    }
    
    
    double Vector::norm() {
        return sqrt(pow(x(),2) + pow(y(),2) + pow(z(),2));
    }
    
    
    void Vector::normalize() {
        double n = norm();
        coords[0] /= n;
        coords[1] /= n;
        coords[2] /= n;
    }
    
    
    Vector Vector::crossProduct(Vector u, Vector v) {
        Vector r;
        r.setX(u[1]*v[2] - u[2]*v[1]);
        r.setY(u[2]*v[0] - u[0]*v[2]);
        r.setZ(u[0]*v[1] - u[1]*v[0]);
        return r;
    }
    
    
    Vector Vector::crossProduct(Point a, Point b, Point c) {
        Vector ab, ac;
        ab[0] = b[0] - a[0];
        ab[1] = b[1] - a[1];
        ab[2] = b[2] - a[2];
        ac[0] = c[0] - a[0];
        ac[1] = c[1] - a[1];
        ac[2] = c[2] - a[2];
        
        Vector r(ab[1]*ac[2] - ab[2]*ac[1],
                 ab[2]*ac[0] - ab[0]*ac[2],
                 ab[0]*ac[1] - ab[1]*ac[0]);
        return r;
    }
    
    
    double Vector::dotProduct(Vector u, Vector v) {
        return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
    }


    double Vector::cosineSimilarity(Vector u, Vector v) {
        u.normalize();
        v.normalize();
        return dotProduct(u,v);
    }
    
    
    double Quaternion::norm() {
        return sqrt(pow(x,2) + pow(y,2) + pow(z,2) + pow(w,2));
    }
    
    
    void Quaternion::normalize() {
        double n = norm();
        x /= n;
        y /= n;
        z /= n;
        w /= n;
    }
    
    
    Quaternion Quaternion::conjugate() {
        Quaternion r;
        r.w = w;
        r.x = x*-1;
        r.y = y*-1;
        r.z = z*-1;
        return r;
    }
    
    
    Quaternion operator*(Quaternion q, Quaternion r) {
        Quaternion t;
        t.w = r.w * q.w - r.x * q.x - r.y * q.y - r.z * q.z;
        t.x = r.w * q.x + r.x * q.w - r.y * q.z + r.z * q.y;
        t.y = r.w * q.y + r.x * q.z + r.y * q.w - r.z * q.x;
        t.z = r.w * q.z - r.x * q.y + r.y * q.x + r.z * q.w;
        return t;
    }

}
