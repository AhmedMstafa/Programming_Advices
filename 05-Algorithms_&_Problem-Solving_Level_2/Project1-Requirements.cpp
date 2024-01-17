#include <iostream>
using namespace std;
/*
1- Stone Paper Scissor
- ask for how many round the game will be
- Start each round Player vs Computer.
- Show The results With each round.
- If computet wins the round ring a bill , and screed red.
- if Player won the round show green screen.
After all rounds show game over the print game results, the ask the user if s/he want to play again ?
- 
- HOW Many Rounds 1 to 10 ?
- Round [1] begins:
- Your Choice : [1]:Stone , [2]:Paper, [3]:Sissors ?
- Scrren color*
--------------Round [1]----------------
Player1 Choice : 
Computer Choice :
Round Winner :
-----------------------------------------

----------------------------------------------------------
               *** G a m e O v e r ***
-----------------------------------------------------------
-----------------[Game Results ]----------------------------
Game Rounds             : 
Player 1 won times		:
Computer won times      :
Draw times              :
Final Winner            : No Winner
-------------------------------------------------------------
Do You want to play again ? Y/N?

*/

/*

enum enChoice { Stone = 1, Paper = 2, Scissor = 3 };

struct stResult {
	bool Player1 = false, Computer =false , Draw = false;
	string PlayerInput = "", ComputerInput = "";
};

int Random(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int ReadNumber(string Message) {
	int Number;
	cout << Message << endl;
	cin >> Number;
	return Number;
}

enChoice Choice(int Input) {
	switch (Input)
	{
	case Stone:
		return enChoice::Stone;
		break;
	case Paper:
		return enChoice::Paper;
		break;
	case Scissor:
		return enChoice::Scissor;
		break;
	}
}



stResult Round(stResult Result, int PlayerInput)
{
	if (Choice(PlayerInput) == enChoice::Paper && Choice(Random(1, 3)) == enChoice::Stone) {
		Result.Player1 = true;
		Result.PlayerInput = "Paper";
		Result.ComputerInput = "Stone";
		system("color 2F");
	}
	else if (Choice(PlayerInput) == enChoice::Paper && Choice(Random(1, 3)) == enChoice::Scissor) {
		Result.Computer = true;
		Result.PlayerInput = "Paper";
		Result.ComputerInput = "Scissor";
		system("color 4F");
	}
	else if (Choice(PlayerInput) == enChoice::Paper && Choice(Random(1, 3)) == enChoice::Paper) {
		Result.Draw = true;
		Result.PlayerInput = "Paper";
		Result.ComputerInput = "Paper";
		system("color 6F");
	}
	else if (Choice(PlayerInput) == enChoice::Stone && Choice(Random(1, 3)) == enChoice::Scissor) {
		Result.Player1 = true;
		Result.PlayerInput = "Stone";
		Result.ComputerInput = "Scissor";
		system("color 2F");
	}
	else if (Choice(PlayerInput) == enChoice::Stone && Choice(Random(1, 3)) == enChoice::Paper) {
		Result.Computer = true;
		Result.PlayerInput = "Stone";
		Result.ComputerInput = "Paper";
		system("color 4F");
	}
	else if (Choice(PlayerInput) == enChoice::Stone && Choice(Random(1, 3)) == enChoice::Stone) {
		Result.Draw = true;
		Result.PlayerInput = "Stone";
		Result.ComputerInput = "Stone";
		system("color 6F");
	}
	else if (Choice(PlayerInput) == enChoice::Scissor && Choice(Random(1, 3)) == enChoice::Paper) {
		Result.Player1 = true;
		Result.PlayerInput = "Scissor";
		Result.ComputerInput = "Paper";
		system("color 2F");
	}
	else if (Choice(PlayerInput) == enChoice::Scissor && Choice(Random(1, 3)) == enChoice::Stone) {
		Result.Computer = true;
		Result.PlayerInput = "Scissor";
		Result.ComputerInput = "Stone";
		system("color 4F");
	}
	else {
		Result.Draw = true;
		Result.PlayerInput = "Scissor";
		Result.ComputerInput = "Scissor";
		system("color 6F");
	}
	return Result;
}


void ViewResult(stResult Result) {
	cout << "Player1 Choice:  " << Result.PlayerInput << "\n";
	cout << "Computer Choice:  " << Result.ComputerInput << "\n";
	if (Result.Player1) {
		cout << "Round Winner\t: [Player1]\n";
	}
	else if (Result.Computer) {
		cout << "Round Winner\t: [Computer]\n";
	}
	else {
		cout << "Round Winner\t: [No Winner]\n";
	}
}

void Play(stResult &Result,stResult arr[100], int& Length) {
	 Length = ReadNumber("HOW Many Rounds 1 to 10 ?");
	
	for (int i = 0; i < Length; i++) {
		cout << "_____________Round [" << i + 1 << "] _____________\n\n";
		arr[i] = Round(Result, ReadNumber("Your Choice : [1]:Stone , [2]:Paper, [3]:Sissors ?"));
		ViewResult(arr[i]);
		cout << "____________________________________\n\n";

	}
}

void PrintFinalResult(stResult arr[100], stResult& Result,int Length) {
	int PlayerWon = 0;
	int ComputerWon = 0;
	int DrowTimes = 0;
	string FinalWinner = "";
	for (int i = 0; i < Length; i++) {
		if (arr[i].Player1) {
			PlayerWon++;
		}
		else if (arr[i].Computer) {
			ComputerWon++;
		}
		else if (arr[i].Draw) {
			DrowTimes++;
		}
	}
	if (PlayerWon > ComputerWon) {
		FinalWinner = "Player 1 Won\n";
	}
	else if (PlayerWon < ComputerWon) {
		FinalWinner = "Computer Won\n";
	}
	else {
		FinalWinner = "No Wonner\n";

	}
	cout << "\n__________________________________________________________\n";
	cout << "\n                 +++ G a m e O v e r +++                  \n";
	cout << "\n__________________________________________________________\n";
	cout << "\n\n_________________[Game Results ]____________________\n";
	cout << "Game Rounds\t\t:" << Length << "\n";
	cout << "Player 1 won times \t:" << PlayerWon << "\n";
	cout << "Computer won times \t:" << ComputerWon << "\n";
	cout << "Draw times\t\t:" << DrowTimes << "\n";
	cout << "_________________________________________________________" << endl;
	system("color 0");

}

void StartGame() {
	stResult Array[100];
	int Length = 0;
	stResult Result;
	string Tray = "";
	system("color 0f");
	do{
	Play(Result,Array, Length);
	PrintFinalResult(Array, Result, Length);
		cout << "\nDo You want to play again ? Y/N?";
		cin >> Tray;
	} while (Tray == "Y");
}
*/

