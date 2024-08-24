#pragma once
#include "Vector.h"

namespace Qm
{
	template<size_t x,size_t y, typename T>
	struct matrix;
	template<typename T>
	struct matrix<3, 3, T>
	{
		vector<3, T> m[3];

		vector<3, T>& operator[](uint64_t i);
		const vector<3, T>& operator[](uint64_t i) const;

		matrix();
		matrix(T s);
		matrix(vector<3, T> v1, vector<3, T> v2, vector<3, T> v3);

		vector<3, T> operator*(vector<3, T> const& other) const;
		matrix<3,3,T> operator*(matrix<3,3,T> const& other) const;
		matrix<3,3,T>& operator*=(matrix<3,3,T> const& other);
	};
	using mat3 = matrix<3,3,long double>;
};
std::ostream& operator<<(std::ostream& out, Qm::mat3 const& data);