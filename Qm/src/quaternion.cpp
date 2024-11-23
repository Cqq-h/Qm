#include "Quaternion.h"

namespace Qm
{
	template <typename T>
	quaterniont<T>::quaterniont() :m_Real(1), m_Imaginary(0), m_Unit(false)
	{}

	template <typename T>
	quaterniont<T>::quaterniont(T real, vector<3, T>  imaginary, bool unit)
		: m_Real(real), m_Imaginary(imaginary), m_Unit(unit)
	{
		if (m_Unit)
			makeUnit();
	}

	template <typename T>
	quaterniont<T>::quaterniont(T angle, vector<3, T>  imaginary, bool unit, bool radiants)
	{
		(*this) = quaterniont<T>(angle, imaginary.i, imaginary.j, imaginary.k, unit, radiants);
	}

	template<typename T>
	quaterniont<T>::quaterniont(T real, T i, T j, T k, bool unit) 
		: m_Real(real), m_Imaginary(i, j, k), m_Unit(unit)
	{
		if (m_Unit)
			makeUnit();
	}

	template<typename T>
	quaterniont<T>::quaterniont(T angle, T i, T j, T k, bool unit, bool radiants) 
		:m_Real(1), m_Imaginary(i, j, k), m_Unit(true)
	{
		float tempa;
		if (radiants == true)
		{
			tempa = angle;
		}
		else
		{
			tempa = (angle / 180) * QM_PI;
		}
		m_Real = std::cos(tempa);
		m_Imaginary = (vector<3, T>(i, j, k) / vector<3, T>(i, j, k).mag()) * std::sin(tempa);
	}

	template<typename T>
	T quaterniont<T>::mag()
	{
		return std::sqrt(mag2());
	}

	template<typename T>
	T quaterniont<T>::mag2()
	{
		return m_Real * m_Real + m_Imaginary.mag2();
	}

	template<typename T>
	void quaterniont<T>::makeUnit()
	{
		(*this) /= mag();
		if (m_Real == -0.0)
			m_Real = 0;
		if (m_Imaginary.i == -0.0)
			m_Imaginary.i = 0;
		if (m_Imaginary.j == -0.0)
			m_Imaginary.j = 0;
		if (m_Imaginary.k == -0.0)
			m_Imaginary.k = 0;
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::multiply(T const& other)
	{
		return quaterniont(m_Real * other, m_Imaginary * other, false);
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::divide(T const& other)
	{
		return quaterniont(multiply(1 / other));
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::multiply(quaterniont const& other)
	{
		T real = m_Real * other.m_Real
			- i() * other.i()
			- j() * other.j()
			- k() * other.k();
		T iHat = m_Real * other.i()
			+ i() * other.m_Real
			+ j() * other.k()
			- k() * other.j();
		T jHat = m_Real * other.j()
			+ j() * other.m_Real
			- i() * other.k()
			+ k() * other.i();
		T kHat = m_Real * other.k()
			+ k() * other.m_Real
			+ i() * other.j()
			- j() * other.i();
		return quaterniont(real, iHat, jHat, kHat, m_Unit * other.m_Unit);
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::divide(quaterniont const& other)
	{
		return multiply(GetInvers());
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::GetConjugate()
	{
		return quaterniont<T>(m_Real, -i(), -j(), -k(), m_Unit);
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::GetInvers()
	{
		return (GetConjugate() / mag2());
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator*(T const& other)
	{
		return multiply(other);
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator*(T const& other) const
	{
		quaterniont temp((*this) * other);
		return quaterniont(temp);
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator*=(T const& other)
	{
		(*this) = (*this) * other;
		return quaterniont((*this));
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator/(T const& other)
	{
		return quaterniont(divide(other));
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator/(T const& other) const
	{
		quaterniont temp((*this) / other);
		return quaterniont(temp);
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator/=(T const& other)
	{
		(*this) = (*this) / other;
		return quaterniont((*this));
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator*(quaterniont const& other)
	{
		return quaterniont(multiply(other));
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator*(quaterniont const& other) const
	{
		quaterniont temp((*this) * other);
		return quaterniont(temp);
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator*=(quaterniont const& other)
	{
		(*this) = (*this) * other;
		return quaterniont((*this));
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator/(quaterniont const& other)
	{
		return quaterniont(divide(other));
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator/(quaterniont const& other) const
	{
		quaterniont temp((*this) / other);
		return quaterniont(temp);
	}

	template<typename T>
	quaterniont<T> quaterniont<T>::operator/=(quaterniont const& other)
	{
		(*this) = (*this) / other;
		return quaterniont((*this));
	}

	template<typename T>
	T quaterniont<T>::i()
	{
		return m_Imaginary.i;
	}

	template<typename T>
	T quaterniont<T>::j()
	{
		return m_Imaginary.j;
	}

	template<typename T>
	T quaterniont<T>::k()
	{
		return m_Imaginary.k;
	}

	template<typename T>
	T quaterniont<T>::i() const
	{
		return m_Imaginary.i;
	}

	template<typename T>
	T quaterniont<T>::j() const
	{
		return m_Imaginary.j;
	}

	template<typename T>
	T quaterniont<T>::k() const
	{
		return m_Imaginary.k;
	}


	template struct quaterniont<bool>;
	template struct quaterniont<char>;
	template struct quaterniont<short>;
	template struct quaterniont<float>;
	template struct quaterniont<double>;
	template struct quaterniont<long double>;
	template struct quaterniont<int>;
	template struct quaterniont<long long>;
					
	template struct quaterniont<unsigned char>;
	template struct quaterniont<unsigned short>;
	template struct quaterniont<unsigned int>;
	template struct quaterniont<unsigned long long>;
};