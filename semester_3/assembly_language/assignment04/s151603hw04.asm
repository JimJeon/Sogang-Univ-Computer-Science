TITLE 43-030 Assembly Programming HW #4 (s151603hw04.asm)

; This program adds and subtracts 32-bit integers.

INCLUDE Irvine32.inc

.data
INCLUDE PHW04.inc

.code
main PROC
	; Eval1 = 21 * Val1 - 33 * (Val1 - Val4) - 16 * (Val3 - Val2)
	; Eval1 = -12 * Val1 + 16 * Val2 - 16 * Val3 + 33 * Val4
	mov eax, 0
	mov ecx, 0
	add ecx, Val1 ; ecx := Val1
	add ecx, Val1 ; ecx := Val1 + Val1
	add ecx, Val1 ; ecx := Val1 + Val1 + Val1
	neg ecx		  ; ecx := (-3) * Val1
	add eax, ecx  ; eax := (-3) * Val1
	mov ecx, 0
	add ecx, Val2 ; ecx := Val2
	add ecx, ecx  ; ecx := Val2 * 2
	add ecx, ecx  ; ecx := Val2 * 2 * 2
	add eax, ecx  ; eax := (-3) * Val1 + 4 * Val2
	mov ecx, 0
	add ecx, Val3 ; ecx := Val3
	add ecx, ecx  ; ecx := Val3 * 2
	add ecx, ecx  ; ecx := Val3 * 2 * 2
	neg ecx		  ; ecx := (-4) * Val3
	add eax, ecx  ; eax := (-3) * Val1 + 4 * Val2 + (-4) * Val3
	mov ecx, 0
	add ecx, Val4 ; ecx := Val4
	add ecx, ecx  ; ecx := Val4 * 2
	add ecx, ecx  ; ecx := Val4 * 2 * 2
	add ecx, ecx  ; ecx := Val4 * 2 * 2 * 2
	add eax, ecx  ; eax := (-3) * Val1 + 4 * Val2 + (-4) * Val3 + 8 * Val4

	add eax, eax  ; eax := (-6) * Val1 + 8 * Val2 + (-8) * Val3 + 16 * Val4
	add eax, eax  ; eax := (-12) * Val1 + 16 * Val2 + (-16) * Val3 + 32 * Val4
	add eax, Val4 ; eax := (-12) * Val1 + 16 * Val2 + (-16) * Val3 + 33 * Val4

	; Eval2 = 15 * Val1 + 32 * (Val1 - Val4) + 12 * (Val3 - Val2)
	; Eval2 = 47 * Val1 - 12 * Val2 + 12 * Val3 - 32 * Val4
	mov ebx, 0
	mov ecx, 0
	add ecx, Val1 ; ecx := Val1
	add ecx, Val1 ; ecx := Val1 + Val1
	add ecx, Val1 ; ecx := Val1 + Val1 + Val1
	add ecx, ecx  ; ecx := Val1 * 3 * 2
	add ecx, ecx  ; ecx := Val1 * 3 * 2 * 2
	add ebx, ecx  ; ebx := 12 * Val1
	mov ecx, 0
	add ecx, Val2 ; ecx := Val2
	add ecx, Val2 ; ecx := Val2 + Val2
	add ecx, Val2 ; ecx := Val2 + Val2 + Val2
	neg ecx		  ; ecx := (-3) * Val2
	add ebx, ecx  ; ebx := 12 * Val1 + (-3) * Val2
	mov ecx, 0
	add ecx, Val3 ; ecx := Val3
	add ecx, Val3 ; ecx := Val3 + Val3
	add ecx, Val3 ; ecx := Val3 + Val3 + Val3
	add ebx, ecx  ; ebx := 12 * Val1 + (-3) * Val2 + 3 * Val3
	mov ecx, 0
	add ecx, Val4 ; ecx := Val4
	add ecx, ecx  ; ecx := Val4 * 2
	add ecx, ecx  ; ecx := Val4 * 2 * 2
	add ecx, ecx  ; ecx := Val4 * 2 * 2 * 2
	neg ecx		  ; ecx := (-8) * Val4
	add ebx, ecx  ; ebx := 12 * Val1 + (-3) * Val2 + 3 * Val3 + (-8) * Val4
	add ebx, ebx  ; ebx := 24 * Val1 + (-6) * Val2 + 6 * Val3 + (-16) * Val4
	add ebx, ebx  ; ebx := 48 * Val1 + (-12) * Val2 + 12 * Val3 + (-32) * Val4
	sub ebx, Val1 ; ebx := 47 * Val1 + (-12) * Val2 + 12 * Val3 + (-32) * Val4

	call DumpRegs
	exit
main ENDP
END main