#ifndef MATH_DEF_H
#define MATH_DEF_H

// Clamps a float between 2 values
float clamp(float val, float min = 0.0f, float max = 1.0f)
{
    return ((val > max) ? max : ((val < min) ? min : val));
}

// Clamps a int between 2 values
int clampi(int val, int min, int max)
{
    return ((val > max) ? max : ((val < min) ? min : val));
}

// Sets the val to be greater than min by diff
float floor(float val, float min, float diff = 0.0001)
{
    return ((val < (min + diff)) ? (min + diff) : val);
}
#endif // MATH_DEF_H
