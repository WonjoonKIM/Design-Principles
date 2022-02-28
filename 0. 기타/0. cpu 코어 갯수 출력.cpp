#include <iostream>
#include <thread>
using namespace std;

int main(int argc, char *argv []) {
	int cpu_cores = std::max(1U, std::thread::hardware_concurrency());

	cout << "CPU ÄÚ¾î °¹¼ö : "<< cpu_cores << endl;

	return 0;
}