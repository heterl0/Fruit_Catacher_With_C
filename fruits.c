
void apple(short** arr, int i) {
    textcolor(2);
    printf(" %c ", 194);
    gotoxy(arr[i][0],arr[i][1] + 1);
    textcolor(4);
    printf("%c%c%c", 222, 219, 221);
    textcolor(15);
}

void orange(short** arr, int i) {
    textcolor(6);
    printf("%c%c", 219, 219);
    textcolor(15);
}

void cherry(short** arr, int i) {
    textcolor(10);
    printf("%c", 191);
    gotoxy(arr[i][0],arr[i][1] + 1);
    textcolor(4);
    printf("%c", 223);
    textcolor(15);
}

void heart(short** arr, int i) {
    textcolor(12);
    printf("%c", 3);
    textcolor(15);
}

void madMove(short** arr, int i) {
    textcolor(1);
    printf("%c%c", 199, 163);
    gotoxy(arr[i][0],arr[i][1] + 1);
    textcolor(7);
    printf("%c%c", 202, 128);
    textcolor(15);
}

void boom(short** arr, int i) {
    textcolor(15);
    printf("%c", 203);
    gotoxy(arr[i][0],arr[i][1] + 1);
    printf("%c", 219);
}


void reverseFunction(short** arr, int i) {
    textcolor(14);
    printf("%c", 219);
    textcolor(5);
    printf("%c", 219);
    textcolor(15);
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
