#include <stdio.h>
#include <string.h>

#define MAX_WALLS 20
#define MAX_ROOM_NAME 25

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
    char* room_name;
} Room;
// ---------------------------------------------------

// --------------- FUNCTION PROTOTYPES ---------------
Rectangle   Rectangle_create(double width, double height);
Rectangle   Rectangle_createPromopt(void);
double      Rectangle_getPerimeter(Rectangle* rect);
double      Rectangle_getArea(Rectangle* rect);
void        Rectangle_print(Rectangle* rect);

Room        Room_create(char* room_name, double width_floor, double height_floor);
void        Room_addWall(Room* room, double width_wall, double height_wall);
double      Room_getFloorPerimeter(Room *room);
double      Room_getWallsPerimeter(Room *room);  // Total perimeter of all the walls
double      Room_getFloorArea(Room *room);
double      Room_getWallsArea(Room *room);
void        Room_print(Room* room);
void        Room_printToFile(Room *r, char *file_name);
// ---------------------------------------------------



int main(void) {
    // Create a rectangle r with 15.4 width and 23.5 height
    Rectangle rect1 = {15.4, 23.5};
    Rectangle rect2 = Rectangle_create(12.50, 8.00);

    Rectangle_print(&rect1);
    Rectangle_print(&rect2);

    puts("");

    printf("Perimeter of rect2:\t%.2lf\n", Rectangle_getPerimeter(&rect2));
    printf("Area of rect2:\t\t%.2lf\n", Rectangle_getArea(&rect2));

    puts("");

    // Create an array of rectangles
    Rectangle arr[3];
    arr[0] = Rectangle_create(14.2, 875.3);
    arr[1] = Rectangle_create(44.2, 84.3);
    arr[2] = Rectangle_create(447.2, 184.3);

    for (int i = 0; i < 3; i++) {
        printf("Rectangle %d: Perimeter %.2lf, Area %.2lf\n", i + 1, Rectangle_getPerimeter(&arr[i]), Rectangle_getArea(&arr[i]));
    }


    // Create a room
    Room living_room = Room_create("Living Room", 12.12, 12.21);
    Room_addWall(&living_room, 13.84, 13.18);
    Room_addWall(&living_room, 16.16, 14.14);
    Room_addWall(&living_room, 13.98, 12.67);
    Room_addWall(&living_room, 14.41, 11.39);

    Room_printToFile(&living_room, "rooms.txt");

    puts("\n============================================\n");

    // Print the room
    Room_print(&living_room);

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

double Rectangle_getPerimeter(Rectangle* rect) {
    return (rect->width * 2) + (rect->height * 2);
}

double Rectangle_getArea(Rectangle* rect) {
    return rect->width * rect->height;
}

void Rectangle_print(Rectangle* rect) {
    printf("Rectangle width:\t%.2lf\n", rect->width);
    printf("Rectangle height:\t%.2lf\n", rect->height);
    printf("Perimeter:\t\t%.2lf\n", Rectangle_getPerimeter(rect));
    printf("Area:\t\t\t%.2lf\n", Rectangle_getArea(rect));
}

Room Room_create(char* room_name, double width_floor, double height_floor) {
    if (strlen(room_name) > MAX_ROOM_NAME) room_name = "";
    return (Room) {.room_name = room_name, .floor = (Rectangle){width_floor, height_floor}, .count_walls = 0};
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
    return Rectangle_getPerimeter(&room->floor);
}

double Room_getWallsPerimeter(Room *room) {
    double perimeter = 0;

    for (int i = 0; i < room->count_walls; i++) {
        perimeter += Rectangle_getPerimeter(&room->walls[i]);
    }

    return perimeter;
}

double Room_getFloorArea(Room *room) {
    return Rectangle_getArea(&room->floor);
}

double Room_getWallsArea(Room *room) {
    double area = 0;

    for (int i = 0; i < room->count_walls; i++) {
        area += Rectangle_getArea(&room->walls[i]);
    }

    return area;
}

void Room_print(Room* room) {
    printf("=== ROOM [%s] ===\n", room->room_name);
    printf("Floor: %.2lf x %.2lf  Perimeter = %.2lf  Area = %.2lf\n", room->floor.width, room->floor.height, Room_getFloorPerimeter(room), Room_getFloorArea(room));
    printf("Walls (%d):\n", room->count_walls);
    for (int i = 0; i < room->count_walls; i++)
        printf("  Wall %d: %.2lf x %.2lf  Perimeter = %.2lf  Area = %.2lf\n", i + 1, room->walls[i].width, room->walls[i].height, Rectangle_getArea(&room->walls[i]), Rectangle_getArea(&room->walls[i]));

}

void Room_printToFile(Room *r, char *file_name) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        return;
    }
    fprintf(file, "=== ROOM [%s] ===\n", r->room_name);
    fprintf(file, "Floor: %.2lf x %.2lf  Perimeter = %.2lf  Area = %.2lf\n", r->floor.width, r->floor.height, Room_getFloorPerimeter(r), Room_getFloorArea(r));
    fprintf(file, "Walls (%d):\n", r->count_walls);
    for (int i = 0; i < r->count_walls; i++)
        fprintf(file, "  Wall %d: %.2lf x %.2lf  Perimeter = %.2lf  Area = %.2lf\n", i + 1, r->walls[i].width, r->walls[i].height, Rectangle_getArea(&r->walls[i]), Rectangle_getArea(&r->walls[i]));
}