//
// ColorFactory.
// factory of colors.
//

#ifndef EX2AP_COLORFACTORY_H
#define EX2AP_COLORFACTORY_H

#include "Color.h"

class ColorFactory {
public:
    /**
     *
     * @param letter to create Color from
     * @return the Color of the letter
     */
    static Color colorFromCharFactory(char letter) {
        switch (letter) {
            case 'R':
                return Color::RED;
            case 'B':
                return Color::BLUE;
            case 'G':
                return Color::GREEN;
            case 'P':
                return Color::PINK;
            case 'W':
                return Color::WHITE;
            default:
                return Color::UNDEFINED;
        }
    }
};


#endif //EX2AP_COLORFACTORY_H