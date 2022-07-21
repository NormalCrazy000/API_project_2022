#include <stdio.h>
#include <stdlib.h>

struct character_node {
    char c;
    int position;
    int correct;
    struct character_node *p;
    struct character_node *left;
    struct character_node *right;
};
struct character_tree {
    struct character_node *root;
};
struct word_node {
    char *c;
    struct word_node *p;
    struct word_node *left;
    struct word_node *right;
};
struct word_tree {
    struct word_node *root;
};




struct information_node {
    char c;
    int *position;
    int *noposition;
    int min;
    int number_correct;
    int counter_noposition;
    int counter_position;
    struct information_node *p;
    struct information_node *left;
    struct information_node *right;
};
struct information_tree {
    struct information_node *root;
};
struct information_array{
    char c;
    int *position;
    int *noposition;
    int min;
    int number_correct;
    int counter_noposition;
    int counter_position;
};


void setup();

void controlla_corrispondeza();

void insert_word_into_dictionary();

void read_command();

void new_game();
int confronto_stringhe(char *c1,char *c2,int len,int position);
void tree_insert_word_node(struct word_tree *T, struct word_node *z);
struct character_node *tree_successor_character_node(struct character_node *x);
struct information_node *tree_minimum_information_node(struct information_node *x);
int numero_di_istanze(struct character_node *x, char k);
int confronto_stringhe_fine(char *c1,char *c2,int len);
int numero_di_istanze(struct character_node *x, char k);
struct word_node *tree_minimum_word_node(struct word_node *x);
struct character_node *tree_search_character_node(struct character_node *x, char k);
void confronta_nuove();
int numero_di_istanze_corretta(struct character_node *x, char k);

int numero_di_istanze_NoncorrettaPrimaDiI(struct character_node *x, char k, int position);
struct information_node *tree_successor_information_node(struct information_node *x);
void tree_insert_character_node(struct character_tree *T, struct character_node *z);
void confronto();
struct character_node *tree_minimum_character_node(struct character_node *x);
struct information_node *tree_search_information_node(struct information_node *x, char k);
int inorder_tree_walk_information(struct information_node* node,char* word);
struct character_node *tree_precessor_character_node(struct character_node *x);
struct character_node *tree_search_character_node_position(struct character_node *x, char k,int i);
void tree_insert_information_node(struct information_tree *T, struct information_node *z);
//struct characters_word_node *tree_search_characters_word_three(struct characters_word_three *characters_word_three,struct characters_word_node *characters_word_node,char c);
//void rb_insert_fixup_characters_word_three(struct characters_word_three *T, struct characters_word_node *z);
int check_if_word_exist(char *dic,char *word);
struct word_node *tree_successor_word_node(struct word_node *x);
void ordina();
int length_words;
char *dictionary;
char *filter_dictionary;
int number_of_words_into_dictionary;
int buffer = 10;
int test = 0;
int lenght;
struct character_tree *word_to_search;
struct character_tree *word_to_check;
struct information_tree *information;
struct word_tree *dictionary_filter;
int number;
int end_game = 0;
int number_word_filtated;
int *position_word_filtarted;
int game;
int prova = 1;
int start = 0;
struct information_array* information_array;
int main() {
    setup();
    return 0;
}

void setup() {
    if (fscanf(stdin, "%d", &length_words) == 1) {
    };
    dictionary = malloc((sizeof(char)) * length_words * 10);
    number_of_words_into_dictionary = 0;
    insert_word_into_dictionary();
    free(dictionary);
}

