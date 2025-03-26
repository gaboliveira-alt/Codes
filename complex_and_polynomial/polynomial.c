#include <stdio.h>

typedef struct polynomial
{
    int degree;
    int coef[10];
}
polynomial;

void elevuation_poly(polynomial *poly);
polynomial sum_polys(polynomial *poly1, polynomial *poly2);

int main()
{
    polynomial poly_1 = {2, {4, -7, 12}};  
    polynomial poly_2 = {3, {8, -2, 5, 11}};  

    printf("\n");
    printf("Polinomio 1:\n");
    printf("Grau: %d\n", poly_1.degree);
    printf("Termo Independente: %d\n", poly_1.coef[0]);
    elevuation_poly(&poly_1);

    printf("\n");
    printf("Polinomio 2:\n");
    printf("Grau: %d\n", poly_2.degree);
    printf("Termo Independente: %d\n", poly_2.coef[0]);
    elevuation_poly(&poly_2);

    printf("\n");
    printf("Soma dos Polinomios:\n");
    polynomial sum_poly = sum_polys(&poly_1, &poly_2);
    printf("Grau: %d\n", sum_poly.degree);
    printf("Termo Independente: %d\n", sum_poly.coef[0]);
    elevuation_poly(&sum_poly);

    return 0;
}



polynomial sum_polys(polynomial *poly1, polynomial *poly2)
{
    polynomial result_poly;

    if (poly1->degree > poly2->degree)
    {
        result_poly.degree = poly1->degree;
    }
    else
    {
        result_poly.degree = poly2->degree;
    }

    for (int i = 0; i <= result_poly.degree; i++)
    {
        int coefp1 = 0;
        int coefp2 = 0;

        if (i <= poly1->degree)
        {
            coefp1 = poly1->coef[i];
        }
        if (i <= poly2->degree)
        {
            coefp2 = poly2->coef[i];
        }

        result_poly.coef[i] = coefp1 + coefp2;
    }

    return result_poly;
}

void elevuation_poly(polynomial *poly)
{
    int first_term = 1;

    for (int i = poly->degree; i >= 0; i--)
    {
        if (poly->coef[i] != 0)
        {
            if (!first_term)
            {
                if (poly->coef[i] > 0)
                {
                    printf(" + ");
                }
                else
                {
                    printf(" - ");
                }
            }
            else
            {
                if (poly->coef[i] < 0)
                {
                    printf("-");
                }

                first_term = 0;
            }

            if (i == 0 || (poly->coef[i] != 1 && poly->coef[i] != -1))
            {
                if (poly->coef[i] < 0) 
                {
                    printf("%d", -poly->coef[i]);  
                }
                else
                {
                    printf("%d", poly->coef[i]);
                }

            }

            if (i > 0)
            {
                printf("x");
                if (i > 1)
                {
                    printf("^%d", i);
                }
            }
        }
    }
    printf("\n");
}
