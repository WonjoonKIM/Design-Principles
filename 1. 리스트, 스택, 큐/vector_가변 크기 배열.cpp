#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	//std::vector<int> vec; //크기 지정할 필요가 없다
	std::vector<int> vec = { 1,2,3,4,5 }; // 크기가 5인 벡터 선언
	//std::vector<int> vec(10); // 크기 지정해줌
	//std::vector<int> vec(10, 5); // 크기가 10이고 모든 원소가 5로 초기화된 벡터 선언

	vec.insert(vec.begin(), 0);

	vec.push_back(6);

	vec.insert(find(vec.begin(), vec.end(), 1), 4); // 1앞에 4추가하기

	std::vector<int> vec2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vec2.pop_back();
	vec2.erase(vec2.begin());
	vec2.erase(vec2.begin() + 1, vec.begin() + 4); // 1번째 원소부터 4번째 앞 원소까지 제거합니다.

	for (auto it = vec.begin(); it != vec.end(); it++) {
		auto element = (*it);
		std::cout << element << ", ";
	}

	//vec.clear();
	//vec2.clear();

}