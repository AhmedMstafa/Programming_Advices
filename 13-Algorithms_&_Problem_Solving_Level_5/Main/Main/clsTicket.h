#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsTicket
{
public:
	string ID;
	string Date;
	short WatingClients;
	short ServingTime;
	clsTicket(string id, short wating_clinets, short serving_time)
	{
		ID = id;
		Date = clsDate::GetSystemDateTimeString();
		WatingClients = wating_clinets;
		ServingTime = serving_time;
	}

};