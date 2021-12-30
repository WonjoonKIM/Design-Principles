#include <iostream>
#include <vector>
using unit = unsigned int;

class hash_map {
	std::vector<int> data;

public:
	hash_map(size_t n) {
		data = std::vector<int>(n, -1); // 데이터를 모두 -1로 초기화했습니다.-1은 해당 위치에 저장된 원소가 없음을 의미합니다.
}
	void insert(unit value) {
		int n = data.size();
		data[value % n] = value; // 해시 값이 중복되면 나중에 삽입한 값만 저장됩니다.
		std::cout << value << "을 삽입했습니다." << std::endl;
	}

	bool find(unit value) {
		int n = data.size();
		return (data[value % n] == value);
	}

	bool erase(unit value) {
		int n = data.size();
		if (data[value % n] == value) {
			data[value % n] = -1;
			std::cout << value << "을 삭제했습니다." << std::endl;
		}
	}
};

int main() {
	hash_map map(7);

	auto print = [&](int value) {
		if (map.find(value))
			std::cout << "해시 맵에서" << value << "을 찾았습니다.";
		else
			std::cout << "해시 맵에서" << value << "을 찾지 못했습니다";

		std::cout << std::endl;
	};

	map.insert(2);
	map.insert(25);
	map.insert(10);
	print(25);

	map.insert(100);
	print(100);
	print(2);

	map.erase(25);
}