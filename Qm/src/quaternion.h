#pragma once
#include "Qm.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

namespace Qm
{
	template <typename T>
	struct quaterniont
	{
		T m_Real;
		vector<3, T> m_Imaginary;

		quaterniont();
		quaterniont(T real, vector<3,T> imaginary, bool unit);
		quaterniont(T angle, vector<3,T> imaginary, bool unit, bool radiants);
		quaterniont(T real, T i, T j, T k, bool unit);
		quaterniont(T angle, T i, T j, T k, bool unit, bool radiants);

		T mag();
		T mag2();

		void makeUnit();
		quaterniont multiply(T const& other);
		quaterniont divide(T const& other);

		quaterniont multiply(quaterniont const& other);
		quaterniont divide(quaterniont const& other);
		quaterniont GetConjugate();
		quaterniont GetInvers();

		quaterniont operator*(T const& other);
		quaterniont operator*(T const& other) const;
		quaterniont operator*=(T const& other);
		quaterniont operator/(T const& other);
		quaterniont operator/(T const& other) const;
		quaterniont operator/=(T const& other);

		quaterniont operator*(quaterniont const& other);
		quaterniont operator*(quaterniont const& other) const;
		quaterniont operator*=(quaterniont const& other);
		quaterniont operator/(quaterniont const& other);
		quaterniont operator/(quaterniont const& other) const;
		quaterniont operator/=(quaterniont const& other);

		inline T i();
		inline T j();
		inline T k();

		inline T i() const;
		inline T j() const;
		inline T k() const;
	private:
		bool m_Unit;
	};

	using quaternion = quaterniont<long double>;
	template <typename T>
	vector<3,T> rotate(vector<3,T> v, vector<3,T> axes, T angle, bool radiants);
	template <typename T>
	matrix<3,3,T> rotate(matrix<3, 3, T> m, vector<3,T> axes, T angle, bool radiants);

	template<typename T>
	vector<3, T> rotate(vector<3, T> v, vector<3, T> axes, T angle, bool radiants)
	{

		quaterniont<T> q(angle / 2.0, axes, true, radiants);
		//std::cout << "\n-------------------------\n" << "q: " << q << "\n-------------------------\n";
		quaterniont<T> qInv(q.GetInvers());
		//std::cout << "qInv: " << qInv << "\n-------------------------\n";
		quaterniont<T> p(0.0, v, false);
		//std::cout << "p: " << p << "\n-------------------------\n";
		//std::cout << "v " << vec3((q * p * qInv).m_Imaginary) << "\n";
		return (q * p * qInv).m_Imaginary;
	}

	template<typename T>
	matrix<3, 3, T> rotate(matrix<3, 3, T> m, vector<3, T> axes, T angle, bool radiants)
	{
		//std::cout << m << '\n';
		return matrix<3, 3, T>(rotate((m[0]), axes, angle, radiants), rotate((m[1]), axes, angle, radiants), rotate((m[2]), axes, angle, radiants));
	}
};
template <typename T>
std::ostream& operator<<(std::ostream& out, Qm::quaterniont<T> const& data);


template<typename T>
std::ostream& operator<<(std::ostream& out, Qm::quaterniont<T>  const& data) {
	out << data.m_Real << "+" << data.i() << "i+" << data.j() << "j+" << data.k() << "k";
	return out;
}