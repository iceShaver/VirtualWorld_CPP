#pragma once
#include "Animal.h"

class Human : public Animal
{
public:
	enum MovementDirection { undefined, upLeft, up, upRight, left, right, downLeft, down, downRight };
	Human(World* world, OrganismPositon organismPositon);
	~Human();
	void act()override;
	void setMovementDirection(MovementDirection movementDirection);
	void spawn(const OrganismPositon& organismPosition) override;
	void activateAlzursShield();
	void handleAlzursShield();
	bool isAlzursShieldActivated()const;
	MovementDirection getMovementDirection()const;
	ResistType resistsAttack(const Organism* otherOrganism) override;
private:
	MovementDirection movementDirection;
	bool alzursShieldActivated;
	uint32_t alzursShieldActDeactRound;

	
};

