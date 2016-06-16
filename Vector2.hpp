#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include<math.h>
#include<cmath>

template<class T>
class Vector2
{
    public:

    T x, y;
           
    Vector2(const T& x_pos = T(), const T& y_pos = T());
            
    template<class E>
    Vector2(const Vector2<E>& other);

    Vector2(const Vector2<T>&);

    Vector2(const Vector2<T>&&);
            
    Vector2& operator=(const Vector2<T>&);
            
    Vector2& operator=(const Vector2<T>&&);
            
    Vector2 operator+(const Vector2&) const;
            
    Vector2 operator-(const Vector2&) const;
            
    Vector2& operator+=(const Vector2&);
            
    Vector2& operator-=(const Vector2&);
            
    Vector2 operator*(const Vector2&) const;

    Vector2 operator*(const T) const;

    Vector2 abs() const;

    float distance(const Vector2&) const;

}; 

template<class T>
Vector2<T>::Vector2(const T& x_pos, const T& y_pos):x(x_pos),y(y_pos)
{}

template<class T>
Vector2<T>::Vector2(const Vector2& other):x(other.x), y(other.y)
{} 

template<class T>
Vector2<T>::Vector2(const Vector2&& other):x(other.x), y(other.y)
{}

template<class T>
Vector2<T>& Vector2<T>::operator=(const Vector2& other)
{
    if(this == &other)
        return *this;

    x = other.x;
    y = other.y;

    return *this;
}

template<class T>
Vector2<T>& Vector2<T>::operator=(const Vector2&& other)
{
    if(this == & other)
        return *this;
    x = other.x;
    y = other.y;

    return *this;
}

template<class T>
Vector2<T> Vector2<T>::operator+(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}

template<class T>
Vector2<T> Vector2<T>::operator-(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator+=(const Vector2& other)
{
    x += other.x;
    y += other.y;
    
    return *this;
}

template<class T>
Vector2<T>& Vector2<T>::operator-=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;
    
    return *this;
}

template<class T>
Vector2<T> Vector2<T>::operator*(const Vector2& other) const
{
    return Vector2(x * other.x, y * other.y);
}

template<class T>
Vector2<T> Vector2<T>::operator*(const T val) const
{
    return Vector2(x*val, y*val);
}

template<class T>
Vector2<T> Vector2<T>::abs() const
{
    return Vector2(std::abs(x), std::abs(y));
}

template<class T>
float Vector2<T>::distance(const Vector2& other) const
{
    float l1 = x - other.x;
    float l2 = y - other.y;
    
    return sqrt(pow(l1, 2) + pow(l2, 2));
}

template<class T>
template<class E>
Vector2<T>::Vector2(const Vector2<E>& other)
{
    x = (T) other.x;
    y = (T) other.y;
}
#endif /*Vector2<T>*/
