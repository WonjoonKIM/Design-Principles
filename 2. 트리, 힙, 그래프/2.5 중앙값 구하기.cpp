// 힙 구조를 활용하여 입력 받은 데이터의 중앙값을 계산합니다.
#include <iostream>
#include <queue>
#include <vector>

struct median {
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

	void insert(int data) {
		if (maxHeap.size() == 0) {
			maxHeap.push(data);
			return;
		}
		if (maxHeap.size() == minHeap.size()) {
			if (data <= get())
				maxHeap.push(data);
			else
				minHeap.push(data);

			return;
		}

		if (maxHeap.size() < minHeap.size()) {
			if (data > get()) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
			else
				maxHeap.push(data);
			return;
		}

		if (data < get()) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else
			minHeap.push(data);
	}
	double get() {
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0;
		if (maxHeap.size() < minHeap.size())
			return minHeap.top();

		return maxHeap.top();
	}
};

int main() {
	median med;

	med.insert(1);
	std::cout << "1 삽입 후 중앙 값: " << med.get() << std::endl;

	med.insert(5);
	std::cout << "5 삽입 후 중앙 값: " << med.get() << std::endl;

	med.insert(2);
	std::cout << "2 삽입 후 중앙 값: " << med.get() << std::endl;

	med.insert(10);
	std::cout << "10 삽입 후 중앙 값: " << med.get() << std::endl;

	med.insert(40);
	std::cout << "40 삽입 후 중앙 값: " << med.get() << std::endl;

	// 새로운 데이터를 추가할 때 O(logN)의 시간복잡도를 가지며 이는 정렬을 이용할 때(O(NlogN)보다 효율적입니다.
}