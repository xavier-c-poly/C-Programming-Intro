typedef struct {
    int data;
    // other members
} MyStruct;

int main() {
    MyStruct obj;
    MyStruct *p = &obj;
    MyStruct **pp = &p;
    MyStruct ***ppp = &pp;
    MyStruct ****pppp = &ppp;

    int value = (**ppp)->data;
}