#include <stdio.h>
#include <stdbool.h> 

char floors[9] = {'C', 'B', 'A', 'G', '1', '2', '3', '4', '5'};
int array_length = 9;

void action_lift();
int find_index();

int main(){
    char* p_elevator_position = &floors[0];
    char user_floor;
    char wants_to_exit;

    // PRINT BUILDING VISUAL
        printf("\n-----\n");
    for (int i = array_length-1; i > -1; i--){
        printf("     \n");
        // FINDS AND PRINTS THE LIFT ON THE CORRECT FLOOR
        if (*p_elevator_position == floors[i]){
        printf(" [ ] \n");
        }else{
        printf("  %c  \n", floors[i]);
        }
    }
        printf("-----");



    while (true){
        printf("\n Where would you like to go to? ");
        scanf(" %c", &user_floor);
        char* p_user_desired_floor = &user_floor;


        // IF THE FLOOR DOESN'T EXIST ASK THE USER TO INPUT ANOTHER FLOOR
        int element_exists = 1;
        for (int i = 0; i < array_length; i++){
        if (*p_user_desired_floor == floors[i]){
            element_exists = 0;
        }
    }
        if (element_exists){
            printf("\nfloor doesnt exist");
            continue;
        }

        action_lift(p_elevator_position, p_user_desired_floor, floors, 9);
        printf("\n do you want to exit the lift? (y or n): ");
        scanf(" %c", &wants_to_exit);
        if (wants_to_exit == 'Y' || wants_to_exit == 'y'){
            break;
        }else if (wants_to_exit == 'N' || wants_to_exit == 'n'){
            continue;
        }
        
        fflush(stdin);
    }

    return 0;
}


void action_lift(char* p_elevator_position, char* p_floor_to_move_to, char array[], int array_length){
    int elevator_index = find_index(p_elevator_position, array, array_length);
    int floor_to_move_to_index = find_index(p_floor_to_move_to, array, array_length);

    while (!(floor_to_move_to_index == elevator_index)){
        elevator_index = find_index(p_elevator_position, array, array_length);
        if (floor_to_move_to_index > elevator_index){
            p_elevator_position = &array[elevator_index+1];
        }else if (floor_to_move_to_index < elevator_index){
            p_elevator_position = &array[elevator_index-1];
        }
    }
    
        printf("\n-----\n");
    for (int i = array_length-1; i > -1; i--){
        printf("     \n");
        //finds and prints the lift on the correct floor
        if (*p_elevator_position == array[i]){
            printf(" [ ] \n");
        }else{
            printf("  %c  \n", array[i]);
        }
    }
        printf("-----");
}

int find_index(char* element_to_find, char array[9], int array_length){
    int element_index;
    for (int i = 0; i < array_length; i++){
        char element_of_array = array[i];
        if (*element_to_find == element_of_array){ 
            element_index = i;
        }
    }
    return element_index;
}