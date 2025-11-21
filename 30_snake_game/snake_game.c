#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SNAKE_SIZE 25

int time_out = 100;

// typedef enum {
    // UP, RIGHT, DOWN, LEFT
// } Direction;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[MAX_SNAKE_SIZE];
    int length;
    int direction;
    // Direction direction;
} Snake;

// Function prototype
void initGame(Snake* snake, Point* fruit);
void draw(Snake* snake, Point* fruit);
void moveSnake(Snake* snake, Point* fruit);
bool checkOverlap(Snake* snake, Point* new_head);

int main(void) {
    // initscr();          // To start working
    // clear();            // Clear the terminal

    // refresh();          // Forces to clear the terminal
    // curs_set(FALSE);    // Remove the cursor

    // int screen_h, screen_w;
    // getmaxyx(stdscr, screen_h, screen_w);
    // mvprintw(screen_h/2, screen_w/2, "Hello, World!");

    Snake python;
    Point apple;

    initGame(&python, &apple);
    while (1) {
        int ch = getch();
        if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_RIGHT || ch == KEY_LEFT) {
            python.direction = ch;
        }
        draw(&python, &apple);
        moveSnake(&python, &apple);
    }

    endwin();           // Restore normal terminal
    return 0;
}

void initGame(Snake* snake, Point* fruit) {
    srand(time(0));

    initscr();          // To start working
    curs_set(FALSE);    // Remove the cursor
    timeout(time_out);
    keypad(stdscr, TRUE);

    snake->length = 5;
    snake->direction = KEY_RIGHT;

    // Initialize the array of Points
    for (int i = 0; i < snake->length; i++) {
        snake->body[i].x = 10 - i;
        snake->body[i].y = 10;
    }

    fruit->x = rand() % COLS;
    fruit->y = rand() % LINES;
}

void draw(Snake* snake, Point* fruit) {
    clear();

    // Print the fruit
    char fruit_symbol = '$';
    mvprintw(fruit->y, fruit->x, "%c", fruit_symbol);

    // Print the snake
    for (int i = 0; i < snake->length; i++) {
        if (i == 0) {
            mvprintw(snake->body[i].y, snake->body[i].x, "@");
        } else {
            mvprintw(snake->body[i].y, snake->body[i].x, "#");
        }
    }

    refresh();
}

void moveSnake(Snake* snake, Point* fruit) {
    Point new_head = snake->body[0];

    // Move the snake based on the direction
    if (snake->direction == KEY_RIGHT) {
        new_head.x++;
    } else if (snake->direction == KEY_LEFT) {
        new_head.x--;
    } else if (snake->direction == KEY_DOWN) {
        new_head.y++;
    } else if (snake->direction == KEY_UP) {
        new_head.y--;
    }

    // Check for collision
    if (new_head.x <= 0 || new_head.x >= COLS -1 || new_head.y <= 0 || new_head.y >= LINES - 1 || checkOverlap(snake, &new_head)) {
        timeout(-1);  // Stop refreshing
        getch();
        endwin();
        exit(0);
    }

    for (int i = snake->length; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    snake->body[0] = new_head;

    // Found the fruit
    if (new_head.x == fruit->x && new_head.y == fruit->y) {
        snake->length++;
        fruit->x = rand() % (COLS - 20) + 20;
        fruit->y = rand() % (LINES - 10) + 10;
        time_out -= 10;
        timeout(time_out);
    }
}

bool checkOverlap(Snake* snake, Point* new_head) {
    for (int i = 0; i < snake->length; i++) {
        if (snake->body[i].x == new_head->x && snake->body[i].y == new_head->y) {
            return true;
        }
    }
    return false;
}