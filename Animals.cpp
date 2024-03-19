#include "Animals.h"

void Animals::eating() {
	satiety++;
}

void Animals::aging() {
	age++;
}

void Animals::kill() {
	dead = true;
}

bool Animals::GetDead() {
	return dead;
}

int Animals::GetX() {
	return x;
}

int Animals::GetY() {
	return y;
}

int Animals::GetD() {
	return d;
}

int Animals::GetK() {
	return k;
}

Tiger::Tiger(int xi, int yi, int di, int ki) {
	x = xi - 1; // т.к. индексация в векторе начинается с 0
	y = yi - 1;
	d = di;
	k = ki;
}

void Tiger::movement(const int length, const int width, int move) {
	switch (d) {
	case 0:
		if (x + 2 > width - 1) {
			x = x + 2 - width;
		}
		else x += 2;
		break;
	case 1:
		if (y + 2 > length - 1) {
			y = y + 2 - length;
		}
		else y += 2;
		break;
	case 2:
		if (x - 2 < 0) {
			x = x - 2 + width;
		}
		else x -= 2;
		break;
	case 3:
		if (y - 2 < 0) {
			y = y - 2 + length;
		}
		else y -= 2;
		break;
	}
	if (move % k == 0) {
		d++;
		if (d == 4) d = 0;
	}
}

bool Tiger::reproduction() {
	if (satiety == 2) {
		satiety = 0;
		return true;
	}
	else return false;
}

void Tiger::death() {
	if (age == max_age_Tiger) {
		dead = true;
	}
}

Deer::Deer(int xi, int yi, int di, int ki) {
	x = xi - 1; // т.к. индексация в векторе начинается с 0
	y = yi - 1;
	d = di;
	k = ki;
}

void Deer::movement(const int length, const int width, int move) {
	switch (d) {
	case 0:
		if (x + 1 > width - 1) {
			x = x + 1 - width;
		}
		else x += 1;
		break;
	case 1:
		if (y + 1 > length - 1) {
			y = y + 1 - length;
		}
		else y += 1;
		break;
	case 2:
		if (x - 1 < 0) {
			x = x - 1 + width;
		}
		else x -= 1;
		break;
	case 3:
		if (y - 1 < 0) {
			y = y - 1 + length;
		}
		else y -= 1;
		break;
	}
	if (move % k == 0) {
		d++;
		if (d == 4) d = 0;
	}
}

bool Deer::reproduction() {
	if (age == 5 || age == 10) return true;
	else return false;
}

void Deer::death() {
	if (age == max_age_Deer) dead = true;
}