    ORG    $1000
START:                  ; first instruction of program

            lea     array,A1    ;address of first element of array in A1
            move.l  A1,-(sp)    ;push that address onto stack
            move.w  size,-(sp)  ;push size of array onto stack

            jsr     MEAN_SUB    ;call mean subroutine
            jsr     VAR_SUB     ;call variance subroutine
            
            move    12(sp),D0   ;move variance to D0
            
            move    #248,D7     
            trap    #14         ;display D0 (variance) and stop execution

MEAN_SUB    move    4(sp),D0    ;retrieve size and put it in D0
            move    D0,D1       ;copy it to D1
            sub     #1,D1       ;subtract 1 from D1
            movea   8(sp),A2    ;move address of array into A2
            clr     D2          ;D2 is our answer holder
loop1       add     (A2)+,D2    ;sum up the array
            dbra    D1,loop1    ;loop size-1 times
            divu    D0,D2       ;divide by size to get mean
            move.w  D2,12(sp)   ;store mean into stack
            rts
            
VAR_SUB     move    12(sp),D6   ;retrive mean from stack and put in D6
            move    D6,D5       ;copy to D5
            move    4(sp),D0    ;retrieve size and put it in D0
            move    D0,D1       ;copy to D1
            sub     #1,D1       ;subtract 1 from D1
            movea   8(sp),A2    ;move address of array into A2
            clr     D4          ;D4 is our answer holder
loop2       move    D6,D5       ;copy mean to D5
            sub     (A2)+,D5    ;subtract each element of array from mean
            muls    D5,D5       ;square the difference
            add     D5,D4       ;sum all the squares
            dbra    D1,loop2    ;loop size-1 number of times
            divu    D0,D4       ;divide by size to get variance
            move.w  D4,16(sp)   ;store variance onto stack
            rts

size    dc.w    12              ;sample array composed of 1 to 12
array   dc.w    1,2,3,4,5,6,7,8,9,10,11,12
    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