int Random(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enum enChoice { Stone = 1, Paper = 2, Scissor = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw };

struct stResult {
	short NumberOfRounds = 0;
	short ComputerWins = 0;
	short Player1Wins = 0;
	short Draw = 0;
	enWinner Winner;
	string WinnerName = "";
};

struct stRoundInfo {
	short RoundNumber;
	enChoice ComputerChoice;
	enChoice Player1Choice;
	enWinner Winner;
	string WinnerName = "";
};

enChoice GetComputerChoice() {
	return (enChoice)Random(1, 3);
}

enChoice GetPlayer1Choice() {
	short Number;
	do {
	cout << "Your Choice : [1]:Stone , [2]:Paper, [3]:Sissors ? ";
	cin >> Number;

	} while (Number <= 0 || Number > 3);
	return (enChoice)Number;
}
void SetWinnerScreenColor(enWinner Winner) {
	switch (Winner)
	{
	case Player1:
		system("color 2F");
		break;
	case Computer:
		system("color 4F");
		cout << "\a";
		break;
	case Draw:
		system("color 6F");
		break;
	}
}

enWinner HowWinRound(stRoundInfo Round) {
	if (Round.Player1Choice == Round.ComputerChoice) {
		return enWinner::Draw;
	}
	switch (Round.Player1Choice)
	{
	case enChoice::Stone:
		if (Round.ComputerChoice == enChoice::Paper) {
			return enWinner::Computer;
		}
			break;
	case enChoice::Paper:
		if (Round.ComputerChoice == enChoice::Scissor) {
			return enWinner::Computer;
		}
		break;
	case enChoice::Scissor:
		if (Round.ComputerChoice == enChoice::Stone) {
			return enWinner::Computer;
		}
		break;
	}

	return enWinner::Player1;
}

string WinnerName(enWinner Winner) {
	string ArratWinnerName[3] = {  "Player1","Computer", "Draw" };
	return ArratWinnerName[Winner - 1];
}

string ChoiceName(enChoice Choice) {
	string arr[3] = { "Stone", "Paper", "Sissors" };
	return arr[Choice - 1];
}

void PrintRoundResults(stRoundInfo Round) {
	cout << "_____________Round [" << Round.RoundNumber << "] _____________\n\n";
	cout << "Player1 Choice : " << ChoiceName(Round.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(Round.ComputerChoice) << endl;
	cout << "Round Winner   : [" << Round.WinnerName << "]\n";
	cout << "___________________________________________________\n";
}

enWinner WhoWonTheGame(short PlayerWinTimes,short ComputerWinTimes) {
	if (PlayerWinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else
		return enWinner::Computer;
}

stResult FillResultWith(short NumberOfRounds, short ComputerWinTimes, short Player1WinTiemes, short DrawTimes) {
	stResult Result;
	Result.NumberOfRounds = NumberOfRounds;
	Result.ComputerWins = ComputerWinTimes;
	Result.Player1Wins = Player1WinTiemes;
	Result.Draw = DrawTimes;
	Result.Winner = WhoWonTheGame(Player1WinTiemes,ComputerWinTimes);
	Result.WinnerName = WinnerName(Result.Winner);
	return Result;
}

stResult PlayRound(short NumberOfRounds) {
	short ComputerWinTimes = 0, Player1WinTimes = 0, DrawTimes = 0;
	stRoundInfo stRound;
	for (int RoundNumber = 1; RoundNumber <= NumberOfRounds; RoundNumber++) {
		
		stRound.RoundNumber = RoundNumber;
		stRound.ComputerChoice = GetComputerChoice();
		stRound.Player1Choice = GetPlayer1Choice();
		stRound.Winner = HowWinRound(stRound);
		stRound.WinnerName = WinnerName(stRound.Winner);
		SetWinnerScreenColor(stRound.Winner);
		if (stRound.Winner == enWinner::Computer) {
			ComputerWinTimes++;
		}
		else if (stRound.Winner == enWinner::Player1) {
			Player1WinTimes++;
		}
		else {
			DrawTimes++;
		}
		PrintRoundResults(stRound);

	}



	return FillResultWith(NumberOfRounds, ComputerWinTimes,Player1WinTimes,DrawTimes);

}

short ReadNumberOfRounds() {
	short Number;
	do {
		cout << "Please Enter Number Of Rounds From 1 to 10\n";
		cin >> Number;

	} while (Number <= 0 || Number > 10);
	return Number;
}

void ClearScreen() {
	system("cls");
	system("color 0F");
}

string Tabs(short NumberOfTabs) {
	string Tap = "";
	for (int i = 1; i <= NumberOfTabs; i++) {
		Tap += "\t";
		cout << Tap;
	}
	return Tap;
}

void ShowGameOverScreen() {
	cout << Tabs(2) << "__________________________________________________\n\n";
	cout << Tabs(2) << "                +++ G a m e O v e r +++            \n\n";
	cout << Tabs(2) << "___________________________________________________\n\n";
}


void ShowFinalGameResults(stResult Result) {
	cout << Tabs(2) << "____________________[Game Reults ]_________________ \n\n";
	cout << Tabs(2) << "Game Rounds        :  " << Result.NumberOfRounds << endl;
	cout << Tabs(2) << "Player1 Won Times  :  " << Result.Player1Wins << endl;
	cout << Tabs(2) << "Computer Won Times :  " << Result.ComputerWins << endl;
	cout << Tabs(2) << "Draw times         :  " << Result.Draw << endl;
	cout << Tabs(2) << "Final Winner       :  " << Result.WinnerName << endl;
	cout << Tabs(2) << "____________________________________________________\n\n";
	SetWinnerScreenColor(Result.Winner);
}

void StartGame() {
	string PlayAgain = "Y";
	stResult Result;
	do {
		ClearScreen();
		Result = PlayRound(ReadNumberOfRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(Result);
		cout << endl << Tabs(3) << "Do You Want To Play Again? Y/N?";
		cin >> PlayAgain;
	} while (PlayAgain == "Y" || PlayAgain == "y");

}




int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;

}
