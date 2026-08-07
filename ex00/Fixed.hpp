#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int _fixedPointNumber;
        static const int _fractionalBits;
    public:
        // construtores
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        // funções membros
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif