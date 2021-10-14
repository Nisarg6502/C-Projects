//preprocessor directives
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

//getting command line arguments. argc is the counter; argv[] is the array to store the arguments
int main(int argc, char *argv[])
{
    if (argc == 2 && isdigit(*argv[1]))
    {
        printf("%s", argv[1]);
        char plaintext;
        scanf("plaintext: ", &plaintext);
        int k = atoi(argv[1]);//converts a string to int
        printf("ciphertext: ");
        for (int j = 0, m = strlen(plaintext); j < m; j++)
        {
            if (islower(plaintext[j])) //lowercase
            {
                printf("%c", (((plaintext[j] - 'a') + k) % 26) + 'a');
            }
            else if (isupper(plaintext[j]))
            {
                printf("%c", (((plaintext[j] - 'A') + k) % 26) + 'A');//uppercase
            }
            else
            {
                printf("%c", plaintext[j]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: %s key", argv[0]);
        return 1;
    }
}


