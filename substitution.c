#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char valid(string argv[]);
string decode(string argv[], string s);

int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        if (valid(argv) == 'n')
        {
            printf("Check command-line arguement - invalid key\n");
            return 1;
        }
        else
        {
            string s = get_string("plaintext: ");
            printf("ciphertext: %s\n", decode(argv, s));
            return 0;
        }
    }
    else
    {
        printf("Usage: ./substitution key - check command-line arguement\n");
        return 1;
    }
}

char valid(string argv[])
{
    char flag = 'v';
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            flag = 'n';
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (argv[1][i] == argv[1][j] ||
                    (isupper(argv[1][i]) && argv[1][i] == argv[1][j] - 32) || (islower(argv[1][i]) && argv[1][i] == argv[1][j] + 32))
                {
                    flag = 'n';
                }
            }
        }
    }
    return flag;
}

string decode(string argv[], string s)
{
    int p = 0;
    string s1 = s;
    for (int j = 0, m = strlen(s); j < m; j++)
    {
        s1[j] = s[j];
        if (isalpha(s[j]))
        {
            if (islower(s[j]))
            {
                p = s[j] - 97;
                if (islower(argv[1][p]))
                {
                    s1[j] = argv[1][p];
                }
                else
                {
                    s1[j] = argv[1][p] + 32;
                }
            }
            else
            {
                p = s[j] - 65;
                if (isupper(argv[1][p]))
                {
                    s1[j] = argv[1][p];
                }
                else
                {
                    s1[j] = argv[1][p] - 32;
                }
            }
        }
    }
    return s1;
}