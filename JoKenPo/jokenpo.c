#include <stdio.h>

int main(){
    int user1, user2;

    // Prompt user 1 to select an option (0 - Rock, 1 - Paper, 2 - Scissors)
    printf("Hello user 01, Select an option \n 0 - Rock \n 1 - Paper \n 2 - Scissors\n");
    scanf("%d", &user1);  // Read user 1's choice

    // Prompt user 2 to select an option (0 - Rock, 1 - Paper, 2 - Scissors)
    printf("Hello user 02, Select an option \n 0 - Rock \n 1 - Paper \n 2 - Scissors\n");
    scanf("%d", &user2);  // Read user 2's choice

    // Check if both users selected the same option
    if(user1 == user2){
        printf("It's a tie!");
    }
    // Check all possible cases where user 1 wins
    else if(user1 == 0 && user2 == 2){
        printf("User 01 wins");
    } else if(user1 == 1 && user2 == 0){
        printf("User 01 wins");
    } else if(user1 == 2 && user2 == 1){
        printf("User 01 wins");
    }
    // If no tie or user 1 win cases match, user 2 wins
    else {
        printf("User 02 wins!");
    }

    return 0;
}