void new_game() {
    char temp = getchar_unlocked();
    end_game = 0;
    word_to_search = malloc(sizeof(struct character_tree));
    word_to_search->root = malloc(sizeof(struct character_node));
    information = malloc(sizeof(struct information_tree));
    //TODO
    information->root = malloc(sizeof(struct information_node));
    word_to_search->root = NULL;
    information->root = NULL;
    int i = 0;
    while (temp != '\n') {
        struct character_node *character = malloc(sizeof(struct character_node));
        character->c = temp;
        character->position = i;

        tree_insert_character_node(word_to_search, character);
        i++;
        temp = getchar_unlocked();
    }
    if (fscanf(stdin, "%d", &number) == 1) {
    };
    i = 0;
    temp = getchar_unlocked();
    temp = getchar_unlocked();

    while (temp != EOF) {
        while (temp != '+' && temp != EOF) {
            i = 0;
            char *word = malloc(sizeof (char)*length_words);
            word_to_check = malloc(sizeof(struct character_tree));
            word_to_check->root = malloc(sizeof(struct character_node));
            word_to_check->root=NULL;
            while (temp != '\n'  && temp != EOF) {
                struct character_node *character = malloc(sizeof(struct character_node));
                character->c = temp;
                word[i] = temp;
                character->position = i;
                character->left = NULL;
                character->right = NULL;
                character->correct = 0;
                character->p = NULL;
                tree_insert_character_node(word_to_check, character);
                temp = getchar_unlocked();
                i++;
            }

            int j = check_if_word_exist(dictionary,word);
            if(j==0){
                printf("not_exists\n");

            }else{
                controlla_corrispondeza();
                number--;
                if(number==0){
                    if(end_game==0){

                        printf("ko\n");
                    }
                    end_game=1;
                }
            }

            free(word_to_check);
            word_to_check = NULL;
            temp = getchar_unlocked();

            if(end_game==1){
                printf("Carattere: %c",temp);
            }
        }
        if(end_game==1){
            printf("Carattere: %c",temp);
        }
        read_command();
        temp = getchar_unlocked();
    }

}

