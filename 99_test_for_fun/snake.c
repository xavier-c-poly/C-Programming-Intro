#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>
#include <time.h>
#define DEBUG_ERROR_TIME 1



// ==========(Structs)==========
typedef struct Node {
    unsigned char direction;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node* head;
} DynamicQueue;

typedef struct {
    int head_x;
    int head_y;
    int tail_x;
    int tail_y;
    unsigned char direction;  // '0'=none '1'=up, '2'=right, '3'=down, '4'=left
    DynamicQueue tail_directions;
    int body_count;  // 1=just the head, 2=one body piece, n=how many body pieces it has including its head
    char head_symbol;  // which symbol to use for head
    char body_symbol;  // which symbol to use for body
    bool is_growing;
} Snake;

typedef struct {
    int apple_x;
    int apple_y;
    int score_multiplier;
    char apple_symbol;
} Apple;

typedef struct {
    Snake* snake;
    WINDOW* window;
    int tick_ms;  // how many milliseconds between movements
    int last_move_time;  // time when snake last moved
    int score;
    int number_of_apples;
    Apple* apples;  // array of apples that will be the size of number of apples (we'll have to use malloc(sizeof(apple) * number_of_apples) in Game_create)
    bool running;
} Game;
// =============================



// ==========(Function prototypes)==========
int             randomInclusive(int min, int max);
int             getScreenSize(Game* g, int* screen_h, int* screen_w);
int             getScreenCenter(Game* g, int* screen_h, int* screen_w);
int             getScreenFrac(Game* g, int numerator, int denominator, int* screen_h, int* screen_w);
int             now_ms();

void            printMiddle(WINDOW* win, char* message);
void            printMiddleY(WINDOW* win, char* message, int height_y);
void            printMiddleDeco(WINDOW* win, char* message, char deco_symbol_left, int deco_count_left, char deco_symbol_right, int deco_count_right);
void            printMiddleYDeco(WINDOW* win, char* message, char deco_symbol_left, int deco_count_left, char deco_symbol_right, int deco_count_right, int height_y);
void            Draw_screenBorder(WINDOW* window, char symbol_horizontal, char symbol_vertical, char symbol_corners);
void            Draw_snakeHead(Snake* s);
void            Draw_snakeBody(Snake* s);
void            Draw_snakeTail(Snake* s);
void            Draw_snake(Snake* s);
void            Draw_apple(Game* g);
void            Draw_beginningGameTitle(Game* g);  // Make this better one day
void            Draw_title(Game* g);
void            Draw_gameOver(Game* g);  // Make this better one day
void            Draw_score(Game* g);
void            Draw_UI(Game* g);

void            Node_print(Node* nd);
DynamicQueue    DynamicQueue_create(unsigned char direction);
unsigned char   DynamicQueue_get(DynamicQueue* dq, int index);
Node*           DynamicQueue_getNode(DynamicQueue* dq, int index);
Node*           DynamicQueue_getLastNode(DynamicQueue* dq);
void            DynamicQueue_add(DynamicQueue* dq, unsigned char new_direction);
unsigned char   DynamicQueue_pop(DynamicQueue* dq);
unsigned char   DynamicQueue_popAndAdd(DynamicQueue* dq, unsigned char new_direction);
void            DynamicQueue_print(DynamicQueue* dq);

Snake           Snake_create(int x, int y, char head_symb, char body_symb);
int             Snake_getVelocities(unsigned char direction, int* vel_y, int* vel_x);
void            Snake_moveHead(Snake* s);
void            Snake_moveTail(Snake* s);
void            Snake_move(Snake* s);
void            Snake_grow(Snake* s, Game* g, int score_mul);
void            Snake_handleInput(Snake* s, int direction);
int             Snake_checkPosition(Game* g); // 0 for nothing, 1 for crash into wall, 2 for crash into self, 3 for apple

Apple           Apple_create(Game* g, int x, int y, int score_mul, char apple_symbol);
int             Apple_findSpot(Game* g, int* place_x, int* place_y);
void            Apple_place(Apple* a, int place_x, int place_y);
Apple*          Apple_findAppleAt(Game* g, int x, int y);
int             Apple_relocate(Game* g, int collision_x, int collision_y);

