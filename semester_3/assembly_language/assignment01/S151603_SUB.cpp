bool SM_ADD_SUB(
        unsigned char A, unsigned char B,
        int ADD_SUB_FLAG,
        unsigned char *S
){
    unsigned char carry = 0x00;
    unsigned char borrow = 0x00;
    unsigned char mask = 0x00;

    unsigned char single_A_bit;
    unsigned char single_B_bit;
    unsigned char single_S_bit;

    unsigned char signed_A_bit = A & 0x80;
    unsigned char signed_B_bit = B & 0x80;
    unsigned char signed_S_bit;

    *S = 0x00;

    if( !ADD_SUB_FLAG )
    {
        // 2^0 bit
        mask = 0x01;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit;
        carry = single_A_bit & single_B_bit;
        *S ^= single_S_bit;

        // 2^1 bit
        mask = 0x02;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ carry;
        carry = (single_A_bit & single_B_bit) | (single_A_bit & carry) | (single_B_bit & carry);
        *S ^= single_S_bit;

        // 2^2 bit
        mask = 0x04;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ carry;
        carry = (single_A_bit & single_B_bit) | (single_A_bit & carry) | (single_B_bit & carry);
        *S ^= single_S_bit;

        // 2^3 bit
        mask = 0x08;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ carry;
        carry = (single_A_bit & single_B_bit) | (single_A_bit & carry) | (single_B_bit & carry);
        *S ^= single_S_bit;

        // 2^4 bit
        mask = 0x10;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ carry;
        carry = (single_A_bit & single_B_bit) | (single_A_bit & carry) | (single_B_bit & carry);
        *S ^= single_S_bit;

        // 2^5 bit
        mask = 0x20;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ carry;
        carry = (single_A_bit & single_B_bit) | (single_A_bit & carry) | (single_B_bit & carry);
        *S ^= single_S_bit;

        // 2^6 bit
        mask = 0x40;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ carry;
        carry = (single_A_bit & single_B_bit) | (single_A_bit & carry) | (single_B_bit & carry);
        *S ^= single_S_bit;

        if(carry) return false;
        return true;
    }
    else
    {
        // 2^0 bit
        mask = 0x01;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit;
        borrow = (~single_A_bit & single_B_bit) | (~single_A_bit & borrow) | (single_B_bit & borrow);
        *S ^= single_S_bit;

        // 2^1 bit
        mask = 0x02;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ borrow;
        borrow = (~single_A_bit & single_B_bit) | (~single_A_bit & borrow) | (single_B_bit & borrow);
        *S ^= single_S_bit;

        // 2^2 bit
        mask = 0x04;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ borrow;
        borrow = (~single_A_bit & single_B_bit) | (~single_A_bit & borrow) | (single_B_bit & borrow);
        *S ^= single_S_bit;

        // 2^3 bit
        mask = 0x08;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ borrow;
        borrow = (~single_A_bit & single_B_bit) | (~single_A_bit & borrow) | (single_B_bit & borrow);
        *S ^= single_S_bit;

        // 2^4 bit
        mask = 0x10;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ borrow;
        borrow = (~single_A_bit & single_B_bit) | (~single_A_bit & borrow) | (single_B_bit & borrow);
        *S ^= single_S_bit;

        // 2^5 bit
        mask = 0x20;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ borrow;
        borrow = (~single_A_bit & single_B_bit) | (~single_A_bit & borrow) | (single_B_bit & borrow);
        *S ^= single_S_bit;

        // 2^6 bit
        mask = 0x40;

        single_A_bit = A & mask;
        single_B_bit = B & mask;
        
        single_S_bit = single_A_bit ^ single_B_bit ^ borrow;
        borrow = (~single_A_bit & single_B_bit) | (~single_A_bit & borrow) | (single_B_bit & borrow);
        *S ^= single_S_bit;

        if(borrow) return false;
        return true;
    }
}
