#define EXPEREMENTALLIBS
#include "Qm.h"

void quaternions() {
	// Create some quaternion objects
	Qm::quaternion q1(1.0, Qm::vec3(0.0, 1.0, 0.0), true);
	Qm::quaternion q2(0.0, Qm::vec3(1.0, 0.0, 0.0), false);
	Qm::quaternion q3(0.5, 0.5, 0.5, 0.5, true);
	Qm::quaternion q4(QM_PI / 4, 1.0, 0.0, 0.0, true, true);

	// Test magnitude functions
	std::cout << "q1 magnitude: " << q1.mag() << std::endl;
	std::cout << "q2 magnitude squared: " << q2.mag2() << std::endl;

	// Test unit quaternion
	q2.makeUnit();
	std::cout << "q2 after making unit: " << q2 << std::endl;

	// Test multiplication and division by scalar
	Qm::quaternion q5 = q1 * 2.0;
	Qm::quaternion q6 = q1 / 2.0;
	std::cout << "q1 * 2: " << q5 << std::endl;
	std::cout << "q1 / 2: " << q6 << std::endl;

	// Test quaternion multiplication and division
	Qm::quaternion q7 = q1 * q3;
	Qm::quaternion q8 = q1 / q3;
	std::cout << "q1 * q3: " << q7 << std::endl;
	std::cout << "q1 / q3: " << q8 << std::endl;

	// Test conjugate and inverse
	Qm::quaternion q9 = q1.GetConjugate();
	Qm::quaternion q10 = q1.GetInvers();
	std::cout << "q1 conjugate: " << q9 << std::endl;
	std::cout << "q1 inverse: " << q10 << std::endl;

	// Create some rotatian obj objects
	Qm::vec3 v1 = { 1.0,0.0,0.0 };
	Qm::vec3 v2 = { 0.0,1.0,0.0 };
	Qm::vec3 v3 = { 0.0,0.0,1.0 };
	Qm::mat3 m1(1);
	Qm::vec3 axes = { 1.0,0.0,0.0 };
	long double angle = QM_PI / 2.0;


	//rotate vector
	Qm::vec3 vr = Qm::rotate(v1, axes, angle, true);
	std::cout << "rotate v1: " << vr << std::endl;

	//rotate vector
	Qm::vec3 vr2 = Qm::rotate(v2, axes, angle, true);
	std::cout << "rotate v2: " << vr2 << std::endl;

	//rotate vector
	Qm::vec3 vr3 = Qm::rotate(v3, axes, angle, true);
	std::cout << "rotate v3: " << vr3 << std::endl;
	//rotate matrix
	Qm::mat3 mr = Qm::rotate(m1, axes, angle, true);
	std::cout << "rotate m1: " << mr << std::endl;

	//rotate vector with matrix
	Qm::vec3 vrm = mr * v2;
	std::cout << "rotate v1 with m1: " << vrm << std::endl;
}
void vectorMatrixMultiplication()
{
	Qm::vec2 av2 = Qm::vec2(1.0f, 2.0f);
	std::cout << "av2 = " << av2 << std::endl;
	Qm::vec2 bv2 = Qm::vec2(1.0f, 0.0f);
	std::cout << "bv2 = " << bv2 << std::endl;
	Qm::vec3 av3 = Qm::vec3(1.0f, 2.0f, 3.0f);
	std::cout << "av3 = " << av3 << std::endl;
	Qm::vec3 bv3 = Qm::vec3(1.0f, 0.0f, 0.0f);
	std::cout << "bv3 = " << bv3 << std::endl;
	Qm::vec4 av4 = Qm::vec4(1.0f, 2.0f, 3.0f, 4.0f);
	std::cout << "av4 = " << av4 << std::endl;
	Qm::vec4 bv4 = Qm::vec4(3.0f, 2.0f, 1.0f, 0.0f);
	std::cout << "bv4 = " << bv4 << std::endl;

	Qm::mat2 am2 = Qm::mat2(1.0f);
	std::cout << "am2 = " << am2 << std::endl;
	Qm::mat2 bm2 = Qm::mat2(2.0f);
	std::cout << "bm2 = " << bm2 << std::endl;
	Qm::mat3 am3 = Qm::mat3(1.0f);
	std::cout << "am3 = " << am3 << std::endl;
	Qm::mat3 bm3 = Qm::mat3(2.0f);
	std::cout << "bm3 = " << bm3 << std::endl;
	Qm::mat4 am4 = Qm::mat4(1.0f);
	std::cout << "am4 = " << am4 << std::endl;
	Qm::mat4 bm4 = Qm::mat4(2.0f);
	std::cout << "bm4 = " << bm4 << std::endl;

	Qm::quaternion m(QM_PI, 1, 1, 1, 0, 1);
	std::cout << m;
	std::cout << '\n' << "vector multiplication" << std::endl;
	std::cout << "av2 * bv2 = " << av2 * bv2 << std::endl;
	std::cout << "av3 * bv3 = " << av3 * bv3 << std::endl;
	std::cout << "av4 * bv4 = " << av4 * bv4 << std::endl;

	std::cout << '\n' << "matrix multiplication" << std::endl;
	std::cout << "am2 * bm2 = " << am2 * bm2 << std::endl;
	std::cout << "am3 * bm3 = " << am3 * bm3 << std::endl;
	std::cout << "am4 * bm4 = " << am4 * bm4 << std::endl;

	std::cout << '\n' << "matrix vector multiplication" << std::endl;
	std::cout << "am2 * av2 = " << am2 * av2 << std::endl;
	std::cout << "bm2 * bv2 = " << bm2 * bv2 << std::endl;
	std::cout << "am3 * av3 = " << am3 * av3 << std::endl;
	std::cout << "bm3 * bv3 = " << bm3 * bv3 << std::endl;
	std::cout << "am4 * av4 = " << am4 * av4 << std::endl;
	std::cout << "bm4 * bv4 = " << bm4 * bv4 << std::endl;
}
void exsample()

{
	quaternions();
	vectorMatrixMultiplication();
}

int main() {
	exsample();
	return 0;
}