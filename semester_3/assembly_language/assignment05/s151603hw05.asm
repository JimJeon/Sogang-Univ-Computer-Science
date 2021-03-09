TITLE 43-030 Assembly Programming HW #5 (s151603hw05.asm)

; This program generates N password of M length

INCLUDE Irvine32.inc

.DATA
filename	BYTE	"s151603hw05.txt", 0
n_prompt	BYTE	"Enter the number of passwords to create(<= 255) : ", 0
m_prompt	BYTE	"Enter the password size(<= 32) : ", 0
n_input		DWORD	?
m_input		DWORD	?
my_handle	DWORD	?
password	BYTE	35 DUP(?)

.CODE
main PROC
	; open file as write mode
	MOV		edx, OFFSET filename	; edx points filename
	call	CreateOutputFile		; open file as write mode with filename in edx
	MOV		my_handle, eax
	; print n_prompt to screen and read N from user
	MOV		edx, OFFSET n_prompt	; edx points start pointer of string
	call	WriteString				; print string in edx to screen
	call	ReadInt					; read one integer from user and stores it to eax
	MOV		n_input, eax
	; print m_prompt to screen and read M from user
	MOV		edx, OFFSET m_prompt	; edx points start pointer of string
	call	WriteString				; print string in edx to screen
	call	ReadInt					; read one integer from user and stores it to eax
	MOV		m_input, eax

	; LOOP instruction start (L1)
	; ecx is for loop counter
	MOV		ecx, n_input
L1:
	; preparing L2
	; pushes ecx to stack in order to keep loop counter data
	; and use ecx for loop counter of L2
	; esi has start pointer of password string
	PUSH	ecx
	MOV		ecx, m_input
	MOV		esi, OFFSET password
	; LOOP instruction start (L2)
L2:
		; generates random number (0-25)
		; and adds 'A' value (041h) to use as character
		MOV		eax, 26				; eax points n value for RandomRange
		call	RandomRange			; generates pseudo random number from 0 to n-1
		ADD		al, 041h
		; and move it to password string
		MOV		[esi], al
		INC		esi
		LOOP	L2
	; since we cannot move value to memory directly
	; register al has been used
	; carriage return (0Dh), line feed (0Ah), null character(0)
	; have been added to the end of string (password)
	MOV		al, 0Dh
	MOV		[esi], al
	INC		esi
	MOV		al, 0Ah
	MOV		[esi], al
	INC		esi
	MOV		al, 0
	MOV		[esi], al
	; write password to opened file
	MOV		edx, OFFSET password	; edx points buffer
	call	StrLength
	MOV		ecx, eax				; ecx points bytes to write
	MOV		eax, my_handle			; eax points file handle
	call	WriteToFile				; write (ecx) bytes in (edx) buffer to (eax) file handle

	POP		ecx						; ecx for loop counter of L1
	LOOP	L1

	MOV		eax, my_handle			; eax points file handle
	call	CloseFile				; closes file handle which eax has
	exit
main ENDP
END main