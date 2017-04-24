#include "Human.h"
#include "Config.h"
#include "World.h"

Human::Human(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::HUMAN_STRENGTH, cfg::HUMAN_INITIATIVE, 
		organismPositon, cfg::HUMAN_SYMBOL, "Czlowiek"),
	movementDirection(undefined), alzursShieldActivated(false)
{
}

Human::~Human()
{
	world->human = nullptr;
}



void Human::act()
{
	handleAlzursShield();
	OrganismPositon newOrganismPositon = position;
	switch (movementDirection)
	{
	case undefined:
		world->newMessage("pozostaje na miejscu", this);
		return;
	case upLeft:
		newOrganismPositon.x--;
		newOrganismPositon.y--;
		break;
	case up:
		newOrganismPositon.y--;
		break;
	case upRight:
		newOrganismPositon.x++;
		newOrganismPositon.y--;
		break;
	case MovementDirection::left:
		newOrganismPositon.x--;
		break;
	case MovementDirection::right:
		newOrganismPositon.x++;
		break;
	case downLeft:
		newOrganismPositon.x--;
		newOrganismPositon.y++;
		break;
	case down:
		newOrganismPositon.y++;
		break;
	case downRight:
		newOrganismPositon.x++;
		newOrganismPositon.y++;
		break;
	default:
		break;
	}
	if (newOrganismPositon == position)
		world->newMessage("pozostaje na miejscu", this);
	else if (world->checkIfPlaceIsValidAndEmpty(newOrganismPositon.x, newOrganismPositon.y))
	{
		moveTo(&newOrganismPositon);
	}
	else if (world->checkIfPlaceIsValid(newOrganismPositon.x, newOrganismPositon.y))
	{
		handleCollision(world->peekOrganism(newOrganismPositon));
	}


}

Human::MovementDirection Human::getMovementDirection() const
{
	return movementDirection;
}

void Human::setMovementDirection(MovementDirection movementDirection)
{
	this->movementDirection = movementDirection;
}


void Human::spawn(const OrganismPositon& organismPosition)
{
}

void Human::activateAlzursShield()
{
	if (alzursShieldActivated) return;
	if ((world->getRoundNumber() - alzursShieldActDeactRound) < 5) return;
	alzursShieldActivated = true;
	alzursShieldActDeactRound = world->getRoundNumber();
}

void Human::handleAlzursShield()
{
	if(alzursShieldActivated)
	{
		if ((world->getRoundNumber() - alzursShieldActDeactRound) < 5) return;
		alzursShieldActivated = false;
		alzursShieldActDeactRound = world->getRoundNumber();
	}
}

Organism::ResistType Human::resistsAttack(const Organism* otherOrganism)
{
	if (alzursShieldActivated)
	{
		world->newMessage("tarcza alzura dla ", this, otherOrganism);
		return moveAroundMe;
	}
	return Organism::resistsAttack(otherOrganism);
}

bool Human::isAlzursShieldActivated() const
{
	return alzursShieldActivated;
}

