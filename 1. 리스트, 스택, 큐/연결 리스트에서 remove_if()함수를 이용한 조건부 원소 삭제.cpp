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

	auto citizens_copy = citizens; // ���� ����

	std::cout << " ��ü �ùε�:";
	for (const auto& c : citizens)
		std::cout << c <<std::endl;
	std::cout << std::endl;

	citizens.remove_if([](const citizen& c) { // ���ٽ�
		return (c.age < 19);
		});

	std::cout << "��ǥ���� �ִ� �����: ";
	for (const auto& c : citizens)
		std::cout << c << " ";
	std::cout << std::endl;

	citizens_copy.remove_if([](const citizen& c) {
		return (c.age != 18); // 18���� ���´�
		});

	std::cout << "���⿡ ��ǥ���� ����� ����� : ";
	for (const auto& c : citizens_copy)
		std::cout << c << " ";
	std::cout << std::endl;


}