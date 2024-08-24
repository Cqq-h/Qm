#pragma once
#include <cmath>
#include <iostream>

namespace Qm
{
    template<size_t S, typename T>
    struct vector;
};

namespace Qm
{
    template<typename T>
    struct vector<2, T>
    {
        union { T x, i; };
        union { T y, j; };

        vector();
        vector(T s);
        vector(const vector<2, T>& u, const vector<2, T>& v);
        vector(T x, T y);

        T dot(const vector<2, T>& other) const;
        T mag() const;
        T mag2() const;

        T cross(const vector<2, T>& other) const;

        T& operator[](uint64_t i);

        vector<2, T> operator*(const T& scale) const;
        vector<2, T>& operator*=(const T& scale);

        vector<2, T> operator+(const vector<2, T>& other) const;
        vector<2, T>& operator+=(const vector<2, T>& other);

        vector<2, T> operator-(const vector<2, T>& other) const;
        vector<2, T>& operator-=(const vector<2, T>& other);

        T operator*(const vector<2, T>& other) const;

        vector<2, T> operator/(T scale) const;
        vector<2, T>& operator/=(T scale);

        bool operator>(const vector<2, T>& other) const;
        bool operator<(const vector<2, T>& other) const;

        bool operator>=(const vector<2, T>& other) const;
        bool operator<=(const vector<2, T>& other) const;

        bool operator==(const vector<2, T>& other) const;
        bool operator!=(const vector<2, T>& other) const;
    };
    using vec2 = vector<2, long double>;
};
template<typename T>
std::ostream& operator<<(std::ostream& out, Qm::vector<2, T> const& data);

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Qm::vector<2, T> const& data)
{
    out << data.x << ", " << data.y;
    return out;
};

namespace Qm
{
    template<typename T>
    struct vector<3, T>
    {
        union { T x, i, r; };
        union { T y, j, g; };
        union { T z, k, b; };

        vector();
        vector(T s);
        vector(const vector<3, T>& u, const vector<3, T>& v);
        vector(T x, T y, T z);

        T dot(const vector<3, T>& other) const;
        T mag() const;
        T mag2() const;

        vector<3, T> cross(const vector<3, T>& other) const;

        T& operator[](uint64_t i);

        vector<3, T> operator*(const T& scale) const;
        vector<3, T>& operator*=(const T& scale);

        vector<3, T> operator+(const vector<3, T>& other) const;
        vector<3, T>& operator+=(const vector<3, T>& other);

        vector<3, T> operator-(const vector<3, T>& other) const;
        vector<3, T>& operator-=(const vector<3, T>& other);

        T operator*(const vector<3, T>& other) const;

        vector<3, T> operator/(T scale) const;
        vector<3, T>& operator/=(T scale);

        bool operator>(const vector<3, T>& other) const;
        bool operator<(const vector<3, T>& other) const;

        bool operator>=(const vector<3, T>& other) const;
        bool operator<=(const vector<3, T>& other) const;

        bool operator==(const vector<3, T>& other) const;
        bool operator!=(const vector<3, T>& other) const;
    };
    using vec3 = vector<3, long double>;
};
template<typename T>
std::ostream& operator<<(std::ostream& out, Qm::vector<3, T> const& data);

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Qm::vector<3, T> const& data)
{
    out << data.x << ", " << data.y << ", " << data.z;
    return out;
};

namespace Qm
{
    template<typename T>
    struct vector<4, T>
    {
        union { T x, r; };
        union { T y, g; };
        union { T z, b; };
        union { T w, a; };

        vector();
        vector(T s);
        vector(const vector<4, T>& u, const vector<4, T>& v);
        vector(T x, T y, T z, T w);

        T dot(const vector<4, T>& other) const;
        T mag() const;
        T mag2() const;

        T& operator[](uint64_t i);

        vector<4, T> operator*(const T& scale) const;
        vector<4, T>& operator*=(const T& scale);

        vector<4, T> operator+(const vector<4, T>& other) const;
        vector<4, T>& operator+=(const vector<4, T>& other);

        vector<4, T> operator-(const vector<4, T>& other) const;
        vector<4, T>& operator-=(const vector<4, T>& other);

        T operator*(const vector<4, T>& other) const;

        vector<4, T> operator/(T scale) const;
        vector<4, T>& operator/=(T scale);

        bool operator>(const vector<4, T>& other) const;
        bool operator<(const vector<4, T>& other) const;

        bool operator>=(const vector<4, T>& other) const;
        bool operator<=(const vector<4, T>& other) const;

        bool operator==(const vector<4, T>& other) const;
        bool operator!=(const vector<4, T>& other) const;
    };
    using vec4 = vector<4, long double>;
};
template<typename T>
std::ostream& operator<<(std::ostream& out, Qm::vector<4, T> const& data);

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Qm::vector<4, T> const& data)
{
    out << data.x << ", " << data.y << ", " << data.z;
    return out;
};

