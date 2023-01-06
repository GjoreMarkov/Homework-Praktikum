
#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>



#define MAX_MISTAKES 6



const char *words[] = { "apple", "banana", "pear", "grape", "orange", "ananas", "grape", "limes", "pomegranate"};

const int word_count = sizeof(words) / sizeof(words[0]);



// ASCII art for the hangman stick figure

const char *hangman[] = {

    "   ____\n"

    "   |   |\n"

    "   |   O\n"

    "   |\n"

    "   |\n"

    "   |\n"

    " __|__\n",

    "   ____\n"

    "   |   |\n"

    "   |   O\n"

    "   |   |\n"

    "   |\n"

    "   |\n"

    " __|__\n",

    "   ____\n"

    "   |   |\n"

    "   |   O\n"

    "   |  /|\n"

    "   |\n"

    "   |\n"

    " __|__\n",

    "   ____\n"

    "   |   |\n"

    "   |   O\n"

    "   |  /|\\\n"

    "   |\n"

    "   |\n"

    " __|__\n",

    "   ____\n"

    "   |   |\n"

    "   |   O\n"

    "   |  /|\\\n"

    "   |  /\n"

    "   |\n"

    " __|__\n",

    "   ____\n"

    "   |   |\n"

    "   |   O\n"

    "   |  /|\\\n"

    "   |  / \\\n"

    "   |\n"

    " __|__\n"

};



int main(void) {

    srand(time(NULL));  // seed the random number generator

    int word_index = rand() % word_count;  // choose a random word

    const char *word = words[word_index];  // get the word

    int word_length = strlen(word);  // get the lenght of the word

    char word_mask[word_length + 1];  // create a mask for the word

    for (int i = 0; i < word_length; i++) {

        word_mask[i] = '_';  // initialize the mask with underscores

    }

    word_mask[word_length] = '\0';  // null-terminate the string



    int mistakes = 0;  // number of mistakes made so far

    char tried_letters[26] = {0};  // array to store tried letters

    int tried_letter_count = 0;  // number of tried letters

    char letter;  // letter entered by the player



    while (mistakes < MAX_MISTAKES) {

        printf("Word: %s\n", word_mask);  // print the word mask

        printf("Tried letters: ");

        for (int i = 0; i < tried_letter_count; i++) {

            printf("%c ", tried_letters[i]);  // print tried letters

        }

        printf("\nEnter a letter: ");

        scanf(" %c", &letter);  // read the letter entered by the player

        

          // check if the letter has already been tried

    int already_tried = 0;

    for (int i = 0; i < tried_letter_count; i++) {

        if (tried_letters[i] == letter) {

            already_tried = 1;  // set the flag to indicate that the letter has already been tried

            break;

        }

    }



    if (already_tried) {

        printf("You have already tried '%c'. Try a different letter.\n", letter);

        continue;  // skip the rest of the loop and start a new iteration

    }

        tried_letters[tried_letter_count++] = letter;  // add the letter to the tried letters array



        int correct = 0;  // flag to store if the letter is correct or not

        for (int i = 0; i < word_length; i++) {

            if (word[i] == letter) {

                word_mask[i] = letter;  // fill in the correct letter in the mask

                correct = 1;  // set the flag to indicate that the letter is correct

            }

        }

        



      if (!correct) {  // if the letter is incorrect

    mistakes++;  // increase the number of mistakes

    printf("Incorrect! %d mistakes out of %d allowed.\n", mistakes, MAX_MISTAKES);

    printf("%s", hangman[mistakes - 1]);  // print the stick figure

}



        if (strcmp(word_mask, word) == 0) {  // if the word has been correctly guessed

            printf("You won! The word was %s.\n", word);

            break;  // exit the game loop

        }

    }



    if (mistakes == MAX_MISTAKES) {  // if the player has made too many mistakes

        printf("You lost! The word was %s.\n", word);

    }



    return 0;

}