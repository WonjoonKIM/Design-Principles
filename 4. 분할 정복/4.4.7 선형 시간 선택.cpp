//분할 정복에서 분할을 두개 이상으로 분할하는 것이 더 유리한 경우도 있습니다.
//정렬되지 않은 원소의 집합 S가 주어졌을 때 여기서 i번째로 작은 원소를 찾아야 합니다
//이 경우 O(nlogn)이지만 분할 정복 방법을 사용하여 O(n)의 시간복잡도를 구현합니다

#include <iostream>
#include <vector>

template<typename T>
auto partition(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) { // 분할 동작을 위한 partition 함수
	// 세 개의 반복자를 생성합니다.
	// 하나는 피벗을 가리키고 나머지 둘은 벡터의 시작과 마지막 원소를 가리킵니다.
	auto pivot_val = *begin;
	auto left_iter = begin + 1;
	auto right_iter = end;

	while (true) {
		//벡터의 첫번째 원소부터 시작하여 피벗보다 큰 원소를 찾습니다.
		while (*left_iter <= pivot_val && std::distance(left_iter, right_iter) > 0)
			left_iter++;

		//벡터의 마지막 원소부터 시작하여 역순으로 피벗보다 작은 원소를 찾습니다.
		while (*right_iter > pivot_val && std::distance(left_iter, right_iter) > 0)
			right_iter--;

		//만약 left_iter과 right_iter이 같다면 교환할 원소가 없음을 의미합니다.
		// 그렇지 않으면 left_iter과 right_iter가 가리키는 원소를 서로 교환합니다.
		if (left_iter == right_iter)
			break;
		else
			std::iter_swap(left_iter, right_iter);
	}
	if (pivot_val > *right_iter)
		std::iter_swap(begin, right_iter);

	return right_iter;
}

template <typename T>
void quick_sort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator last) {
	//만약 벡터에 하나 이상의 원소가 있다면 
	if (std::distance(begin, last) >= 1) {
		//분할 작업 수행
		auto partition_iter = partition<T>(begin, last);

		//분할 작업에 의해 생성된 벡터를 재귀적으로 정렬
		quick_sort<T>(begin, partition_iter - 1);
		quick_sort<T>(partition_iter, last);
	}
}


//두 반복자 사이의 중간 값을 찾는 함수를 작성합니다.
template<typename T>
auto find_median(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator last) {
	//정렬
	quick_sort<T>(begin, last);

	//가운데 원소 반복자를 반환
	return begin + (std::distance(begin, last) / 2);
}

//여기서는 피벗 위치 반복자를 인자로 받는 형태의 분할 함수를 만들어 사용하겠습니다.
template<typename T>
auto partition_using_given_pivot(
	typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, typename std::vector<T>::iterator pivot) {
	//피벗 위치는 함수 인자로 주어지므로
	//벡터의 시작과 마지막 원소를 가리키는 반복자를 정의합니다.
	auto left_iter = begin;
	auto right_iter = end;

	while (true) {
		//벡터의 첫 번쨰 원소부터 시작하여 피벗보다 큰 원소를 찾습니다.
		while (*left_iter < *pivot && left_iter != right_iter)
			left_iter++;

		//벡터의 마지막 원소부터 시작하여 역순으로 피벗보다 작은 원소를 찾습니다.
		while (*right_iter >= *pivot && left_iter != right_iter)
			right_iter--;
		//만약 left_iter과 left_iter가 같다면 교환할 원소가 없음을 의미합니다.
		//그렇지 않으면 left_iter와 left_iter가 가리키는 원소를 교환합니다.
		if (left_iter == right_iter)
			break;
		else
			std::iter_swap(left_iter, right_iter);
	}

	if (*pivot > *right_iter)
		std::iter_swap(pivot, right_iter);

	return right_iter;
}

template<typename T>
typename std::vector<T>::iterator linear_time_select(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator last, size_t i) {
	auto size = std::distance(begin, last);

	if (size > 0 && i < size) {
		auto num_Vi = (size + 4) / 5;
		size_t j = 0;

		//각각 Vi에서 중앙값을 찾아 벡터 M에 저장
		std::vector<T> M;
		for (; j < size/5; j++) {
			auto b = begin + (j * 5);
			auto l = begin + (j * 5) + 5;

			M.push_back(*find_median<T>(b, l));
		}
		if (j * 5 < size) {
			auto b = begin + (j * 5);
			auto l = begin + (j * 5) + (size % 5);

			M.push_back(*find_median<T>(b, l));
		}

		//Vi중앙값으로 구성된 벡터 M에서 다시 중앙값 q를 찾음
		auto median_of_medians = (M.size() == 1) ?
			M.begin() : linear_time_select<T>(M.begin(), M.end() - 1, M.size() / 2);

		//분할 연산을 적용하고 피벗 q의 위치 k를 찾음
		auto partition_iter = partition_using_given_pivot<T>(begin, last, median_of_medians);
		auto k = std::distance(begin, partition_iter) + 1;

		if (i == k)
			return partition_iter;
		else if (i < k)
			return linear_time_select<T>(begin, partition_iter - 1, i);
		else if (i > k)
			return linear_time_select<T>(partition_iter + 1, last, i - k);
	}
	else{
		return begin;
	}
}

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

//선형 시간 선택 알고리즘이 정확한지 검사하기 위한 병합 정렬 함수
template <typename T>
std::vector<T> merge_sort(std::vector<T> arr) {
	if (arr.size() > 1) {
		auto mid = size_t(arr.size() / 2);
		auto left_half = merge_sort(std::vector<T>(arr.begin(), arr.begin() + mid));
		auto right_half = merge_sort(std::vector<T>(arr.begin() + mid, arr.end()));

		return merge<T>(left_half, right_half);
	}
	return arr;
}

template <typename T>
void print_vector(std::vector<T> arr) {
	for (auto i : arr)
		std::cout << i << " ";

	std::cout << std::endl;
}

void run_linear_select_test() {
	std::vector<int> S1{ 45,1,3,1,2,3,45,5,1,2,44,5,7 };
	std::cout << "입력 벡터" << std:: endl;
	print_vector<int>(S1);
	
	std::cout << "정렬된 벡터" << std::endl;
	print_vector<int>(merge_sort<int>(S1));

	std::cout << "3번째 원소 : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 3) << std::endl;
	std::cout << "5번째 원소 : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 5) << std::endl;
	std::cout << "11번째 원소 : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 11) << std::endl;
}

int main() {
	run_linear_select_test();
	return 0;
}
