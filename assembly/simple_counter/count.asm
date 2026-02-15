    ORG $8000           ; Start of code (somewhere in your 32K ROM)

START:
    CLRB                ; Clear Register B (B = 0)
    
LOOP:
    STB >$0000          ; Write the value of B to your LED Latch at $0000
    
    ; --- Delay Loop ---
    ; Without a delay, the LEDs will blink too fast to see.
    ; LDX #$FFFF          ; Load X register with 65535
    LDX #$0004          ; Load X register with 4
DELAY:
    LEAX -1,X           ; Decrement X
    BNE DELAY           ; If X is not zero, keep looping
    ; ------------------

    INCB                ; Increment Register B (B = B + 1)
    BRA LOOP            ; Branch back to the start of the loop

    ; --- Fill/Pad ROM ---
    ; FILL $FF,$FFFE-*   ; Fill memory with FF up to $FFFE

    ; --- Reset Vector ---
    ; The 6809 looks at $FFFE-$FFFF to find the start address after a reset.
    ORG $FFFE
    FDB START           ; Form Double Byte: Stores the address of START
