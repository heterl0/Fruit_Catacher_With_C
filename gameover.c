#include<stdio.h>
struct letter {
    char ch[1000];
    int x;
    int y;
};

struct man {
    char name[10];
    int score;
};

void printChar(struct letter* cha, int x, int y) {
    gotoxy(x, y);
    for (int i = 0; cha->ch[i] != '\0'; i++) {
        if (cha->ch[i] != '\n') {
            printf("%c", cha->ch[i]);
        } else {
            y = y + 1;
            gotoxy(x, y);
        }
    }
}



int gameOver(int point) {
    struct letter* g = (struct letter*)malloc(sizeof(struct letter));

    strcpy(g->ch, "  $$$$$$$$$$\n");
    strcat(g->ch, " $$$      $$$\n");
    strcat(g->ch, " $$\n");
    strcat(g->ch, " $$\n");
    strcat(g->ch, " $$        $$\n");
    strcat(g->ch, " $$      $$$$$$\n");
    strcat(g->ch, " $$        $$\n");
    strcat(g->ch, " $$$      $$$\n");
    strcat(g->ch, "  $$$$$$$$$$\n");


    struct letter* a = (struct letter*)malloc(sizeof(struct letter));

    strcpy(a->ch, "         $\n");
    strcat(a->ch, "        $$$\n");
    strcat(a->ch, "       $$$$$\n");
    strcat(a->ch, "      $$$ $$$\n");
    strcat(a->ch, "     $$$   $$$\n");
    strcat(a->ch, "    $$$$$$$$$$$\n");
    strcat(a->ch, "   $$$       $$$\n");
    strcat(a->ch, "  $$$         $$$\n");
    strcat(a->ch, " $$$           $$$\n");

    struct letter* m = (struct letter*)malloc(sizeof(struct letter));

    strcpy(m->ch, "         $       $\n");
    strcat(m->ch, "        $$$     $$$\n");
    strcat(m->ch, "       $$$$$   $$$$$\n");
    strcat(m->ch, "      $$$ $$$ $$$ $$$\n");
    strcat(m->ch, "     $$$   $$ $$   $$$\n");
    strcat(m->ch, "    $$$     $$$     $$$\n");
    strcat(m->ch, "   $$$               $$$\n");
    strcat(m->ch, "  $$$                 $$$\n");
    strcat(m->ch, " $$$                   $$$\n");

    struct letter* e = (struct letter*)malloc(sizeof(struct letter));

    strcpy(e->ch, "   $$$$$$$$\n");
    strcat(e->ch, "  $$$\n");
    strcat(e->ch, "  $$\n");
    strcat(e->ch, "  $$\n");
    strcat(e->ch, "  $$$$$$$$$\n");
    strcat(e->ch, "  $$\n");
    strcat(e->ch, "  $$\n");
    strcat(e->ch, "  $$$\n");
    strcat(e->ch, "   $$$$$$$$\n");


    struct letter* o = (struct letter*)malloc(sizeof(struct letter));

    strcpy(o->ch, "   $$$$$$$\n");
    strcat(o->ch, "  $$     $$\n");
    strcat(o->ch, " $$       $$\n");
    strcat(o->ch, " $$       $$\n");
    strcat(o->ch, " $$       $$\n");
    strcat(o->ch, " $$       $$\n");
    strcat(o->ch, " $$       $$\n");
    strcat(o->ch, "  $$     $$\n");
    strcat(o->ch, "   $$$$$$$\n");

    struct letter* v = (struct letter*)malloc(sizeof(struct letter));

    strcpy(v->ch, " $$              $$\n");
    strcat(v->ch, " $$$            $$$\n");
    strcat(v->ch, "  $$$          $$$\n");
    strcat(v->ch, "   $$$        $$$\n");
    strcat(v->ch, "    $$$      $$$\n");
    strcat(v->ch, "     $$$    $$$\n");
    strcat(v->ch, "      $$$  $$$\n");
    strcat(v->ch, "       $$$$$$\n");
    strcat(v->ch, "        $$$$\n");

    struct letter* r = (struct letter*)malloc(sizeof(struct letter));

    strcpy(r->ch, " $$$$$$$$$\n");
    strcat(r->ch, " $$$    $$$\n");
    strcat(r->ch, " $$      $$\n");
    strcat(r->ch, " $$$    $$$\n");
    strcat(r->ch, " $$$$$$$$$\n");
    strcat(r->ch, " $$    $$\n");
    strcat(r->ch, " $$     $$\n");
    strcat(r->ch, " $$      $$\n");
    strcat(r->ch, " $$       $$\n");

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
        printf("Enter your name to save: ");
        scanf("%s", name);
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
    return menuAgain();
}
