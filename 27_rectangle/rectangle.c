#include <stdio.h>

#define MAX_WALLS 20

// --------------- STRUCTURES ------------------------
typedef struct {
    double width;
    double height;
} Rectangle;

typedef struct {
    // When one structure is inside another one, it's called a composition
    Rectangle floor;
    Rectangle walls[MAX_WALLS];
    int count_walls;
} Room;
// ---------------------------------------------------

// --------------- FUNCTION PROTOTYPES ---------------
Rectangle   createRectangle(double width, double height);
Rectangle   createRectanglePromopt(void);
double      rectanglePerimeter(Rectangle* rect);
double      rectangleArea(Rectangle* rect);
void        printRectangle(Rectangle* rect);
Room        createRoom(double width_floor, double height_floor);
void        roomAddWall(Room* room, double width_wall, double height_wall);
// TODO
double      Room_getFloorPerimeter(Room *room);
double      Room_getWallsPerimeter(Room *room);  // Total perimeter of all the walls
double      Room_getFloorArea(Room *room);
double      Room_getWallsArea(Room *room);
void        printRoom(Room* room);
// ---------------------------------------------------

int main(void) {
    // Create a rectangle r with 15.4 width and 23.5 height
    Rectangle rect1 = {15.4, 23.5};
    Rectangle rect2 = createRectangle(12.50, 8.00);

    printRectangle(&rect1);
    printRectangle(&rect2);

    puts("");

    printf("Perimeter of rect2:\t%.2lf\n", rectanglePerimeter(&rect2));
    printf("Area of rect2:\t\t%.2lf\n", rectangleArea(&rect2));

    puts("");

    // Create an array of rectangles
    Rectangle arr[3];
    arr[0] = createRectangle(14.2, 875.3);
    arr[1] = createRectangle(44.2, 84.3);
    arr[2] = createRectangle(447.2, 184.3);

    for (int i = 0; i < 3; i++) {
        printf("Rectangle %d: Perimeter %.2lf, Area %.2lf\n", i + 1, rectanglePerimeter(&arr[i]), rectangleArea(&arr[i]));
    }


    // Create a room
    Room living_room = createRoom(12, 12);
    roomAddWall(&living_room, 13, 13);
    roomAddWall(&living_room, 16, 14);
    roomAddWall(&living_room, 13, 12);
    roomAddWall(&living_room, 14, 11);

    return 0;
}

Rectangle createRectangle(double width, double height) {
    return (Rectangle) {width, height};
}

Rectangle createRectanglePromopt(void) {
    Rectangle r;
    double w, h;

    printf("Enter rectangle width: ");
    scanf("%lf", &w);
    printf("Enter rectangle height: ");
    scanf("%lf", &h);

    r.width = w;
    r.height = h;
    return r;
}

double rectanglePerimeter(Rectangle* rect) {
    return (rect->width * 2) + (rect->height * 2);
}

double rectangleArea(Rectangle* rect) {
    return rect->width * rect->height;
}

void printRectangle(Rectangle* rect) {
    printf("Rectangle width:\t%.2lf\n", rect->width);
    printf("Rectangle height:\t%.2lf\n", rect->height);
    printf("Perimeter:\t\t%.2lf\n", rectanglePerimeter(rect));
    printf("Area:\t\t\t%.2lf\n", rectangleArea(rect));
}

Room createRoom(double width_floor, double height_floor) {
    // Room room;
    // room.floor = createRectangle(width_floor, height_floor);
    // room.count_walls = 0;

    // return room;

    return (Room) {.floor = (Rectangle){width_floor, height_floor}, .count_walls = 0};
}

void roomAddWall(Room* room, double width_wall, double height_wall) {
    if (room->count_walls >= MAX_WALLS) {
        printf("Cannot have more than %d walls", MAX_WALLS);
        return;
    }
    room->walls[room->count_walls] = createRectangle(width_wall, height_wall);
    room->count_walls++;
}

double Room_getFloorPerimeter(Room *room);
double Room_getWallsPerimeter(Room *room);  // Total perimeter of all the walls
double Room_getFloorArea(Room *room);
double Room_getWallsArea(Room *room);

void printRoom(Room* room) {
    //





}