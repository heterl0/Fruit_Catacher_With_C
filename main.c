#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define SIZE_SCREEN "MODE CON COLS=118 LINES=30"
// create struct
struct man {
    char name[10];
    int score;
};


// relative to <windows.h>
void textcolor(int color) {
    static int __BACKGROUND;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color + (__BACKGROUND << 4));
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void ShowConsoleCursor(int x) {

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = x; // set the cursor visibility
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

}

// time.h
void delay(int milli_seconds) {
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


// functions to display

void drawSquare(int start_x, int start_y, int wide, int high) {
    int i;

    for(i = 1; i <= wide - 2; i++) {
        gotoxy(i + start_x, start_y);
        printf("%c",205);
        gotoxy(i + start_x,start_y + high - 1);
        printf("%c",205);
    }

    for(i = 1; i <= high - 2; i++) {
        gotoxy(start_x,i + start_y);
        printf("%c",186);
        gotoxy(start_x + wide - 1, i +start_y);
        printf("%c",186);
    }

    gotoxy(start_x + wide - 1, start_y);
    printf("%c",187);

    gotoxy(start_x + wide - 1, start_y + high - 1);
    printf("%c",188);

    gotoxy(start_x ,start_y);
    printf("%c",201);

    gotoxy(start_x, start_y + high - 1);
    printf("%c",200);

}

void changePoint(int p) {
    gotoxy(79,12);
    printf("Score %d", p);
}

void changeLevel(int level) {
    gotoxy(79,10);
    printf("Level %d", level);
}

void changeLife(int life) {
    gotoxy(80,14);
    printf("life ");
    textcolor(4);
    printf("%d %c  ", life, 3);
    textcolor(15);

}


//functions to control

int moveRight(int x) {
    char str[6] = {212, 205, 205, 205, 190, '\0'};
    gotoxy(x, 24);
    printf(" ");
    gotoxy(++x, 24);
    printf("%s", str);
    return x;
}
int moveLeft(int x) {
    char str[6] = {212, 205, 205, 205, 190, '\0'};
    gotoxy(x + 4, 24);
    printf(" ");
    gotoxy(--x, 24);
    printf("%s", str);
    return x;
}

//functions relative to gameplay

short** createFruit(short** arr) {
    for (int i = 0; i < 10; i++) {
        if (arr[i][1] == 23 || arr[i][1] == 0) {
            arr[i][0] = 47 + rand() % 21; // khoi tao vi tri rot
            arr[i][1] = 5;
            arr[i][2] = rand() % 10; // khoi tao loai qua
            break;
        }
    }
    return arr;
}


int newLevel(int point) {
    if (point < 100) {
        return 1;
    }
    if (point < 200) {
        return 2;
    }
    if (point < 300) {
        return 3;
    }
    if (point < 500) {
        return 4;
    }
    if (point < 1000) {
        return 5;
    }
    if (point < 2000) {
        return 6;
    }
    if (point < 5000) {
        return 7;
    }
    if (point < 7000) {
        return 8;
    }
    if (point < 10000) {
        return 9;
    }
    if (point >= 10000) {
        return 10;
    }
}

void updateReverse(int** bonus) {
    gotoxy(23, 19);
    if (bonus[0][0] != 0) {
        printf("+%ds", (bonus[0][1] - clock()) / 1000 + 1);
    } else {
        printf("    ");
        bonus[0][1] = 0;
    }
}

void updateMadmove(int** bonus) {
    gotoxy(23, 17);
    if (bonus[1][0] != 0) {
        printf("+%ds", (bonus[1][1] - clock()) / 1000 + 1);
    } else {
        printf("    ");
        bonus[1][1] = 0;
    }
}

void checkBonus(int** bonus) {
    if (bonus[0][0] == 1) {
        if (bonus[0][1] - clock() > 0) {
            updateReverse(bonus);
        } else {
            bonus[0][0] = 0;
            updateReverse(bonus);
        }
    }
    if (bonus[1][0] == 1) {
        if (bonus[1][1] - clock() > 0) {
            updateMadmove(bonus);
        } else {
            bonus[1][0] = 0;
            updateMadmove(bonus);
        }
    }
}

int setSpeed(int level) {
    switch (level) {
        case 1:
            return 450;
        case 2:
            return 400;
        case 3:
            return 350;
        case 4:
            return 300;
        case 5:
            return 275;
        case 6:
        case 7:
            return 250;
        case 8:
        case 9:
            return 225;
        case 10:
            return 200;
    }
}


int plusPoint(short** arr, int i, int point, int** bonus, int* life) {
    int pointGet = 0;
    int bn = 1;
    switch(arr[i][2]) {
        case 0:
            *life = 0;
            break;
        case 1:
        case 2:
        case 3:
            pointGet = 10;
            break;
        case 4:
        case 5:
            pointGet = 20;
            break;
        case 6:
            pointGet = 30;
            break;
        case 7:
            pointGet = 10;
            bonus[1][0] = 1;
            if (bonus[1][1] != 0) {
                bonus[1][1] += 5000;
            } else {
                bonus[1][1] = 5000 + clock();
            }
            updateMadmove(bonus);
            break;
        case 8:
            pointGet = 10;
            bonus[0][0] = 1;
            if (bonus[0][1] != 0) {
                bonus[0][1] += 5000;
            } else {
                bonus[0][1] = 5000 + clock();
            }
            updateReverse(bonus);
            break;
        case 9:
            pointGet = 10;
            *life = *life + 1;
            changeLife(*life);
            break;

    }
    if (bonus[0][0] == 1) {
        bn = bn * 2;
    }
    if (bonus[1][0] == 1) {
        bn = bn * 3;
    }
    return point + pointGet * bn;
}

short** moveFruit(short** arr, int x, int* p, int* level, int* sLevel, int** bonus, int* life) {
    for (int i = 0; i < 10; i++) {
        if (arr[i][1] != 23 && arr[i][1] != 0) {
            gotoxy(arr[i][0],arr[i][1]);
            printf("    ");
            gotoxy(arr[i][0],arr[i][1] + 1);
            printf("    ");
            if (arr[i][1] != 22) {
                arr[i][1] = arr[i][1] + 1;
                gotoxy(arr[i][0],arr[i][1]);
                fruit(arr, i);
            } else {
                arr[i][1] = arr[i][1] + 1;
                if (arr[i][0] >= x && arr[i][0] <= x + 4) {
                    *p = plusPoint(arr, i, *p, bonus, life);
                    if (*level < newLevel(*p)) {
                        *level = newLevel(*p);
                        changeLevel(*level);
                        *sLevel = setSpeed(*level);
                    }
                    changePoint(*p);
                } else if (arr[i][2] >= 1 && arr[i][2] <= 6) {
                    *life = *life - 1;
                    changeLife(*life);
                }
            }
        }

    }
    return arr;
}





int playGame(int select) {
    srand(time(NULL));
    setUpGame();
    short** fruits = (short**)calloc(10, sizeof(short*));
    for (int i = 0; i < 10; i++) {
        fruits[i] = (short*)calloc(3, sizeof(short));
    }
    int** bonus = (int**)calloc(2, sizeof(int*));
    for (int i = 0; i < 2; i++) {
        bonus[i] = (int*)calloc(2, sizeof(int));
    }
    int life = 3;
    int point = 0;
    int x = 47;
    gotoxy(x, 24);
    printf("%c%c%c%c%c", 212, 205, 205, 205, 190);
    char c;
    int level = 1;
    int speedLevel = setSpeed(level);
    int speedDropFruit = speedLevel + clock();
    int speedCreateFruit = clock();
    while (life != 0) {
        if (_kbhit() || bonus[1][0] == 1 && clock() > speedDropFruit) {
            if (bonus[1][0] == 1 && clock() > speedDropFruit) {
                if (rand() % 2 == 0) {
                    c = 77;
                } else {
                    c = 75;
                }
            } else  c = _getch();
            if (bonus[0][0] == 1) {
                if (c == 77) {
                    c = 75;
                } else if ( c == 75) {
                    c = 77;
                }
            }
            if (c == 77 && x < 66) {
                x = moveRight(x);
            }
            if (c == 75 && x > 47) {
                x = moveLeft(x);
            }
        }
        if (clock() > speedCreateFruit) {
            fruits = createFruit(fruits);
            speedCreateFruit = speedLevel * 15 / (level <= 3 ? 2 : ((level + 1) / 2)) + clock();
        }
        if (clock() > speedDropFruit) {
            checkBonus(bonus);
            fruits = moveFruit(fruits, x, &point, &level, &speedLevel, bonus, &life);
            speedDropFruit = speedLevel + clock();
        }
        if (life == 0) {
            system("cls");
            for (int i = 0; i < 10; i++) {
                free(fruits[i]);
            }
            free(fruits);
            for (int i = 0; i < 2; i++) {
                free(bonus[i]);
            }
            free(bonus);
            return gameOver(point);
        }
    }
}


void printTopScore() {
    FILE *score;
    FILE *name;
    score = fopen("score.txt","r+");
    name = fopen("name.txt", "r+");
    struct man* top = (struct man*)malloc(8*sizeof(struct man));
    fscanf(score, "%d %d %d %d %d %d %d %d", &top[0].score, &top[1].score, &top[2].score, &top[3].score, &top[4].score, &top[5].score, &top[6].score, &top[7].score);
    fscanf(name, "%s %s %s %s %s %s %s %s", top[0].name, top[1].name, top[2].name, top[3].name, top[4].name, top[5].name, top[6].name, top[7].name);
    drawSquare(46, 4, 26, 22);
    gotoxy(46 + 8, 4 + 2);
    printf("TOP SCORE");
    for (int i = 0; i < 8; i++) {
        if (i == 0) {
            textcolor(4);
        } else if (i == 1) {
            textcolor(5);
        } else if (i == 2) {
            textcolor(14);
        } else textcolor(15);
        gotoxy(46 + 4, 8 + 2*i);
        printf("%d  %s", i + 1, top[i].name);
        gotoxy(46 + 16, 8 + 2*i);
        printf("%d", top[i].score);
    }
    gotoxy(4, 28);
    printf("Press any button to back to menu.....");
    getch();
    system("cls");
    free(top);
    fclose(score);
    fclose(name);
}


int main() {
    system(SIZE_SCREEN);
    int select = 0;
        while (select != 3) {
        if (select != 1)
            select = printMenu();
        if (select == 1) {
            select = playGame(select);
        }
        if (select == 2) {
            printTopScore();
        }
    }
    return 0;
}
