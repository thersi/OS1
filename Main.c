#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



int main()
{

    while (1) //needs different logic than this maybe
    {
        printf ("\n======================================================\n");
        printf("Select one of the following operations:\n");
        printf("s (schedule) | l (list) | c (cancel) | x (exit)\n");
        printf ("======================================================\n");
        char chr;
        printf("Enter a character: ");
        scanf("%c", &chr);


        switch (chr){
            case 's':
                printf("You typed s\n"); //function call here
                break;

            case 'l':
                printf("You typed l\n"); //function call here
                break;

            case 'c':
                printf("You typed c\n"); //function call here
                break;

            case 'x':
                printf("good bye\n"); //function call here
                exit(0);

                // operator doesn't match any option
            default:
                printf("Error! operator is not correct\n");
                break;
        }
    }

    return 0;
}


