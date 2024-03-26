#include <iostream>
#include <string>
using namespace std;

class Triangle {
public:
    Triangle(float a, float b, float c);
    ~Triangle();
    Triangle(const Triangle& oth);
    bool isTriangle(float a, float b, float c);
    float getSideA() const {
        return sideA;
    }
    float getSideB() const {
        return sideB;
    }
    float getSideC() const {
        return sideC;
    }
    void setValue(float a, float b, float c);
    bool isEquilateral();
    bool isScalene();
    bool isIsosceles();
    void triangleType();
    float calculateArea();
private:
    float sideA, sideB, sideC;
};
Triangle::Triangle(float a,float b,float c) {
    while (!isTriangle(a, b, c)) {
        cout << "Please enter the sides(a-b-c):" << endl;
        cin >> a >> b >> c;
    }
    sideA = a;
    sideB = b;
    sideC = c;
    cout << "Triangle created." << endl;
}
Triangle::~Triangle() {
    cout << "Triangle destroyed." << endl;
}
Triangle::Triangle(const Triangle& oth) {
    sideA = oth.sideA;
    sideB = oth.sideB;
    sideC = oth.sideC;
    cout << "Triangle copied to target." << endl;
}
void Triangle::setValue(float a, float b, float c) {
    while (!isTriangle(a, b, c)) {
        cout << "Please enter the sides(a-b-c):" << endl;
        cin >> a >> b >> c;
    }
    sideA = a;
    sideB = b;
    sideC = c;
}

bool Triangle::isTriangle(float a, float b, float c) {
    //sideA:     |b-c|<a<b+c
    //sideB:     |a-c|<b<a+c
    //sideC:     |a-b|<c<a+b
    if (!((abs(b - c) < a && (a < b + c)))) {
        cout << "Invalid A" << endl;
        return false;
    }
    if (!((abs(a - c) < b && (b < a + c)))) {
        cout << "Invalid B" << endl;
        return false;
    }
    if (!((abs(a-b) < c && (c<a+b)))) {
        cout << "Invalid A" << endl;
        return false;
    }
    return true;
}

bool Triangle::isEquilateral() {
    return sideA == sideB && sideC == sideB;
}

bool Triangle::isIsosceles() {
    if (isEquilateral()) {
        return true;
    }
    else {
        return sideA == sideB || sideB == sideC || sideA == sideC;
    }
}

bool Triangle::isScalene() {
    return !isEquilateral();
}

void Triangle::triangleType() {
    if (isEquilateral()) {
        cout << "Equilateral Triangle" << endl;
    }
    else if (isIsosceles()){
        cout << "Isosceles Trinagle" << endl;
    }
    else {
        cout << "Scalene Triangle" << endl;
    }
}

float Triangle::calculateArea() {
    float area;
    if (isEquilateral()) {
        area = (pow(sideA, 2) * sqrt(3) / 4);
        return area;
    }
    float s =(sideA + sideB + sideC) / 2;
    area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    return area;
}

