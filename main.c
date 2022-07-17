#include <stdio.h>
#include <stdlib.h>
 struct  character_node{
    char c;
    int position;
    int correct;
    struct character_node *p;
    struct character_node *left;
    struct character_node *right;
} ;
struct  character_tree{
    struct character_node *root;
};

void setup();
void controlla_corrispondeza();
void insert_word_into_dictionary();

void read_command();

void new_game();
struct character_node* tree_successor_character_node(struct character_node *x);
int numero_di_istanze(struct character_node *x,char k);
int numero_di_istanze(struct character_node *x,char k);
struct character_node* tree_search_character_node(struct character_node *x,char k);
int numero_di_istanze_corretta(struct character_node *x,char k);
int numero_di_istanze_NoncorrettaPrimaDiI(struct character_node *x,char k,int position);
void tree_insert_character_node(struct character_tree* T,struct character_node* z);
struct character_node* tree_minimum_character_node(struct character_node *x);
struct character_node* tree_precessor_character_node(struct character_node *x);
//struct characters_word_node *tree_search_characters_word_three(struct characters_word_three *characters_word_three,struct characters_word_node *characters_word_node,char c);
//void rb_insert_fixup_characters_word_three(struct characters_word_three *T, struct characters_word_node *z);

int length_words;
char* dictionary;
int number_of_words_into_dictionary;
int buffer = 10;
int lenght;
struct character_tree *word_to_search;
struct character_tree *word_to_check;

int main() {
    setup();
    return 0;
}

void setup() {
    if (fscanf(stdin, "%d", &length_words) == 1) {
    };
    dictionary = malloc((sizeof (char))*length_words*10);
    number_of_words_into_dictionary = 0;
    insert_word_into_dictionary();
    free(dictionary);
}

void new_game() {
    char temp = getchar_unlocked();
    word_to_search = malloc(sizeof (struct character_tree));
    word_to_search->root = malloc(sizeof (struct character_node));
    word_to_search->root = NULL;
    int i = 0;
    while (temp != '\n') {
        struct character_node * character = malloc(sizeof (struct character_node));
        character->c = temp;
        character->position = i;

        tree_insert_character_node(word_to_search,character);
        i++;
        temp = getchar_unlocked();
    }
    int number;
    if (fscanf(stdin, "%d", &number) == 1) {
    };
    i = 0;
    temp = getchar_unlocked();
    temp = getchar_unlocked();
    word_to_check = malloc(sizeof (struct character_tree));
    word_to_check->root = malloc(sizeof (struct character_node));
    while (temp != EOF) {
        while (temp != '+' && temp != EOF) {
            i = 0;
            while (temp != '\n' && temp != EOF) {
                struct character_node * character = malloc(sizeof (struct character_node));
                character->c = temp;
                character->position = i;
                character->left = NULL;
                character->right = NULL;
                character->correct = 0;
                character->p = NULL;
                tree_insert_character_node(word_to_check,character);
                temp = getchar_unlocked();
                i++;
            }
            controlla_corrispondeza();

            temp = getchar_unlocked();
        }
        //read_command();
        temp = getchar_unlocked();
    }

}

void read_command() {
    char temp = getchar_unlocked();
    if (temp == 'n') {
        for (int i = 0; i < 13; i++) {
            temp = getchar_unlocked();
        }
        new_game();
    } else if (temp == 's') {
        for (int i = 0; i < 15; i++) {
            temp = getchar_unlocked();
        }
    } else if (temp == 'i') {

        for (int i = 0; i < 16; i++) {
            temp = getchar_unlocked();
        }

        while (temp != '+') {
            int i = 0;
            while (temp != '\n') {
                temp = getchar_unlocked();
                dictionary[number_of_words_into_dictionary*length_words+i]=temp;
                i++;
            }
            number_of_words_into_dictionary++;
            buffer++;
            if(buffer%10==0){
                dictionary = realloc(dictionary,(sizeof (char )*length_words*buffer));
            }
            //insert tree characters into tree words
            temp = getchar_unlocked();
        }
        //Check if new word must be filtarted
        for (int i = 0; i < 15; i++) {
            temp = getchar_unlocked();
        }

    }

}

