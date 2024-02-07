/*
Name : Harish Thangaraj
Reg_No : 21BRS1033
Slot : L45+L46
Language considered : L = { a^n b^m ; (n)mod 2=0, m>=1 }
*/

// Including header files
#include <stdio.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABETS 2

// Global declaration of dfa array and its size variables
int dfa[MAX_STATES][MAX_ALPHABETS];
int no_states, no_alphabets, accept_state;
int state = 0;

// Consructing a dfa
int construct_dfa()
{

    // Initializing the table
    printf("Enter No. of states");
    scanf("%d", &no_states);
    printf("Enter No. of alphabets");
    scanf("%d", &no_alphabets);
    printf("\n");
      printf("Enter acceptance state");
    scanf("%d", &accept_state);
    printf("\n");

    // Taking user input for transitions

    printf("Consider numerical states and enter the transitions\n");
    printf("If no transition exists, specify -1\n");
    printf("\n");

    for (int i = 0; i < no_states; i++)
    {
        for (int j = 0; j < no_alphabets; j++)
        {
            printf("Enter transition from %d on reading %c : ", i, (j == 0) ? 'a' : 'b');
            scanf("%d", &dfa[i][j]);
        }
    }

    // Printing the transition table
    printf("\nDFA Transition Table:\n");

    printf("States\t| Input 'a'\t| Input 'b'\n");
    printf("--------|------------|------------\n");

    for (int i = 0; i < no_states; i++)
    {
        printf("  %d\t|", i);
        for (int j = 0; j < no_alphabets; j++)
        {
            printf("\t%d\t|", dfa[i][j]);
        }
        printf("\n");
    }
    return accept_state;
}

int validate(char input[], int n)
{
    for (int a = 0; a < n; a++)
    {
        int found = 0;
        for (int j = 0; j < no_states; j++)
        {
            if (input[a] == 'a' && state == j)
            {
                state = dfa[j][0];
                found = 1;
                break;
            }
            if (input[a] == 'b' && state == j)
            {
                state = dfa[j][1];
                found = 1;
                break;
            }
        }
        if (!found)
        {
            // If no valid transition is found for the current character and state, reject the string
            return -1;
        }
    }
    return state;
}

// Primary code
int main()
{
    accept_state=construct_dfa();
    int n, result;
    printf("Enter length of string");
    scanf("%d", &n);
    char str[n];
    printf("Enter string");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &str[i]);
    }
    result = validate(str, n);
    printf("%d", result);
    if (result == accept_state)
    {
        printf("Accepted!");
    }
    else
    {
        printf("Not accepted!");
    }
}
