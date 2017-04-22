#include "Organism.h"
#include "World.h"
#include "Program.h"

bool Organism::Comparator::operator()(const Organism* left, const Organism* right) const
{
	bool result;
	if (left->initiative == right->initiative)
		return left->age > right->age;
	return left->initiative > right->initiative;

}

Organism::Organism(World * world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol)
	:world(world), strength(strength), initiative(initiative), position(organismPositon), symbol(symbol), age(0)
{}


Organism::~Organism()
{
}

Organism::operator char()
{
	return symbol;
}

OrganismPositon Organism::getOrganismPosition() const
{
	return position;
}



/**
 * \brief Return random neighbour position in given range
 * \param range Max range to search neighbour position
 * \param mustBeEmpty Set true of the place you want have to be empty
 * \return ptr to OrganismPosition if found, else nullptr
 */
OrganismPositon * Organism::getRandomNeighbourPosition(uint8_t range, bool mustBeEmpty) const
{
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
		if (mustBeEmpty) {
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
		else
		{
			if (!(tmpPos.x == position.x && tmpPos.y == position.y))
				whereCanMove.push_back(tmpPos);
			if (tmpPos.x >= rect.right)
			{
				if (tmpPos.y >= rect.bottom)
				{
					if (!(tmpPos.x == position.x && tmpPos.y == position.y))
						whereCanMove.push_back(tmpPos);
					break;
				};
				tmpPos.y++;
				tmpPos.x = rect.left;
			}
			else
				tmpPos.x++;
		}
	}
	int randomLimit = whereCanMove.size();
	if (!randomLimit) return nullptr;
	if (randomLimit == 1)  return new OrganismPositon{ whereCanMove[0].x, whereCanMove[0].y };
	int randomNumber = Program::getRandomIntNumber(0, randomLimit - 1);
	return new OrganismPositon{ whereCanMove[randomNumber].x, whereCanMove[randomNumber].y };


	/*switch (Program::getRandomIntNumber(1, 8))
	{
	case 1:
		if (!(position.x == 0 || position.y == 0)) {
			return new OrganismPositon{ uint8_t(position.x - 1), uint8_t(position.y - 1) };
			break;
		}
	case 2:
		if (!position.y == 0)
		{
			return new OrganismPositon{ position.x, uint8_t(position.y - 1) };
			break;
		}
	case 3:
		if (!(position.x == world->width - 1 || position.y == 0))
		{
			return new OrganismPositon{ uint8_t(position.x + 1), uint8_t(position.y - 1) };
			break;
		}
	case 4:
		if (!position.x == 0)
		{
			return new OrganismPositon{ uint8_t(position.x - 1), position.y };
			break;
		}
	case 5:
		if (!(position.x == world->width - 1))
		{
			return new OrganismPositon{ uint8_t(position.x + 1), position.y };
			break;
		}
	case 6:
		if (!(position.x == 0 || position.y == world->height - 1))
		{
			return new OrganismPositon{ uint8_t(position.x - 1), uint8_t(position.y + 1) };
			break;
		}
	case 7:
		if (!(position.y == world->height - 1))
		{
			return new OrganismPositon{ position.x, uint8_t(position.y + 1) };
			break;
		}
	case 8:
		if (!(position.x == world->width - 1 || position.y == world->height - 1))
		{
			return new OrganismPositon{ uint8_t(position.x + 1), uint8_t(position.y + 1) };
			break;
		}
	default:
		return nullptr;
		break;
	}*/
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

unsigned short Organism::getInitiative()
{
	return initiative;
}

