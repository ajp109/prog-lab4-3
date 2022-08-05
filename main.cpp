#include "mbed.h"

class BoundedInt {

    int min_;
    int max_;
    int value_;

public:
  
    /* Constructor: takes a minimum and maximum value, and an initial value.
    Enforces min <= max and calls setValue() to enforce min <= value <= max. */
    BoundedInt(int min, int max, int value) {
        if (max < min) {
            max = min;
        }
        min_ = min;
        max_ = max;
        setValue(value);
    }

    /* Sets a new value for this BoundedInt.  If the supplied value is outside
    the range [min, max] it will be set to the closest valid value instead. */
    void setValue(int value) {
        if (value < min_) {
            value = min_;
        }
        if (value > max_) {
            value = max_;
        }
        value_ = value;
    }

    /* Returns the value of this BoundedInt as an int */
    int getValue() {
        return value_;
    }

    /* Shorthand for .setValue() */
    BoundedInt & operator=(int value) {
        setValue(value);
        return *this;
    }

};

int main() {
    printf("ok\r\n");

    BoundedInt test(0, 10, 0); // Minimum, maximum, initial value

    printf("Value is %d\r\n", test.getValue());
    test = 4;
    printf("Value is %d\r\n", test.getValue());
    test = 25;
    printf("Value is %d\r\n", test.getValue());

    // Do nothing, forever, when the program is complete
    while (true) sleep();
}
