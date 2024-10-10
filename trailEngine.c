#include <ncurses.h>

void passagePrint(char* data) {
    printw("%s\n", data);
    int continuePassage = 0;
    printw("[C]ontinue, [s]ave, [l]oad\n");
    refresh();
    while(!continuePassage) {  
        char choice = getch();
        if (choice == 'c' || choice == 'C') {
            continuePassage = 1;
        } else if (choice == 's' || choice == 'S') {
            printw("Saving is not implemented.\n");
            refresh();
        } else if (choice == 'l' || choice == 'L') {
            printw("Loading is not implemented.\n");
            refresh();
        }
    }
    printw("\n");
    refresh();
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
            printw("Passage %d is undefined, terminating program.\n", *passagePointer);
            return 1;
            break;
    }
}


int main() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    int passage = 0;
    int exit = 0;
    while(!exit) {
        exit = advancePassage(&passage);
    }
    printw("Program has terminated. Press any key to continue.\n");
    refresh();
    getch();
    endwin();
    return 0;
}