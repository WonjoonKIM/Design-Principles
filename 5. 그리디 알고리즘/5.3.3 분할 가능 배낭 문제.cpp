#include <iostream>
#include <algorithm>
#include <vector>

struct object {
	int id;
	int weight;
	double value;
	double value_per_unit_weight;

	object(int i, int w, double v) :id(i), weight(w), value(v), value_per_unit_weight(v / w) {}

	inline bool operator< (const object& obj) const {
		return this->value_per_unit_weight < obj.value_per_unit_weight;
	}
};

std::ostream& operator<<(std::ostream& os, const object& obj) {
	os << "[" << obj.id << "] 가격 : " << obj.value
		<< "\t무게 : " << obj.weight
		<< "kg\t단위 무게 당 가격 : " << obj.value_per_unit_weight;
	return os;
}

auto fill_knapsack(std::vector<object>& objects, int knapsack_capacity) {
	std::vector<object> knapsack_contents;
	knapsack_contents.reserve(objects.size());

	// 물건들을 내림차순으로 정렬 (단위 무게 당 가격 기준)
	std::sort(objects.begin(), objects.end());
	std::reverse(objects.begin(), objects.end());

	// '가장 가치있는' 물건들 먼저 배낭에 추가
	auto current_object = objects.begin();
	int current_total_weight = 0;
	while (current_total_weight < knapsack_capacity && current_object != objects.end()) {
		knapsack_contents.push_back(*current_object);
		current_total_weight += current_object->weight;
		current_object++;
	}

	//마지막 추가한 물건에 의해 배낭 최대 허용 무게가 초과된 경우
	int weight_of_last_obj_to_remove = current_total_weight - knapsack_capacity;
	object& last_object = knapsack_contents.back();
	if (weight_of_last_obj_to_remove > 0) {
		last_object.weight -= weight_of_last_obj_to_remove;
		last_object.value -= last_object.value_per_unit_weight * weight_of_last_obj_to_remove;
	}
	return knapsack_contents;
}

int main(int argc, char* argv[]) {
	std::vector<object> main_objects;
	main_objects.reserve(7);

	std::vector<int> weights{ 1,2,5,9,2,3,4 };
	std::vector<double> values{ 10,7,15,10,12,11,5 };
	for (auto i = 0; i < 7; i++)
		main_objects.push_back(object(i + 1, weights[i], values[i]));

	// 사용할 수 있는 물건 정보 출력
	std::cout << "[사용할 수 있는 물건 정보]" << std::endl;
	for (auto& o : main_objects)
		std::cout << o << std::endl;
	std::cout << std::endl;

	//분할가능 배낭문제 알고리즘 실행, 최대 허용무게는 7로 지정
	int knapsack_capacity = 7;
	auto solution = fill_knapsack(main_objects, knapsack_capacity);

	//배낭에 넣을 물건 정보 출력
	std::cout << "[배낭에 넣을 물건들 (최대용량 = " << knapsack_capacity << ")]" << std::endl;
	for (auto& o : solution)
		std::cout << o << std::endl;
	std::cout << std::endl;
}