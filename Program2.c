/*
 * Program2.c
 *
 *  Created on: Feb 19, 2023
 *      Author: Cycle
 */

#include <stdio.h>

int main()
{
   
    int input_score;
    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf("%d", &input_score);

   if (input_score >= 2) {
        int td_2pt = 0;
        while ( td_2pt <= 2 + (input_score/8) ) {
            int td_fg = 0;
            while ( td_fg <= 2 + (input_score/7) ) {
                int tdscore = 0;
                while ( tdscore <= 2 + (input_score/6) ) {
                    int fgscore = 0;
                    while ( fgscore <= 2 + (input_score/3) ) {
                        int safety = 0;
                        while ( safety <= 2 + (input_score/2) ) {
                            if ( (td_2pt * 8) + (td_fg * 7) + (tdscore * 6) + (fgscore * 3) + (safety * 2 ) == input_score ) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                td_2pt, td_fg, tdscore, fgscore, safety);
                            }
                            safety++;
                        }
                        fgscore++;
                    }
                    tdscore++;
                }
                td_fg++;
            }
            td_2pt++;
        }
    }
    else{
        printf("program end.");
    }
    return 0;
}

