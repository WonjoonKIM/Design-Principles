// std::forward_list에서는 증가 연산만 가능하며 이러한 반복자를 순방향 반복자라고 합니다.
// 반복자를 사용하여 특정한 위치의 원소에 곧바로 접근할 것이고 이를 임의 접근 반복자라고 합니다.
// 반복자 타임에 따라 사용할 수 있는 함수 중에서 advance(), next(), prev() 함수가 있습니다.
// 벡터 반복자의 덧셈 뺄셈 연산은 O(1)의 시간 복잡도를 가집니다.

#include <iostream>
#include <forward_list>
#include <vector>

int main() {

	std::vector<std::string> vec = {
		"Lewis", "Lewis", "Nico", "Sebastian", " Lewis", "Sebastian", "Sebastian", "Sebastian", "Fernando"
	};

	auto it = vec.begin();
	std::cout << "가장 최근 우승자 : " << *it << std::endl;

	it += 8; // 원하는 인덱스
	std::cout << "8년전 우승자 : " << *it << std::endl;

	advance(it, -3); // 그 후 3년 뒤 우승자 
	std::cout << "그 후 3년 뒤 우승자 : " << *it << std::endl;

	std::forward_list<std::string> fwd(vec.begin(), vec.end());
	auto it2 = fwd.begin();
	std::cout << "가장 최근 우승자: " << *it2 << std::endl;
	advance(it2, 5);
	std::cout << "5년전 우승자 : " << *it2 << std::endl;

	//forward_list는 순방향으로만 이동할 수 있으므로 에러 발생!
	//advance(it2, -3); 
	
	// forward_list는 상수시간으로 동작 못하므로 에러 발생!
	// it2+=1;

}