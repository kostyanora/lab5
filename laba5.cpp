#include <iostream>
#include <vector>
#include "Animals.h"

using namespace std;

//const int max_age_Tiger = 20, max_age_Deer = 15;
//
//class Animals {
//protected:
//	int x, y, d, k, satiety = 0, age = 0;
//	bool dead = false;
//
//public:
//	virtual void movement(const int length, const int width, int move) = 0;
//	virtual void eating() {
//		satiety++;
//	};
//	virtual void aging() {
//		age++;
//	}
//	virtual bool reproduction() = 0;
//	virtual void death() = 0;
//	virtual void kill() {
//		dead = true;
//	};
//	virtual bool GetDead() {
//		return dead;
//	}
//	virtual int GetX() {
//		return x;
//	}
//	virtual int GetY() {
//		return y;
//	}
//	virtual int GetD() {
//		return d;
//	}
//	virtual int GetK() {
//		return k;
//	}
//};
//
//class Tiger : public Animals {
//public:
//	Tiger(int xi, int yi, int di, int ki) {
//		x = xi - 1; // т.к. индексация в векторе начинается с 0 
//		y = yi - 1;
//		d = di;
//		k = ki;
//	}
//
//	void movement(const int length, const int width, int move) override {
//		switch (d) {
//		case 0:
//			if (x + 2 > width - 1) {
//				x = x + 2 - width;
//			}
//			else x += 2;
//			break;
//		case 1:
//			if (y + 2 > length - 1) {
//				y = y + 2 - length;
//			}
//			else y += 2;
//			break;
//		case 2:
//			if (x - 2 < 0) {
//				x = x - 2 + width;
//			}
//			else x -= 2;
//			break;
//		case 3:
//			if (y - 2 < 0) {
//				y = y - 2 + length;
//			}
//			else y -= 2;
//			break;
//		}
//		if (move % k == 0) {
//			d++;
//			if (d == 4) d = 0;
//		}
//	}
//
//	bool reproduction() override {
//		if (satiety == 2) {
//			satiety = 0;
//			return true;
//		}
//		else return false;
//	}
//
//	void death() override {
//		if (age == max_age_Tiger) {
//			//cout << "Тигр умер по достижении 20 лет";
//			dead = true;
//		}
//	}
//};
//
//class Deer : public Animals {
//public:
//	Deer(int xi, int yi, int di, int ki) {
//		x = xi - 1; // т.к. индексация в векторе начинается с 0
//		y = yi - 1;
//		d = di;
//		k = ki;
//	}
//
//	void movement(const int length, const int width, int move) override {
//		switch (d) {
//		case 0:
//			if (x + 1 > width - 1) {
//				x = x + 1 - width;
//			}
//			else x += 1;
//			break;
//		case 1:
//			if (y + 1 > length - 1) {
//				y = y + 1 - length;
//			}
//			else y += 1;
//			break;
//		case 2:
//			if (x - 1 < 0) {
//				x = x - 1 + width;
//			}
//			else x -= 1;
//			break;
//		case 3:
//			if (y - 1 < 0) {
//				y = y - 1 + length;
//			}
//			else y -= 1;
//			break;
//		}
//		if (move % k == 0) {
//			d++;
//			if (d == 4) d = 0;
//		}
//	}
//
//	bool reproduction() override {
//		if (age == 5 || age == 10) return true;
//		else return false;
//	}
//
//	void death() override {
//		if (age == max_age_Deer) dead = true;
//	}
//};

