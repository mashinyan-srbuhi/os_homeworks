#include <stdio.h>

struct RegularStruct {
	char a;
	int b;
	double c;

};

#pragma pack(1)
struct PackedStruct1 {
	char a;
	int b;
	double c;
};

#pragma pack(2)
struct PackedStruct2 {
        char a;
        int b;
        double c;
};

#pragma pack(4)
struct PackedStruct4 {
        char a;
        int b;
        double c;
};

int main() {

        struct RegularStruct s;
        struct PackedStruct1 p1;
        struct PackedStruct2 p2;
        struct PackedStruct4 p4;

        printf("Without #pragma pack\n");
        printf("Size: %lu bytes\n", sizeof(s));
        printf("Address of char a: %p\n", &s.a);
        printf("Address of int b: %p\n", &s.b);
        printf("Address of double c: %p\n", &s.c);
        printf("\n");

        printf("#pragma pack(1)\n");
        printf("Size: %lu bytes\n", sizeof(p1));
        printf("Address of char a: %p\n", &p1.a);
        printf("Address of int b: %p\n", &p1.b);
        printf("Address of double c: %p\n", &p1.c);
        printf("\n");

        printf("#pragma pack(2)\n");
        printf("Size: %lu bytes\n", sizeof(p2));
        printf("Address of char a: %p\n", &p2.a);
        printf("Address of int b: %p\n", &p2.b);
        printf("Address of double c: %p\n", &p2.c);
        printf("\n");

        printf("#pragma pack(4)\n");
        printf("Size: %lu bytes\n", sizeof(p4));
        printf("Address of char a: %p\n", &p4.a);
        printf("Address of int b: %p\n", &p4.b);
        printf("Address of double c: %p\n", &p4.c);

	return 0;
}
