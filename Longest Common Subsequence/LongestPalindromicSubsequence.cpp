//In this problem i/p only one string and o/p is int so its match LCS pattern.
//As usual Palindrome means String which is same as reversed string.
//But they didn't given second string ....Now we are using palindrome def
//Now our second string will be reversed of given string.Then we can apply LCS pattern

// s1="absgba"; given
// s2="abgsba"; by palindrom def (reversed of i/p string)
// LCS- "abgba".. This is longest palindrome.

//code will be same as LCS.


//very simple code.
// -----------------------------------------------------------------------

// Que. Minimum Deletion to make string palindromic

// This que is same as "minInsertionDeletion" code but in that we are doing only
// minimum deletion. So for that we need LCS we can get it from above Que. 
// then from original string size we are reducing that LCS size. 

//----------------------------------------------------------------
//LeetCode Hard.

//1312. Minimum Insertion Steps to Make a String Palindrome

//same approach as above instead of deletion we are doing insertion.