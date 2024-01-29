#include <iostream>
#include<cstdlib>
using namespace std;

/*
How Many Questions do you want to answer ?
Enter Duetions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?
Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?


Quttion [1/5]

6
10 /
_________
0
Right Answer :-)

_________________________________________

Final Results is Pas :-)

________________________________________

Number of Quetions: 1
Qustion Level     : Easy
OpType            : Div
Number of Right Answers: 1
Number of Wrong Answers: 0

____________________________________________

Do you want to palay again? Y/N?

*/
/*
int Random(int From, int To) {
	return rand() % (To - From + 1) + From;
}

enum OpType { Add = 1, Sup = 2, Mul = 3, Div = 4, Mix = 5 };
enum QLevel { Esay = 1, Med = 2, Hard = 3, Mi = 4 };

struct stQustion {
	int FirstNum = 0;
	int SecondNum = 0;
	OpType OpetationType;
	QLevel QuestionLevel;
	int Result = 0;
	int UserInput = 0;
	int IsRightAnswer;
};

struct stFinalResult {
	int NumberOfQutions = 0;
	OpType OperationType;
	QLevel QuestionLevel;
	int NumberOfRightAnswers = 0;
	int NumberOfWrongAnsowers = 0;
};

int ReadNumber(string Message) {
	int Number = 0;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}



OpType OperationType(int Number) {
	switch (Number)
	{
	case 1:
		return OpType::Add;
		break;
	case 2:
		return OpType::Sup;
		break;
	case 3:
		return OpType::Mul;
		break;
	case 4:
		return OpType::Div;
		break;
	case 5:
		return (OpType)Random(1, 4);
		break;
	}
}


QLevel QuestionLevel(int NumLevel) {
	switch (NumLevel)
	{
	case 1:
		return QLevel::Esay;
		break;
	case 2:
		return QLevel::Med;
		break;
	case 3:
		return QLevel::Hard;
		break;
	case 4:
		return QLevel::Mi;
		break;
	}
}

int RandomNumber(QLevel NumLevel) {
	switch (NumLevel)
	{
	case Esay:
		return Random(1, 5);
		break;
	case Med:
		return Random(5, 10);
		break;
	case Hard:
		return Random(10, 15);
		break;
	case Mix:
		return Random(1, 20);
		break;
	}
}


int Sum2Number(int Num1, int Num2, OpType OperationType, QLevel QuestionLevel) {
	switch (OperationType)
	{
	case Add:
		return Num1 + Num2;
		break;
	case Sup:
		return Num1 - Num2;

		break;
	case Mul:
		return Num1 * Num2;

		break;
	case Div:
		if (Num1 / Num2 <= 0)
			return 0;
		return Num1 / Num2;
		;
		break;
	};
}

bool ChickIfRightAnswer(int Result, int UserInput) {
	return (Result == UserInput);
}

char OperationType(OpType O) {
	char Op[4] = { '+','-','*', '/' };
	return Op[O - 1];
}

void PrintQuestion(int Num1, int Num2, OpType Op) {
	cout << "\n\n";
	cout << Num1 << "\n";
	cout << Num2 << " " << OperationType(Op) << "\n";
	cout << "_________________" << endl;

}

void PrintResult(bool IsRigitAnswer) {
	if (IsRigitAnswer) {
		cout << "Right Answer :-)\n\n";
		system("color 2F");
	}
	else {
		cout << "Wrong Answer :-(\n\n";
		system("color 4F");
	}
}

stFinalResult FillFinalResult(int NumberOfQuestions, OpType OperationType, QLevel QuestionLevel, int NumberOfRightAnswores, int NumberOfWrongAnsowres) {
	stFinalResult R;
	R.NumberOfQutions = NumberOfQuestions;
	R.OperationType = OperationType;
	R.QuestionLevel = QuestionLevel;
	R.NumberOfRightAnswers = NumberOfRightAnswores;
	R.NumberOfWrongAnsowers = NumberOfWrongAnsowres;
	return R;
}

stFinalResult PlayRound(int NumberOfQuestions) {
	int NumberOfRightAnswers = 0, NumberOfWrongAnsowers = 0;
	stQustion Question;
	for (int QuestionNumber = 1; QuestionNumber <= NumberOfQuestions; QuestionNumber++) {
		cout << "Quttion [" << QuestionNumber << "/" << NumberOfQuestions << "]" << endl;
		Question.QuestionLevel = QuestionLevel(ReadNumber("Enter Duetions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? "));
		Question.OpetationType = OperationType(ReadNumber("Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?"));
		Question.FirstNum = RandomNumber(Question.QuestionLevel);
		Question.SecondNum = RandomNumber(Question.QuestionLevel);
		PrintQuestion(Question.FirstNum, Question.SecondNum, Question.OpetationType);
		Question.Result = Sum2Number(Question.FirstNum, Question.SecondNum, Question.OpetationType, Question.QuestionLevel);
		Question.UserInput = ReadNumber(" ");
		Question.IsRightAnswer = ChickIfRightAnswer(Question.Result, Question.UserInput);
		PrintResult(Question.IsRightAnswer);
		if (Question.IsRightAnswer)
			NumberOfRightAnswers++;
		else
			NumberOfWrongAnsowers++;
	}
	return FillFinalResult(NumberOfQuestions, Question.OpetationType, Question.QuestionLevel, NumberOfRightAnswers, NumberOfWrongAnsowers);
}

bool PassOrFail(int NumberOfRightAnswers, int NumberOfWrongAnswers) {
	return (NumberOfRightAnswers >= NumberOfWrongAnswers);
}

void ShowFinalResult(stFinalResult Result) {
	cout << "\n\_____________________________\n\n";
	if (PassOrFail(Result.NumberOfRightAnswers, Result.NumberOfWrongAnsowers)) {
		cout << "Final Results is Pas :-)\n\n";
		system("color 2F");
	}
	else {
		cout << "\n\nFinal Results is fail :-(\n";
		system("color 4F");
	}
	cout << "\n_____________________________\n";

}

string QLName(QLevel QL) {
	string Q[4] = { "Esay", "Med", "Hard", "Mix" };
	return Q[QL - 1];
}

string OPName(OpType OP) {
	string O[5] = { "Add", "Sup", "Mul","Div" , "Mix" };
	return O[OP - 1];
}

void ShowFinalResultData(stFinalResult Result) {
	cout << "\nNumber of Questions    : " << Result.NumberOfQutions << "\n";
	cout << "\nQuestions Level        : " << QLName(Result.QuestionLevel) << "\n";
	cout << "\nQuestions OpType       : " << OPName(Result.OperationType) << "\n";
	cout << "\nNumber of Right Answers: " << Result.NumberOfRightAnswers << "\n";
	cout << "\nNumber of Wrong Answers: " << Result.NumberOfWrongAnsowers << "\n";
	cout << "\n\_____________________________\n";

}

void ClearScreen() {
	system("cls");
	system("color 0F");
}

void StartGame() {
	char PlayAgain = 'Y';
	stFinalResult Result;
	do {
		ClearScreen();
		Result = PlayRound(ReadNumber("How Many Questions do you want to answer ?"));
		ShowFinalResult(Result);
		ShowFinalResultData(Result);
		cout << "Do you want to palay again? Y/N?\n";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

*/


