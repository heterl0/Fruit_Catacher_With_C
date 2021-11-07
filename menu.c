void colorForMenu(char s[20], int position_x, int position_y , int color) {
    gotoxy(position_x , position_y);
    textcolor(color);
    if (color == 15) {
        printf("%s        ", s);
    } else {
        printf(">> %s", s);
        textcolor(15);
    }
}

void fruitInMenu()  {
    gotoxy(15, 6);
    textcolor(2);
    printf("   /\n");
    textcolor(5);
    gotoxy(15, 7);
    printf(" ()()\n");
    gotoxy(15, 8);
    printf("()()()\n");
    gotoxy(15, 9);
    printf(" ()()\n");
    gotoxy(15, 10);
    printf("  ()");

    gotoxy(67, 2);
    textcolor(2);
    printf(",\n");
    textcolor(14);
    gotoxy(67, 3);
    printf("\\`.__.. \n");
    gotoxy(67, 4);
    printf(" `.__,'  \n");
    textcolor(15);

}


void welcome() {
    char str[2000];
    strcpy(str,"\n");
    strcat(str,"\n");
    strcat(str,"                        $$$    $$$             $$       $$\n");
    strcat(str,"                         $$$    $$$   $       $$        $$\n");
    strcat(str,"                          $$$    $$$ $$      $$         $$\n");
    strcat(str,"                           $$$    $$$$      $$          $$\n");
    strcat(str,"                            $$$    $$$$    $$    $$$$   $$     $$$$    $$$$   $$$  $$$    $$$$\n");
    strcat(str,"                             $$$  $$ $$$  $$    $    $  $$    $       $    $  $   $   $  $    $\n");
    strcat(str,"                              $$$$$   $$$$$     $$$$$$  $$    $       $    $  $   $   $  $$$$$$\n");
    strcat(str,"                               $$$     $$$      $       $$$$  $    $  $    $  $   $   $  $\n");
    strcat(str,"                                $       $        $$$$    $$$   $$$$    $$$$   $   $   $   $$$$\n");
    strcat(str,"\n");
    strcat(str,"                                                       $\n");
    strcat(str,"                                                      $$     $$$$\n");
    strcat(str,"                                                    $$$$$   $    $\n");
    strcat(str,"                                                      $$    $    $\n");
    strcat(str,"                                                      $$ $  $    $\n");
    strcat(str,"                                                       $$    $$$$\n");
    strcat(str,"\n");
    ShowConsoleCursor(0);
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
        delay(1);
    }
    fruitInMenu();
    delay(500);
    gotoxy(0, 19);
    printf("                                             __________Menu Game___________");
    gotoxy(3, 28);
    printf("This project is copyright by group 10");

}


int printMenu(){
    welcome();
    int n = 21;
    char str[][20] = {"Play", "Score", "Exit"};
    for (int i = 0; i < 3; i++) {
        gotoxy(54, n + i);
        printf("%s", str[i]);
    }
    colorForMenu(str[0], 54, n, 14);
    while (1){
        if(_kbhit()){
            int c = getch();
            // 80 = mui ten di xuong
            if(c == 80){
                colorForMenu(str[n - 21], 54, n, 15);
                n++;
                if(n == 24){
                    n = 21;
                }
                colorForMenu(str[n - 21], 54, n, 14);
            }
            // 72 la mui ten di len
            if(c == 72){
                colorForMenu(str[n - 21], 54, n, 15);
                n--;
                if(n == 20){
                    n = 23;
                }
                colorForMenu(str[n - 21], 54, n, 14);
            }
            if (c == 13) {
                break;
            }
        }
    }
    system("cls");
    return n - 20;
}

int menuAgain() {
     int n = 18;
    char str[3][20];
    strcpy(str[0], "Play Again");
    strcpy(str[1], "Score");
    strcpy(str[2], "Exit");
    for (int i = 0; i < 3; i++) {
        gotoxy(11, n + i);
        printf("%s", str[i]);
    }
    colorForMenu(str[0], 11, n, 14);
    while (1){
        if(_kbhit()){
            int c = getch();
            // 80 = mui ten di xuong
            if(c == 80){
                colorForMenu(str[n - 18], 11, n, 15);
                n++;
                if(n == 21){
                    n = 18;
                }
                colorForMenu(str[n - 18], 11, n, 14);
            }
            // 72 la mui ten di len
            if(c == 72){
                colorForMenu(str[n - 18], 11, n, 15);
                n--;
                if(n == 17){
                    n = 20;
                }
                colorForMenu(str[n - 18], 11, n, 14);
            }
            if (c == 13) {
                break;
            }
        }
    }
    system("cls");
    return n - 17;
}

void setUpGame() {
        drawSquare(20, 4, 26, 22);

        gotoxy(28, 6);
        textcolor(2);
        printf(" %c ", 194);
        gotoxy(28, 6 + 1);
        textcolor(4);
        printf("%c%c%c", 222, 219, 221);
        textcolor(15);
        gotoxy(28 + 4, 6 + 1);
        printf("10 point");

        textcolor(6);
        gotoxy(28, 9);
        printf("%c%c", 219, 219);
        textcolor(15);
        gotoxy(28 + 4, 9);
        printf("20 point");

        textcolor(10);
        gotoxy(28, 10);
        printf("%c", 191);
        gotoxy(28, 10 + 1);
        textcolor(4);
        printf("%c", 223);
        textcolor(15);
        gotoxy(28+ 4, 10 + 1);
        printf("30 point");

        gotoxy(28, 14);
        textcolor(12);
        printf("%c", 3);
        textcolor(15);
        gotoxy(28 + 4, 14);
        printf("+1 heart");

        gotoxy(28, 16);
        textcolor(1);
        printf("%c%c", 199, 163);
        gotoxy(28, 16 + 1);
        textcolor(7);
        printf("%c%c", 202, 128);
        textcolor(15);
        gotoxy(28 + 4, 16 + 1);
        printf("Mad Move: x3");

        gotoxy(28, 19);
        textcolor(14);
        printf("%c", 219);
        textcolor(5);
        printf("%c", 219);
        textcolor(15);
        gotoxy(28 + 4, 19);
        printf("Reverse: x2");

        gotoxy(28, 21);
        textcolor(15);
        printf("%c", 203);
        gotoxy(28, 22);
        printf("%c", 219);
        gotoxy(28 + 4, 22);
        printf("Game Over");

        drawSquare(46, 4, 26, 22);
        drawSquare(72, 4, 26, 22);
        changePoint(0);
        changeLevel(1);
        changeLife(3);
        ShowConsoleCursor(0);
}
