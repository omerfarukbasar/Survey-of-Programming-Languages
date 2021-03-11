; Author: Omer Basar
; Filename: count.scm
; Version: 12/8/20
; Assignment: 6
;-----------------------------------------------

; additional notes
; car => 'value' of head
; cdr => 'list' of tail

;-----------------------------------------------
; the function for counting all values in a list
; parameter: a given list of numbers
; return: the total number of values in a list
(define
        (count-list lst)
        ; checks if the list is empty
        (if (null? lst)
                ; performs this if the answer is true,
                ; if list is length 0,
                ; return value 0
                0
                ; performs this if the answer is false,
                ; return sum of 1 and result from count-list
                ; function call using cdr
                (+ 1
                    	; pass the inputted list but excluding the head
                        ; this is a recursive function call
                        (count-list (cdr lst))
                )
        )
)
;-----------------------------------------------
; run the main function of the program
(count-list '(3 14 15 9 62 64 37))