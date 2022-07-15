#include <stdio.h>
#include <stdbool.h>

void setup();

void insert_word_into_dictionary();

void read_command();
void new_game();

int length_words;

struct words {
    struct characters_word *characters_word;
    struct words *p;
    struct words *left;
    struct words *right;
    char color;
};

struct characters_word {
    struct character *character;
    struct characters_word *p;
    struct characters_word *left;
    struct characters_word *right;
    char color;
};

struct character {
    int tot;
    struct position_into_word *positions;
};
struct position_into_word {
    int position;
    struct position *p;
    struct position *left;
    struct position *right;
    char color;
};
struct words *words;

int main() {
    setup();
    int c;
    while (1) {
        c = getchar_unlocked();            // Get one character from the input
        if (c == EOF) { break; }  // Exit the loop if we receive EOF ("end of file")
        putchar(c);               // Put the character to the output
    }
    return 0;
}

void setup() {
    if (fscanf(stdin, "%d", &length_words) == 1) {
        printf("%d", length_words);
    };
    insert_word_into_dictionary();
}

void new_game() {
    char temp = getchar_unlocked();
    while (temp != '\n') {
        printf("%c", temp);
        temp = getchar_unlocked();
    }
    printf("%c", temp);
    int number;
    if (fscanf(stdin, "%d", &number) == 1) {
        printf("%d", number);
    };
    temp = getchar_unlocked();
    while(temp != EOF){
        while (temp != '+' && temp!= EOF) {
            while (temp != '\n' && temp!= EOF) {
                printf("%c", temp);
                temp = getchar_unlocked();
            }
            printf("%c",temp);
            temp = getchar_unlocked();
        }
        read_command();
        temp = getchar_unlocked();
    }
}

void read_command() {
    char temp = getchar_unlocked();
    if (temp == 'n') {
        printf("+n");
        for (int i = 0; i <13 ; i++) {
            temp = getchar_unlocked();
            printf("%c",temp);
        }
        new_game();
    }else if (temp == 's'){
        printf("+s");
        for (int i = 0; i <15 ; i++) {
            temp = getchar_unlocked();
            printf("%c",temp);
        }
    }else if( temp == 'i'){
        printf("+i");

        for (int i = 0; i <16 ; i++) {
            temp = getchar_unlocked();
            printf("%c",temp);
        }

        while (temp != '+') {
            while (temp != '\n') {

                temp = getchar_unlocked();
                printf("%c", temp);
            }

            temp = getchar_unlocked();
        }
        for (int i = 0; i <15 ; i++) {
            temp = getchar_unlocked();
            printf("%c",temp);
        }

    }

}

void insert_word_into_dictionary() {
    char temp = getchar_unlocked();
    while (temp != '+') {
        while (temp != '\n') {
            printf("%c", temp);
            temp = getchar_unlocked();
        }
        printf("%c",temp);
        temp = getchar_unlocked();
    }
    read_command();
}