Game            Game_create(Snake* s, WINDOW* window, int t_ms, int num_apples, int score_multiplier, char apple_symb);
void            Game_draw(Game* g);  // FINISH IMPLMENETING LAST
void            Game_gameOver(Game* g, int game_over_code);  // Implement
void            Game_run(Game* g);

void            debugging_1();
void            debugging_2();
void            debugger(int debug_number);
void            debuggerError(char* message);
// IMPLEMENT LATER: title screen, text based menu, game over screen, revisit the game loop to make sure Snake_checkPosition is checking for death and collisions and stuff
// =========================================



int main(void) {
    printf("Welcome to snake!\n");

    // Initialize ncurses
    initscr();
    cbreak();  // Disable line buffering (get chars immediately)
    noecho();  // Don't echo typed characters
    keypad(stdscr, TRUE);  // Enable arrow keys, F-keys, etc.
    nodelay(stdscr, TRUE);  // getch() becomes non-blocking
    curs_set(0);  // Hide cursor (0 = hide)

    Snake main_snake = Snake_create(10, 10, '+', '*');
    Game main_game = Game_create(&main_snake, stdscr, 30, 1, 1, 'A');
    Game_run(&main_game);

    endwin();  // Restore normal terminal mode
    printf("Thanks for playing!\n");
    return 0;
}



