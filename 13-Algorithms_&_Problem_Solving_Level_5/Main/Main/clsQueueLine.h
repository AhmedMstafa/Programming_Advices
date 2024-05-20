#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include "clsTicket.h"
using namespace std;

class clsQueueLine
{
private:
	string _Prefix;
	short _TotalClinets;
	short _Duration;
	short _ServedClinets;
	queue<clsTicket> _MyLine;

public:

	clsQueueLine(string prefix, short duration)
	{
		_Prefix = prefix;
		_Duration = duration;
		_TotalClinets = 0;
		_ServedClinets = 0;
	}

	void IssueTicket()
	{
		// create ticket will be here.
		_TotalClinets++;

		string TicketId = _Prefix + to_string(_TotalClinets);
		short WatingClients = _MyLine.size() ;
		short ServingTime = (_MyLine.size() * _Duration);

		_MyLine.push(clsTicket(TicketId, WatingClients, ServingTime));

	}

	void PrintInfo()
	{
		// Queue info will be here.
		cout << "\nPay Bills Queue Info:\n\n";

		cout << setw(37) << "" << "_________________________\n\n";
		cout << setw(37) << "" << "        Queue Info\n";
		cout << setw(37) << "" << "_________________________\n\n";

		cout << setw(37) << "" << "\tPrefix    = " << _Prefix <<'\n';
		cout << setw(37) << "" << "\tTotal Tickets  = " << _TotalClinets <<'\n';
		cout << setw(37) << "" << "\tServed Clients = " << _ServedClinets <<'\n';
		cout << setw(37) << "" << "\tWating Clients = " << _MyLine.size() <<'\n';
		cout << setw(37) << "" << "_________________________\n";
		cout << endl;


	}

	void PrintTicketsLineRTL()
	{
		// Print tickts form right to left will be here.
		queue<clsTicket> TempLine;

		cout <<  '\n' << setw(20) << "" << "Tickets:  ";

		while (!_MyLine.empty())
		{
			cout << _MyLine.front().ID << " <-- ";
			TempLine.push(_MyLine.front());
			_MyLine.pop();
		}

		cout << endl;

		_MyLine.swap(TempLine);

	}

	void PrintTicketsLineLTR()
	{
		// Print tickts form lift to right will be here.
		queue<clsTicket> TempLine;
		stack<clsTicket> _MyReverseLine;

		TempLine = _MyLine;

		while (!TempLine.empty())
		{
			_MyReverseLine.push(TempLine.front());
			TempLine.pop();
		}

		cout << '\n' << setw(20) << "" << "Tickets:  ";

		while (!_MyReverseLine.empty())
		{
			cout << _MyReverseLine.top().ID << " --> ";
			_MyReverseLine.pop();
		}

		cout << endl;
		
	}

	void PrintTicketInfo(clsTicket Ticket)
	{
		// Print ticket info will be here.
		cout << setw(37) << "" << "_________________________\n\n";
		cout << setw(37) << "" << "\t\t" << Ticket.ID << '\n';
		cout << setw(37) << "" << '\t' << Ticket.Date << '\n';
		cout << setw(37) << "" << "\tWating Clinets = " << Ticket.WatingClients << '\n';
		cout << setw(37) << "" << "\t   Serve Time In\n";
		cout << setw(37) << "" << "\t   " << Ticket.ServingTime << " Minutes.\n";
		cout << setw(37) << "" << "_________________________\n";
		cout << endl;

	}

	void PrintAllTickets()
	{
		queue<clsTicket> TempLine;

		TempLine = _MyLine;

		if (TempLine.empty())
			cout << "The Queue Is Empty!\n";
		else
			while (!TempLine.empty())
			{
				PrintTicketInfo(TempLine.front());
				TempLine.pop();
			}
	}

	void ServeNextClinet()
	{
		if (_MyLine.empty())
			return;

		_ServedClinets++;

		queue<clsTicket> TempLine ;

		_MyLine.pop();

		while (!_MyLine.empty())
		{
			_MyLine.front().ServingTime = (TempLine.size() * _Duration);
			_MyLine.front().WatingClients = TempLine.size();
			TempLine.push(_MyLine.front());
			_MyLine.pop();
		}

		_MyLine.swap(TempLine);

	}
};