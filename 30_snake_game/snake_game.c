#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SNAKE_SIZE 25

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
    draw(&python, &apple);
    moveSnake(&python, &apple);

    getch();            // Wait for the key to be pressed
    endwin();           // Restore normal terminal

    return 0;
}

void initGame(Snake* snake, Point* fruit) {
    srand(time(0));

    initscr();          // To start working
    curs_set(FALSE);    // Remove the cursor
    // timeout(100);

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
    new_head.x++;

    for (int i = snake->length; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    snake->body[0] = new_head;
}