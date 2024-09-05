 int getSum(int a, int b) {
        uint32_t carry = a & b;
        int sumWithoutCarry = a ^ b;

        int actualCarry = carry << 1;

        while(carry != 0){
            carry = sumWithoutCarry & actualCarry;
            sumWithoutCarry = sumWithoutCarry ^ actualCarry;
            actualCarry = carry << 1;
        }

        return sumWithoutCarry;
    }