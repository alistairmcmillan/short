#include <math.h>
#include "jd-geometry.h"

namespace JD {

    double Point::distance(Point a, Point b) {
        return sqrt(pow(a[0]-b[0],2)+
                    pow(a[1]-b[1],2)+
                    pow(a[2]-b[2],2));
    }


    Point Point::midpoint(Point a, Point b) {
        return Point((a[0]+b[0]) / 2.0,
                     (a[1]+b[1]) / 2.0,
                     (a[2]+b[2]) / 2.0);
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


    Vector operator*(Vector v, double d) {
        v *= d;
        return v;
    }


    Vector operator*(double d, Vector v) {
        return v * d;
    }


    Point &Point::operator*=(double f) {
        this->x() *= f;
        this->y() *= f;
        this->z() *= f;
        return *this;
    }


    Vector::Vector(double x, double y, double z):Point(x,y,z) {
    }
    
    
    Vector::Vector(Point p):Point(p) {
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


    Vector &Vector::rotate(Vector axis, double angle) {
        double s = sin(angle);
        double c = cos(angle);
        *this = this->perpendicular(axis) * c +
                crossProduct(axis, *this) * s +
                this->parallel(axis);
        return *this;
    }


    Vector &Vector::rotate(Quaternion q) {
        Vector vq(q.x, q.y, q.z);
        Vector v = *this;
        *this += 2.0*crossProduct(vq, crossProduct(vq, v) + q.w * v);
        return *this;
    }


    Vector Vector::perpendicular(Vector axis) {
        return *this - this->parallel(axis);
    }


    Vector Vector::parallel(Vector axis) {
        return axis * dotProduct(*this, axis);
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


    Vector &Vector::operator+=(const Vector other) {
        this->x() += other.x();
        this->y() += other.y();
        this->z() += other.z();
        return *this;
    }


    Vector &Vector::operator-=(const Vector other) {
        this->x() -= other.x();
        this->y() -= other.y();
        this->z() -= other.z();
        return *this;
    }


    Point &Point::operator-=(const Point other) {
        this->x() -= other.x();
        this->y() -= other.y();
        this->z() -= other.z();
        return *this;
    }
    
    
    Point &Point::operator+=(const Point other) {
        this->x() += other.x();
        this->y() += other.y();
        this->z() += other.z();
        return *this;
    }


    Vector operator+(Vector u, Vector v) {
        u += v;
        return u;
    }


    Vector operator-(Vector u, Vector v) {
        u -= v;
        return u;
    }
    
    
    Point operator+(Point a, Point b) {
        a += b;
        return a;
    }
    
    
    Point operator-(Point a, Point b) {
        a -= b;
        return a;
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


    Quaternion Quaternion::getRotationTo(JD::Vector src, JD::Vector dest) {
        JD::Quaternion q;
        
        double d = JD::Vector::dotProduct(src, dest);
        
        if (d >= 1.0f)
        {
            q.x = q.y = q.z = 0;
            q.w = 1;
            return q;
        }
        
        if (d < (1e-6f - 1.0f))
        {
            // Generate an axis
            JD::Vector tmp(1,0,0);
            JD::Vector axis = JD::Vector::crossProduct(tmp, src);
            
            if (axis.norm() == 0.0f)
            {
                tmp[0] = 0;
                tmp[1] = 1;
                tmp[2] = 0;
                axis = JD::Vector::crossProduct(tmp, src);
            }
            
            axis.normalize();
            
            q.x = axis[0]; // ( * sin(pi/2) ) which is 1
            q.y = axis[1];
            q.z = axis[2];
            q.w = 0; // ( cos(pi/2) which is 0
        } else {
            double s = sqrt((1 + d) * 2.0);
            double invs = 1.0 / s;
            
            JD::Vector c = JD::Vector::crossProduct(src, dest);
            
            q.x = (float)(c[0] * invs);
            q.y = (float)(c[1] * invs);
            q.z = (float)(c[2] * invs);
            q.w = (float)(s * 0.5);
            q.normalize();
        }
        
        return q;
    }

}
