#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double real_number;
    double imaginary_number;
}
complex;

complex create_complex(double *real_number, double *imaginary_number);
complex addition_complex(complex *result_complex1, complex *result_complex2);
complex multiplication_complex(complex *result_complex1, complex *result_complex2);


int main()
{
    double real_number1, real_number2;
    printf("Digite um numero real: ");
    scanf("%lf", &real_number1);
    printf("Digite o segundo numero real: ");
    scanf("%lf", &real_number2);

    double imaginary_number1, imaginary_number2;
    printf("Digite um numero imaginario: ");
    scanf("%lf", &imaginary_number1);
    printf("Digite o segundo numero imaginario: ");
    scanf("%lf", &imaginary_number2);
    printf("\n");

    complex result_1 = create_complex(&real_number1, &imaginary_number1);
    complex result_2 = create_complex(&real_number2, &imaginary_number2);
    printf("\n");

    addition_complex(&result_1, &result_2);
    printf("\n");
    multiplication_complex(&result_1, &result_2);


    return 0;
}






complex create_complex(double *real_number, double *imaginary_number)
{ 
    complex numbers;
    
    numbers.real_number = *real_number;
    numbers.imaginary_number = *imaginary_number;

    printf("Complex number = %.2f + %.2fi\n", numbers.real_number, numbers.imaginary_number);

    return numbers;
}


complex addition_complex(complex *result_complex1, complex *result_complex2)
{
   complex sum_complex;

   sum_complex.real_number = result_complex1->real_number + result_complex2->real_number;
   sum_complex.imaginary_number = result_complex1->imaginary_number + result_complex2->imaginary_number;

    printf("Resultado da soma = %.2f + %.2fi\n", sum_complex.real_number, sum_complex.imaginary_number);

    return sum_complex;
}

complex multiplication_complex(complex *result_complex1, complex *result_complex2)
{
    complex mult_complex;

   
    mult_complex.real_number = result_complex1->real_number * result_complex2->real_number - result_complex1->imaginary_number * result_complex2->imaginary_number;

    mult_complex.imaginary_number = result_complex1->real_number * result_complex2->imaginary_number + result_complex1->imaginary_number * result_complex2->real_number;

    printf("Resultado da multiplicao = %.2f + %.2fi\n", mult_complex.real_number, mult_complex.imaginary_number);

    return mult_complex;
}


