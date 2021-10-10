#include <stdio.h>
/******************
* Function Name:isPalindromeHelper (task 1)
* Input:char str[],int start,int end
* Output:0 or 1 (true or false)
* Function Operation:the function check if a ward is palindrom
******************/
int isPalindromeHelper(char str[], int start, int end) {
	//check if 1 or 0 letter is left to check return true
	if ((start == end) ||
		(end - start == 1)) {
		return 1;
	}
	//if the char is similar send to recurtion
	else if (str[start] == str[end]) {
		isPalindromeHelper(str, start + 1, end - 1);
	}
	//not same char exit and return false
	else {
		return 0;
	}
}
/******************
* Function Name:isPalindrome(task 1)
* Input:char str[],int len
* Output:no output only print
* Function Operation:print an option depens on value recived from isPalindromehelper
******************/
void isPalindrome(char str[], int len) {
	//check if helper function is true or the array is 0
	if ((isPalindromeHelper(str, 0, len - 1) == 1) ||
		(len == 0)) {
		printf("The reverse of %s is also %s.\n", str, str);
	}
	//the helper function is false
	else {
		printf("The reverse of %s is not %s.\n", str, str);
	}
}
/******************
* Function Name:printAllCombinationsHelper (task 2)
* Input:char pattern[], int startNum,int endNum
* Output:no outpot only print
* Function Operation:print all combination of string with wild chars
* ******************/
int counter = 0;
void printAllCombinationsHelper(char pattern[], int startNum, int endNum) {
	if (startNum <= endNum) {
		if (pattern[startNum] == '?') {
			pattern[startNum] = '0';
			printAllCombinationsHelper(pattern, startNum + 1, endNum);
			pattern[startNum] = '1';
			printAllCombinationsHelper(pattern, startNum + 1, endNum);
			pattern[startNum] = '2';
			printAllCombinationsHelper(pattern, startNum + 1, endNum);
			pattern[startNum] = '?';
		}
		else {
			printAllCombinationsHelper(pattern, startNum + 1, endNum);
		}
	}
	else {
		printf("%s\n", pattern);
		counter++;
	}
}
/******************
* Function Name:printAllCombinations (task 2)
* Input:char pattern[], int len
* Output:no outpot only print
* Function Operation:print all combination of string with wild chars and counter
* ******************/
void printAllCombinations(char pattern[], int len) {
	printAllCombinationsHelper(pattern, 0, len);
	printf("Number of combinations is: %d\n", counter);
}
/******************
* Function Name:powRecHelper (task 3)
* Input:float firsrtNum, int secondNum, float resultNum
* Output:no outpot only print
* Function Operation:power of first num in second num.
******************/
void powRecHelper(float firsrtNum, int secondNum, float resultNum) {
	//check if the first num is 0 if so dont loop i know the answer
	if (firsrtNum == 0) {
		//if second num is lower then 0 its nan
		if (secondNum < 0) {
			printf("The result is nan.\n");
		}
		//if second num bigger then 0 its 0
		if (secondNum > 0) {
			printf("The result is 0.\n");
		}
	}
	//check if the second num is positive
	else if (secondNum > 0) {
		//do the multipication
		resultNum = (firsrtNum * resultNum);
		//send for recurtion
		powRecHelper(firsrtNum, secondNum - 1, resultNum);
	}
	//check if the second num is negetive
	else if (secondNum < 0) {
		//do the multipication
		resultNum = (1 / firsrtNum) * resultNum;
		//send for recurtion
		powRecHelper(firsrtNum, secondNum + 1, resultNum);
	}
	//check if the second num is 0 if so dont loop i know the answer
	if (secondNum == 0) {
		printf("The result is %f.\n", resultNum);
	}
}
/******************
* Function Name:powRec (task 3)
* Input:float firsrtNum, int secondNum
* Output:no outpot only print
* Function Operation:send arguments to a new function
******************/
void powRec(long int firsrtNum, long int secondNum) {
	powRecHelper(firsrtNum, secondNum, 1);
}
/******************
* Function Name:isDivisibleBy3Helper (task 4)
* Input:long long num,int leftOver
* Output:true or false if the num is divided by 3
* Function Operation:check if num is divided by 3
******************/
int isDivisibleBy3Helper(long long num, int leftOver) {
	if ((num % 10 == 1) &&
		(leftOver == 0)) {
		num = num / 10;
		leftOver = 1;
		isDivisibleBy3Helper(num, leftOver);
	}
	else if ((num % 10 == 1) &&
		(leftOver == 1)) {
		num = num / 10;
		leftOver = 2;
		isDivisibleBy3Helper(num, leftOver);
	}
	else if ((num % 10 == 1) &&
		(leftOver == 2)) {
		num = num / 10;
		leftOver = 0;
		isDivisibleBy3Helper(num, leftOver);
	}
	else if ((num % 10 == 2) &&
		(leftOver == 0)) {
		num = num / 10;
		leftOver = 2;
		isDivisibleBy3Helper(num, leftOver);
	}
	else if ((num % 10 == 2) &&
		(leftOver == 1)) {
		num = num / 10;
		leftOver = 0;
		isDivisibleBy3Helper(num, leftOver);
	}
	else if ((num % 10 == 2) &&
		(leftOver == 2)) {
		num = num / 10;
		leftOver = 1;
		isDivisibleBy3Helper(num, leftOver);
	}
	else if (num % 10 == 3) {
		num = num / 10;
		isDivisibleBy3Helper(num, leftOver);
	}
	if ((num == 0) &&
		(leftOver == 0)) {
		return 0;
	}
	if ((num == 0) &&
		(leftOver != 0)) {
		return 1;
	}
}
/******************
* Function Name:isDivisibleBy3 (task 4)
* Input:long long num
* Output:no outpot only print
* Function Operation:check if num is divided by 3
******************/
void isDivisibleBy3(long long num) {
	if (isDivisibleBy3Helper(num, 0) == 0) {
		printf("the number %lld is divisible by 3.\n", num);
	}
	else
	{
		printf("the number %lld is not divisible by 3.\n", num);
	}
}
/******************
* Function Name:gcdHelper (task5)
* Input:long int n1, long int n2
* Output:no outpot only print
* Function Operation:what the gcd of 2 numbers
******************/
void gcdHelper(long int n1, long int n2) {
	if (n2 != 0) {
		//print what needed
		printf("%ld*%ld+%ld=%ld(a=%ld, b=%ld)\n", n2, n1 / n2, n1 % n2, n1, n1, n2);
		//send to new recurtion
		gcdHelper(n2, n1 % n2);
	}
	//recurtion is over print the outcome
	else {
		if (n1 < 0) {
			//if gcd is - make it +
			n1 = -n1;
		}
		printf("GCD=%d\n", n1);
	}
}
/******************
* Function Name:gcd (task5)
* Input:long int n1, long int n2
* Output:no outpot only print
* Function Operation:check all the cases of 2 numbers and send to correct gcd format
******************/
void gcd(long int n1, long int n2) {
	//if n1 is zero i know gcd
	if (n1 == 0) {
		if (n2 > 0) {
			printf("GCD=%ld\n", n2);
		}
		if (n2 < 0) {
			printf("GCD=%ld\n", -n2);
		}
	}
	else {
		//send to recurtion to find gcd
		gcdHelper(n1, n2);
	}
}
/******************
* Function Name:countDigitHelper (task 6)
* Input:long long long n, int d, int count
* Output:a number(0-inf)
* Function Operation:count how many time x is inside y
******************/
int countDigitHelper(long long n, int d, int count) {
	//if n is zero stop the loop
	if (n == 0) {
		//if d is zero add 1 to count
		if (d == 0) {
			return 1;
		}
		//return the result num
		return count;
	}
	else {
		//check if the most right digit is the same as d
		if (n % 10 == d) {
			//if so remove the digit
			n = n / 10;
			//continue recurtion and add count
			countDigitHelper(n, d, count + 1);
		}
		//if the most right digit is not the same as d
		else {
			//if so remove the digit
			n = n / 10;
			//continue recurtion
			countDigitHelper(n, d, count);
		}
	}
}
/******************
* Function Name:countDigit (task 6)
* Input:long long n, int d
* Output:no outpot only print
* Function Operation:count how many time x is inside y then prints.
******************/
void countDigit(long long n, int d) {
	//print the answer and call the recurtion
	printf("%lld has %d times %d.\n", n, countDigitHelper(n, d, 0), d);
}
/******************
* Function Name:isPalindromeIter (task 7-1)
* Input:char str[], int len
* Output:0 or 1 (false or true)
* Function Operation:check if an array is palindrom
******************/
int isPalindromeIterHelper(char str[], int len) {
	//looping on array
	for (int i = 0; i < len; i++) {
		//check if the char is the same if so continue looping
		if (str[i] == str[(len - i) - 1]) {
			continue;
		}
		//not the same exit send false
		else {
			return 0;
		}
	}
	//send true
	return 1;
}
/******************
* Function Name:isPalindromeIter (task 7-1)
* Input:char str[], int len
* Output:no outpot only print
* Function Operation:if helper function is true print true else print false
******************/
void isPalindromeIter(char str[], int len) {
	//check true or false
	if (isPalindromeIterHelper(str, len) == 0) {
		//its false print false
		printf("The reverse of %s is not %s.\n", str, str);
	}
	else {
		//its true print true
		printf("The reverse of %s is also %s.\n", str, str);
	}
}
/******************
* Function Name:isPalindromeIter (task 7-4)
* Input:long long num long long sum
* Output:sum of all digits
* Function Operation:sum all digits
******************/
int IsDividedBy3IterHelper(long long num, long long sum) {
	while (num > 0) {
		sum = sum + num % 10;
		num = num / 10;
	}
	return sum;
}
/******************
* Function Name:isPalindromeIter (task 7-4)
* Input:long long num
* Output:no outpot only print
* Function Operation:check if num is divided by 3
******************/
void IsDividedBy3Iter(long long num) {
	//a constant is needed or num will change and i cant print it
	int sumofdigit = IsDividedBy3IterHelper(num, 0);
	//loop while the sum is bigger then 9
	while (sumofdigit >= 10) {
		//make a sum of all the digit in the long int
		sumofdigit = IsDividedBy3IterHelper(sumofdigit, 0);
	}
	// if the single digit is 9 6 or 3 it is divided
	if (sumofdigit == 9 || sumofdigit == 6 || sumofdigit == 3) {
		printf("%lld is divisible by 3.\n", num);
	}
	//if the single didigt isnt 9 6 or 3 it is not divided
	else {
		printf("%lld is not divisible by 3.\n", num);
	}
}

