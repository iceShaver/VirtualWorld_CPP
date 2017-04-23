#pragma once
#include "Animal.h"

class Human : public Animal
{
public:
	enum MovementDirection { undefined, upLeft, up, upRight, left, right, downLeft, down, downRight };
	//static const char MovementDirectionSymbols[9] = {'0', }
	Human(World* world, OrganismPositon organismPositon);
	~Human();
	void handleCollision(Organism*) override;
	void act()override;
	MovementDirection getMovementDirection()const;
	void setMovementDirection(MovementDirection movementDirection);
private:
	MovementDirection movementDirection;
public:


	
};