enum enOperationType { Add = 1, Sup = 2, Mul = 3, Div = 4, MixType = 5 };
enum enQuestionLevel { Esay = 1, Med = 2, Hard = 3, MixLevel = 4 };

struct stQuestion {
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short FirstNumber = 0;
	short SecondNumber = 0;
	int CorrectAnsower = 0;
	short PlayerAnsower = 0;
	bool IsRightAnsower = true;
};

struct stQuizz {
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short NumberOfWrongAnsowers = 0;
	short NumberOfRightAnsowers = 0;
	bool IsPass = true;
};

short Random(int From, int To) {
	return rand() % (To - From + 1) + From;
}

short ReadHowManyRounds() {
	short Number = 0;
	do {
		cout << "How Many Questions do you want to answer ? ";
		cin >> Number;
	} while (Number < 1 || Number > 100);
	return Number;
}

enQuestionLevel ReadQuestionLevel() {
	short Number = 0;
	do {
		cout << "Enter Duetions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> Number;
	} while (Number < 1 || Number > 4);
	return (enQuestionLevel)Number;
}

enOperationType ReadOperationType() {
	short Number = 0;
	do {
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> Number;
	} while (Number < 1 || Number > 5);
	return (enOperationType)Number;
}

int SimpleCalc(short FirstNumber, short SecondNumber, enOperationType OperationType) {
	switch (OperationType)
	{
	case Add:
		return FirstNumber + SecondNumber;
		break;
	case Sup:
		return FirstNumber - SecondNumber;

		break;
	case Mul:
		return FirstNumber * SecondNumber;

		break;
	case Div:
		return FirstNumber / SecondNumber;

		break;
	default:
		return FirstNumber + SecondNumber;
		break;
	}
}

