#include "Qm.h"

void exsample()
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

}

int main() {
	exsample();
	return 0;
}