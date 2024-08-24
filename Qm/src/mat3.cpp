#include "Matrix.h"

namespace Qm
{
	template<typename T>
	matrix<3, 3, T>::matrix()
	{
		m[0] = vector<3,T>(1, 0, 0);
		m[1] = vector<3,T>(0, 1, 0);
		m[2] = vector<3,T>(0, 0, 1);
	}
	template<typename T>
	matrix<3, 3, T>::matrix(T s)
	{
		m[0][0] = s;
		m[1][1] = s;
		m[2][2] = s;
	}

	template<typename T>
	matrix<3, 3, T>::matrix(vector<3,T> v1, vector<3,T> v2, vector<3,T> v3)
	{
		m[0] = v1;
		m[1] = v2;
		m[2] = v3;
	}

	template<typename T>
	vector<3,T>& matrix<3,3, T>::operator[](uint64_t i)
	{
		return m[i];
	}
	template<typename T>
	const vector<3,T>& matrix<3, 3, T>::operator[](uint64_t i) const
	{
		return m[i];
	}

	template<typename T>
	vector<3,T> matrix<3, 3, T>::operator*(vector<3,T> const& other) const
	{

		return vector<3,T>(m[0] * other.x + m[1] * other.y + m[2] * other.z);
	}

	template<typename T>
	matrix<3,3,T> matrix<3,3,T>::operator*(matrix<3,3,T> const& other) const
	{
		return matrix<3,3,T>((*this) *other[0], (*this) *other[1], (*this) *other[2]);
	}

	template<typename T>
	matrix<3,3,T>& matrix<3,3,T>::operator*=(matrix<3,3,T> const& other)
	{
		(*this) = (*this) * other;
		return (*this);
	}
	//// Explicit template instantiation
	template struct matrix<3,3,bool>;
	template struct matrix<3,3,char>;
	template struct matrix<3,3,short>;
	template struct matrix<3,3,float>;
	template struct matrix<3,3,double>;
	template struct matrix<3,3,long double>;
	template struct matrix<3,3,int>;
	template struct matrix<3,3,long long>;

	template struct matrix<3,3,unsigned char>;
	template struct matrix<3,3,unsigned short>;
	template struct matrix<3,3,unsigned int>;
	template struct matrix<3,3,unsigned long long>;
}

std::ostream& operator<<(std::ostream& out, Qm::mat3 const& data)
{
	out << "\n" << data[0] << "\n" << data[1] << "\n" << data[2];
	return out;
}
