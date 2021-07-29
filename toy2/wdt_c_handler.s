	.data

state:
	.byte 1
sec_count:
	.word 0
  
  	.text
jt:
	.word case_1
  	.word case_2
  	.word case_3
  	.word case_4
  
  	.global wdt_c_handler
  
wdt_c_handler:
	cmp #76, &secCount
        jnz updateSec
        mov #0, &secCount
        cmp #4, &state
  	jc default
  	mov &state, r12
  	add r12, r12
  	mov jt(r12), r0
  
case_1:
	call #move_up(3)
	jmp end

case_2:
	call #move_down(3)
	jmp end
  
case_3:
	call #move_left(3)
	jmp end
  
case_4:
	call #move_right(3)
	jmp end

end:
  	pop r0 ; return 
  
  
  	
updateSec:
  	add 1, &secCount
  
default:
  	mov #1, &state


	