int main() {
	vector <Animals*> animals;
	Tiger* tiger;
	Deer* deer;
	setlocale(LC_ALL, "rus");
	cout << "\t\tПрограмма 'Хищник-Жертва'" << endl << endl;
	int length, width, moves;
	cout << "Введите размер поля и количество ходов через пробел: ";
	cin >> length >> width >> moves;
	vector <vector<int>> field(length, vector<int>(width));
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			field[i][j] = 0;
		}
	}
	int T, D;
	cout << "\nВведите количество оленей и тигров (так же через пробел): ";
	cin >> D >> T;
	int x, y, d, k;
	for (int i = 0; i < D; i++) {
		cout << "\nВведите расположение оленя (X и Y через пробел) : ";
		cin >> x >> y;
		cout << "\nВведите направление оленя (0 - вправо, 1 - вниз, 2 - влево, 3 - вверх): ";
		cin >> d;
		d %= 4;
		cout << "\nВведите, через какое количество ходов олень поменяет направление: ";
		cin >> k;
		deer = new Deer(x, y, d, k);
		animals.push_back(deer);
	}
	for (int i = 0; i < T; i++) {
		cout << "\nВведите расположение тигра (X и Y через пробел) : ";
		cin >> x >> y;
		cout << "\nВведите направление тигра (0 - вправо, 1 - вниз, 2 - влево, 3 - вверх): ";
		cin >> d;
		d %= 4;
		cout << "\nВведите, через какое количество ходов тигр поменяет направление: ";
		cin >> k;
		tiger = new Tiger(x, y, d, k);
		animals.push_back(tiger);
	}
	for (int i = 0; i < D; i++) {
		field[animals[i]->GetY()][animals[i]->GetX()]++;
	}
	for (int i = D; i < animals.size(); i++) {
		for (int j = 0; j < D; j++) {
			if (animals[j]->GetDead()) continue;
			if (animals[i]->GetX() == animals[j]->GetX() && animals[i]->GetY() == animals[j]->GetY()) {
				field[animals[i]->GetY()][animals[i]->GetX()]--;
				animals[i]->eating();
				animals[j]->kill();
				cout << "Тигр съел оленя" << endl << endl;
			}
		}
		if (animals[i]->reproduction()) {
			tiger = new Tiger(animals[i]->GetX() + 1, animals[i]->GetY() + 1, animals[i]->GetD(), animals[i]->GetK());
			animals.push_back(tiger);
			cout << "На свет появился новый тигренок" << endl << endl;
		}
		field[animals[i]->GetY()][animals[i]->GetX()]--;
	}
	cout << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (field[i][j] == 0) cout << "*\t";
			else cout << field[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	for (int m = 1; m <= moves; m++) {
		cout << "Ход №" << m << endl << endl;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				field[i][j] = 0;
			}
		}
		for (int i = 0; i < animals.size(); i++) {
			if (animals[i]->GetDead()) continue;
			animals[i]->movement(length, width, m);
			animals[i]->death();
			if (i >= D) {
				for (int j = 0; j < D; j++) {
					if (animals[j]->GetDead()) continue;
					if (animals[i]->GetX() == animals[j]->GetX() && animals[i]->GetY() == animals[j]->GetY()) {
						animals[i]->eating();
						animals[j]->kill();
						cout << "Тигр съел оленя" << endl << endl;
					}
				}
			}
			if (animals[i]->reproduction()) {
				if (i >= D) {
					tiger = new Tiger(animals[i]->GetX() + 1, animals[i]->GetY() + 1, animals[i]->GetD(), animals[i]->GetK());
					animals.push_back(tiger);
					cout << "На свет появился новый тигренок" << endl << endl;
				}
				else {
					deer = new Deer(animals[i]->GetX() + 1, animals[i]->GetY() + 1, animals[i]->GetD(), animals[i]->GetK());
					vector <Animals*>::iterator iter = animals.begin();
					animals.insert(iter + i + 1, deer);
					cout << "На свет появился новый олененок" << endl << endl;
					D++;
				}
			}
			if (animals[i]->GetDead()) {
				if (i >= D) cout << "Тигр умер по достижении 20 лет" << endl << endl;
				else cout << "Олень умер по достижении 15 лет" << endl << endl;
			}
			animals[i]->aging();
		}
		for (int i = 0; i < animals.size(); i++) {
			if (animals[i]->GetDead()) continue;
			if (i < D) field[animals[i]->GetY()][animals[i]->GetX()]++;
			else field[animals[i]->GetY()][animals[i]->GetX()]--;
		}
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				if (field[i][j] == 0) cout << "*\t";
				else cout << field[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}