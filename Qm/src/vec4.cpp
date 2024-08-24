#include "Vector.h"

namespace Qm
{
    template<typename T>
    vector<4, T>::vector() : x(0), y(0), z(0), w(0) {}

    template<typename T>
    vector<4, T>::vector(T s) : x(s), y(s), z(s), w(s) {}

    template<typename T>
    vector<4, T>::vector(const vector<4, T>& u, const vector<4, T>& v) : vector<4, T>(v - u) {}

    template<typename T>
    vector<4, T>::vector(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    template<typename T>
    T vector<4, T>::dot(const vector<4, T>& other) const
    {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    template<typename T>
    T vector<4, T>::mag() const
    {
        return std::sqrt(mag2());
    }

    template<typename T>
    T vector<4, T>::mag2() const
    {
        return dot(*this);
    }

    template<typename T>
    T& vector<4, T>::operator[](uint64_t i)
    {
        switch (i)
        {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            break;
        }
    }

    template<typename T>
    vector<4, T> vector<4, T>::operator*(const T& scale) const
    {
        return vector<4, T>(x * scale, y * scale, z * scale, w * scale);
    }

    template<typename T>
    vector<4, T>& vector<4, T>::operator*=(const T& scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        w *= scale;
        return *this;
    }

    template<typename T>
    vector<4, T> vector<4, T>::operator+(const vector<4, T>& other) const
    {
        return vector<4, T>(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    template<typename T>
    vector<4, T>& vector<4, T>::operator+=(const vector<4, T>& other)
    {
        (*this) = (*this) + other;
        return (*this);
    }

    template<typename T>
    vector<4, T> vector<4, T>::operator-(const vector<4, T>& other) const
    {
        return (*this) + (other * -1.0f);
    }

    template<typename T>
    vector<4, T>& vector<4, T>::operator-=(const vector<4, T>& other)
    {
        (*this) = (*this) - other;
        return (*this);
    }

    template<typename T>
    T vector<4, T>::operator*(const vector<4, T>& other) const
    {
        return dot(other);
    }

    template<typename T>
    vector<4, T> vector<4, T>::operator/(T scale) const
    {
        return vector<4, T>(x / scale, y / scale, z / scale, w / scale);
    }

    template<typename T>
    vector<4, T>& vector<4, T>::operator/=(T scale)
    {
        x /= scale;
        y /= scale;
        z /= scale;
        w /= scale;
        return *this;
    }

    template<typename T>
    bool vector<4, T>::operator>(const vector<4, T>& other) const
    {
        return x > other.x && y > other.y && z > other.z && w > other.w;
    }

    template<typename T>
    bool vector<4, T>::operator<(const vector<4, T>& other) const
    {
        return x < other.x && y < other.y && z < other.z && w < other.w;
    }

    template<typename T>
    bool vector<4, T>::operator>=(const vector<4, T>& other) const
    {
        return x >= other.x && y >= other.y && z >= other.z && w >= other.w;
    }

    template<typename T>
    bool vector<4, T>::operator<=(const vector<4, T>& other) const
    {
        return x <= other.x && y <= other.y && z <= other.z && w <= other.w;
    }

    template<typename T>
    bool vector<4, T>::operator==(const vector<4, T>& other) const
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    template<typename T>
    bool vector<4, T>::operator!=(const vector<4, T>& other) const
    {
        return x != other.x || y != other.y || z != other.z || w != other.w;
    }
    //// Explicit template instantiation

    template struct vector<4, bool>;
    template struct vector<4, char>;
    template struct vector<4, short>;
    template struct vector<4, float>;
    template struct vector<4, double>;
    template struct vector<4, long double>;
    template struct vector<4, int>;
    template struct vector<4, long long>;

    template struct vector<4, unsigned char>;
    template struct vector<4, unsigned short>;
    template struct vector<4, unsigned int>;
    template struct vector<4, unsigned long long>;
}