int randomInclusive(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int getScreenSize(Game* g, int* screen_h, int* screen_w) {
    getmaxyx(g->window, *screen_h, *screen_w);
    return 0;
}

int getScreenCenter(Game* g, int* screen_h, int* screen_w) {
    getmaxyx(g->window, *screen_h, *screen_w);
    *screen_h /= 2;
    *screen_w /= 2;
    return 0;
}

int getScreenFrac(Game* g, int numerator, int denominator, int* screen_h, int* screen_w) {
    if (denominator == 0) return 1;

    int height, width;
    getmaxyx(g->window, height, width);

    *screen_h = (int) (((double) height) * (((double)numerator)/((double)denominator)));
    *screen_w = (int) (((double) width) * (((double)numerator)/((double)denominator)));

    // This might cause issues later if this code isn't right lmao
    while (*screen_h > height)
        *screen_h -= height;
    while (*screen_w > width)
        *screen_w -= width;

    return 0;
}

void Draw_screenBorder(WINDOW* window, char symbol_horizontal, char symbol_vertical, char symbol_corners) {
    int screen_height, screen_width;
    getmaxyx(window, screen_height, screen_width);

    // Print top horizontal (with no corner)
    for (int i = 1; i < screen_width - 1; i++) {
        mvprintw(0, i, "%c", symbol_horizontal);
    }
    // Print bottom horizontal (with no corner)
    for (int i = 1; i < screen_width - 1; i++) {
        mvprintw(screen_height - 1, i, "%c", symbol_horizontal);
    }
    // Print left vertical (with no corner)
    for (int j = 1; j < screen_height - 1; j++) {
        mvprintw(j, 0, "%c", symbol_vertical);
    }
    // Print right vertical (with no corner)
    for (int j = 1; j < screen_height - 1; j++) {
        mvprintw(j, screen_width - 1, "%c", symbol_vertical);
    }

    // Print corners
    mvprintw(0, 0, "%c", symbol_corners);
    mvprintw(0, screen_width - 1, "%c", symbol_corners);
    mvprintw(screen_height - 1, 0, "%c", symbol_corners);
    mvprintw(screen_height - 1, screen_width - 1, "%c", symbol_corners);
}

void Draw_snakeHead(Snake* s) {
    mvprintw(s->head_y, s->head_x, "%c", s->head_symbol);
    // printf("Drew snake head at x=%d, y=%d, with character %c", s->head_x, s->head_y, s->head_symbol);
}
void Draw_snakeBody(Snake* s) {
    // Meant to be used only in Snake_moveHead(), updating the position
    // of the previous position before moving the snake head
    mvprintw(s->head_y, s->head_x, "%c", s->body_symbol);
}
void Draw_snakeTail(Snake* s) {
    mvprintw(s->tail_y, s->tail_x, " ");
}

void Draw_snake(Snake* s) {
    Draw_snakeHead(s);
    Draw_snakeTail(s);
}

void Draw_apple(Game *g) {
    for (int i = 0; i < g->number_of_apples; i++) {
        mvprintw(g->apples[i].apple_y, g->apples[i].apple_x, "%c", g->apples[i].apple_symbol);
    }
}

void Draw_beginningGameTitle(Game* g) {
    // create some crazy ascii art for this one day
    printMiddle(g->window, "SNAKEEEEEEE!!");
}

void Draw_title(Game* g) {
    printMiddleYDeco(g->window, "SNAKE", '(', 3, ')', 3, 0);
}

void Draw_gameOver(Game* g) {
    // create some crazy ascii art for this one day
    printMiddle(g->window, "Game over!");
}

void Draw_score(Game* g) {
    char score_string[32];
    snprintf(score_string, sizeof(score_string), "Score: %d", g->score);
    printMiddleYDeco(g->window, "SNAKE", '[', 2, ']', 2, 0);
}

void Draw_UI(Game* g) {
    Draw_title(g);
    Draw_score(g);
}

void printMiddle(WINDOW* win, char* message) {
    int screen_height, screen_width;
    getmaxyx(win, screen_height, screen_width);
    mvprintw(screen_height/2, (screen_width/2) - (strlen(message)/2), "%s", message);
}

void printMiddleY(WINDOW* win, char* message, int height_y) {
    int screen_height, screen_width;
    getmaxyx(win, screen_height, screen_width);
    mvprintw(height_y, (screen_width/2) - (strlen(message)/2), "%s", message);
}

void printMiddleDeco(WINDOW* win, char* message, char deco_symbol_left, int deco_count_left, char deco_symbol_right, int deco_count_right) {
    int screen_height, screen_width;
    getmaxyx(win, screen_height, screen_width);
    // Example:
    // message = "hi"
    // deco_symbol = '*'
    // deco_count = 3
    // "*** hi ***\0"
    char final_message[deco_count_left + 1 + strlen(message) + deco_count_right + 1 + 1];
    for (int i = 0; i < deco_count_left; i++) {
        final_message[i] = deco_symbol_left;
    }
    final_message[deco_count_left] = ' ';
    for (int i = 0; i < strlen(message); i++) {
        final_message[i + deco_count_left + 1] = message[i];
    }
    final_message[deco_count_left + 1 + strlen(message)] = ' ';
    for (int i = 0; i < deco_count_right; i++) {
        final_message[i + deco_count_left + 1 + strlen(message) + 1] = deco_symbol_right;
    }
    final_message[strlen(final_message) - 1] = '\0';
    mvprintw(screen_height/2, (screen_width/2) - (strlen(message)/2), "[%s]", final_message);
}

void printMiddleYDeco(WINDOW* win, char* message, char deco_symbol_left, int deco_count_left, char deco_symbol_right, int deco_count_right, int height_y) {
    int screen_height, screen_width;
    getmaxyx(win, screen_height, screen_width);
    char final_message[deco_count_left + 1 + strlen(message) + deco_count_right + 1 + 1];
    for (int i = 0; i < deco_count_left; i++) {
        final_message[i] = deco_symbol_left;
    }
    final_message[deco_count_left] = ' ';
    for (int i = 0; i < strlen(message); i++) {
        final_message[i + deco_count_left + 1] = message[i];
    }
    final_message[deco_count_left + 1 + strlen(message)] = ' ';
    for (int i = 0; i < deco_count_right; i++) {
        final_message[i + deco_count_left + 1 + strlen(message) + 1] = deco_symbol_right;
    }
    final_message[strlen(final_message) - 1] = '\0';
    mvprintw(height_y, (screen_width/2) - (strlen(message)/2), "[%s]", final_message);
}

int now_ms() {
    return (clock() * 1000) / CLOCKS_PER_SEC;
}

void Node_print(Node* nd) {
    printf("[Node: (Address=%p), (Direction=%c), (next=%p)]\n", nd, nd->direction, nd->next);
}

DynamicQueue DynamicQueue_create(unsigned char direction) {
    Node* head = malloc(sizeof(Node));
    head->direction = direction;
    head->next = NULL;
    return (DynamicQueue){1, head};
}

unsigned char DynamicQueue_get(DynamicQueue* dq, int index) {
    if (index > dq->size)
        return '/';  // '/' means error
    
    // Node current = {dq->head->direction, dq->head->next};  // Wrong code
    Node* current = dq->head;

    for (int i = 0; i < index; i++) {
        // current = *current.next;  // Wrong code
        current = current->next;
    }

    // return current.direction;  // Wrong code
    return current->direction;
}

Node* DynamicQueue_getNode(DynamicQueue* dq, int index) {
    if (index > dq->size)
        return &(Node){'/', NULL};  // '0' means error
    
    // Node current = {dq->head->direction, dq->head->next};  // Wrong code
    Node* current = dq->head;

    for (int i = 0; i < index; i++) {
        // current = *current.next;  // Wrong code
        current = current->next;
    }

    // return current;  // Wrong code
    return current;
}

Node* DynamicQueue_getLastNode(DynamicQueue* dq) {
    return DynamicQueue_getNode(dq, dq->size - 1);
}

void DynamicQueue_add(DynamicQueue* dq, unsigned char new_direction) {
    // Node new_last = {new_direction, NULL};
    // Node old_last = DynamicQueue_getLastNode(dq);  // Get the last current node in the queue
    // old_last.next = &new_last;
    // dq->size++;

    Node* new_node = malloc(sizeof(Node));
    new_node->direction = new_direction;
    new_node->next = NULL;

    if (dq->head == NULL) {
        dq->head = new_node;
    } else {
        Node* last = dq->head;
        while (last->next != NULL)
            last = last->next;
        last->next = new_node;
    }
    dq->size++;
}

unsigned char DynamicQueue_pop(DynamicQueue* dq) {
    unsigned char next_direction = dq->head->direction;

    // Get and free previous node
    Node* previous_node = dq->head;
    dq->head = dq->head->next;
    free(previous_node);
    
    dq->size--;

    return next_direction;
}

unsigned char DynamicQueue_popAndAdd(DynamicQueue* dq, unsigned char new_direction) {
    unsigned char direction = DynamicQueue_pop(dq);
    DynamicQueue_add(dq, new_direction);
    return direction;
}

void DynamicQueue_print(DynamicQueue* dq) {
    Node* current = dq->head;
    printf("[");
    for (int i = 0; i < dq->size; i++) {
        if (current->next == NULL)
            printf("%c]\n", current->direction);
        else
            printf("%c, ", current->direction);
        current = current->next;
    }
    puts("");
}

void debugging_1() {
    printf("\n\ndebugging_1 {\n");

    printf("Hello debugging time!!\n");
    printf("--------(Testing Queues and Queue functions)--------\n");
    DynamicQueue my_queue = DynamicQueue_create('1');
    DynamicQueue_print(&my_queue);
    DynamicQueue_add(&my_queue, 'a');
    DynamicQueue_add(&my_queue, 'r');
    DynamicQueue_add(&my_queue, 'x');
    DynamicQueue_add(&my_queue, 'p');
    DynamicQueue_add(&my_queue, 'k');
    DynamicQueue_print(&my_queue);
    int idx = 2;
    printf("Getting index %d: %c\n", idx, DynamicQueue_get(&my_queue, idx));
    printf("Popping it returns %c\n", DynamicQueue_pop(&my_queue));
    DynamicQueue_print(&my_queue);
    printf("Popping it again returns %c\n", DynamicQueue_pop(&my_queue));
    DynamicQueue_print(&my_queue);
    printf("Popping it one more time returns %c\n", DynamicQueue_pop(&my_queue));
    DynamicQueue_print(&my_queue);
    printf("Popping AND adding returns %c\n", DynamicQueue_popAndAdd(&my_queue, 'E'));
    DynamicQueue_print(&my_queue);
    printf("----------------------------------------------------\n");

    puts("");

    printf("--------(Testing Nodes)--------\n");
    DynamicQueue_add(&my_queue, 'G');
    DynamicQueue_add(&my_queue, 'y');
    DynamicQueue_add(&my_queue, 'n');
    DynamicQueue_add(&my_queue, '8');
    DynamicQueue_print(&my_queue);
    idx = 2;
    printf("Getting node at index %d:\t", idx);
    Node_print(DynamicQueue_getNode(&my_queue, idx));
    idx = 3;
    printf("Getting node at index %d:\t", idx);
    Node_print(DynamicQueue_getNode(&my_queue, idx));
    idx = 4;
    printf("Getting node at index %d:\t", idx);
    Node_print(DynamicQueue_getNode(&my_queue, idx));
    printf("Getting last node:\t\t");
    Node_print(DynamicQueue_getLastNode(&my_queue));
    printf("-------------------------------\n");

    printf("}\n");
    puts("\n\n");
}

void debugging_2() {
    // /* BEGINNING OF TESTING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Initialize ncurses
    initscr();
    cbreak();  // Disable line buffering (get chars immediately)
    noecho();  // Don't echo typed characters
    keypad(stdscr, TRUE);  // Enable arrow keys, F-keys, etc.
    nodelay(stdscr, TRUE);  // getch() becomes non-blocking
    curs_set(0);  // Hide cursor (0 = hide)

    // Get screen width and height
    int SCREEN_HEIGHT, SCREEN_WIDTH;
    getmaxyx(stdscr, SCREEN_HEIGHT, SCREEN_WIDTH);  // height = rows, width = columns

    // Print snake screen
    clear();
    printw("\n Hello with printw!");
    mvprintw(10, 10, "Hello ncurses! (with mvprintw)");
    mvprintw(20, 20, "The screen height is %d chars and width is %d chars", SCREEN_HEIGHT, SCREEN_WIDTH);
    Draw_screenBorder(stdscr, '*', '|', '+');
    const char title_text[] = "SNAKE";
    // printMiddle(SCREEN_HEIGHT, SCREEN_WIDTH, "---");
    // printMiddleDeco(SCREEN_HEIGHT, SCREEN_WIDTH, "test meow", '+', 3);
    // printMiddleDeco(stdscr, "test meow", '+', 3);
    printMiddleDeco(stdscr, "test meow", '+', 3, '+', 3);
    mvprintw(SCREEN_HEIGHT/2 + 1, (SCREEN_WIDTH/2) - (strlen(title_text)/2), "%s", title_text); // Move + print formatted text
    refresh();
    napms(3 * 1000);  // Sleep for n ms
    mvprintw(4, 4, "Lets see what happens");
    refresh();
    napms(2 * 1000);  // Sleep for n ms

    // while (running) {
        // mvaddch(y, x, '@'); // Move + put one character
        // refresh();          // Apply changes to visible screen

        // int ch = getch();  // non-blocking if nodelay() used (for arrow keys, you'll get constants like KEY_UP, KEY_DOWN)
        // halfdelay(1);  // Wait up to 0.1 sec for input; otherwise return ERR
    // }

    endwin();  // Restore normal terminal mode
    // */ // END TESTING MODE RIGHT HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void debugger(int debug_number) {
    printf("Debugging: debug %d ran\n", debug_number); // DEBUGGING!!!
    refresh();  // DEBUGGING!!!
    napms(DEBUG_ERROR_TIME * 1000);  // DEBUGGING!!!
    refresh();  // DEBUGGING!!!
}

void debuggerError(char* message) {
    printf("%s", message);
    refresh();  // DEBUGGING!!!
    napms(DEBUG_ERROR_TIME * 1000);  // DEBUGGING!!!
    refresh();  // DEBUGGING!!!
}

Snake Snake_create(int x, int y, char head_symb, char body_symb) {
    // Get screen width and height
    // bool touching_up = false, touching_right = false, touching_down = false, touching_left = false;
    // Snake error_snake = (Snake){-1, -1, -1, -1, '/', DynamicQueue_create('/'), -1, '/', '/', false};  // Ultimate error lmao
    int screen_height, screen_width;
    getmaxyx(stdscr, screen_height, screen_width);  // height = rows, width = columns

    // Make sure snake isn't being created on the screen border
    // if it is, make the snake spawn into closest valid area
    if (x <= 0)
        x = 1;
    else if (x >= screen_width - 1)
        x = screen_width - 2;
    if (y <= 0)
        y = 1;
    else if (y >= screen_height - 1)
        y = screen_height - 2;
    
    return (Snake) {x, y, x, y, '0', DynamicQueue_create('0'), 1, head_symb, body_symb, false};

    // Find if its touching the screen border's border
    // if (x == 1) touching_left = true;
    // if (x == screen_width - 2) touching_right = true;
    // if (y == 1) touching_up = true;
    // if (y == screen_height - 2) touching_down = true;

    // Determine where to place the snake tail x
    // if (!touching_left) tail_x = x - 1;
    // else if (!touching_right) tail_x = x + 1;

    // Determine where to place the snake tail y (unfinished)
    // if (!touching_up) tail_x = x - 1;
    // else if (!touching_right) tail_x = x + 1;
    // else return error_snake;

    // The tail cannot be on top of the snake..
    // if (tail_x == x && tail_y == y) return error_snake;
}

int Snake_getVelocities(unsigned char direction, int* vel_y, int* vel_x) {
    // Don't move
    if (direction == '0') {
        *vel_y = 0;
        *vel_x = 0;
    }
    // Up
    else if (direction == '1') {
        *vel_y = -1;
        *vel_x = 0;
    }
    // Right
    else if (direction == '2') {
        *vel_y = 0;
        *vel_x = 1;
    }
    // Down
    else if (direction == '3') {
        *vel_y = 1;
        *vel_x = 0;
    }
    // Left
    else if (direction == '4') {
        *vel_y = 0;
        *vel_x = -1;
    }
    // Error
    else {
        return 1;
    }

    return 0;
}

void Snake_moveHead(Snake* s) {
    int velocity_y = 0;
    int velocity_x = 0;

    if (Snake_getVelocities(s->direction, &velocity_y, &velocity_x) == 1) {
        debuggerError("ERROR 1 (Snake_moveHead): Something went wrong in Snake_move, the snake's direction is neither '0', '1', '2', '3', or '4'.\n");
        return;
    }

    Draw_snakeBody(s);
    s->head_x += velocity_x;
    s->head_y += velocity_y;
}

void Snake_moveTail(Snake* s) {
    int velocity_tail_x = 0;
    int velocity_tail_y = 0;
    unsigned char old_direction;

    if (!s->is_growing)
        old_direction = DynamicQueue_popAndAdd(&s->tail_directions, s->direction);
    else {
        DynamicQueue_add(&s->tail_directions, s->direction);
        s->is_growing = false;
        return;
    }

    if (Snake_getVelocities(old_direction, &velocity_tail_y, &velocity_tail_x) == 1) {
        debuggerError("ERROR 2 (Snake_moveTail): Something went wrong in Snake_moveTail, the snake's old_direction is neither '0', '1', '2', '3', or '4'.\n");
        return;
    }

    s->tail_x += velocity_tail_x;
    s->tail_y += velocity_tail_y;
}

void Snake_move(Snake* s) {
    Snake_moveHead(s);
    Snake_moveTail(s);
}

void Snake_grow(Snake* s, Game* g, int score_mul) {
    // we're gonna have to delay the Pop from the tail (that evil normal DynamicQueue_popAndAdd() is found in Snake_moveTail())
    // lets set a flag on the snake that the snake is currently growing
    //
    // So when the game ticks, and then the snake is on top of the apple, before the next tick starts, we will set a flag
    // on the snake struct field, that says that it is growing. when the next tick goes off, Snake_moveTail() will
    // check for that field, and find that its on, so it only adds the direction to the DynamicQueue, and doesn't pop.

    s->is_growing = true;
    g->score += score_mul;
}

void Snake_handleInput(Snake* s, int input) {
    unsigned char new_direction = s->direction;
    if (input == KEY_UP)
        new_direction = '1';
    else if (input == KEY_RIGHT)
        new_direction = '2';
    else if (input == KEY_DOWN)
        new_direction = '3';
    else if (input == KEY_LEFT)
        new_direction = '4';
    // new_direction = s->direction;
    s->direction = new_direction;
}

// IMPLEMENT (return 0 for nothing, 1 for crash into wall, 2 for crash into self, 3 for apple)
int Snake_checkPosition(Game* g) {
    int collision = -1;  // 0 for collision with nothing, 1 for wall, 2 for body, 3 for apple
    int apple_score_mul = 1;
    int x = g->snake->head_x, y = g->snake->head_y;
    int screen_height, screen_width;
    getScreenSize(g, &screen_height, &screen_width);
    char c = mvinch(y, x) & A_CHARTEXT;

    // Check if there's an apple at this location
    Apple* found_apple = Apple_findAppleAt(g, x, y);
    if (found_apple != NULL) {
        collision = 3;
    }

    // Get all the possible apple symbols
    // char* all_apple_symbols = malloc(sizeof(char) * g->number_of_apples);
    // for (int i = 0; i < g->number_of_apples; i++) {
        // all_apple_symbols[i] = g->apples[i].apple_symbol;
    // }

    // Crash into apple
    // Checks if snake touches one of the apple symbols
    // for (int i = 0; i < g->number_of_apples; i++) {
        // if (c == all_apple_symbols[i]) {
            // collision = 3;
            // Apple* found_apple = Apple_findAppleAt(g, x, y);
            // if (found_apple == NULL) {
                // debuggerError("ERROR 3 (Snake_checkPosition()): Something went wrong in Apple_findAppleAt(), could not find the apple at the said location\n");
            // } else {
                // apple_score_mul = found_apple->score_multiplier;
            // }
        // }
    // }

    if (c == ' ') {
        // Crash into nothing
        collision = 0;
    } else if (x == 0 || x == screen_width - 1 || y == 0 || y == screen_height - 1) {
        // Crash into wall
        collision = 1;
        Game_gameOver(g, collision);
    } else if (c == g->snake->body_symbol) {
        // Crash into body
        collision = 2;
        Game_gameOver(g, collision);
    }

    if (collision == 3) {
        Snake_grow(g->snake, g, apple_score_mul);
        int relocate_code = Apple_relocate(g, x, y);
        if (relocate_code == 1) {
            debuggerError("ERROR 4 (Snake_checkPosition): Something went wrong in Apple_relocate() function, could not find the apple that needed to be replaced\n");
        }
        else if (relocate_code == 2) {
            debuggerError("ERROR 5 (Snake_checkPosition): Something went wrong in Apple_relocate() function, could not find a new place to place the apple\n");
        }
        else {
            Draw_apple(g);  // Making sure the apple is drawn at the new spot before next tick
            refresh();
        }
    }

    return collision;
}

Apple Apple_create(Game* g, int x, int y, int score_mul, char apple_symbol) {
    int screen_height, screen_width;
    int new_x, new_y;
    getScreenFrac(g, randomInclusive(1, 4), randomInclusive(5, 8), &new_x, &new_y);
    getScreenSize(g, &screen_height, &screen_width);
    if (x <= 0 || x >= screen_width - 1)
        x = new_x;
    if (y <= 0 || y >= screen_height - 1)
        y = new_y;
    return (Apple) {x, y, score_mul, apple_symbol};
}

int Apple_findSpot(Game* g, int* place_x, int* place_y) {
    int random_cap = 100000, i = 0;
    int screen_height, screen_width;
    int new_x, new_y;
    char c;
    bool placed = false;
    getScreenSize(g, &screen_height, &screen_width);

    while (!placed && i < random_cap) {
        new_x = randomInclusive(1, screen_width - 2);
        new_y = randomInclusive(1, screen_height - 2);
        c = mvinch(new_y, new_x) & A_CHARTEXT;

        if (c == ' ') {
            *place_x = new_x;
            *place_y = new_y;
            placed = true;
        }
        
        i++;
    }

    if (i >= random_cap) {
        debuggerError("ERROR 6 (Apple_findSpot): Something went wrong in Apple_findSpot() function, couldn't find a spot to place the apple\n");
        return 1;
    }

    return 0;
}
void Apple_place(Apple* a, int place_x, int place_y) {
    a->apple_x = place_x;
    a->apple_y = place_y;
}

Apple* Apple_findAppleAt(Game* g, int x, int y) {
    /*
    Apple error_apple = Apple_create(g, 3, 3, -1, '/');
    Apple* apple_to_find = &error_apple;
    int status_code = 1;

    for (int i = 0; i < g->number_of_apples; i++) {
        if (g->apples[i].apple_x == x && g->apples[i].apple_y == y) {
        // if (g->apples[i].apple_x == g->snake->head_x && g->apples[i].apple_y == g->snake->head_y) {  // DEBUGGING!!! replaced the above line with this line
            return &g->apples[i];
        }
    }

    debuggerError("ERROR 7 (Apple_findAppleAt): Could not find apple at said location\n");
    return apple_to_find;
    */

    for (int i = 0; i < g->number_of_apples; i++) {
        // printf("Comparing apple_x=%d apple_y=%d to collision coordinates x=%d y=%d", g->apples[i].apple_x, g->apples[i].apple_y, x, y);  // DEBUGGING!!!
        // refresh();  // DEBUGGING!!!
        // napms(DEBUG_ERROR_TIME * 1000);  // DEBUGGING!!!
        // refresh();  // DEBUGGING!!!
        if (g->apples[i].apple_x == x && g->apples[i].apple_y == y) {
            printf("I got inside the if statement!!! (apple touching snake found)\n");  // DEBUGGING!!!
            refresh();  // DEBUGGING!!!
            napms(DEBUG_ERROR_TIME * 1000);  // DEBUGGING!!!
            refresh();  // DEBUGGING!!!
            return &g->apples[i];
        }
    }

    debuggerError("ERROR 8 (Apple_findAppleAt): Could not find apple at said location\n");
    return NULL;
}

int Apple_relocate(Game* g, int collision_x, int collision_y) {
    // If it hits an apple (MAKE SURE THAT THIS IF STATEMENT HANDLES CREATING A NEW APPLE PLACE AND SELECTING A RANODM SPOT, as well as the score going up, probably should create a function for this) (probably going to have to save the coordinates of the apple using this function's x and y variables, then do a for loop through game->apples and see which one's x and y positions match it, then use Apple_findSpot and assign THAT ELEMENT to the new coordinates)
    // replace apple at this spot, if no apple found at collision spot return 1, if unable to find a new spot return 2

    int new_spot_x, new_spot_y;
    Apple* apple_to_relocate = Apple_findAppleAt(g, collision_x, collision_y);
    if (apple_to_relocate == NULL) {
        debuggerError("ERROR 9 (Apple_relocate): Something went wrong in Apple_findAppleAt() function, could not find the apple that needed to be replaced\n");
        return 1;
    }

    if (Apple_findSpot(g, &new_spot_x, &new_spot_y) == 1) {
        debuggerError("ERROR 10 (Apple_relocate): Something went wrong in Apple_findSpot() function, could not find a new place to place the apple\n");
        return 2;
    } else {
        apple_to_relocate->apple_x = new_spot_x;
        apple_to_relocate->apple_y = new_spot_y;
        debugger(231);  // DEBUGGING!!!
    }

    return 0;
}

Game Game_create(Snake* s, WINDOW* window, int t_ms, int num_apples, int score_multiplier, char apple_symb) {
    Apple* apples = malloc(sizeof(Apple) * num_apples);
    Game game = {s, window, t_ms, 0, 0, num_apples, apples, true};

    // Fill up all the apples in the array with random spots
    int apple_spot_x, apple_spot_y;
    Apple_findSpot(&game, &apple_spot_x, &apple_spot_y);
    for (int i = 0; i < num_apples; i++) {
        // apples[i] = Apple_create(&game, apple_spot_x, apple_spot_y, score_multiplier, apple_symb);
        apples[i] = Apple_create(&game, 20, 10, score_multiplier, apple_symb);  // DEBUGGING!!! DELETE THIS LINE AND UNCOMMENT THE ABOVE ONE
    }
    return game;
}

void Game_draw(Game* g) {
    clear();
    Draw_screenBorder(g->window, '*', '|', '+');
    Draw_snake(g->snake);
    Draw_apple(g);
    Draw_UI(g);  // Implement
    refresh();
}

void Game_gameOver(Game* g, int game_over_code) {
    //
    g->running = false;
    if (game_over_code == 1) {
        printf("You lowkey crashed into yourself vroski\n");
    } else if (game_over_code == 2) {
        printf("You kinda crashed cro\n");
    }
}

void Game_run(Game* g) {
    nodelay(g->window, true);

    while (g->running) {
        int now = now_ms();
        int ch = getch();
        Snake_handleInput(g->snake, ch);
        Snake_checkPosition(g);

        if (now - g->last_move_time >= g->tick_ms) {
            Snake_move(g->snake);
            g->last_move_time = now;

            Game_draw(g);
            // printf("Drew");
        }
    }
}



