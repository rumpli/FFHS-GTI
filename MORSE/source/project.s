/*
Das 3.1 Programm
18.10.2020 www.satyria.de
*/

.include "base.inc"
.include "gpio.h"
.include "time.h"
.include "alphabet.h"

.section .init
.globl _start
_start:

b main

.section .text    @Anweisung an den Linker, dass jetzt Code kommt

main:             @Erzeuge das Label "main"
  mov sp,#0x8000 @Erzeuge einen Stapel von 32768 Bytes

MainLoop:         @Endlosschleife 

  bl S
  bl O
  bl S

b MainLoop
