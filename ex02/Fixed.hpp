#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int                 _fixedPointNumber;
        static const int    _fractionalBits;
    public:
        // construtores
        Fixed();
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        // funções membros
        int                 getRawBits(void) const;
        void                setRawBits(int const raw);
        float               toFloat( void ) const;
        int                 toInt( void ) const;
        static Fixed        &min(Fixed &a, Fixed &b);
        static Fixed        &max(Fixed &a, Fixed &b);
        static const Fixed  &min(const Fixed &a, const Fixed &b);
        static const Fixed  &max(const Fixed &a, const Fixed &b);

        bool operator > (const Fixed &other) const;
        bool operator < (const Fixed &other) const;
        bool operator >= (const Fixed &other) const;
        bool operator <= (const Fixed &other) const;
        bool operator == (const Fixed &other) const;
        bool operator != (const Fixed &other) const;

        Fixed operator + (const Fixed &other) const;
        Fixed operator - (const Fixed &other) const;
        Fixed operator * (const Fixed &other) const;
        Fixed operator / (const Fixed &other) const;

        Fixed &operator ++ (void);
        Fixed operator ++ (int);
        Fixed &operator -- (void);
        Fixed operator -- (int);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif