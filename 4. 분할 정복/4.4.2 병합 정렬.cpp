#include <iostream>
#include <vector>

template <typename T> // 타입 T의 벡터 두 개를 참조로 받고 두 벡터의 원소를 하나로 병합한 새로운 벡터를 반환합니다.
std::vector<T> merge(std::vector<T>& arr1, std::vector<T>& arr2) { // 두개의 벡터를 병합하는 merge()함수를 작성합니다.
	std::vector<T> merged;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end()) {
		if (*iter1 < *iter2) {
			merged.emplace_back(*iter1); 
			// push_back과 같은 삽입 함수들은 삽입할 객체를 받지만 emplace_back과 같은 생성 삽입 함수는 
			// 삽입할 객체의 생성자를 위한 인자들을 받아 std::vector 내에서 직접 객체를 생성하여 삽입하므로 
			// 임시 객체의 생성과 파괴, 복사(혹은 move)를 하지 않아도 되어 성능상 더 유리하다는 것이다.
			iter1++;
		}
		else {
			merged.emplace_back(*iter2);
			iter2++;
		}
	}

	// 짝이 안맞아서 남는 수까지 merged벡터에 넣는다.
	if (iter1 != arr1.end()) {
		for (; iter1 != arr1.end(); iter1++)
			merged.emplace_back(*iter1);
	}
	else {
		for (; iter2 != arr2.end(); iter2++)
			merged.emplace_back(*iter2);
	}
	return merged;
}

template <typename T>
std::vector<T> merge_sort(std::vector<T> arr) { // 재귀적으로 병합 정렬을 구현합니다.
	if (arr.size() > 1) {
		auto mid = size_t(arr.size() / 2);
		auto left_half = merge_sort<T>(std::vector<T>(arr.begin(), arr.begin() + mid));
		auto right_half = merge_sort<T>(std::vector<T>(arr.begin() + mid, arr.end()));

		return merge<T>(left_half, right_half);
	}
	return arr;
}

template<typename T>
void print_vector(std::vector<T> arr) { // 벡터에 포함된 모든 데이터를 출력하는 함수를 작성합니다.
	for (auto i : arr)
		std::cout << i << " ";

	std::cout << std::endl;
}

void run_merge_sort_test() {
	std::vector<int> S1 = { 45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7 };
	std::vector<float> S2 = { 45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 45.3f, 5.5f, 1.0f, 2.0f, 44.0f, 5.0f, 7.0f };
	std::vector<double> S3 = { 45.6, 1.0, 3.8, 1.01, 2.2, 3.9, 45.3, 5.5, 1.0, 2.0, 44.0, 5.0, 7.0 };
	std::vector<char> C{ 'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y' };

	std::cout << "정렬되지 않은 입력 벡터" << std::endl;
	print_vector<int>(S1);
	print_vector<float>(S2);
	print_vector<double>(S3);
	print_vector<char>(C);
	std::cout << std::endl;

	auto sorted_S1 = merge_sort<int>(S1);
	auto sorted_S2 = merge_sort<float>(S2);
	auto sorted_S3 = merge_sort<double>(S3);
	auto sorted_C = merge_sort<char>(C);

	std::cout << "병합 정렬에 의해 정렬된 벡터" << std::endl;
	print_vector<int>(sorted_S1);
	print_vector<float>(sorted_S2);
	print_vector<double>(sorted_S3);
	print_vector<char>(sorted_C);
	std::cout << std::endl;
 }

int main() {
	run_merge_sort_test();
	return 0;
}