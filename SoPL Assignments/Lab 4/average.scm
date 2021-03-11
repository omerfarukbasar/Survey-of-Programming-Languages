; Author: Omer Basar
; Filename: average.scm
; Version: 12/3/20
; Lab: 4
;-----------------------------------------------

; additional notes
; car => 'value' of head
; cdr => 'list' of tail

;-----------------------------------------------
; the function for adding up all values in a list
; parameter: a given list of numbers
; return: the sum of all values in a list
(define
        (sum lst)
        ; checks if the list is empty
        (if (null? lst)
                ; performs this if the answer is true
                ; if list is length 0,
                ; return value 0
                0
                ; performs this if the answer is false
                ; return 'sum' of
                ;   1. head
                ;   2. sum of the tail
                (+
                        ; head : the value
                        (car lst)
                        ; sum of the tail : the rest of the list excluding the head
                        ; this is a recursive function call
                        (sum (cdr lst))
                )
        )
)

;-----------------------------------------------
; the function for finding the average of all values in a list
; parameter: a given list of numbers
; return: the average of all values in a list
(define
        (average lst)
        ; divide sum by length
        (/
                ; calls the sum function with the whole list as a parameter
                (sum lst)
                ; calls the length function with the whole list as a parameter
                (length lst)
        )
)

;-----------------------------------------------

; run the main function of the program
(average '(3 14 15 9 62 64 37))