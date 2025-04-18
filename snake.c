#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define WIDTH 30
#define HEIGHT 20
#define snakelength 5
#define DELAY 100000

int gameover;
int score;
int tailX[snakelength];
int tailY[snakelength];
int snakeX, snakeY;
int foodX, foodY;
int direction;

void setup() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    timeout(DELAY);

    snakeX = WIDTH / 2;
    snakeY = HEIGHT / 2;
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
    direction = KEY_RIGHT;

    gameover = 0;
    score = 0;
}

void draw() {
    clear();

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
                mvaddch(i, j, '#');
            else
                mvaddch(i, j, ' ');
        }
    }

    mvaddch(foodY, foodX, '*');

    for (int i = 0; i < snakelength; i++) {
        if (i == 0)
            mvaddch(tailY[i], tailX[i], 'O');
        else
            mvaddch(tailY[i], tailX[i], 'o');
    }

    mvprintw(HEIGHT + 1, 0, "Score: %d", score);
}

void input() {
    int key = getch();

    switch (key) {
        case KEY_UP:
            if (direction != KEY_DOWN)
                direction = KEY_UP;
            break;
        case KEY_DOWN:
            if (direction != KEY_UP)
                direction = KEY_DOWN;
            break;
        case KEY_LEFT:
            if (direction != KEY_RIGHT)
                direction = KEY_LEFT;
            break;
        case KEY_RIGHT:
            if (direction != KEY_LEFT)
                direction = KEY_RIGHT;
            break;
        case 'q':
            gameover = 1;
            break;
    }
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = snakeX;
    tailY[0] = snakeY;

    for (int i = 1; i < snakelength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (direction) {
        case KEY_UP:
            snakeY--;
            break;
        case KEY_DOWN:
            snakeY++;
            break;
        case KEY_LEFT:
            snakeX--;
            break;
        case KEY_RIGHT:
            snakeX++;
            break;
    }

    if (snakeX < 0 || snakeX >= WIDTH || snakeY < 0 || snakeY >= HEIGHT)
        gameover = 1;

    for (int i = 0; i < snakelength; i++) {
        if (tailX[i] == snakeX && tailY[i] == snakeY)
            gameover = 1;
    }

    if (snakeX == foodX && snakeY == foodY) {
        score += 10;
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;
    }
}

void teardown() {
    endwin();
}

void sigintHandler(int signum) {
    gameover = 1;
}

int main() {
    signal(SIGINT, sigintHandler);

    setup();

    while (!gameover) {
        draw();
        input();
        logic();
    }

    teardown();
    printf("Game Over! Your Score: %d\n", score);
    return 0;
}
