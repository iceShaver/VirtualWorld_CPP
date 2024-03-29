#include "Organism.h"
#include "World.h"
#include "Program.h"
#include <sstream>
OrganismPositon::operator basic_string<char>() const
{
	stringstream ss;
	ss << "(" << (int)x << "," << (int)y << ")";
	return ss.str();
}

bool OrganismPositon::operator==(const OrganismPositon& other) const
{
	if (x == other.x && y == other.y)return true;
	return false;
}

bool Organism::Comparator::operator()(const Organism* left, const Organism* right) const
{
	bool result;
	if (left->initiative == right->initiative)
		return left->age > right->age;
	return left->initiative > right->initiative;

}


Organism::Organism(World * world, unsigned short strength, unsigned short initiative,
	OrganismPositon organismPositon, const char symbol, std::string name)
	:world(world), strength(strength), initiative(initiative),
	position(organismPositon), symbol(symbol), name(name), age(0)
{}


Organism::~Organism()
{
	world->newMessage("umiera ", this);
}

Organism::operator char()
{
	return symbol;
}

std::string Organism::toString()const
{
	stringstream ss;
	ss << name << " (" << (int)position.x << "," << (int)position.y << ")";
	return ss.str();
}

bool Organism::operator==(const Organism& other) const
{
	if (this == &other) return true;
	return false;
}

OrganismPositon Organism::getOrganismPosition() const
{
	return position;
}

OrganismPositon * Organism::getRandomNeighbourPosition(
	uint8_t range,
	NeighbourPlaceSearchMode neighbourPlaceSearchMode,
	const Organism*fixedOrganism) const
{
	vector<OrganismPositon> whereCanMove =
		getAllNeigbourPosition(range, neighbourPlaceSearchMode, fixedOrganism);
	int randomLimit = whereCanMove.size();
	if (!randomLimit) return nullptr;
	if (randomLimit == 1) 
		return new OrganismPositon{ whereCanMove[0].x, whereCanMove[0].y };
	int randomNumber = Program::getRandomIntNumber(0, randomLimit - 1);
	return new OrganismPositon{ whereCanMove[randomNumber].x, whereCanMove[randomNumber].y };

}

std::vector<OrganismPositon>
Organism::getAllNeigbourPosition(
	uint8_t range, NeighbourPlaceSearchMode neighbourPlaceSearchMode,
	const Organism*fixedOrganism) const
{
	OrganismPositon position;
	if (fixedOrganism)
	{
		position = fixedOrganism->position;
	}
	else
	{
		position = this->position;
	}

	RECT rect;
	rect.left = position.x - range;
	rect.right = position.x + range;
	rect.top = position.y - range;
	rect.bottom = position.y + range;

	//Assert wanted rect is inside organism area
	while (rect.left < 0) rect.left++;
	while (rect.top < 0) rect.top++;
	while (rect.right > world->width - 1) rect.right--;
	while (rect.bottom > world->height - 1)rect.bottom--;
	short rectWidth = (rect.right - rect.left) + 1;
	short rectHeight = (rect.bottom - rect.top) + 1;

	OrganismPositon tmpPos = { rect.left, rect.top };
	vector<OrganismPositon> whereCanMove;
	//Search rect for empty places
	for (;;)
	{
		if (neighbourPlaceSearchMode == onlyEmpty) {
			if (world->peekOrganism(tmpPos) == nullptr)
			{
				whereCanMove.push_back(tmpPos);
			}
			if (tmpPos.x >= rect.right)
			{
				if (tmpPos.y >= rect.bottom)
				{
					if (world->peekOrganism(tmpPos) == nullptr)
						whereCanMove.push_back(tmpPos);
					break;
				}
				tmpPos.y++;
				tmpPos.x = rect.left;
			}
			else
				tmpPos.x++;
		}
		else if (neighbourPlaceSearchMode == all)
		{
			if (!(tmpPos.x == position.x && tmpPos.y == position.y) && !(tmpPos == position))
				whereCanMove.push_back(tmpPos);
			if (tmpPos.x >= rect.right)
			{
				if (tmpPos.y >= rect.bottom)
				{
					if (!(tmpPos.x == position.x && tmpPos.y == position.y) && !(tmpPos == position))
						whereCanMove.push_back(tmpPos);
					break;
				};
				tmpPos.y++;
				tmpPos.x = rect.left;
			}
			else
				tmpPos.x++;
		}
		else if (neighbourPlaceSearchMode == emptyOrWithWeakOrganism)
		{
			if (world->peekOrganism(tmpPos) == nullptr)
				whereCanMove.push_back(tmpPos);
			else if (strength >= world->peekOrganism(tmpPos)->strength && !(tmpPos == position))
				whereCanMove.push_back(tmpPos);
			if (tmpPos.x >= rect.right)
			{
				if (tmpPos.y >= rect.bottom)
				{
					if (world->peekOrganism(tmpPos) == nullptr)
						whereCanMove.push_back(tmpPos);
					else if (strength >= world->peekOrganism(tmpPos)->strength && !(tmpPos == position))
						whereCanMove.push_back(tmpPos);
					break;
				}
				tmpPos.y++;
				tmpPos.x = rect.left;
			}
			else
				tmpPos.x++;



		}
	}
	return whereCanMove;
}

short Organism::getStrength()const
{
	return strength;
}

uint8_t Organism::getOrganismXPos() const
{
	return position.x;
}

uint8_t Organism::getOrganismYPos() const
{
	return  position.y;
}

void Organism::increaseAge()
{
	age++;
}

uint32_t Organism::getAge() const
{
	return age;
}

unsigned short Organism::getInitiative() const
{
	return initiative;
}

std::string Organism::getName()const
{
	return name;
}

Organism::ResistType Organism::resistsAttack(const Organism* otherOrganism)
{
	if (this->strength > otherOrganism->strength) return kill;
	return surrender;
}

std::string Organism::getName()
{
	return name;
}

