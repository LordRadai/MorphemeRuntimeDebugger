#pragma once
#include <math.h>
#include <Windows.h>

#include <iostream>
#include <cmath>

using namespace std;

class ScreenPoint
{
public:
    int x, y;
};

class Vector3 {
public:
    float x, y, z; // vector components

    // Constructors
    Vector3() {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3(float x0, float y0, float z0) {
        x = x0;
        y = y0;
        z = z0;
    }

    // Copy constructor
    Vector3(const Vector3& v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    // Vector addition
    Vector3 operator+(const Vector3& v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    // Vector subtraction
    Vector3 operator-(const Vector3& v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    // Scalar multiplication
    Vector3 operator*(float s) const {
        return Vector3(s * x, s * y, s * z);
    }

    // Dot product
    float operator*(const Vector3& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    // Cross product
    Vector3 operator%(const Vector3& v) const {
        return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }

    // Vector magnitude
    float magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Normalize vector
    void normalize() {
        float mag = magnitude();
        if (mag > 0) {
            x /= mag;
            y /= mag;
            z /= mag;
        }
    }

    // Print vector
    void print() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

class Matrix4 {
public:
    float m[4][4]; // 4x4 matrix elements

    // Constructor
    Matrix4() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j)
                    m[i][j] = 1;
                else
                    m[i][j] = 0;
            }
        }
    }

    // Overloaded constructor
    Matrix4(float elements[4][4]) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] = elements[i][j];
            }
        }
    }

    // Matrix multiplication
    Matrix4 operator*(Matrix4 const& b) {
        Matrix4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    result.m[i][j] += m[i][k] * b.m[k][j];
                }
            }
        }
        return result;
    }

    // Scalar multiplication
    Matrix4 operator*(float const& scalar) {
        Matrix4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i][j] = m[i][j] * scalar;
            }
        }
        return result;
    }

    Vector3 operator*(Vector3 const& vector) {
        Vector3 result;
        result.x = (vector.x * m[0][0]) + (vector.y * m[0][1]) + (vector.z * m[0][2]) + m[0][3];
        result.y = (vector.x * m[1][0]) + (vector.y * m[1][1]) + (vector.z * m[1][2]) + m[1][3];
        result.z = (vector.x * m[2][0]) + (vector.y * m[2][1]) + (vector.z * m[2][2]) + m[2][3];

        return result;
    }

    // Transpose of matrix
    Matrix4 transpose() {
        Matrix4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i][j] = m[j][i];
            }
        }
        return result;
    }
};

#include <iostream>
#include <cmath>
using namespace std;

// Define quaternion class
class Quaternion {
public:
    float w, x, y, z; // quaternion components

    // Constructors
    Quaternion() {
        w = 1;
        x = 0;
        y = 0;
        z = 0;
    }

    Quaternion(float w0, float x0, float y0, float z0) {
        w = w0;
        x = x0;
        y = y0;
        z = z0;
    }

    // Convert quaternion to 4x4 matrix
    void toMatrix(Matrix4* mat) {
        // Compute matrix components
        float xx = x * x;
        float xy = x * y;
        float xz = x * z;
        float xw = x * w;
        float yy = y * y;
        float yz = y * z;
        float yw = y * w;
        float zz = z * z;
        float zw = z * w;

        mat->m[0][0] = 1 - 2 * (yy + zz);
        mat->m[0][1] = 2 * (xy - zw);
        mat->m[0][2] = 2 * (xz + yw);
        mat->m[0][3] = 0;

        mat->m[1][0] = 2 * (xy + zw);
        mat->m[1][1] = 1 - 2 * (xx + zz);
        mat->m[1][2] = 2 * (yz - xw);
        mat->m[1][3] = 0;

        mat->m[2][0] = 2 * (xz - yw);
        mat->m[2][1] = 2 * (yz + xw);
        mat->m[2][2] = 1 - 2 * (xx + yy);
        mat->m[2][3] = 0;

        mat->m[3][0] = 0;
        mat->m[3][1] = 0;
        mat->m[3][2] = 0;
        mat->m[3][3] = 1;
    }
};

namespace Math
{
    bool worldToScreen(Vector3 position, ScreenPoint* sp);

	float frameToTime(int frame, int frameRate);

	int timeToFrame(float time, int frameRate);
}