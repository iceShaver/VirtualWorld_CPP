#pragma once
class Organism
{
public:
	Organism();
	virtual ~Organism();
	virtual void Act();
	virtual void HandleCollision();
	virtual void Draw();
private:
	unsigned short strength;
	unsigned short priority;
	unsigned short x, y;
	//World*world;
};

