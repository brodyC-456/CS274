#include <iostream>
#include <cmath>

class Vector2d {

    public:
        float x;
        float y;
        Vector2d(float x, float y) : x(x), y(y) {}
        virtual ~Vector2d() = default;
        virtual float magnitude() {return std::sqrt(x*x + y*y);}

};

class Vector3d : public Vector2d {
    public:
        float z;
        Vector3d(float x, float y, float z) : Vector2d(x, y), z(z) {};
        float magnitude() override {return std::sqrt(x*x + y*y + z*z);}
};


int main(){
    Vector2d vector2d(4, 6.5);
    std::cout << vector2d.magnitude() << '\n';
    Vector3d vector3d(9, 6.5, 4.12);
    std::cout << vector3d.magnitude() << '\n';
}