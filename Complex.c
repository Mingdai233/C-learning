#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>



¸´ÊýÔËËã
typedef struct Complex
{
	float realpart;
	float imagpart;
}Complex;

void assign(Complex *A, float real, float imag);
void add(Complex*C, Complex A, Complex B);
void multiply(Complex*C, Complex A, Complex B);
void divide(Complex*C, Complex A, Complex B);

int main()
{
	Complex A, B, C,D,E;
	assign(&A, 8, 6);
	assign(&B, 4, 3);
	multiply(&C, A, B); 
	add(&D, A, B);
	divide(&E, C, D);
	return 0;
}

void assign(Complex*A, float real, float imag)
{
	A->realpart = real;
	A->imagpart = imag;
}

void add(Complex *C, Complex A, Complex B)
{
	C->realpart = A.realpart + B.realpart;
	C->imagpart = A.imagpart + B.imagpart;
}

void multiply(Complex*C, Complex A, Complex B)
{
	C->realpart = A.realpart*B.realpart - A.imagpart*B.imagpart;
	C->imagpart = A.imagpart*B.realpart + B.imagpart*A.realpart;
}

void divide(Complex *C, Complex A, Complex B)
{
	float a;
	Complex d,e;
	assign(&d, B.realpart, -(B.imagpart));
	multiply(&e, A, d);
	a = B.realpart*B.realpart + B.imagpart*B.imagpart;
	C->realpart = e.realpart / a;
	C->imagpart = e.imagpart / a;
}
