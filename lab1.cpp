#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Car {
private:
	string model;
	string mark;
public:
	Car(string model_, string mark_) {
		model = model_;
		mark = mark_;
	}
	void print() {
		cout << "mark: " << mark <<'\t'<< " model: " << model << endl;
	}
	void Setmark(string mark_) {
		mark = mark_;
	}
	string Getmark() {
		return mark;
	}
	void Setmodel(string model_) {
		model = model_;
	}
	string Getmodel() {
		return model;
	}
};
int main() {
	vector<Car> cars;
	ifstream file("db.txt");
	string line;

	if (!file.is_open()) {
		cout << "error" << endl;
	}
	while (getline(file, line)) {
		size_t space_pos = line.find(' ');

		if (space_pos != string::npos) {
			string model = line.substr(0, space_pos);
			string mark = line.substr(space_pos + 1);

			cars.emplace_back(mark, model);
		}
	}
	file.close();
	for (int i = 0; i < cars.size(); i++) {
		cars[i].print();
	}

	return 0;
}