void read_command() {
    char temp = getchar_unlocked();
    if(end_game==1){
        printf("Carattere: %c",temp);
    }
    if (temp == 'n') {
        prova++;
        for (int i = 0; i < 13; i++) {
            temp = getchar_unlocked();
        }
        free(filter_dictionary);
        free(word_to_search);
        free(word_to_check);
        free(information);
        free(dictionary_filter);
        free(position_word_filtarted);
       number = 0;
        end_game = 0;
         number_word_filtated = 0;
        position_word_filtarted = NULL;

        new_game();
    } else if (temp == 's') {
        ordina();
        for (int i = 0; i < 15; i++) {
            temp = getchar_unlocked();
        }

    } else if (temp == 'i') {

        for (int i = 0; i < 16; i++) {
            temp = getchar_unlocked();

        }
        temp = getchar_unlocked();

        while (temp != '+') {
            int i = 0;
            while (temp != '\n') {
                dictionary[number_of_words_into_dictionary * length_words + i] = temp;
                temp = getchar_unlocked();

                i++;
            }
            confronta_nuove();

            number_of_words_into_dictionary++;
            buffer++;
            if (buffer % 10 == 0) {
                dictionary = realloc(dictionary, (sizeof(char) * length_words * buffer));
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

void ordina(){
    struct word_tree* word_tree = malloc(sizeof (struct word_tree));
    word_tree->root = malloc(sizeof (struct word_node));
    word_tree->root = NULL;
    int i = 0;
    if(number_word_filtated!=0){
        while (i<number_word_filtated){
            struct word_node *word_node = malloc(sizeof(struct word_node));
            word_node->c = malloc(sizeof(int)*length_words);
            int k = 0;
            while (k<length_words){
                word_node->c[k] = dictionary[position_word_filtarted[i]+k];
                k++;
            }
            word_node->left = NULL;
            word_node->right = NULL;
            word_node->p = NULL;
            tree_insert_word_node(word_tree, word_node);
            i++;
        }
    }else{
        while (i<number_of_words_into_dictionary){
            struct word_node *word_node = malloc(sizeof(struct word_node));
            word_node->c = malloc(sizeof(int)*length_words);
            int k = 0;
            while (k<length_words){
                word_node->c[k] = dictionary[i*length_words+k];
                k++;
            }
            word_node->left = NULL;
            word_node->right = NULL;
            word_node->p = NULL;
            tree_insert_word_node(word_tree, word_node);
            i++;
        }
    }

    struct word_node *word_node = NULL;
    if(word_tree->root!=NULL){
        word_node = tree_minimum_word_node(word_tree->root);
    }

    while (word_node!=NULL){
        int k = 0;

        while (k<length_words){
            printf("%c",word_node->c[k]);
            k++;
        }
        printf("\n");

        word_node = tree_successor_word_node(word_node);
    }



}

void controlla_corrispondeza() {

    char outpi[length_words];
    struct character_node *node_search, *node_check;
    node_check = tree_minimum_character_node(word_to_check->root);
    int correct_word = 0;
    while (node_check!=NULL){
        node_search = tree_search_character_node(word_to_search->root,node_check->c);
        if(node_search == NULL){
            char temp = node_check->c;
            while (node_check!=NULL && temp == node_check->c){
                outpi[node_check->position] = '/';
                node_check->correct = 0;
                temp = node_check->c;
                node_check = tree_successor_character_node(node_check);
            }
        }else{
            if(tree_search_character_node_position(word_to_search->root,node_check->c,node_check->position)!=NULL){
                outpi[node_check->position] = '+';
                correct_word++;
                node_check->correct = 1;
                node_check = tree_successor_character_node(node_check);
            }else{
                outpi[node_check->position] = '|';
                node_check->correct = -1;
                node_check = tree_successor_character_node(node_check);
            }
        }
    }
if(correct_word==length_words){

    printf("ok\n");
    end_game = 1;
    return;
}
    //Check condiction to |
    node_check = tree_minimum_character_node(word_to_check->root);



    int j = 0;
    while(j<length_words) {
        if (node_check->correct == -1) {
            int numero_di_instanze = numero_di_istanze(word_to_search->root, node_check->c);
            int numero_corrette = numero_di_istanze_corretta(word_to_check->root, node_check->c);
            char old = node_check->c;
            while (node_check!=NULL && old == node_check->c) {
                if (node_check->correct == -1) {
                    int numerto_nonCorrette = numero_di_istanze_NoncorrettaPrimaDiI(word_to_check->root, node_check->c,
                                                          node_check->position);

                    if (numerto_nonCorrette >= numero_di_instanze - numero_corrette) {

                        outpi[node_check->position] = '/';
                    }
                    //char temp = node_check->c;
                    old = node_check->c;
                    node_check = tree_successor_character_node(node_check);
                    j++;
                } else {
                    old = node_check->c;
                    node_check = tree_successor_character_node(node_check);
                    j++;
                }

            }
        } else {
            node_check = tree_successor_character_node(node_check);
            j++;
        }


    }


        node_check = tree_minimum_character_node(word_to_check->root);
        int numeri_piu ;
        int numeri_tarttino ;
        int numeri_sbarra;
        int x = 0;
        while(x<length_words) {
            //set information
            struct information_node *node = tree_search_information_node(information->root, node_check->c);
             numeri_piu = 0;
             numeri_tarttino = 0;
             numeri_sbarra = 0;
            struct information_node* node_info;
            if (node == NULL) {
                  node_info = malloc(sizeof(struct information_node));
                  node_info->c = node_check->c;
                tree_insert_information_node(information,node_info);
            }else{
                node_info = node;
            }
                char temp = node_check->c;
                while (node_check!=NULL && temp == node_check->c) {
                    if (outpi[node_check->position] == '+') {
                        numeri_piu++;
                        node_info->counter_position++;
                        node_info->position = realloc(node_info->position, node_info->counter_position * sizeof(int));
                        node_info->position[node_info->counter_position - 1] = node_check->position;
                        //printf("%c --- %d\n",node_info->c,node_info->position[node_info->counter_position - 1]+1);
                    } else if (outpi[node_check->position] == '|') {
                        numeri_tarttino++;
                        node_info->counter_noposition++;
                        node_info->noposition = realloc(node_info->noposition,
                                                        node_info->counter_noposition * sizeof(int));
                        node_info->noposition[node_info->counter_noposition - 1] = node_check->position;
                    } else if (outpi[node_check->position] == '/') {
                        numeri_sbarra++;
                        node_info->counter_noposition++;
                        node_info->noposition = realloc(node_info->noposition,
                                                        node_info->counter_noposition * sizeof(int));
                        node_info->noposition[node_info->counter_noposition - 1] = node_check->position;
                    }
                    temp = node_check->c;
                    node_check = tree_successor_character_node(node_check);
                   // printf("%d\n",x);
                    //TODO
                    x++;

                }
                int min = 0;
                int esatto = -1;
                if(numeri_sbarra>0){

                    esatto = numeri_piu+numeri_tarttino;
                    min = esatto;
                    //printf("%d -- %d",node_info->c,esatto);
                    node_info->number_correct = esatto;
                    node_info->min = min;
                }else{
                    min = numeri_tarttino +numeri_piu;

                    if(min>node_info->min){

                        node_info->min = min;
                    }
                    node_info->number_correct = esatto;
                }




        }
    confronto();



    for (int i = 0; i < length_words; ++i) {
        printf("%c", outpi[i]);
    }
    printf("\n");
    printf("%d\n",number_word_filtated);



}
//0 first string is less
//1 second string is less
//2 equal
int confronto_stringhe(char *c1,char *c2,int len,int position){
    int i = 0;
    while(i<len){
        if(c1[i+position]>c2[i]){
            return 1;
        } else if(c1[i+position]<c2[i]){
            return 0;
        }
        i++;
    }
    return 2;
}
//0 first string is less
//1 second string is less
//2 equal
int confronto_stringhe_fine(char *c1,char *c2,int len){
    int i = 0;
    while(i<len){
        if(c1[i]>c2[i]){
            return 1;
        } else if(c1[i]<c2[i]){
            return 0;
        }
        i++;
    }
    return 2;
}
void confronto() {
    int i = 0;


    struct information_node *node = NULL;
    if(information->root!=NULL){
         node = tree_minimum_information_node(information->root);
    }
    while (node != NULL){
    if (number_word_filtated == 0) {
        int *pos = node->position;
        int *nopos = node->noposition;
        int min = node->min;
        int correct = node->number_correct;
        int save = 1;
        i = 0;
        while (i < number_of_words_into_dictionary) {

            save = 1;
            int j = 0;
            while (j < node->counter_position) {
                if (dictionary[i * length_words + pos[j]] != node->c) {
                    save = 0;
                    break;
                }
                j++;
            }
            if (save != 0) {
                j = 0;

                while (j < node->counter_noposition) {

                    if (dictionary[i * length_words + nopos[j]] == node->c) {

                        save = 0;
                        break;
                    }
                    j++;
                }
            }
            if (save != 0) {
                //TODO
                j = 0;
                int x = 0;
                while (j < length_words) {
                    if (dictionary[i * length_words + j] == node->c) {
                        x++;
                    }
                    j++;
                }
                if (x < min) {
                    save = 0;
                }
                if(x==0 && min==0){
                    save = 1;
                }
                if (correct != -1) {
                    if (correct != x) {
                        save = 0;
                    }
                }

            }
            if (save == 1) {

                number_word_filtated++;
                if(number_word_filtated==1){
                    position_word_filtarted = malloc(sizeof(int) * number_word_filtated);

                }else{
                    position_word_filtarted = realloc(position_word_filtarted, sizeof(int) * number_word_filtated);

                }
                position_word_filtarted[number_word_filtated - 1] = i * length_words;
            }
            i++;

        }
    }else{
        int *pos = node->position;
        int *nopos = node->noposition;
        int min = node->min;
        int correct = node->number_correct;
        int save = 1;

        int new_number_word_filtrated=0;
        int *new_position_filtrated = NULL;


        i = 0;

        while (i < number_word_filtated) {
            save = 1;
            int j = 0;

            while (j < node->counter_position) {
                if (dictionary[position_word_filtarted[i] + pos[j]] != node->c) {
                    save = 0;


                    break;
                }
                j++;
            }
            if (save != 0) {
                j = 0;


                while (j < node->counter_noposition) {

                    if (dictionary[position_word_filtarted[i] + nopos[j]] == node->c) {
                        save = 0;
                        break;
                    }
                    j++;
                }
            }
            if (save != 0) {
                //TODO


                j = 0;
                int x = 0;
                while (j < length_words) {
                    if (dictionary[position_word_filtarted[i] + j] == node->c) {
                        x++;
                    }
                    j++;
                }
                if (x < min) {
                    save = 0;
                }
                if(x==0 && min==0){
                    save = 1;
                }
                if (correct != -1) {
                    if (correct != x) {
                        save = 0;
                    }
                }

            }
            if (save == 1) {


                new_number_word_filtrated++;
                if(new_number_word_filtrated==1){
                    new_position_filtrated = malloc( sizeof(int) * new_number_word_filtrated);

                }else{
                    new_position_filtrated = realloc(new_position_filtrated, sizeof(int) * new_number_word_filtrated);

                }
                new_position_filtrated[new_number_word_filtrated - 1] = position_word_filtarted[i];

            }
            i++;

        }
            number_word_filtated = new_number_word_filtrated;
            position_word_filtarted = new_position_filtrated;


    }



    node = tree_successor_information_node(node);
}


}

//TODO
void confronta_nuove() {
    int i = 0;
    struct information_node *node = NULL;
    int save = 0;
    if(information->root!=NULL){
        save=1;
        node = tree_minimum_information_node(information->root);
    }

    while (node != NULL) {

        int *pos = node->position;
        int *nopos = node->noposition;
        int min = node->min;
        int correct = node->number_correct;

        i = 0;


            int j = 0;

            while (j < node->counter_position) {
                if (dictionary[number_of_words_into_dictionary*length_words + pos[j]] != node->c) {
                    save = 0;


                    break;
                }
                j++;
            }
            if (save != 0) {
                j = 0;


                while (j < node->counter_noposition) {

                    if (dictionary[number_of_words_into_dictionary*length_words + nopos[j]] == node->c) {
                        save = 0;
                        break;
                    }
                    j++;
                }
            }
            if (save != 0) {
                //TODO


                j = 0;
                int x = 0;
                while (j < length_words) {
                    if (dictionary[number_of_words_into_dictionary*length_words  + j] == node->c) {
                        x++;
                    }
                    j++;
                }
                if (x < min) {
                    save = 0;
                }
                if (x == 0 && min == 0) {
                    save = 1;
                }
                if (correct != -1) {
                    if (correct != x) {
                        save = 0;
                    }
                }

            }

            i++;



        node = tree_successor_information_node(node);
    }
    if (save == 1) {


        number_word_filtated++;
        if(number_word_filtated==1){
            position_word_filtarted = malloc(sizeof(int) * number_word_filtated);

        }else{
            position_word_filtarted = realloc(position_word_filtarted, sizeof(int) * number_word_filtated);

        }
        position_word_filtarted[number_word_filtated - 1] = number_of_words_into_dictionary*length_words;

    }

}

int check_if_word_exist(char *dic,char *word){
    int i = 0;
    while (i<number_of_words_into_dictionary){
        if(confronto_stringhe(dictionary,word,length_words,i*length_words)==2){
            return 1;
        }
        i++;
    }
    return 0;
}

int numero_di_istanze(struct character_node *x, char k) {
    int i = 0;
    struct character_node *node = tree_search_character_node(x, k);
    if (node == NULL) {
        return 0;
    } else {
        while (1) {
            i++;
              node = tree_successor_character_node(node);
            if (node == NULL || node->c > k) {
                return i;
            }
        }
    }
}

int numero_di_istanze_corretta(struct character_node *x, char k) {
    int i = 0;
    struct character_node *node = tree_search_character_node(x, k);
    if (node == NULL) {
        return 0;
    } else {
        while (1) {
            if (node->correct == 1) {
                i++;
            }
            node = tree_successor_character_node(node);

            if (node == NULL || node->c > k) {
                return i;
            }
        }
    }
}

int numero_di_istanze_NoncorrettaPrimaDiI(struct character_node *x, char k, int position) {
    int i = 0;
    struct character_node *node = tree_search_character_node(x, k);
    if (node == NULL) {
        return 0;
    } else {
        while (1) {
            if (node->position<position && node->correct == -1) {
                i++;
            }
            node = tree_successor_character_node(node);
            if (node == NULL || node->c > k) {
                return i;
            }
            if (node->position >= position) {
                return i;
            }

        }
    }
}


void insert_word_into_dictionary() {
    char temp = getchar_unlocked();
    //TODO
    temp = getchar_unlocked();
    while (temp != '+') {
        int i = 0;
        while (temp != '\n') {

            dictionary[number_of_words_into_dictionary * length_words + i] = temp;

            temp = getchar_unlocked();
            i++;
        }
        //printf("\n");
        //printf("\n");
        number_of_words_into_dictionary++;
        buffer++;
        if (buffer % 10 == 0) {
            dictionary = realloc(dictionary, (sizeof(char) * length_words * buffer));
        }
        //insert tree characters into tree words
        temp = getchar_unlocked();
    }
    read_command();
}

struct character_node *tree_search_character_node(struct character_node *x, char k) {
    if (x == NULL || k == x->c) {
        return x;
    }
    if (k < x->c) {
        return tree_search_character_node(x->left, k);
    } else {
        return tree_search_character_node(x->right, k);
    }
}

struct character_node *tree_search_character_node_position(struct character_node *x, char k,int i) {
    if (x == NULL || (k == x->c && x->position==i)) {
        return x;
    }
    if (k < x->c) {
        return tree_search_character_node_position(x->left, k,i);
    } else {
        return tree_search_character_node_position(x->right, k,i);
    }
}

struct information_node *tree_search_information_node(struct information_node *x, char k) {
    if (x == NULL || k == x->c) {
        return x;
    }
    if (k < x->c) {
        return tree_search_information_node(x->left, k);
    } else {
        return tree_search_information_node(x->right, k);
    }
}

struct character_node *tree_minimum_character_node(struct character_node *x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}
struct information_node *tree_minimum_information_node(struct information_node *x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

struct word_node *tree_minimum_word_node(struct word_node *x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}


struct character_node *tree_successor_character_node(struct character_node *x) {
    if (x->right != NULL) {
        return tree_minimum_character_node(x->right);
    }
    struct character_node *y = x->p;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}
struct information_node *tree_successor_information_node(struct information_node *x) {
    if (x->right != NULL) {
        return tree_minimum_information_node(x->right);
    }
    struct information_node *y = x->p;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}
struct word_node *tree_successor_word_node(struct word_node *x) {
    if (x->right != NULL) {
        return tree_minimum_word_node(x->right);
    }
    struct word_node *y = x->p;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}


void tree_insert_character_node(struct character_tree *T, struct character_node *z) {
    struct character_node *y = NULL;
    struct character_node *x = T->root;
    while (x != NULL) {
        y = x;
        if (z->c < x->c) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->p = y;
    if (y == NULL) {
        T->root = z;
    } else if (z->c < y->c) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void tree_insert_information_node(struct information_tree *T, struct information_node *z) {
    struct information_node *y = NULL;
    struct information_node *x = T->root;
    while (x != NULL) {
        y = x;
        if (z->c < x->c) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->p = y;
    if (y == NULL) {
        T->root = z;
    } else if (z->c < y->c) {
        y->left = z;
    } else {
        y->right = z;
    }
}

//0 first string is less
//1 second string is less
//2 equal
void tree_insert_word_node(struct word_tree *T, struct word_node *z) {
    struct word_node *y = NULL;
    struct word_node *x = T->root;
    while (x != NULL) {
        y = x;

        if (confronto_stringhe_fine(z->c,x->c,length_words)==0) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->p = y;
    if (y == NULL) {
        T->root = z;
    } else if (confronto_stringhe_fine(z->c,y->c,length_words)==0) {
        y->left = z;
    } else {
        y->right = z;
    }
}

