#pragma once
#include "Includes.h"
#include "Vector.h"

namespace Qm
{
	template<size_t x, size_t y, typename T>
	struct matrix;
};
namespace Qm
{
	template<typename T>
	struct matrix<2, 2, T>
	{
		vector<2, T> m[2];

		vector<2, T>& operator[](uint64_t i);
		const vector<2, T>& operator[](uint64_t i) const;

		matrix();
		matrix(T s);
		matrix(vector<2, T> v1, vector<2, T> v2);

		vector<2, T> operator*(vector<2, T> const& other) const;
		matrix<2, 2, T> operator*(matrix<2, 2, T> const& other) const;
		matrix<2, 2, T>& operator*=(matrix<2, 2, T> const& other);
	};
	using mat2 = matrix<2, 2, long double>;
};
std::ostream& operator<<(std::ostream& out, Qm::mat2 const& data);

namespace Qm
{
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

namespace Qm
{
	template<typename T>
	struct matrix<4, 4, T>
	{
		vector<4, T> m[4];

		vector<4, T>& operator[](uint64_t i);
		const vector<4, T>& operator[](uint64_t i) const;

		matrix();
		matrix(T s);
		matrix(vector<4, T> v1, vector<4, T> v2, vector<4, T> v3, vector<4, T> v4);

		vector<4, T> operator*(vector<4, T> const& other) const;
		matrix<4, 4, T> operator*(matrix<4, 4, T> const& other) const;
		matrix<4, 4, T>& operator*=(matrix<4, 4, T> const& other);
	};
	using mat4 = matrix<4, 4, long double>;
};
std::ostream& operator<<(std::ostream& out, Qm::mat4 const& data);