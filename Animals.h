#pragma once

const int max_age_Tiger = 20, max_age_Deer = 15;

class Animals {
protected:
	int x, y, d, k, satiety = 0, age = 0;
	bool dead = false;

public:
	virtual void movement(const int length, const int width, int move) = 0;
	virtual void eating();
	virtual void aging();
	virtual bool reproduction() = 0;
	virtual void death() = 0;
	virtual void kill();
	virtual bool GetDead();
	virtual int GetX();
	virtual int GetY();
	virtual int GetD();
	virtual int GetK();
};

class Tiger : public Animals {
public:
	Tiger(int xi, int yi, int di, int ki);
	void movement(const int length, const int width, int move) override;
	bool reproduction() override;
	void death() override;
};

class Deer : public Animals {
public:
	Deer(int xi, int yi, int di, int ki);
	void movement(const int length, const int width, int move) override;
	bool reproduction() override;
	void death() override;
};