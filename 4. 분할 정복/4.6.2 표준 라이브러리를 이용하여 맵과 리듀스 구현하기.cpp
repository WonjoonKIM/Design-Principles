/*
�ʸ��ེ�� ��Ը� �����ͼ��� �����ϰ� ó���ϱ� ���� ���α׷��� �� �� �����Դϴ�.
����ڴ� Ű�� ���� ���� ó���Ͽ� �߰� �ܰ��� Ű/�� ���� �����ϴ� ��(map)�Լ��� ���� �߰� �ܰ� Ű�� �ش��ϴ�
��� �߰� �ܰ� ���� �����ϴ� ���ེ(reduce)�Լ��� �����մϴ�.
e.g. �ϵ�
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

void transform_test(std::vector<int> S) {
	std::vector<int> Tr;
	std::cout << "�� �׽�Ʈ" << std::endl;
	std::cout << "�Է� �迭, S = ";
	for (auto i : S)
		std::cout << i << " ";
	std::cout << std::endl;

	//std::transform() �Լ� ���, transform() �Լ��� �Է� ���͸� �ٲ��� �ʰ� ������ ���͸� ����
	std::transform(S.begin(), S.end(), std::back_inserter(Tr), [](int x) {return std::pow(x, 2.0); }); 
	std::cout << "std::transform(), Tr : ";
	for (auto i : Tr)
		std::cout << i << " ";
	std::cout << std::endl;

	//std::for_each()�Լ� ���, for_each()�Լ��� �Է� ���� ��ü�� �����Ѵ�.
	std::for_each(S.begin(), S.end(), [](int& x) {x = std::pow(x, 2.0); });
	std::cout << "std::for_each(), S : ";
	for (auto i : S)
		std::cout << i << " ";
	std::cout << std::endl;
}

//���ེ ���� �׽�Ʈ �Լ��� �ۼ��մϴ�.
void reduce_test(std::vector<int> S) {
	std::cout << std::endl << "���ེ �׽�Ʈ" << std::endl;
	std::cout << "�Է� �迭, S : ";
	for (auto i : S)
		std::cout << i << " ";
	std::cout << std::endl;

	//std::accumulate() �Լ� ���
	auto ans = std::accumulate(S.begin(), S.end(), 0, [](int acc, int x) { return acc + x; });
	std::cout << "std::accumulate(), ans : " << ans << std::endl;
}

int main() {
	std::vector<int> S{ 1, 10, 4, 7, 3, 5, 6, 9,8, 2 };

	transform_test(S);
	reduce_test(S);

	return 0;
}


