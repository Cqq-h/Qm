#include "Vector.h"

namespace Qm
{
    template<typename T>
    vector<2, T>::vector() : x(0), y(0) {}
	template<typename T>
	vector<2, T>::vector(T s) : x(s), y(s) {}

    template<typename T>
    vector<2, T>::vector(const vector<2, T>& u, const vector<2, T>& v) : vector<2, T>(v - u) {}
    template<typename T>
    vector<2, T>::vector(T x, T y) : x(x), y(y) { }
    template<typename T>
    T vector<2, T>::dot(const vector<2, T>& other) const
    {
        return x * other.x + y * other.y;
    }

    template<typename T>
    T vector<2, T>::mag() const
    {
        return std::sqrt(mag2());
    }

    template<typename T>
    T vector<2, T>::mag2() const
    {
        return dot(*this);
    }

    template<typename T>
    T vector<2, T>::cross(const vector<2, T>& other) const
    {
        return x * other.y - y * other.x;
    }

    template<typename T>
    T& vector<2, T>::operator[](uint64_t i)
    {
        switch (i)
        {
        case 0:
            return x;
        case 1:
            return y;
        default:
            break;
        }
    }

    template<typename T>
    vector<2, T> vector<2, T>::operator*(const T& scale) const
    {
        return vector<2, T>(x * scale, y * scale);
    }

    template<typename T>
    vector<2, T>& vector<2, T>::operator*=(const T& scale)
    {
        x *= scale;
        y *= scale;
        return *this;
    }

    template<typename T>
    vector<2, T> vector<2, T>::operator+(const vector<2, T>& other) const
    {
        return vector<2, T>(x + other.x, y + other.y);
    }

    template<typename T>
    vector<2, T>& vector<2, T>::operator+=(const vector<2, T>& other)
    {
        (*this) = (*this) + other;
        return (*this);
    }

    template<typename T>
    vector<2, T> vector<2, T>::operator-(const vector<2, T>& other) const
    {
        return (*this) + (other * -1.0f);
    }

    template<typename T>
    vector<2, T>& vector<2, T>::operator-=(const vector<2, T>& other)
    {
        (*this) = (*this) - other;
        return (*this);
    }

    template<typename T>
    T vector<2, T>::operator*(const vector<2, T>& other) const
    {
        return dot(other);
    }

    template<typename T>
    vector<2, T> vector<2, T>::operator/(T scale) const
    {
        return vector<2, T>(x / scale, y / scale);
    }

    template<typename T>
    vector<2, T>& vector<2, T>::operator/=(T scale)
    {
        x /= scale;
        y /= scale;
        return *this;
    }

    template<typename T>
    bool vector<2, T>::operator>(const vector<2, T>& other) const
    {
        return x > other.x && y > other.y;
    }

    template<typename T>
    bool vector<2, T>::operator<(const vector<2, T>& other) const
    {
        return x < other.x && y < other.y;
    }

    template<typename T>
    bool vector<2, T>::operator>=(const vector<2, T>& other) const
    {
        return x >= other.x && y >= other.y;
    }

    template<typename T>
    bool vector<2, T>::operator<=(const vector<2, T>& other) const
    {
        return x <= other.x && y <= other.y;
    }

    template<typename T>
    bool vector<2, T>::operator==(const vector<2, T>& other) const
    {
        return x == other.x && y == other.y;
    }

    template<typename T>
    bool vector<2, T>::operator!=(const vector<2, T>& other) const
    {
        return x != other.x || y != other.y;
    }
    //// Explicit template instantiation

    template struct vector<2, bool>;
    template struct vector<2, char>;
    template struct vector<2, short>;
    template struct vector<2, float>;
    template struct vector<2, double>;
    template struct vector<2, long double>;
    template struct vector<2, int>;
    template struct vector<2, long long>;

    template struct vector<2, unsigned char>;
    template struct vector<2, unsigned short>;
    template struct vector<2, unsigned int>;
    template struct vector<2, unsigned long long>;
};