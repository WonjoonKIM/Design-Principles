// 분할 정복 방법 중 이진 검색 기능을 구현해보겠습니다.

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

bool linear_search(int N, std::vector<int>& S) { // 선형 탐색 기법
	for (auto i : S) {
		if (i == N)
			return true; // 원소를 찾았다
	}
	return false;
}

bool binary_search(int N, std::vector<int>& S) {
	auto first = S.begin();
	auto last = S.end();

	while (true) {
		// 현재 검색 범위의 중간 원소를 mid_element에 저장
		auto range_length = std::distance(first, last);
		auto mid_element_index = first + std::floor(range_length / 2);
		auto mid_element = *(first + mid_element_index);

		//mid_element와 N값을 비교
		if (mid_element == N)
			return true;
		else if (mid_element > N)
			std::advance(last, -mid_element);
		if (mid_element < N)
			std::advance(first, mid_element_index);

		//현재 검색 범위에 하나의 원소만 남아 있다면 false 반환
		if (range_length == 1)
			return false;
	}
}

void run_small_search_test() { //검색 성능을 평가 하기 위한 테스트 함수이며 이것은 작은 크기의 배열입니다.
	auto N = 2;
	std::vector<int> S{ 1,3,2,4,5,7,9,8,6 };

	std::sort(S.begin(), S.end());

	if (linear_search(N, S))
		std::cout << "선형 검색으로 원소를 찾았습니다!" << std::endl;
	else
		std::cout << "선형 검색으로 원소를 찾지 못했습니다!" << std::endl;

	if (binary_search(N, S))
		std::cout << "이진 검색으로 원소를 찾았습니다!" << std::endl;
	else
		std::cout << "이진 검색으로 우너소를 찾지 못했습니다!" << std::endl;
}

void run_large_search_test(int size, int N) { // 이번엔 큰 배열입니다.
	std::vector<int> S;
	std::random_device rd;
	std::mt19937 rand(rd());

	// [1, size]범위에서 정수 난수 발생
	std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);

	// S에 난수 추가
	for (auto i = 0; i < size; i++)
		S.push_back(uniform_dist(rand));

	std::sort(S.begin(), S.end());

	//검색 시간 측정 시작
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	bool search_result = binary_search(N, S);

	//검색 시간 측정 종료
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "이진 검색 수행 시간 : " << diff.count() << std::endl;

	if (search_result)
		std::cout << "원소를 찾았습니다" << std::endl;
	else
		std::cout << "원소를 찾지 못했습니다." << std::endl;
}

int main() {
	run_small_search_test();

	run_large_search_test(100000, 36543);
	run_large_search_test(1000000, 36543);
	run_large_search_test(10000000, 36543);

	return 0;
}