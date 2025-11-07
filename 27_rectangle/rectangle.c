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
Rectangle   Rectangle_create(double width, double height);
Rectangle   Rectangle_createPromopt(void);
double      Rectangle_perimeter(Rectangle* rect);
double      Rectangle_area(Rectangle* rect);
void        Rectangle_print(Rectangle* rect);
Room        Room_create(double width_floor, double height_floor);
void        Room_addWall(Room* room, double width_wall, double height_wall);
// TODO
double      Room_getFloorPerimeter(Room *room);
double      Room_getWallsPerimeter(Room *room);  // Total perimeter of all the walls
double      Room_getFloorArea(Room *room);
double      Room_getWallsArea(Room *room);
void        Room_print(Room* room);
// ---------------------------------------------------

int main(void) {
    // Create a rectangle r with 15.4 width and 23.5 height
    Rectangle rect1 = {15.4, 23.5};
    Rectangle rect2 = Rectangle_create(12.50, 8.00);

    Rectangle_print(&rect1);
    Rectangle_print(&rect2);

    puts("");

    printf("Perimeter of rect2:\t%.2lf\n", Rectangle_perimeter(&rect2));
    printf("Area of rect2:\t\t%.2lf\n", Rectangle_area(&rect2));

    puts("");

    // Create an array of rectangles
    Rectangle arr[3];
    arr[0] = Rectangle_create(14.2, 875.3);
    arr[1] = Rectangle_create(44.2, 84.3);
    arr[2] = Rectangle_create(447.2, 184.3);

    for (int i = 0; i < 3; i++) {
        printf("Rectangle %d: Perimeter %.2lf, Area %.2lf\n", i + 1, Rectangle_perimeter(&arr[i]), Rectangle_area(&arr[i]));
    }


    // Create a room
    Room living_room = Room_create(12, 12);
    Room_addWall(&living_room, 13, 13);
    Room_addWall(&living_room, 16, 14);
    Room_addWall(&living_room, 13, 12);
    Room_addWall(&living_room, 14, 11);

    return 0;
}

Rectangle Rectangle_create(double width, double height) {
    return (Rectangle) {width, height};
}

Rectangle Rectangle_createPromopt(void) {
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

double Rectangle_perimeter(Rectangle* rect) {
    return (rect->width * 2) + (rect->height * 2);
}

double Rectangle_area(Rectangle* rect) {
    return rect->width * rect->height;
}

void Rectangle_print(Rectangle* rect) {
    printf("Rectangle width:\t%.2lf\n", rect->width);
    printf("Rectangle height:\t%.2lf\n", rect->height);
    printf("Perimeter:\t\t%.2lf\n", Rectangle_perimeter(rect));
    printf("Area:\t\t\t%.2lf\n", Rectangle_area(rect));
}

Room Room_create(double width_floor, double height_floor) {
    // Room room;
    // room.floor = Rectangle_create(width_floor, height_floor);
    // room.count_walls = 0;

    // return room;

    return (Room) {.floor = (Rectangle){width_floor, height_floor}, .count_walls = 0};
}

void Room_addWall(Room* room, double width_wall, double height_wall) {
    if (room->count_walls >= MAX_WALLS) {
        printf("Cannot have more than %d walls", MAX_WALLS);
        return;
    }
    room->walls[room->count_walls] = Rectangle_create(width_wall, height_wall);
    room->count_walls++;
}

double Room_getFloorPerimeter(Room *room) {
    return Rectangle_perimeter(&room->floor);
}

double Room_getWallsPerimeter(Room *room) {
    double perimeter = 0;

    for (int i = 0; i < room->count_walls; i++) {
        perimeter += Rectangle_perimeter(&room->walls[i]);
    }

    return perimeter;
}

double Room_getFloorArea(Room *room) {
    return Rectangle_area(&room->floor);
}

double Room_getWallsArea(Room *room) {
    double area = 0;

    for (int i = 0; i < room->count_walls; i++) {
        area += Rectangle_area(&room->walls[i]);
    }

    return area;
}

void Room_print(Room* room) {
    printf("Room with floor size %.2lf width by %.2lf length.\n", room->floor.width, room->floor.height);

    for (int i = 0; i < room->count_walls; i++) {
        printf("Wall %d: ", i + 1);
        Rectangle_print(&room->walls[i]);
        puts("");
    }
}