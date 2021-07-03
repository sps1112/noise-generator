#ifndef MATH_DEF_H
#define MATH_DEF_H

// Clamps a float between 2 values
float clamp(float val, float min = 0.0f, float max = 1.0f)
{
    return ((val > max) ? max : ((val < min) ? min : val));
}

// Returns the min of a and b
float min(float a, float b)
{
    return (a < b) ? a : b;
}

// Returns the max of a and b
float max(float a, float b)
{
    return (a > b) ? a : b;
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

// Lerps between a and b by amount l
float lerp(float a, float b, float l)
{
    l = clamp(l);
    float diff = b - a;
    return a + (l * diff); // l=0 => a and l=1 => b
}

// Lerps the value of 'a' such that min==>0 and max==>1
float inverse_lerp(float a, float min, float max)
{
    float diff = max - min;
    return (a - min) / diff;
}

#endif // MATH_DEF_H
