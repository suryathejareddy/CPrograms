/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>

void count_vowels_and_consonants(char *str, int *consonants, int *vowels){
	*consonants = *vowels = 0;
	if (str == NULL)
		return;
	int i = 0;
	while (str[i] != '\0'){
		int t = str[i];
		if (t <= 90 && t >= 65){
			if (t == 65 || t == 69 || t == 73 || t == 79 || t == 85){
				*vowels = *vowels + 1;
			}
			else{
				*consonants = *consonants + 1;
			}
		}
		else if (t <= 122 && t >= 97){
			if (t == 97 || t == 101 || t == 111 || t == 105 || t == 117){
				*vowels = *vowels + 1;
			}
			else{
				*consonants = *consonants + 1;
			}
		}
		i++;
	}
	return;
}