#include <iostream>
//#include "clsMyString.h"
#include "clsQueueLine.h"
using namespace std;

int main()
{
	clsQueueLine PayBillsQueue("A0", 10);
	clsQueueLine SubscriptionsQueue("B0", 5);

	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	cout << "\nPay Bills Queue Info:\n";
	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintTicketsLineRTL();
	PayBillsQueue.PrintTicketsLineLTR();

	PayBillsQueue.PrintAllTickets();

	PayBillsQueue.ServeNextClient();
	cout << "\nPay Bills Queue After Serving One Client\n";
	PayBillsQueue.PrintInfo();
	PayBillsQueue.PrintAllTickets();

	cout << "\nSubscription Queue Info:\n";

	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket();

	SubscriptionsQueue.PrintInfo();

	SubscriptionsQueue.PrintTicketsLineLTR();
	SubscriptionsQueue.PrintTicketsLineRTL();

	SubscriptionsQueue.PrintAllTickets();

	SubscriptionsQueue.ServeNextClient();
	cout << "\nSubscriptions Queue After Serving One Client\n";
	SubscriptionsQueue.PrintInfo();

	return 0;
}


/*
int main()
{
	cout << "\n\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";

	clsMyString S1;
	
	cout << "\nS1 = " << S1.Value << '\n';

	S1.Value = "Mohamed";

	cout << "S1 = " << S1.Value << '\n';

	S1.Value = "Mohammed2";

	cout << "S1 = " << S1.Value << '\n';

	S1.Value = "Mohammed3";

	cout << "S1 = " << S1.Value << '\n';

	cout << "\nUndo:  ";
	cout << "\n________\n";

	S1.Undo();

	cout << "S1 after undo = " << S1.Value << '\n';

	S1.Undo();

	cout << "S1 after undo = " << S1.Value << '\n';
	
	S1.Undo();

	cout << "S1 after undo = " << S1.Value << '\n';

	cout << "\nRedo:  ";
	cout << "\n________\n";

	S1.Redo();

	cout << "S1 after redo = " << S1.Value << '\n';


	S1.Redo();

	cout << "S1 after redo = " << S1.Value << '\n';


	S1.Redo();

	cout << "S1 after redo = " << S1.Value << '\n';

	system("pause>0");
	return 0;
}
*/