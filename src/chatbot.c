#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHRASE_LEN 100

int main(void)
{
    int selection;
    char string_input[PHRASE_LEN];
    char response[][PHRASE_LEN] = {
        "Ich höre dich!",
        "Also, redest du mit mir.",
        "Mach nur weiter, ich höre dich.",
        "Sehr interessante Unterhaltung",
        "Erzähl mir mehr"};

    srand(time(NULL));

    while (1)
    {
        printf("> ");
        fflush(stdout);
        fgets(string_input, sizeof(string_input), stdin);
        string_input[strlen(string_input) - 1] = '\0'; // remove '\n' from input

        if (strcmp(string_input, "Ciao"))
        {
            selection = rand() % 5;
            puts(response[selection]);
            fflush(stdout);
        }
        else
        {
            puts("Schön dich kennengelernt zu haben, bis zum nächsten Mal!");
            fflush(stdout);
            break;
        }
    }

    return 0;
}
