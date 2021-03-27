#include "HotDogStand.h"
#include <iostream>

using namespace std;

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
	standId = "id";
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id)
{
	standId = id;
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id, int amount)
{
	standId = id;
	hotDogSellAmount = amount;
	totalSellAmount += amount;
}


HotDogStand::~HotDogStand()
{
}

void HotDogStand::justSold()
{
	hotDogSellAmount++;
	totalSellAmount++;
}

void HotDogStand::print()
{
	cout << standId << " " << hotDogSellAmount << endl;
}

int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
