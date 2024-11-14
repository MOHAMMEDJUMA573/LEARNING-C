#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>

//function to check the presence of a char in an array
int special_check(char *special,char input) {
    while (*special) {
        if (*special == input) {
            return 1;
        }
        special++;
    }
}


// the main function
int main() {

    char pass[50], pass2[50];
    int has_lower = 0, has_upper = 0, has_digit = 0, has_special= 0, i=0;
    int choice;

    //capture the password from the user
    printf("***___Mohammed's Password Checker___***\n");
    printf("Please enter your password: ");
    fgets(pass,sizeof(pass),stdin);

    //remove the newline character if in existence
    pass[strcspn(pass, "\n")] = '\0';

    //an array of the special characters
    char specials[] = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";

    //test for the strength of the password
    while (pass[i] != 0) {
        if (islower(pass[i])) {
            has_lower = 1;
        }else if (isdigit(pass[i])) {
            has_digit = 1;
        }else if (isupper(pass[i])) {
            has_upper = 1;
        }else if(special_check(specials, pass[i])) {
            has_special = 1;
        }
        i++; //move to the next character in the word
    }

    if (has_digit && has_lower &&has_special && has_upper) {
        printf("Your password is strong proceed😇...\n\n");

        //begin password encryption
        printf("***WELCOME TO THE PASSWORD ENCRYPTION SECTOR\n");

        //confirm the entered passswrd 
        printf("Please confirm your password: ");
        fgets(pass2,sizeof(pass2),stdin);

        //strip off any newline character that mght be present
        pass2[strcspn(pass2, "\n")] = '\0';

        //check if the password is the same and proceed else abort
        if (strcmp(pass,pass2) == 0) {
            printf("Password confirmed!😇 Welcome\n");
            
            printf("Encrypted password\n***___***\n");
            i=0;
            while (pass[i] != 0) {
                //encrypt the pass word by the given formula
                pass[i] = (pass[i] + 5) % 256; 
                //print the new character after encryption
                printf("%c",pass[i]);
                //increment to the next character in the password
                i++;

            }
            printf("\n");

            //ask if the user would like to decript the password
            printf("Proceed to decryption ?\n 1.(YES) \n 2. (NO)\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            getchar(); //remove the newline character from the scanf ..avoiding complicating matters

            switch (choice) {
                case 1: {
                    printf("***Welcome to decryption***\n\n");
                    i=0;
                    while (pass[i] != 0) {
                        //decrypt the password by reversing the formula
                        pass[i] = (pass[i] - 5 + 256) % 256;
                        //print the password
                        printf("%c", pass[i]);
                        //increment to the next character
                        i++;
                    }
                    printf("\n");
                    printf("Copyright © 2024 JUMA MOHAMMED\n");
                    break;
                }
                case 2: {
                    printf("Welcome once again😇!\n");
                    printf("Copyright © 2024 JUMA MOHAMMED\n");
                    return 2;
                }
                default : {
                    printf("Go learn to use common sense my guy😂!\n");
                    return 3;
                }
            }

        }else {
            printf("Wrong password bruv😅\n^_^\nGive it a thought and be back!\n");
            printf("Copyright © 2024 JUMA MOHAMMED\n");
            return 1;
        }


    }else {
        printf("You have a weak password my guy😂!");
        if (!has_digit) {
            printf("Your password must have atleast one digit\n");
        }
        if (!has_special) {
            printf("Your password must have atleast one special character\n");
        }
        if (!has_lower) {
            printf("Your password must have atleast one lower case letter\n");
        }
        if (!has_upper) {
            printf("Your password must have atleast one uppercase character");
        }
        printf("Copyright © 2024 JUMA MOHAMMED\n");

    }
    return 0;
}