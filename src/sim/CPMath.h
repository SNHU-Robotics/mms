// CPMath stands for Cross Platform Math

#ifdef _WIN32
#   define _USE_MATH_DEFINES
#endif

#include <cmath>

#undef M_PI
#define M_PI 3.14159265358979323846
#undef M_TWOPI
#define M_TWOPI (2 * M_PI)
