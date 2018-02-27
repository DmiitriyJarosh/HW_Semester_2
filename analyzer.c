#pragma once
#include "asm.h"

int analyzeAndDoCode(int IP)
{
    int i, flag = 1, wrongCommand = 0;
    if (checkPoint(code.memory[IP]))
    {
        i = takeTag(code.memory[IP]);
    }
    else
    {
        i = 0;
    }
    switch (code.memory[IP][i])
    {
        case 'r':
            if ((code.memory[IP][i + 1] == 'e') && (code.memory[IP][i + 2] == 't') && ((code.memory[IP][i + 3] == ' ') || (code.memory[IP][i + 3] == '\n') || (code.memory[IP][i + 3] == '\0')))
            {
                flag = 0;
            }
            else
            {
                wrongCommand = 1;
            }
        break;
        case 'l':
            if ((code.memory[IP][i + 1] == 'd') && (code.memory[IP][i + 2] == 'c') && ((code.memory[IP][i + 3] == ' ') || (code.memory[IP][i + 3] == '\n') || (code.memory[IP][i + 3] == '\0')))
            {
                ldc(charToInt(code.memory[IP], i + 4));
            }
            else
            {
                if ((code.memory[IP][i + 1] == 'd') && ((code.memory[IP][i + 2] == ' ') || (code.memory[IP][i + 2] == '\n') || (code.memory[IP][i + 2] == '\0')))
                {
                    ld(charToInt(code.memory[IP], i + 3));
                }
                else
                {
                    wrongCommand = 1;
                }
            }
        break;
        case 's':
            if ((code.memory[IP][i + 1] == 't') && ((code.memory[IP][i + 2] == ' ') || (code.memory[IP][i + 2] == '\n') || (code.memory[IP][i + 2] == '\0')))
            {
                st(charToInt(code.memory[IP], i + 3));
            }
            else
            {
                if ((code.memory[IP][i + 1] == 'u') && (code.memory[IP][i + 2] == 'b') && ((code.memory[IP][i + 3] == ' ') || (code.memory[IP][i + 3] == '\n') || (code.memory[IP][i + 3] == '\0')))
                {
                    sub();
                }
                else
                {
                    wrongCommand = 1;
                }
            }
        break;
        case 'a':
            if ((code.memory[IP][i + 1] == 'd') && (code.memory[IP][i + 2] == 'd') && ((code.memory[IP][i + 3] == ' ') || (code.memory[IP][i + 3] == '\n') || (code.memory[IP][i + 3] == '\0')))
            {
                add();
            }
            else
            {
                wrongCommand = 1;
            }
        break;
        case 'p':
            if ((code.memory[IP][i + 1] == 'r') && (code.memory[IP][i + 2] == 'i') && (code.memory[IP][i + 3] == 'n') && (code.memory[IP][i + 4] == 't') && ((code.memory[IP][i + 5] == ' ') || (code.memory[IP][i + 5] == '\n') || (code.memory[IP][i + 5] == '\0')))
            {
                print();
            }
            else
            {
                wrongCommand = 1;
            }
        break;
        case 'c':
            if ((code.memory[IP][i + 1] == 'm') && (code.memory[IP][i + 2] == 'p') && ((code.memory[IP][i + 3] == ' ') || (code.memory[IP][i + 3] == '\n') || (code.memory[IP][i + 3] == '\0')))
            {
                cmp();
            }
            else
            {
                wrongCommand = 1;
            }
        break;
        case 'j':
            if ((code.memory[IP][i + 1] == 'm') && (code.memory[IP][i + 2] == 'p') && ((code.memory[IP][i + 3] == ' ') || (code.memory[IP][i + 3] == '\n') || (code.memory[IP][i + 3] == '\0')))
            {
                jmp(readTag(code.memory[IP], i + 4));
            }
            else
            {
                wrongCommand = 1;
            }
        break;
        case 'b':
            if ((code.memory[IP][i + 1] == 'r') && ((code.memory[IP][i + 2] == ' ') || (code.memory[IP][i + 2] == '\n') || (code.memory[IP][i + 2] == '\0')))
            {
                br(readTag(code.memory[IP], i + 3));
            }
            else
            {
                wrongCommand = 1;
            }
        break;
        case ';':
        break;
        default :
            {
                printf("Unknown command");
                exit(0);
            }
    }
    if (wrongCommand == 1)
    {
        printf("Unknown command");
        exit(0);
    }
    if (code.IP == IP)
    {
        code.IP++;
    }
    return flag;
}
