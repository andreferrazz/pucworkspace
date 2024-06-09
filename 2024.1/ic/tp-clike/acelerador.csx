#define DEBUG

static int sensor(int d)
{
    int res = (d % 8) - 5;
    return (res == -5) ? 3 : res;
}
Debug.Assert(sensor(6) == 1);
Debug.Assert(sensor(23) == 2);
Debug.Assert(sensor(9192) == 3);