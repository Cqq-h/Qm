#include "Vector.h"

namespace Qm
{
    template<typename T>
    vector<3,T>::vector() : x(0), y(0), z(0) {}

    template<typename T>
    vector<3,T>::vector(T s) : x(s), y(s), z(s) {}

    template<typename T>
    vector<3, T>::vector(const vector<3, T>& u, const vector<3, T>& v) : vector<3, T>(v - u) {}

    template<typename T>
    vector<3,T>::vector(T x, T y, T z) : x(x), y(y), z(z) {}

    template<typename T>
    T vector<3,T>::dot(const vector<3,T>& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }
    template<typename T>
    T vector<3,T>::mag() const
    {
        return std::sqrt(mag2());
    }

    template<typename T>
    T vector<3,T>::mag2() const
    {
        return dot(*this);
    }

    template<typename T>
    vector<3, T> vector<3, T>::cross(const vector<3, T>& other) const
    {
        return vector<3, T>(y * other.z -z * other.y, x * other.z - z * other.x,y * other.x - z*other.x);
    }

    template<typename T>
    T& vector<3,T>::operator[](uint64_t i)
    {
        switch (i)
        {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            break;
        }
    }

    template<typename T>
    vector<3,T> vector<3,T>::operator*(const T& scale) const
    {
        return vector<3,T>(x * scale, y * scale, z * scale);
    }

    template<typename T>
    vector<3,T>& vector<3,T>::operator*=(const T& scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        return *this;
    }

    template<typename T>
    vector<3,T> vector<3,T>::operator+(const vector<3,T>& other) const
    {
        return vector<3,T>(x+other.x, y+other.y, z+other.z);
    }

    template<typename T>
    vector<3,T>& vector<3,T>::operator+=(const vector<3,T>& other)
    {
        (*this) = (*this) + other;
        return (*this);
    }

    template<typename T>
    vector<3,T> vector<3,T>::operator-(const vector<3,T>& other) const
    {
        return (*this) + (other*-1.0f);
    }

    template<typename T>
    vector<3,T>& vector<3,T>::operator-=(const vector<3,T>& other)
    {
        (*this) = (*this) - other;
		return (*this);
    }

    template<typename T>
    T vector<3,T>::operator*(const vector<3,T>& other) const
    {
        return dot(other);
    }

    template<typename T>
    vector<3,T> vector<3,T>::operator/(T scale) const
    {
        return vector<3,T>(x / scale, y / scale, z / scale);
    }

    template<typename T>
    vector<3,T>& vector<3,T>::operator/=(T scale)
    {
        x /= scale;
        y /= scale;
        z /= scale;
        return *this;
    }

    template<typename T>
    bool vector<3, T>::operator>(const vector<3, T>& other) const
    {
        return x>other.x && y>other.y && z>other.z;
    }

    template<typename T>
    bool vector<3, T>::operator<(const vector<3, T>& other) const
    {
        return x<other.x && y<other.y && z<other.z;
    }

    template<typename T>
    bool vector<3, T>::operator>=(const vector<3, T>& other) const
    {
        return x>=other.x && y>=other.y && z>=other.z;
    }

    template<typename T>
    bool vector<3, T>::operator<=(const vector<3, T>& other) const
    {
        return x<=other.x && y<=other.y && z<=other.z;
    }

    template<typename T>
    bool vector<3, T>::operator==(const vector<3, T>& other) const
    {
        return x==other.x && y==other.y && z==other.z;
    }

    template<typename T>
    bool vector<3, T>::operator!=(const vector<3, T>& other) const
    {
        return x!=other.x || y!=other.y || z!=other.z;
    }
    //// Explicit template instantiation
    
    template struct vector<3,bool>;
    template struct vector<3,char>;
    template struct vector<3,short>;
    template struct vector<3,float>;
    template struct vector<3,double>;
    template struct vector<3,long double>;
    template struct vector<3,int>;
    template struct vector<3,long long>;
                           
    template struct vector<3,unsigned char>;
    template struct vector<3,unsigned short>;
    template struct vector<3,unsigned int>;
    template struct vector<3,unsigned long long>;
}
