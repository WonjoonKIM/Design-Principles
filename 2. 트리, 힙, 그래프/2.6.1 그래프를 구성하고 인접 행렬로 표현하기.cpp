// 도시 네트워크를 그래프로 구성하고 이를 인접 행렬을 이용하여 저장할 것입니다.

#include <iostream>
#include <vector>

enum class city :int { // enum클래스를 이용하여 도시 이름 저장
	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAI,
	SYDNEY
};

std::ostream& operator<<(std::ostream& os, const city c) { // city enum에 대해 연산자 <<정의
	switch (c) {
	case city::LONDON:
		os << "런던";
		return os;

	case city::MOSCOW:
		os << "모스크바";
		return os;

	case city::SEOUL:
		os << "서울";
		return os;

	case city::SEATTLE:
		os << "시애틀";
		return os;

	case city::DUBAI:
		os << "두바이";
		return os;

	case city::SYDNEY:
		os << "시드니";
		return os;

	default:
		return os;
	}
}

struct graph { // 실제 데이터를 저장할 graph구조체를 정의합니다.
	std::vector<std::vector<int>> data;

	graph(int n) {
		data.reserve(n);
		std::vector<int> row(n);
		std::fill(row.begin(), row.end(), -1);

		for (int i = 0; i < n; i++) {
			data.push_back(row);
		}
	}

	//주어진 개수의 노드로 구성된 그래프를 구성하는 생성자를 추가하고 이 그래프는 에지가 전혀없는 비어있는 그래프입니다.
	void addEdge(const city c1, const city c2, int dis) {
		std::cout << "에지 추가 : " << c1 << " - " << c2 << " = " << dis << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = dis;
		data[n2][n1] = dis;
	}

	void removeEdge(const city c1, const city c2) {
		std::cout << "에지 삭제 : " << c1 << " - " << c2 << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = -1;
		data[n2][n1] = -1;
	}
};

int main() {
	graph g(6);
	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);

	//노드의 갯수가 V라면 전체 VxV크기의 메모리 공간을 사용하게 됩니다.

	return 0;
}