stQuestion GenerateQuestion(enQuestionLevel Level, enOperationType Operation) {
	stQuestion Question;
	if (Level == enQuestionLevel::MixLevel) {
		Level = (enQuestionLevel)Random(1, 3);
	}
	if (Operation == enOperationType::MixType) {
		Operation = (enOperationType)Random(1, 4);
	}
	Question.OperationType = Operation;

	switch (Level)
	{
	case Esay:
		Question.FirstNumber = Random(1, 10);
		Question.SecondNumber = Random(1, 10);
		Question.QuestionLevel = Level;
		Question.CorrectAnsower = SimpleCalc(Question.FirstNumber, Question.SecondNumber, Question.OperationType);
		return Question;
		break;
	case Med:
		Question.FirstNumber = Random(10, 50);
		Question.SecondNumber = Random(10, 50);
		Question.QuestionLevel = Level;
		Question.CorrectAnsower = SimpleCalc(Question.FirstNumber, Question.SecondNumber, Question.OperationType);
		return Question;
		break;
	case Hard:
		Question.FirstNumber = Random(50, 100);
		Question.SecondNumber = Random(50, 100);
		Question.QuestionLevel = Level;
		Question.CorrectAnsower = SimpleCalc(Question.FirstNumber, Question.SecondNumber, Question.OperationType);
		return Question;
		break;
	}

}

void GenerateQuizzQuestions(stQuizz& Quizz) {
	for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
		Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OperationType);
	}
}

char PrintOperationType(enOperationType Operation) {
	char Op[100] = { '+','-','*', '/' };
	return Op[Operation - 1];
}

void PrintTheQuestion(stQuizz Quizz, short QuestionNumber) {
	cout << "[" << QuestionNumber << "/" << Quizz.NumberOfQuestions << "]" << "\n\n";
	cout << Quizz.QuestionList[QuestionNumber].FirstNumber << "\n";
	cout << Quizz.QuestionList[QuestionNumber].SecondNumber << "  ";
	cout << PrintOperationType(Quizz.QuestionList[QuestionNumber].OperationType) << "\n";
	cout << "______________" << endl;
}

short ReadQuestionAnswer() {
	short Number = 0;
	cin >> Number;
	return Number;

}

void CorrectQuetionAnswer(stQuizz& Quizz, short QuestionNumber) {
	if (Quizz.QuestionList[QuestionNumber].CorrectAnsower == Quizz.QuestionList[QuestionNumber].PlayerAnsower) {
		Quizz.QuestionList[QuestionNumber].IsRightAnsower = true;
		Quizz.NumberOfRightAnsowers++;
		cout << "\nRight Answer :-)\n";
	}
	else {
		Quizz.QuestionList[QuestionNumber].IsRightAnsower = false;
		Quizz.NumberOfWrongAnsowers++;
		cout << "\nWrong Answer :-(\n";
		cout << "The Right Answer is " << Quizz.QuestionList[QuestionNumber].CorrectAnsower << "\n\n";
	}
}

bool IsPassOrFail(short RightAnswers, short WrongAnswers) {
	return RightAnswers >= WrongAnswers;
}

void AskAndCorrectQuizzAnswers(stQuizz& Quizz) {
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {
		PrintTheQuestion(Quizz, QuestionNumber);
		Quizz.QuestionList[QuestionNumber].PlayerAnsower = ReadQuestionAnswer();
		CorrectQuetionAnswer(Quizz, QuestionNumber);
	}

	Quizz.IsPass = Quizz.NumberOfRightAnsowers >= Quizz.NumberOfWrongAnsowers;
}

string GetFinalResultText(bool IsPass) {
	if (IsPass)
		return "Pass";
	else
		return "Fail";
}

string GetQusetionLevelText(enQuestionLevel Level) {
	string Qlevle[4] = { "Easy", "Med", "Hard", "Mix" };
	return Qlevle[Level - 1];
}

string GetOpTypeSymbol(enOperationType Type) {
	string OpType[5] = { "Add", "Sub", "Mul", "Div", "Mix" };
	return OpType[Type - 1];
}

void PrintQuizzResults(stQuizz Quizz) {
	cout << "\n";
	cout << "___________________________\n\n";
	cout << "Final Result is " << GetFinalResultText(Quizz.IsPass);
	cout << "\n_________________________\n";
	cout << "Number of Quetions: " << Quizz.NumberOfQuestions << endl;
	cout << "Quetions Level    : " << GetQusetionLevelText(Quizz.QuestionLevel) << endl;
	cout << "Op Type           : " << GetOpTypeSymbol(Quizz.OperationType) << endl;
	cout << "Number of Right Answers: " << Quizz.NumberOfRightAnsowers << endl;
	cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnsowers << endl;
	cout << "____________________________\n";
}

void PlayMathGame() {
	stQuizz Quizz;
	Quizz.NumberOfQuestions = ReadHowManyRounds();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OperationType = ReadOperationType();
	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuizzAnswers(Quizz);
	PrintQuizzResults(Quizz);
}


void StartGame() {
	char PlayAgain = 'Y';
	do {
		PlayMathGame();

		cout << "Do you want to palay again? Y/N? \n";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}



int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}