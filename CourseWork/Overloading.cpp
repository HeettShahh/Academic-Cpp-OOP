#include <iostream>

struct Vector{
    float x, y;

    Vector operator- (const Vector& p2){
        return {x - p2.x, y - p2.y};
    };
};

Vector operator+ (const Vector& p1, const Vector& p2){
    return {p1.x + p2.x, p1.y + p2.y};
};

std::ostream& operator<< (std::ostream& stream, const Vector& point){
    stream << point.x << ',' << point.y <<std::endl;
    return stream;
};

int main() {
    
    // Vector position, speed;
    // position.x = 4.0f;
    // position.y = 5.0f;
    // speed.x = 0.5f;
    // speed.y = 1.5f;

    Vector position {4.0f, 5.0f};
    Vector speed {0.5f, 1.5f};

    Vector newPostion = position + speed;
    Vector newPostion2 = position - speed;

    std::cout << position;

    std::cout << position.x << "," << position.y << std::endl;
    // std::cout << speed.x << "," << speed.y << std::endl;

    // std::cout << newPostion.x << "," << newPostion.y << std::endl;
    // std::cout << newPostion2.x << "," << newPostion2.y << std::endl;

    return 0;
}