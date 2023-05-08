    .text
    .align 2

    .globl _start

_start:
    lui     sp, 0x80020     # set stack pointer to 0x80020000

    li      a0, 0           # no arguments (argc=0)
    li      a1, 0           # no arguments (argv=NULL)
    call    main

    ebreak
