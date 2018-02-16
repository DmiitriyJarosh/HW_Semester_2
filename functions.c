#pragma once
#include "asm.h"

void init()
{
    stack.memory = (int*)malloc(sizeof(int) * SIZE_OF_STACK);
    stack.esp = SIZE_OF_STACK - 1;
    heap.memory = (int*)malloc(sizeof(int) * SIZE_OF_HEAP);
    code.memory = (char**)calloc(sizeof(char*), SIZE_OF_CODE);
    code.point = 0;
    code.IP = 0;
    code.points = (int*)calloc(sizeof(int), SIZE_OF_CODE);
}

void deinit()
{
    int i;
    free(stack.memory);
    free(heap.memory);
    free(code.points);
    for (i = 0; i < code.point; i++)
    {
        free(code.memory[i]);
    }
    free(code.memory);
}

void ld(int adr)
{
    stack.memory[stack.esp] = heap.memory[adr];
    stack.esp--;
}

void st(int adr)
{
    heap.memory[adr] = stack.memory[stack.esp + 1];
    stack.esp++;
}

void print()
{
    printf("%d\n", stack.memory[stack.esp + 1]);
}

void ldc(int num)
{
    stack.memory[stack.esp] = num;
    stack.esp--;
}

void add()
{
    stack.memory[stack.esp] = stack.memory[stack.esp + 1] + stack.memory[stack.esp + 2];
    stack.esp--;
}

void sub()
{
    stack.memory[stack.esp] = stack.memory[stack.esp + 1] - stack.memory[stack.esp + 2];
    stack.esp--;
}

void cmp()
{
    if (stack.memory[stack.esp + 1] > stack.memory[stack.esp + 2])
    {
        stack.memory[stack.esp] = 1;
        stack.esp--;
    }
    else
    {
        if (stack.memory[stack.esp + 1] < stack.memory[stack.esp + 2])
        {
            stack.memory[stack.esp] = -1;
            stack.esp--;
        }
        else
        {
            stack.memory[stack.esp] = 0;
            stack.esp--;
        }
    }
}

void br(int point)
{
    if (checkZero())
    {
        code.IP = code.points[point];
    }
}

void jmp(int point)
{
    code.IP = code.points[point];
}
