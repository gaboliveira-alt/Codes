#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool checkPassword(char *password);

int main()
{
    char password[50];
    printf("Enter a password: ");
    scanf("%s", password);

    if (checkPassword(password))
    {
        printf("Password accepted\n");
    }
    else
    {
        printf("Wrong Password\n");
    }
}



bool checkPassword(char *password)
{
    bool checkLower = false;
    bool checkUpper = false;
    bool checkNumber = false;
    bool checkSymbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            checkLower = true;
        }
        if (isupper(password[i]))
        {
            checkUpper = true;
        }
        if (isdigit(password[i]))
        {
            checkNumber = true;
        }
        if (isalnum(password[i]))
        {
            checkSymbol = true;
        }
    }

    if (checkLower == true && checkUpper == true && checkNumber == true && checkSymbol == true)
    {
        return true;
    }

    return false;
}