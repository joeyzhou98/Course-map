    ORG    $1000
START:                  ; first instruction of program

MUL_MAC macro           ;summary: add N2, N1 number of times and put result in third parameter
        move    #\1,D1  ;move N1 into D1
        move    #\2,D2  ;move N2 into D2
        clr     D3      ;D3 is our answer holder
while   cmp     #0,D1   ;as long as D1 != 0 or loop N1 number of times
        beq     done    ;if D1 = 0, branch to done
        add     D2,D3   ;add N2 to our answer (D3)
        sub     #1,D1   ;decrement D1
        bra     while   ;branch to while
done    move    D3,\3   ;move answer to third parameter
        endm
        
        MUL_MAC 10,6,D0 ;test 5*6 and move answer to D4
        
        move #248,D7   
        trap #14        ;display D0 (prod) and stop execution
        
    END    START        ; last line of source


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
