28. Find the Index of the First Occurrence in a String

in case of string matching KMP and ROBIN KARP algorithm or trie  should come in our mind 

we will cvonvert hashcode of needle and haystack and then we will compare the hashcode of needle with the hashcode of haystack

drawback is if the hashcode matches then we have to check the string again to avoid false positive
bcoz for the same hashcode there may be different strings => spurious hit

example  of same hashcode is "abc" and "acb" both have same hashcode


Input: haystack = "sadbutsad", needle = "sad"