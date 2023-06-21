/* time.h */

/* void wait (int r0)
   in r0 werden die Millisekunden angegeben
*/

wait:
   push {lr}
   
   mov r2,r0            @sichere den Vergleich

	bl GetTimeStamp      @hole den aktuellen Zeitzähler
	mov r3,r0            @und speichere ihn in r3

	wait_loop$:
      bl GetTimeStamp   @hole den aktuellen Zeitzähler
		sub r1,r0,r3      @Subtrahiere von r0 den gespeicherten Wert und schreibe es in r1
		cmp r1,r2         @Vergleiche den Unterschied mit der Übergabe
		bls wait_loop$    @Wenn Kleiner oder gleich, weiter warten

	pop {pc}             @Wait beenden

/* int GetTimeStamp (void)
*/
GetTimeStamp:
	push {lr}

	ldr r0,=TIMER_CLO    @Adresse vom unteren System Timer Counter
	ldr r0,[r0]          @Hole den aktuellen Wert

	pop {pc}
