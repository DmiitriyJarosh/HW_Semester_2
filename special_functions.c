#pragma once
#include "asm.h"

int checkZero()
{
    if (stack.memory[stack.esp + 1] == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void getCode()
{
    char* buf;
    buf = calloc(sizeof(char), LENGTH_OF_STRING);
    gets(buf);
    code.memory[code.point] = buf;
    code.point++;
}

int charToInt(char* string, int pos)
{
    int number = 0;
    while (string[pos] >= '0' && string[pos] <= '9')
    {
        number = number * 10 + string[pos] - '0';
        pos++;
    }
    return number;
}

int checkPoint(char* string)
{
    if (string[0] >= '0' && string[0] <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int analyzeAndDoCode(int IP)
{
    int i, flag = 1;
    if (checkPoint(code.memory[IP]))
    {
        code.points[charToInt(code.memory[IP], 0)] = IP;
        i = 3;
    }
    else
    {
        i = 0;
    }
    switch (code.memory[IP][i])
    {
        case 'r':
            flag = 0;
        break;
        case 'l':
            if (code.memory[IP][i + 2] == 'c')
            {
                ldc(charToInt(code.memory[IP], i + 4));
            }
            else
            {
                ld(charToInt(code.memory[IP], i + 3));
            }
        break;
        case 's':
            if (code.memory[IP][i + 1] == 't')
            {
                st(charToInt(code.memory[IP], i + 3));
            }
            else
            {
                sub();
            }
        break;
        case 'a':
            add();
        break;
        case 'p':
            print();
        break;
        case 'c':
            cmp();
        break;
        case 'j':
            jmp(charToInt(code.memory[IP], i + 4));
        break;
        case 'b':
            br(charToInt(code.memory[IP], i + 3));
        break;
        case ';':
        break;
    }
    if (code.IP == IP)
    {
        code.IP++;
    }
    return flag;
}

