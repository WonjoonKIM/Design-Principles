#include <iostream>
#include <vector>

class bloom_filter {
	std::vector<bool> data;
	int nBits;

	int hash(int num, int key) { // 단순한 해시 함수를 선언했습니다.
		switch (num) {
		case 0: return key % nBits;
		case 1: return (key / 7) % nBits;
		case 2: return (key / 11) % nBits;
		}
		return 0;
	}

public : 
	bloom_filter(int n) : nBits(n) { // 블룸 필터의 생성자
		data = std::vector<bool>(nBits, false);
	}

	void lookup(int key) {
		bool result = data[hash(0, key)] & data[hash(1, key)] & data[hash(2, key)]; // 모든 비트가 1로 설정되어 있는 지를 검사합니다.

		if (result) {
			std::cout << key << " : 있을 수 있음" << std::endl;
		}
		else {
			std::cout << key << " : 절대 없음" << std::endl;
		}
	}

	void insert(int key) { // 삽입 함수
		data[hash(0, key)] = true;
		data[hash(1, key)] = true;
		data[hash(2, key)] = true;
		std::cout << key << "을 삽입 : ";

		for (auto a : data)
			std::cout << a << " ";
		std::cout << std::endl;
	}
};

int main() {
	bloom_filter bf(7);
	bf.insert(100);
	bf.insert(54);
	bf.insert(82);

	bf.lookup(5);
	bf.lookup(50);
	bf.lookup(20);
	bf.lookup(54);
}