#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using unit = unsigned int;

class hash_map {
	std::vector<std::vector<int>> data;

public:
	hash_map(size_t n) {
		data.resize(n);
	}

	void insert(unit value) {
		int n = data.size();
		data[value % n].push_back(value);
		std::cout << value << "�� �����߽��ϴ�." << std::endl;
	}

	bool find(unit value) {
		int n = data.size();
		auto& entries = data[value % n];
		return std::find(entries.begin(), entries.end(), value) != entries.end();
	}

	void erase(int value) {
		int n = data.size();
		auto& entries = data[value % n];
		auto iter = std::find(entries.begin(), entries.end(), value);

		if (iter != entries.end()) {
			entries.erase(iter);
			std::cout << value << "�� �����߽��ϴ�." << std::endl;
		}
	}
};

int main() {
	hash_map map(7);

	auto print = [&](int value) {
		if (map.find(value))
			std::cout << "�ؽ� �ʿ��� " << value << "�� ã�ҽ��ϴ�.";
		else
			std::cout << "�ؽ� �ʿ��� " << value << "�� ã�� ���߽��ϴ�";

		std::cout << std::endl;
	};

	map.insert(2);
	map.insert(25);
	map.insert(10);
	print(25);

	map.insert(100);
	map.insert(55);
	print(100);
	print(2);

	map.erase(2);
}
