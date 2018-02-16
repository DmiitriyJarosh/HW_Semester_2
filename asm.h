#pragma once
#ifndef ASM_H_INCLUDED
#define ASM_H_INCLUDED


#define SIZE_OF_HEAP 0x80000
#define SIZE_OF_STACK 100
#define SIZE_OF_CODE 256
#define LENGTH_OF_STRING 256


struct stack
{
    int* memory;
    int esp;
}stack;

struct heap
{
    int* memory;

}heap;

struct code
{
    char** memory;
    int point;
    int IP;
    int* points;
}code;

#include <stdio.h>
//#include "functions.c"
//#include "asm.c"
//#include "special_functions.c"


void init();
void ld(int adr);
void st(int adr);
void ldc(int num);
void add();
void sub();
void cmp();
void br(int point);
void jmp(int point);
int checkZero();
void getCode();
int charToInt(char* string, int pos);
int checkPoint(char* string);
int analyzeAndDoCode(int IP);
void print();


#endif // ASM_H_INCLUDED
