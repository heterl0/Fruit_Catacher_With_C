#include<stdio.h>


struct man {
    char name[10];
    int score;
};

void printChar(char* ch, int x, int y) {
    gotoxy(x, y);
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] != '\n') {
            printf("%c", ch[i]);
        } else {
            y = y + 1;
            gotoxy(x, y);
        }
    }
}

struct man* sort(struct man* top, int yourScore, char* name, int position) {
    for (int i = 7; i > position; i--) {
        strcpy(top[i].name, top[i - 1].name);
        top[i].score = top[i - 1].score;
    }
    strcpy(top[position].name, name);
    top[position].score = yourScore;
    return top;
}

int checkPoint(struct man* top, int newPoint) {
    for (int i = 0; i < 8; i++) {
        if (newPoint >= top[i].score) {
            return i + 1;
        }
    }
    return 0;
}


int gameOver(int point) {
    char* g = (char*)malloc(500);

    strcpy(g, "  $$$$$$$$$$\n");
    strcat(g, " $$$      $$$\n");
    strcat(g, " $$\n");
    strcat(g, " $$\n");
    strcat(g, " $$        $$\n");
    strcat(g, " $$      $$$$$$\n");
    strcat(g, " $$        $$\n");
    strcat(g, " $$$      $$$\n");
    strcat(g, "  $$$$$$$$$$\n");


    char* a = (char*)malloc(500);

    strcpy(a, "         $\n");
    strcat(a, "        $$$\n");
    strcat(a, "       $$$$$\n");
    strcat(a, "      $$$ $$$\n");
    strcat(a, "     $$$   $$$\n");
    strcat(a, "    $$$$$$$$$$$\n");
    strcat(a, "   $$$       $$$\n");
    strcat(a, "  $$$         $$$\n");
    strcat(a, " $$$           $$$\n");

    char* m = (char*)malloc(500);

    strcpy(m, "         $       $\n");
    strcat(m, "        $$$     $$$\n");
    strcat(m, "       $$$$$   $$$$$\n");
    strcat(m, "      $$$ $$$ $$$ $$$\n");
    strcat(m, "     $$$   $$ $$   $$$\n");
    strcat(m, "    $$$     $$$     $$$\n");
    strcat(m, "   $$$               $$$\n");
    strcat(m, "  $$$                 $$$\n");
    strcat(m, " $$$                   $$$\n");

    char* e = (char*)malloc(500);

    strcpy(e, "   $$$$$$$$\n");
    strcat(e, "  $$$\n");
    strcat(e, "  $$\n");
    strcat(e, "  $$\n");
    strcat(e, "  $$$$$$$$$\n");
    strcat(e, "  $$\n");
    strcat(e, "  $$\n");
    strcat(e, "  $$$\n");
    strcat(e, "   $$$$$$$$\n");


    char* o = (char*)malloc(500);

    strcpy(o, "   $$$$$$$\n");
    strcat(o, "  $$     $$\n");
    strcat(o, " $$       $$\n");
    strcat(o, " $$       $$\n");
    strcat(o, " $$       $$\n");
    strcat(o, " $$       $$\n");
    strcat(o, " $$       $$\n");
    strcat(o, "  $$     $$\n");
    strcat(o, "   $$$$$$$\n");

    char* v = (char*)malloc(500);

    strcpy(v, " $$              $$\n");
    strcat(v, " $$$            $$$\n");
    strcat(v, "  $$$          $$$\n");
    strcat(v, "   $$$        $$$\n");
    strcat(v, "    $$$      $$$\n");
    strcat(v, "     $$$    $$$\n");
    strcat(v, "      $$$  $$$\n");
    strcat(v, "       $$$$$$\n");
    strcat(v, "        $$$$\n");

    char* r = (char*)malloc(500);

    strcpy(r, " $$$$$$$$$\n");
    strcat(r, " $$$    $$$\n");
    strcat(r, " $$      $$\n");
    strcat(r, " $$$    $$$\n");
    strcat(r, " $$$$$$$$$\n");
    strcat(r, " $$    $$\n");
    strcat(r, " $$     $$\n");
    strcat(r, " $$      $$\n");
    strcat(r, " $$       $$\n");

    textcolor(4);
    printChar(g, 9, 2);
    textcolor(3);
    printChar(a, 22, 2);
    textcolor(2);
    printChar(m, 37, 2);
    textcolor(14);
    printChar(e, 59, 2);

    printChar(o, 50, 14);
    textcolor(10);
    printChar(v, 62, 14);
    textcolor(11);
    printChar(e, 79, 14);
    textcolor(12);
    printChar(r, 91, 14);
    textcolor(15);

    gotoxy(11, 15);
    printf("You got %d point", point);


    FILE *score;
    FILE *name;
    score = fopen("score.txt","r+");
    name = fopen("name.txt", "r+");
    struct man* top = (struct man*)malloc(8*sizeof(struct man));
    fscanf(score, "%d %d %d %d %d %d %d %d", &top[0].score, &top[1].score, &top[2].score, &top[3].score, &top[4].score, &top[5].score, &top[6].score, &top[7].score);
    fscanf(name, "%s %s %s %s %s %s %s %s", top[0].name, top[1].name, top[2].name, top[3].name, top[4].name, top[5].name, top[6].name, top[7].name);
    gotoxy(11, 16);
    if (checkPoint(top, point) > 0) {
        int i = checkPoint(top, point);
        char name[10];

        printf("Your score in top %d", i);
        gotoxy(11, 17);
        ShowConsoleCursor(1);
        printf("Enter your name to save: ");
        scanf("%7s", name);
        ShowConsoleCursor(0);
        top = sort(top, point, name, i - 1);
    } else {
        printf("You are not in top score");

    }
    score = fopen("score.txt","w");
    name = fopen("name.txt", "w");
    fprintf(score, "%d %d %d %d %d %d %d %d", top[0].score, top[1].score, top[2].score, top[3].score, top[4].score, top[5].score, top[6].score, top[7].score);
    fprintf(name, "%s %s %s %s %s %s %s %s", top[0].name, top[1].name, top[2].name, top[3].name, top[4].name, top[5].name, top[6].name, top[7].name);
    fclose(score);
    fclose(name);
    free(g);
    free(a);
    free(m);
    free(e);
    free(o);
    free(v);
    free(r);
    free(top);
    return menuAgain();
}
