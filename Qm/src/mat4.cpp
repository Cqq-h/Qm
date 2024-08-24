#include "Matrix.h"

namespace Qm
{
	template<typename T>
	matrix<4, 4, T>::matrix()
	{
		m[0][0] = 1;
		m[1][1] = 1;
		m[2][2] = 1;
		m[3][3] = 1;
	}
	template<typename T>
	matrix<4, 4, T>::matrix(T s)
	{
		m[0][0] = s;
		m[1][1] = s;
		m[2][2] = s;
		m[3][3] = s;
	}

	template<typename T>
	matrix<4, 4, T>::matrix(vector<4, T> v1, vector<4, T> v2, vector<4, T> v3, vector<4, T> v4)
	{
		m[0] = v1;
		m[1] = v2;
		m[2] = v3;
		m[3] = v4;
	}

	template<typename T>
	vector<4, T>& matrix<4, 4, T>::operator[](uint64_t i)
	{
		return m[i];
	}
	template<typename T>
	const vector<4, T>& matrix<4, 4, T>::operator[](uint64_t i) const
	{
		return m[i];
	}

	template<typename T>
	vector<4, T> matrix<4, 4, T>::operator*(vector<4, T> const& other) const
	{

		return vector<4, T>(m[0] * other.x + m[1] * other.y + m[2] * other.z+ m[3] * other.w);
	}

	template<typename T>
	matrix<4, 4, T> matrix<4, 4, T>::operator*(matrix<4, 4, T> const& other) const
	{
		return matrix<4, 4, T>((*this) * other[0], (*this) * other[1], (*this) * other[2], (*this) * other[3]);
	}

	template<typename T>
	matrix<4, 4, T>& matrix<4, 4, T>::operator*=(matrix<4, 4, T> const& other)
	{
		(*this) = (*this) * other;
		return (*this);
	}
	//// Explicit template instantiation
	template struct matrix<4, 4, bool>;
	template struct matrix<4, 4, char>;
	template struct matrix<4, 4, short>;
	template struct matrix<4, 4, float>;
	template struct matrix<4, 4, double>;
	template struct matrix<4, 4, long double>;
	template struct matrix<4, 4, int>;
	template struct matrix<4, 4, long long>;

	template struct matrix<4, 4, unsigned char>;
	template struct matrix<4, 4, unsigned short>;
	template struct matrix<4, 4, unsigned int>;
	template struct matrix<4, 4, unsigned long long>;
}

std::ostream& operator<<(std::ostream& out, Qm::mat4 const& data)
{
	out << "\n" << data[0] << "\n" << data[1] << "\n" << data[2]<< "\n" << data[3];
	return out;
}
