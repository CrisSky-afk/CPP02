#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : _fixedPointNumber(number << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _fixedPointNumber(static_cast<int>(roundf(number * (1 << _fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixedPointNumber(other._fixedPointNumber)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointNumber = other._fixedPointNumber;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointNumber;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPointNumber = raw;
}

float Fixed::toFloat(void) const 
{
    return (static_cast<float>(_fixedPointNumber) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_fixedPointNumber >> _fractionalBits);
}

bool Fixed::operator > (const Fixed &other) const 
{ 
    return _fixedPointNumber > other._fixedPointNumber; 
}

bool Fixed::operator < (const Fixed &other) const 
{ 
    return _fixedPointNumber < other._fixedPointNumber; 
}

bool Fixed::operator >= (const Fixed &other) const 
{ 
    return _fixedPointNumber >= other._fixedPointNumber; 
}

bool Fixed::operator <= (const Fixed &other) const 
{ 
    return _fixedPointNumber <= other._fixedPointNumber; 
}

bool Fixed::operator == (const Fixed &other) const 
{ 
    return _fixedPointNumber == other._fixedPointNumber; 
}

bool Fixed::operator != (const Fixed &other) const 
{ 
    return _fixedPointNumber != other._fixedPointNumber; 
}

Fixed Fixed::operator + (const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator - (const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator * (const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator / (const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    _fixedPointNumber++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _fixedPointNumber++;
    return temp;
}

Fixed &Fixed::operator--()
{
    _fixedPointNumber--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _fixedPointNumber--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}