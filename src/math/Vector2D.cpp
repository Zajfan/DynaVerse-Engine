// 2D Vector Class
class Vector2D {
public:
    float x, y;

    Vector2D() : x(0), y(0) {}
    Vector2D(float x, float y) : x(x), y(y) {}

    // Vector addition
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Vector subtraction
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // Scalar multiplication
    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    // Scalar division
    Vector2D operator/(float scalar) const {
        return Vector2D(x / scalar, y / scalar);
    }

    // Dot product
    float dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    // Cross product (for 2D, it returns a scalar representing the magnitude)
    float cross(const Vector2D& other) const {
        return x * other.y - y * other.x;
    }

    // Magnitude (length)
    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    // Squared magnitude (avoids the square root for efficiency in some cases)
    float squaredMagnitude() const {
        return x * x + y * y;
    }

    // Distance to another vector
    float distanceTo(const Vector2D& other) const {
        return (*this - other).magnitude();
    }

    // Normalize (make unit length)
    void normalize() {
        float mag = magnitude();
        if (mag > 0) {
            x /= mag;
            y /= mag;
        }
    }
};