#include <iostream>
#include <iomanip>
using namespace std;

enum enLevelOfEncryption { low = 10, medium = 100 , high = 1000};

struct RSA
{
    short FirstSecretKey;
    short SecondSecretKey;
    int PublicKey;
};

bool IsPrimeNumber(short num)
{
  /*  if (num <= 0 || num == 1)
        return 0;
    
    for (short i = 2; i < num -1; i++)
    {
        if ((num % i) == 0)
            return 0;
    }

    return 1;
    */

    if (num <= 0 || num == 1)
        return 0;

    int M = round(num / 2);

    for (int counter = 2; counter <= M; counter++)
        if (num % counter == 0)
            return 0;

    return 1;
}

short RandomNumber(short from, short to)
{
   return rand() % (to - from + 1) + from;
}

short CreateSecretKey(enLevelOfEncryption encriptionlevel)
{
    short EncryptionMax = (int)encriptionlevel;
    short EncryptionMin = EncryptionMax * 0.1;
    short SecretKey = 0;
    bool NotPrime = 1;

    while (NotPrime)
    {
       SecretKey = RandomNumber(EncryptionMin, EncryptionMax);
       NotPrime = !IsPrimeNumber(SecretKey);
    }

    return SecretKey;
}

RSA AsymmetricEncryption(enLevelOfEncryption encriptionlevel)
{
    RSA stRSA;

    stRSA.FirstSecretKey = CreateSecretKey(encriptionlevel);
    stRSA.SecondSecretKey = CreateSecretKey(encriptionlevel);
    stRSA.PublicKey = stRSA.FirstSecretKey * stRSA.SecondSecretKey;

    return stRSA;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << setw(37) << left << "" << "=================================\n";
    cout << setw(37) << left << "" << "      Asymmetric Encryption\n";
    cout << setw(37) << left << "" << "=================================\n\n";

    RSA RSAEX = AsymmetricEncryption(enLevelOfEncryption::high);

    cout << "Your Key Is : " << RSAEX.PublicKey << '\n';
    cout << "Your Secret key Is : " << RSAEX.FirstSecretKey <<
        " * " << RSAEX.SecondSecretKey << endl;

    return 0;
}
