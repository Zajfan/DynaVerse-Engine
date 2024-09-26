// 2D Vector Class
class Vector2D {
public:
    float x, y;

    Vector2D();
    Vector2D(float x, float y);

    // Vector addition
    Vector2D operator+(const Vector2D& other) const;

    // Vector subtraction
    Vector2D operator-(const Vector2D& other) const;

    // Scalar multiplication
    Vector2D operator*(float scalar) const;

    // Scalar division
    Vector2D operator/(float scalar) const;

    // Dot product
    float dot(const Vector2D& other) const;

    // Magnitude (length)
    float magnitude() const;

    // Normalize (make unit length)
    void normalize();

    // Cross product (for 2D, it returns a scalar representing the magnitude)
    float cross(const Vector2D& other) const;

    // Squared magnitude (avoids the square root for efficiency in some cases)
    float squaredMagnitude() const;

    // Distance to another vector
    float distanceTo(const Vector2D& other) const;
};