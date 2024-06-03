#include <stdio.h>

int a = 3;
float b = 1;

int func3(float a, float *m) {
    b += (*m) + 1;
    (*m) += 3;
    printf("(func3) a=%.2f b=%.2f m=%.2f \n", (float)a, (float)b, (float)(*m));
    return a + b;
}

void func2(int b, float c, float *m) {
    b = func3(a, &c);
    (*m) = a + b;
    printf("(func2) a=%.2f b=%.2f c=%.2f m=%.2f \n", (float)a, (float)b, (float)c, (float)(*m));
}

int main() {
    int a = 10;
    float res;
    func2(a, b, &res);
    printf("(main) a=%.2f b=%.2f res=%.2f \n", (float)a, (float)b, (float)res);
}
