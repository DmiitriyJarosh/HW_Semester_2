#include "asm.h"

main()
{
    printf("Welcome to ASM!\n");
    init();
    getCode();
    while (analyzeAndDoCode(code.IP))
    {
        if (code.point == code.IP)
        {
            getCode();
        }
    }
    deinit();
    return 0;
}
