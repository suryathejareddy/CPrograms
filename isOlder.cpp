/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isNotValid(char *dob);
int isOlder(char *dob1, char *dob2) {
	int i;
	if (isNotValid(dob1) != 0 || isNotValid(dob2) != 0)
		return -1;
	for (i = 6; i<10; i++){
		if (dob1[i]>dob2[i])
			return 2;
		if (dob1[i]<dob2[i])
			return 1;
	}
	for (i = 3; i<5; i++){
		if (dob1[i]>dob2[i])
			return 2;
		if (dob1[i]<dob2[i])
			return 1;
	}
	for (i = 0; i<2; i++){
		if (dob1[i]>dob2[i])
			return 2;
		if (dob1[i]<dob2[i])
			return 1;
	}
	return 0;
}
int isNotValid(char *dob){
	int i, t = 0;
	for (i = 6; i <= 9; i++){
		t = t * 10 + (dob[i] - '0');
	}
	if (t % 4 != 0){
		if (dob[0] == '2'&&dob[1] == '9'&&dob[3] == '0'&&dob[4] == '2'){
			return -1;
		}
	}
	if (dob[5] == '-'&&dob[2] == '-'){
		for (i = 0; i<10; i++){
			if (i != 2 && i != 5){
				if (dob[i] >= '0'&&dob[i] <= '9'){
					continue;
				}
				else
					return 1;
			}
		}
		if (dob[0] <= '3'){
			if (dob[0] == '3'&&dob[1]>'1'){
				return 1;
			}
			else{
				if (dob[3] == '1' || dob[3] == '0'){
					if (dob[3] == '1'&&dob[4]>'2'){
						return 1;
					}
					else
						return 0;
				}
				else
					return 1;
			}
		}
		else
			return 1;
	}
	else
		return 1;
}