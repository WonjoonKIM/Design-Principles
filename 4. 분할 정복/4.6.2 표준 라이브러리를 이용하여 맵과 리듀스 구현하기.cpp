/*
맵리듀스는 대규모 데이터셋을 생성하고 처리하기 위한 프로그래밍 모델 및 구현입니다.
사용자는 키와 값의 쌍을 처리하여 중간 단계의 키/값 쌍을 생성하는 맵(map)함수와 같은 중간 단계 키에 해당하는
모든 중간 단계 값을 병합하는 리듀스(reduce)함수를 지정합니다.
e.g. 하둡
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

void transform_test(std::vector<int> S) {
	std::vector<int> Tr;
	std::cout << "맵 테스트" << std::endl;
	std::cout << "입력 배열, S = ";
	for (auto i : S)
		std::cout << i << " ";
	std::cout << std::endl;

	//std::transform() 함수 사용, transform() 함수는 입력 벡터를 바꾸지 않고 별도의 벡터를 생성
	std::transform(S.begin(), S.end(), std::back_inserter(Tr), [](int x) {return std::pow(x, 2.0); }); 
	std::cout << "std::transform(), Tr : ";
	for (auto i : Tr)
		std::cout << i << " ";
	std::cout << std::endl;

	//std::for_each()함수 사용, for_each()함수는 입력 벡터 자체를 변경한다.
	std::for_each(S.begin(), S.end(), [](int& x) {x = std::pow(x, 2.0); });
	std::cout << "std::for_each(), S : ";
	for (auto i : S)
		std::cout << i << " ";
	std::cout << std::endl;
}

//리듀스 연산 테스트 함수를 작성합니다.
void reduce_test(std::vector<int> S) {
	std::cout << std::endl << "리듀스 테스트" << std::endl;
	std::cout << "입력 배열, S : ";
	for (auto i : S)
		std::cout << i << " ";
	std::cout << std::endl;

	//std::accumulate() 함수 사용
	auto ans = std::accumulate(S.begin(), S.end(), 0, [](int acc, int x) { return acc + x; });
	std::cout << "std::accumulate(), ans : " << ans << std::endl;
}

int main() {
	std::vector<int> S{ 1, 10, 4, 7, 3, 5, 6, 9,8, 2 };

	transform_test(S);
	reduce_test(S);

	return 0;
}


