// The original code in C for ALIZA
// By Rafael Sanchez

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXBUF 2048
#define NUMBEROFGREET 14
#define NUMBEROFNORESP 9

bool conv_ended = false;

void flushArr(char array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        array[i] = '\0';
    }
}

// turns strings to lowercase provided in buffer
void string_to_lowercase(char buf[], size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        buf[i] = tolower(buf[i]);
    }
}

// searches if a character is in an array
bool is_elem(char c, char str[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] == c)
        {
            return true;
        }
    }
    return false;
}

// removes leading spaces
void removeLeadingSpaces(char *str, int len)
{
    char str1[len];
    int count = 0, j, k;

    while (str[count] == ' ')
    {
        count++;
    }

    for (j = count, k = 0;
         str[j] != '\0'; j++, k++)
    {
        str1[k] = str[j];
    }
    str1[k] = '\0';

    for (int i = 0; i < len; i++)
    {
        str[i] = str1[i];
    }
}

// removes trailing spaces
void removeTrail(char *str, int len)
{
    int count = 0;
    int i = 0;
    while (i < len)
    {
        if (isspace(str[i]) && (count == 0))
        {
            count++;
        }
        else if (isspace(str[i]) && (count == 1))
        {
            str[i - 1] = '\0';
            return;
        }
        else
        {
            count = 0;
        }
        i++;
    }
}

// replaces . ? ! ' " , of a string, with empty string
void getRoot(char buf[], int len)
{
    char new_buf[len];
    int j = 0;
    for (int i = 0; i < len; i++)
    {

        if ((buf[i] == '.') || (buf[i] == '!') || (buf[i] == '?') || (buf[i] == ',') || (buf[i] == '\'') || (buf[i] == '"'))
        {
            continue;
        }
        else
        {
            new_buf[j] = buf[i];
            j++;
        }
    }
    j++;
    new_buf[j] = '\0';
    strcpy(buf, new_buf);
}

// stores in reply what aliza will say to the user
void aliza_says(char input[], char reply[], int input_len)
{
    // COMMAND CORE
    if (is_elem('+', input, input_len) || is_elem('-', input, input_len) || is_elem('/', input, input_len) || is_elem('*', input, input_len))
    {
        // calculate stuff
    } else if (strstr(input, "repeat"))
    {
        // repeat after me
    } else if (input_len==0)
    {
        char noresp[NUMBEROFNORESP][MAXBUF] = {"Are you busy? You said nothing.", "Is anyone there?", "You haven't said anything.", "I'm here waiting for you.", "Get back to me when you are ready.", "Hello?", "I'm waiting.", "Did you mean to send me a blank message?", "Your message was blank."};
        strcpy(reply, noresp[rand() % NUMBEROFNORESP]);
    } else
    {
        // send stuff to json, get it back
        // also, set conv_ended var to true when we reach END IT
    }

}

int main()
{
    printf("\n");
    printf("*************************** ALIZA CHATBOT ***************************\n");
    printf("*********************** By Rafael Sanchez ***************************\n");
    printf("***************** To stop Aliza, type bye ***************************\n");
    printf("\n");
    printf("-------------------- CONVERSATION STARTED ---------------------------\n");
    printf("\n");

    char greetings[NUMBEROFGREET][MAXBUF] = {"Hey there...", "How do you do?", "How have you been?", "Hello there.", "Hi!", "How are you doing?", "How's it going?", "It's great to see you.", "What's up?", "Yo!", "Lovely to see you.", "Ahoy!", "Heyo.", "HOLA."};
    printf("Aliza: %s\n", greetings[rand() % NUMBEROFGREET]);

    while (1)
    {
        // TO THIS ADD THE CHATLOG FOLDER THAT IT NEEDS TO WRITE TO IT AS WELL
        char *reply = calloc(MAXBUF, sizeof(char));
        char input[MAXBUF];
        printf("User: ");
        fgets(input, MAXBUF, stdin);
        input[strlen(input) - 1] = '\0';
        aliza_says(input, reply, strlen(input));
        printf("Aliza: %s\n", reply);
        free(reply);
        if (conv_ended)
        {
            break;
        }
    }
    printf("\n");
    printf("-------------------- CONVERSATION ENDED -----------------------------\n");
    printf("\n");
    return 0;
}
