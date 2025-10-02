Introduction to Bit Manipulation [Theory]

decimal to binary conversion :: 

time - o ( log n )
space - o ( 1 )

string decimal_to_binary(int n) { 
    string binary = "";
    while (n != 1) {
        if(n % 2 == 1) {
            binary += "1" ;
        } else {
            binary += "0" ;
        }
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

binary number conversion :: 
time - o ( log n )
space - o ( 1 )

int binary_to_decimal(string binary) {
    int decimal = 0;
    int base = 1; // 2^0
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Move to the next power of 2
    }
    return decimal;
}

AND OR NOT XOR 

RIGHT SHIFT OPERATION  [ >> ] :: 

[x >> k]  => [x / (2 ^ k)]
[x >> 1]  => [x / 2]

LEFT SHIFT OPERATION  [ << ] ::

[x << k]  => [x * (2 ^ k)]
[x << 1]  => [x * 2]

[XOR OPERATOR] ::

even no of 1's => 0
odd no of 1's => 1