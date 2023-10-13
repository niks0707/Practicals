struct numbers{
    int a;
};

program MATH_PROG {
    version MATH_VERSION {
        int SQUARE(numbers) = 1;
        float SQRT(numbers) = 2;
        int FACTORIAL(numbers) = 3;
    } = 1;
} = 0x20000001;

