    ORG     $1000
START:                  ; first instruction of program
    LEA     a,A0        ;A0 = Address(a[0])
    MOVE    #5,(A0)+    ;a[0] = 5 
    MOVE    #4,(A0)+    ;a[1] = 4
    MOVE    #3,(A0)+    ;a[2] = 3
    MOVE    #2,(A0)+    ;a[3] = 2
    MOVE    #1,(A0)+    ;a[4] = 1
    LEA     a,A0        ;A0 = address of a[0]
    MOVEA   A0,A1
    ADDA    #2,A1       ;A1 = address of A0 + 2
    MOVE    #4,D0
    MOVE    #1,D1
    SUB     D1,D0
    MOVE    D0,n        ;n := 4-1 = D0
    MOVE    #0,fg       ;flag = false
W   CMP     #0,n        ;while n >= 0
    BLT     PR          ;else go to print
    CMP     #0,fg       ;while flag == false
    BNE     PR          ;else go to print
    MOVE    #1,fg       ;flag = true
    LEA     a,A0        ;A0 = address of a[0]
    MOVEA   A0,A1
    ADDA    #2,A1       ;A1 = address of A0 + 2
FOR CMPM    (A0)+,(A1)+
    BGE     EF          ;if (a[i+1] >= a[i], skip swapping
    MOVE    -2(A0),temp ;temp = a[i]
    MOVE    (A0),-2(A0) ;a[i] = a[i+1]
    MOVE    temp,(A0)   ;a[i+1] = temp
    MOVE    #0,fg       ;flag = false
EF  DBRA    D0,FOR      ;loops n+1 times since D0 = n
    MOVE    n,D0
    SUB     #1,D0
    MOVE    D0,n        ;n = n - 1
    BRA     W
PR  LEA     a,A0        ;A0 = address of a[0]
    MOVE    #3,D1
FO  MOVE    (A0)+,D0    ;print out all a[0] to a[4]
    MOVE    #248,D7
    TRAP    #14
    DBRA    D1,FO       ;branch to FO 3 times
    MOVE    #228,D7
    TRAP    #14         ;end

a   ds      5
i   ds      1
n   ds      1
fg  ds      1
temp    ds  1
    END     START        ; last line of source
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