void controlla_corrispondeza(){
    char outpi[length_words];
    struct character_node * node_search,*node_check;
    node_check = tree_minimum_character_node(word_to_check->root);
    node_search = tree_minimum_character_node(word_to_search->root);
    while(1){
        if(node_check->c>node_search->c){
            outpi[node_check->position]='/';
            node_check->correct=0;

            node_search = tree_successor_character_node(node_search);
        }else if(node_check->c<node_search->c){
            outpi[node_check->position]='/';
            node_check->correct=0;

            node_check = tree_successor_character_node(node_check);
        }else{
            if(node_check->position==node_search->position){
                outpi[node_check->position]='+';
                node_check->correct=1;
                node_check = tree_successor_character_node(node_check);
                node_search = tree_successor_character_node(node_search);
            }else{
                if(node_check->position>node_search->position){
                    outpi[node_check->position]='|';
                    node_check->correct=0;
                    node_search = tree_successor_character_node(node_search);
                }else{
                    outpi[node_check->position]='|';
                    node_check->correct=-1;
                    node_check = tree_successor_character_node(node_check);
                }
            }
        }
        if(node_check==NULL || node_search==NULL){
            break;
        }
    }
    //Check condiction to |
    node_check = tree_minimum_character_node(word_to_check->root);

        for (int i = 0; i < length_words; ++i) {


        if(node_check->correct == -1){
            //TODO sistema con ciclo annidato
            int numero_di_instanze = numero_di_istanze(word_to_search->root,node_check->c);
            int numero_corrette = numero_di_istanze_corretta(word_to_check->root,node_check->c);
                int numerto_nonCorrette = numero_di_istanze_NoncorrettaPrimaDiI(word_to_check->root,node_check->c,node_check->position);
                if(numerto_nonCorrette>=numero_di_instanze-numero_corrette){
                    outpi[node_check->position] = '|';
                }
                //char temp = node_check->c;
                node_check = tree_successor_character_node(node_check);

        }else{
            node_check = tree_successor_character_node(node_check);
        }

    }
    for (int i = 0; i < length_words; ++i) {
        printf("%c",outpi[i]);

    }



}

int numero_di_istanze(struct character_node *x,char k){
    int i = 0;
    struct character_node  *node = tree_search_character_node(x,k);
    if(node==NULL){
        return 0;
    }else{
        while (1){
            i++;
            struct character_node *node_cicle = node->right;
            if(node_cicle==NULL || node_cicle->c>k){
                return i;
            }
        }
    }
}

int numero_di_istanze_corretta(struct character_node *x,char k){
    int i = 0;
    struct character_node  *node = tree_search_character_node(x,k);
    if(node==NULL){
        return 0;
    }else{
        while (1){
            if(node->correct==1){
                i++;
            }
            node = node->right;

            if(node==NULL || node->c>k){
                return i;
            }
        }
    }
}
int numero_di_istanze_NoncorrettaPrimaDiI(struct character_node *x,char k,int position){
    int i = 0;
    struct character_node  *node = tree_search_character_node(x,k);
    if(node==NULL){
        return 0;
    }else{
        while (1){
            if(node->correct==-1){
                i++;
            }
            node = tree_successor_character_node(node);
            if(node->position>=position){
                return i;
            }
            if(node==NULL || node->c>k){
                return i;
            }
        }
    }
}


void insert_word_into_dictionary() {
    char temp = getchar_unlocked();
    while (temp != '+') {
        int i = 0;
        while (temp != '\n') {

            dictionary[number_of_words_into_dictionary*length_words+i]=temp;

            temp = getchar_unlocked();
            i++;
        }
        number_of_words_into_dictionary++;
        buffer++;
        if(buffer%10==0){
            dictionary = realloc(dictionary,(sizeof (char )*length_words*buffer));
        }
        //insert tree characters into tree words
        temp = getchar_unlocked();
    }
    read_command();
}

struct character_node* tree_search_character_node(struct character_node *x,char k){
    if(x==NULL || k == x->c){
        return x;
    }
    if(k<x->c){
        return tree_search_character_node( x->left, k);
    }else{
        return tree_search_character_node(x->right, k);
    }
}
struct character_node* tree_minimum_character_node(struct character_node *x){
    while (x->left!=NULL){
        x =  x->left;
    }
    return x;
}
struct character_node* tree_maximum_character_node(struct character_node *x){
    while (x->right!=NULL){
        x = x->right;
    }
    return x;
}
struct character_node* tree_successor_character_node(struct character_node *x){
    if(x->right!=NULL){
        return tree_minimum_character_node( x->right);
    }
    struct character_node *y =  x->p;
    while (y!=NULL && x == y->right){
        x = y;
        y = y->p;
    }
    return y;
}

void tree_insert_character_node(struct character_tree* T,struct character_node* z) {
    struct character_node *y = NULL;
    struct character_node *x =  T->root;
    while (x != NULL) {
        y = x;
        if (z->c < x->c) {
            x =  x->left;
        } else {
            x =x->right;
        }
    }
    z->p = y;
    if (y == NULL) {
        T->root =  z;
    } else if (z->c<y->c){
        y->left =  z;
    } else{
        y->right = z;
    }
}