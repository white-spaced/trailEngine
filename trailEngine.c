#include <stdio.h>

void passagePrint(char* data) {
    printf("%s\n", data);
    int continuePassage = 0;
    int addedLines = 0;
    while(!continuePassage) {
        printf("[C]ontinue, [S]ave, [L]oad\n");
        char choice = 0;
        scanf( " %c", &choice);
        if (choice == 'c' || choice == 'C') {
            continuePassage = 1;
            addedLines = addedLines + 2;
        } else if (choice == 's' || choice == 'S') {
            printf("Saving is not implemented.\n");
            addedLines = addedLines + 3;
        } else if (choice == 'l' || choice == 'L') {
            printf("Loading is not implemented.\n");
            addedLines = addedLines + 3;
        } else {
            printf("Invalid option.\n");
            addedLines = addedLines + 3;
        }
    }
    for(int i=0;i<addedLines;i++) {
      printf("\x1b[1F\x1b[2K");
    }
    printf("\n");
    return;
}

int advancePassage(int* passagePointer) {
    switch(*passagePointer) {
        case 0:
            passagePrint("This is passage 0");
            *passagePointer = 1;
            return 0;
            break;
        case 1:
            passagePrint("This is passage 1");
            *passagePointer = -1;
            return 0;
            break;
        default:
            return 1;
            break;
    }
}


int main() {
    int passage = 0;
    int exit = 0;
    while(!exit) {
        exit = advancePassage(&passage);
    }
    return 0;
}
