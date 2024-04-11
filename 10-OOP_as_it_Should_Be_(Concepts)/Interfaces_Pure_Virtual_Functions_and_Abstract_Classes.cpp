#include <iostream>
using namespace std;

class clsMobile
{
	virtual void Dail(string PhoneNumber) = 0;

	virtual void SendSMS(string PhoneNumber, string Text) = 0;

	virtual void TakePicture() = 0;
};

class clsIPhone : public clsMobile
{

public:

	void Dail(string PhoneNumber)
	{
	};

	void SendSMS(string PhoneNumber, string Text)
	{

	};

	void TakePicture()
	{

	};
};

class clsSamsungNot10 : public clsMobile
{

	void Dail(string PhoneNumber)
	{
	};

	void SendSMS(string PhoneNumber, string Text)
	{

	};

	void TakePicture()
	{

	};
};

int main()
{
	clsIPhone IPhone;

	clsSamsungNot10 SamsungNot10;

	return 0;
}
