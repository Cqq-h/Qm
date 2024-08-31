#include <iostream>
#include "quaternion.h"

void testQuaternion() {
    // Create some quaternion objects
    Qm::quaternion q1(1.0, Qm::vec3(0.0, 1.0, 0.0), true);
    Qm::quaternion q2(0.0, Qm::vec3(1.0, 0.0, 0.0), false);
    Qm::quaternion q3(0.5, 0.5, 0.5, 0.5, true);
    Qm::quaternion q4(M_PI / 4, 1.0, 0.0, 0.0, true, true);

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
    Qm::vec3 axes = { 1.0,0.0,0.0};
    long double angle = M_PI/2.0;


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

int main() {
    testQuaternion();
    return 0;
}

