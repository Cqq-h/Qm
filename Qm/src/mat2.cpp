#include "Matrix.h"

namespace Qm
{
	template<typename T>
	matrix<2, 2, T>::matrix()
	{
		m[0][0] = 1;
		m[1][1] = 1;
	}
	template<typename T>
	matrix<2, 2, T>::matrix(T s)
	{
		m[0][0] = s;
		m[1][1] = s;
	}

	template<typename T>
	matrix<2, 2, T>::matrix(vector<2, T> v1, vector<2, T> v2)
	{
		m[0] = v1;
		m[1] = v2;
	}

	template<typename T>
	vector<2, T>& matrix<2, 2, T>::operator[](uint64_t i)
	{
		return m[i];
	}
	template<typename T>
	const vector<2, T>& matrix<2, 2, T>::operator[](uint64_t i) const
	{
		return m[i];
	}

	template<typename T>
	vector<2, T> matrix<2, 2, T>::operator*(vector<2, T> const& other) const
	{

		return vector<2, T>(m[0] * other.x + m[1] * other.y);
	}

	template<typename T>
	matrix<2, 2, T> matrix<2, 2, T>::operator*(matrix<2, 2, T> const& other) const
	{
		return matrix<2, 2, T>((*this) * other[0], (*this) * other[1]);
	}

	template<typename T>
	matrix<2, 2, T>& matrix<2, 2, T>::operator*=(matrix<2, 2, T> const& other)
	{
		(*this) = (*this) * other;
		return (*this);
	}
	//// Explicit template instantiation
	template struct matrix<2, 2, bool>;
	template struct matrix<2, 2, char>;
	template struct matrix<2, 2, short>;
	template struct matrix<2, 2, float>;
	template struct matrix<2, 2, double>;
	template struct matrix<2, 2, long double>;
	template struct matrix<2, 2, int>;
	template struct matrix<2, 2, long long>;

	template struct matrix<2, 2, unsigned char>;
	template struct matrix<2, 2, unsigned short>;
	template struct matrix<2, 2, unsigned int>;
	template struct matrix<2, 2, unsigned long long>;
}

std::ostream& operator<<(std::ostream& out, Qm::mat2 const& data)
{
	out << "\n" << data[0] << "\n" << data[1];
	return out;
}
