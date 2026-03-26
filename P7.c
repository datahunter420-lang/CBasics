/*P7.** Take a character input. Using `if` and logical operators, print:
- "Vowel" if it's a, e, i, o, u
- "Consonant" if it's any other letter
- "Not a letter" if it's a digit or symbol*/

#include <stdio.h>
#include <ctype.h>    // for tolower()

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);    // space before %c — skips leftover newline

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {

        // It IS a letter — now check vowel or consonant
        char lower = tolower(ch);   // normalize to lowercase

        if (lower=='a' || lower=='e' || lower=='i' ||
            lower=='o' || lower=='u') {
            printf("Vowel\n");
        }
        else {
            printf("Consonant\n");
        }

    }
    else {
        // Not a letter — digit, symbol, space, etc.
        printf("Not a letter\n");
    }

    return 0;
}
