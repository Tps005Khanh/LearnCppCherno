#include <iostream>

// union U { int i; char f; };
// struct S { int i; char f; };
// class C { public: int i; char f; };

// union U { char f;};
// struct S { char f; };
// class C { public: char f; };

// #pragma pack(1)
// union U { char f; int x;};
// struct S { char f; int x;};
// class C { public: char f; int x;};

union U { char f; long long x;};
struct S { char f; long long x;};
class C { public: char f; long long x;};

union MyUnion {
    char c;     // 1 byte
    unsigned int i;      // 4 byte
    double d;   // 8 byte
};

//------------------------Fisrt Stage---------------------


struct Vector2D
{
    float x,y;

    // Vector2D(float x, float y) 
    // : x(x), y(y) 
    // {
    // }
};

struct Vector4D
{
    //-----------------------------------------------------
    //float w,x,y,z;

    // //We can get vector 4 by two vector 2
    // Vector2D GetA()
    // {
    //     return Vector2D(w,x);
    // }
    // Vector2D GetB()
    // {
    //     return Vector2D(y,z);
    // }

    //Or we can 
    // Vector2D& Get()
    // {
    //     return *(Vector2D*)&w; 
    // }
    //-----------------------------------------------------

    union 
    {
        struct 
        {
            float w,x,y,z;
        };
        struct 
        {
            Vector2D a,b;
        };
        //}vec2; if vector2D have constructor 
        
    };
};

void Print(const Vector2D &vector2d)
{
    std::cout << vector2d.x << "   " << vector2d.y;
}
void PrintAddress(const Vector2D &vector2d)
{
    std::cout << &vector2d << std::endl;
}

int main() {

    // std::cout << "Union:  " << sizeof(U) << " bytes\n";
    // std::cout << "Struct: " << sizeof(S) << " bytes\n";
    // std::cout << "Class:  " << sizeof(C) << " bytes\n";
    // MyUnion uni{15};
    // std::cout << uni.c << "\n";// 15 in char
    // std::cout << uni.i << "\n";// 15 in int
    // std::cout << uni.d << "\n";// 15 in double 

    //------------------------Fisrt Stage---------------------

    Vector4D vec{1.0f, 2.0f, 3.0f, 4.0f};
    //PrintAddress(vec.vec2.a);
    PrintAddress(vec.a);//if vector2D have constructor 
    std::cout << &vec.w << "\n";
}
