/* Alphabet.h */

dot: @kurz .
   push {r5,lr}
   mov r5,r0 @sichere die Übergabe
   mov r0,#24
   bl LED_on
   mov r0,#0x50000
   bl wait
   mov r0,#24
   bl LED_off
   pop {r5,pc}
   
dash: @lang _
   push {r5,lr}	
   mov r0,#24
   bl LED_on
   mov r0,#0x100000
   bl wait
   mov r0,#24
   bl LED_off
   pop {r5,pc}

space: @kurze pause
   push {r5,lr}
   mov r0,#0x50000
   bl wait
   pop {r5,pc}
   
letterspace: @lange pause
   push {r5,lr}
   mov r0,#0x100000
   bl wait
   pop {r5,pc}
   
A:
   push {r5,lr}
   bl dot
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

B:
   push {r5,lr}
   bl dash
   bl space
   bl dot
   bl space
   bl dot
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

C:
   push {r5,lr}
   bl dash
   bl space
   bl dot
   bl space
   bl dash
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

D:
   push {r5,lr}
   bl dash
   bl space
   bl dot
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

E:
   push {r5,lr}
   bl dot
   bl letterspace
   pop {r5,pc}

F:
   push {r5,lr}
   bl dot
   bl space
   bl dot
   bl space
   bl dash
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

G:
   push {r5,lr}
   bl dash
   bl space
   bl dash
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

H:
   push {r5,lr}
   bl dot
   bl space
   bl dot
   bl space
   bl dot
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

I:
   push {r5,lr}
   bl dot
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

J:
   push {r5,lr}
   bl dot
   bl space
   bl dash
   bl space
   bl dash 
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

K:
   push {r5,lr}
   bl dash
   bl space
   bl dot
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

L:
   push {r5,lr}
   bl dot
   bl space
   bl dash
   bl space
   bl dot
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

M:
   push {r5,lr}
   bl dash
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

N:
   push {r5,lr}
   bl dash
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

O:
   push {r5,lr}
   bl dash
   bl space
   bl dash
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

P:
   push {r5,lr}
   bl dot
   bl space
   bl dash
   bl space
   bl dash
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

Q:
   push {r5,lr}
   bl dash
   bl space
   bl dash
   bl space
   bl dot
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

R:
   push {r5,lr}
   bl dot
   bl space
   bl dash
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

S:
   push {r5,lr}
   bl dot
   bl space
   bl dot
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

T:
   push {r5,lr}
   bl dash
   bl letterspace
   pop {r5,pc}

U:
   push {r5,lr}
   bl dot
   bl space
   bl dot
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

V:
   push {r5,lr}
   bl dot
   bl space
   bl dot
   bl space
   bl dot
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

W:
   push {r5,lr}
   bl dot
   bl space
   bl dash
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

X:
   push {r5,lr}
   bl dash
   bl space
   bl dot
   bl space
   bl dot
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

Y:
   push {r5,lr}
   bl dash
   bl space
   bl dot
   bl space
   bl dash
   bl space
   bl dash
   bl letterspace
   pop {r5,pc}

Z:
   push {r5,lr}
   bl dash
   bl space
   bl dash
   bl space
   bl dot
   bl space
   bl dot
   bl letterspace
   pop {r5,pc}

