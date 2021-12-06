#include <iostream>
#include <forward_list>
using namespace std;

struct citizen {
	std::string name;
	int age;
};

std::ostream& operator<<(std::ostream& os, const citizen& c) {
	return(os << "[" << c.name << ", " << c.age << "]");
}

int main(void) {
	std::forward_list<citizen> citizens = { 
		{"kim",28}, {"lee",25}, {"park", 18}, {"jin",16} 
	};

	auto citizens_copy = citizens; // 깊은 복사

	std::cout << " 전체 시민들:";
	for (const auto& c : citizens)
		std::cout << c <<std::endl;
	std::cout << std::endl;

	citizens.remove_if([](const citizen& c) { // 람다식
		return (c.age < 19);
		});

	std::cout << "투표권이 있는 사람들: ";
	for (const auto& c : citizens)
		std::cout << c << " ";
	std::cout << std::endl;

	citizens_copy.remove_if([](const citizen& c) {
		return (c.age != 18); // 18세만 남는다
		});

	std::cout << "내년에 투표권이 생기는 사람들 : ";
	for (const auto& c : citizens_copy)
		std::cout << c << " ";
	std::cout << std::endl;


}