/* Deklarationen von GPIO-Funktionen */
/* erstellt 17.10.2020 */

/* void LED_on (int r0)
   in r0 wird der Pin der LED übergeben
*/
LED_on:
   push {r5,lr}
   mov r5,r0 @sichere die Übergabe
   
/* Zunächst wird die Funktion zugewiesen */
   mov r1,#0b001
   bl SetGPIOFunction

/*Nun schalten wir die LED an.*/
   mov r0,r5         @hole unsere Nummer der LED wieder rein
   
   ldr r1,=GPSET0
   cmp r0,#31
   subhi r0,#32
   addhi r1,#4
   
   mov r2,#1
   lsl r2,r0

   str r2,[r1]
   pop {r5,pc}

/* void LED_off (int r0)
   in r0 wird der Pin der LED übergeben
*/
LED_off:
   push {r5,lr}
   mov r5,r0 @sichere die Übergabe
   
/* Zunächst wird die Funktion zugewiesen */
   mov r1,#0b001
   bl SetGPIOFunction
   
/*Nun schalten wir die LED aus.*/
   mov r0,r5         @hole unsere Nummer der LED wieder rein
   
   ldr r1,=GPCLR0
   cmp r0,#31
   subhi r0,#32
   addhi r1,#4
   
   mov r2,#1
   lsl r2,r0

   str r2,[r1]
   pop {r5,pc}

/* void SetGPIOFunction (int Pin(r0), int Function(r1))
*/

SetGPIOFunction:
   push {lr}
   ldr r2,=GPFSEL0
SetGPIOFunction_loop1:
   cmp r0,#9
   subhi r0,#10
   addhi r2,#4
   bhi SetGPIOFunction_loop1

   @In r0, steht nun der Rest drin
   @r2 beinhaltet das entsprechende Register

   add r0,r0,lsl #1  @entspricht einer multiplikation von 3

   lsl r1,r0         @Schiebe Code an Position
   
   @Erstellung einer Maske, für den alten Code.
   
   mov r3,#0b111     @Entspricht eine Funktion im Register
   lsl r3,r0         @Und schiebe es an die gleiche Stelle, wie zuvor
   mvn r3,r3         @invertiere den Wert
   
   ldr r4,[r2]       @Lade ursprünglichen Wert des Registers
   and r4,r3         @Lösche die benötigte Stelle
   
   orr r1,r4         @Kopiere neuen Wert hinein
   str r1,[r2]       @Und speichere sie ab.
    
   pop {pc}
   