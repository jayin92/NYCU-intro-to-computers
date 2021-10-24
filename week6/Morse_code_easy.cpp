#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// This is the provided raw morse code table. 
// '*' indicates a short signal  and '-' indicates a long signal.
const char table[26][5] = {
    "*-", //A
    "-***", //B
    "-*-*", //C
    "-**", //D
    "*", //E
    "**-*", //F
    "--*", //G
    "****", //H
    "**", //I
    "*---", //J
    "-*-", //K
    "*-**", //L
    "--", //M
    "-*", //N
    "---", //O
    "*--*", //P
    "--*-", //Q
    "*-*", //R
    "***", //S
    "-", //T
    "**-", //U
    "***-", //V
    "*--", //W
    "-**-", //X
    "-*--", //Y
    "--**" //Z
};


int main(void) {
	
	// Declare your morse code table and initialize it.
	// Hint: You might need one more row than "table" to store "space".
	int i, j;
	char map[27][30];
	
	for (i = 0; i < 27; i++) {
		for (j = 0; j < 30; j++) {
			map[i][j] = '\0';
		}
	}
    
    
    // Declare your file pointer for input and output files and fopen it.
    // YOUR CODE HERE!

	/*
	 * Build your morse code table here. 
	 * For every original morse code indicating a letter, you do the conversion.
	 * For every char in a original morse code, 
	 * 1) if the char is '*', you transform to "=." where '.' indicates pause for signals
	 * 2) if the char is '-', you transform to "===." where '.' indicates pause for signals
	 * Finally, do not forget to store "space" as we have declared one more row in map for it.
	 * Hint: You might want to use strcat(), but do not forget to append '\0' to the end of every converted morse code.
	 *       Also, the signal pause for the last signal is not needed since there is no signals after that.
 	 *       How to get rid of it?
	 */
    for(i = 0 ; i < 26 ; i++){  
        int len = (int)strlen(table[i]);
        for(j = 0; j < len ; j++){   
            // YOUR CODE HERE!
        }
		// YOUR CODE HERE!
    }
    // YOUR CODE HERE!

    
    /*
     * Read the input file sentence by sentence until end of file. We process one line and output one line.
     * Hint: For each line, there is '\n' and then '\0' in the end. However, we do not process '\n'.
     * How to move '\0' to get rid of it?
     * 
	 * First, we parse the input signal sentence, that is, we cut the input signals to parts. 
     * Each part can be converted into one english letter by the mapping we has built.
     * Hence you might need a 2d array with row indicating how many parts you cut and column
     * indicating the length of each part.
     *
     * Now you can start parsing the input signal sentence. Consider two case when you need to cut:
     * 1) "..."   2) "......."
     * However, you never know you are reading one dot in a three dots sequence or not until you have read three (or seven) dots. 
     * You can first append the input character to your 2d array (column index++) no matter the dots, and count the cumulated number of dots
     * at the same time. (if this character is '.', you add one to the cumulated number of dots. If not, reset to 0)
     *
     * Later if you find that the cumulated number of dots is:
     * 1) 3: you know it is a pause between english letters. Remember to delete those three dots
     *    Hint: you can do deletion by placing '\0' at just right place
     * 2) 7: you know it is a pause between english words. Remember to delete those seven dots and add " " 
	 *    Hint: you can do it by replacing whole string with " " (space)
	 * Finally, you then move to finding next part of input signals (row index++)
     */
    char input[1005];
	while(/* YOUR CODE HERE! */){
    	char tmp[400][60];
		for (i = 0; i < 400; i++) {
			for (j = 0; j < 60; j++) {
				tmp[i][j] = '\0';
			}
		}
		input[strlen(input)] = '\0';
		int last = 0;  // how many parts we have processed
		int dot = 0;  // how many accumulated dots 
		
	    for(i=0; input[i]; i++ ) {  
	        char c = input[i];
	        // YOUR CODE HERE!
	        
	    }
	   /*
	    * Now we have the parsed input (to 2d array) and the mapping table, just do mapping!
	    * For each part in the one input string, we check correspondance to your code table
	    * If it is a match, write out to file.
	    * Hint: We discard '\n' at first. Do not forget to place back.
	    */
		
	    // YOUR CODE HERE!
	}
    
    return 0;
}
