#include <stdio.h>

void getPlays(int score, int tds, int extra1, int extra2, int fg, int safety, int duplicates[10][10][10][10][10]){
    /* Recursively find all possible scoring combinations that can result in a given score, ignoring duplicates */

    if (duplicates[tds][extra1][extra2][fg][safety]){ //Check for duplicates, if it's a duplicate then move on
        return;
    }
    duplicates[tds][extra1][extra2][fg][safety] = 1; //If it's unique, add it to list of already reached circumstances

    if (score == 0){ //If the total score has been reached, then print out the combination
        printf("Touchdowns (Td): %d, Td with extra point: %d, Td with 2 point conversion: %d, Field Goals: %d, Safeties: %d\n", tds, extra1, extra2, fg, safety);
        return;
    }
    
    // Recursive calls to find possible scoring combos
    if (score >= 8){ //td with 2 point conversion
        getPlays(score-8, tds, extra1, extra2+1, fg, safety, duplicates);
    }
    if (score >= 7){ //td with extra point
        getPlays(score-7, tds, extra1+1, extra2, fg, safety, duplicates);
    }
    if (score >= 6){ //td no extra points
        getPlays(score-6, tds+1, extra1, extra2, fg, safety, duplicates);
    }
    if (score >= 3){ //field goal
        getPlays(score-3, tds, extra1, extra2, fg+1, safety, duplicates);
    }
    if (score >= 2){ //safety
        getPlays(score-2, tds, extra1, extra2, fg, safety+1, duplicates);
    }
}


int main(){
    int score; //Score to be entered
    int duplicates[10][10][10][10][10] = {0}; //Duplicate array originally all 0s (ie, no combos yet)

    printf("Enter score: "); //Get a score
    scanf("%d", &score);

    if (score == 1 || score < 0){ //Check if score is possible
        printf("Impossible score\n");
        return 0;
    }

    //Find all play combos. Initialized to 0s since no plays to start with
    getPlays(score, 0,0,0,0,0, duplicates);
    return 0;
}