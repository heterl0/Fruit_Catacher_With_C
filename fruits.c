#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED	4
#define MAGENTA	5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

void apple(short** arr, int i) {
    textcolor(GREEN);
    printf(" %c ", 194);
    gotoxy(arr[i][0],arr[i][1] + 1);
    textcolor(RED);
    printf("%c%c%c", 222, 219, 221);
    textcolor(WHITE);
}

void orange(short** arr, int i) {
    textcolor(6);
    printf("%c%c", 219, 219);
    textcolor(WHITE);
}

void cherry(short** arr, int i) {
    textcolor(LIGHTGREEN);
    printf("%c", 191);
    gotoxy(arr[i][0],arr[i][1] + 1);
    textcolor(RED);
    printf("%c", 223);
    textcolor(WHITE);
}

void heart(short** arr, int i) {
    textcolor(LIGHTRED);
    printf("%c", 3);
    textcolor(WHITE);
}

void madMove(short** arr, int i) {
    textcolor(BLUE);
    printf("%c%c", 199, 163);
    gotoxy(arr[i][0],arr[i][1] + 1);
    textcolor(LIGHTGRAY);
    printf("%c%c", 202, 128);
    textcolor(WHITE);
}

void boom(short** arr, int i) {
    textcolor(WHITE);
    printf("%c", 203);
    gotoxy(arr[i][0],arr[i][1] + 1);
    printf("%c", 219);
}


void reverseFunction(short** arr, int i) {
    textcolor(YELLOW);
    printf("%c", 219);
    textcolor(MAGENTA);
    printf("%c", 219);
    textcolor(WHITE);
}

void fruit(short** arr, int i) {
    switch(arr[i][2]) {
        case 0:
            boom(arr, i);
            break;
        case 1:
        case 2:
        case 3:
            apple(arr, i);
            break;
        case 4:
        case 5:
            orange(arr, i);
            break;
        case 6:
            cherry(arr, i);
            break;
        case 7:
            madMove(arr, i);
            break;
        case 8:
            reverseFunction(arr, i);
            break;
        case 9:
            heart(arr, i);
            break;
    }
}
