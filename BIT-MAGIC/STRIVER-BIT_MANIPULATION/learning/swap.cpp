swap using bit manipulation

a = a ^ b
b = a ^ b  // now b is original a
a = a ^ b  // now a is original b