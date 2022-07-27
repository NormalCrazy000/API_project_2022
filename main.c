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

void setup();

void controlla_corrispondeza();
void liberaAlberi(struct character_node *characterNode);
void insert_word_into_dictionary();
void liberaAlberi_informazione(struct information_node *characterNode);
void read_command();
void liberaParola(struct word_node *characterNode);
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
int confronto_stringhe_heap(int pos1,int pos2,int len);
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
int parent(int i);
int left(int i);
int right(int i);
void swap(int pos1, int pos2, int length);
void max_heapify(int i);
void build_max();
void heapSort();

void ordina();
void ordina2();
int length_words;
char *dictionary;
char *filter_dictionary;
int number_of_words_into_dictionary;
int buffer = 5;
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
int prova = 1;
int heap_size;
int main() {
    length_words = 0;
    dictionary = NULL;
    filter_dictionary = NULL;
    number_of_words_into_dictionary = 0;
    buffer = 5;
    test = 0;
    lenght = 0;
    word_to_search = NULL;
    word_to_check = NULL;
    information = NULL;
    dictionary_filter = NULL;
    number = 0;
    end_game = 0;
    number_word_filtated = 0;
    position_word_filtarted = NULL;
    prova = 1;
    setup();
    if(information!=NULL){
        liberaAlberi_informazione(information->root);
        free(information);
        information = NULL;
    }
    if(position_word_filtarted!=NULL){
        free(position_word_filtarted);
    }
    if(word_to_search!=NULL){
        liberaAlberi(word_to_search->root);
        free(word_to_search);
        information = NULL;
    }
    return 0;
}

void setup() {
    if (fscanf(stdin, "%d", &length_words) == 1) {
    };
    dictionary = malloc((sizeof(char)) * length_words * 5);
    number_of_words_into_dictionary = 0;
    insert_word_into_dictionary();
    char temp = 0;
    while (temp!=EOF){
        read_command();
        temp = getchar_unlocked();
    }
    free(dictionary);
}

void new_game() {
    char temp = getchar_unlocked();
    end_game = 0;
    if(word_to_search!=NULL){
        liberaAlberi(word_to_search->root);
        free(word_to_search);
        word_to_search =NULL;
    }
    word_to_search = malloc(sizeof(struct character_tree));
    //word_to_search->root = malloc(sizeof(struct character_node));
    if(information!=NULL){
        liberaAlberi_informazione(information->root);
        free(information);
        information =NULL;
    }
    information = malloc(sizeof(struct information_tree));
    //TODO
    //information->root = malloc(sizeof(struct information_node));
    word_to_search->root = NULL;
    information->root = NULL;
    int i = 0;
    while (temp != '\n') {
        struct character_node *character = malloc(sizeof(struct character_node));
        character->c = temp;
        character->position = i;
        character->correct = 0;
        character->p =NULL;
        character->right = NULL;
        character->left = NULL;
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
            if(word_to_check!=NULL){
                liberaAlberi(word_to_check->root);
                free(word_to_check);
                word_to_check = NULL;
            }
            word_to_check = malloc(sizeof(struct character_tree));
            //word_to_check->root = malloc(sizeof(struct character_node));
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
            free(word);
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
            temp = getchar_unlocked();
            if(word_to_check!=NULL){
                liberaAlberi(word_to_check->root);
                free(word_to_check);
                word_to_check =NULL;

            }


        }


        read_command();
        temp = getchar_unlocked();
    }

}

void liberaAlberi(struct character_node *characterNode){


    if(characterNode==NULL) {
        return;
    }
    liberaAlberi(characterNode->left);
    liberaAlberi(characterNode->right);
    free(characterNode);

}
void liberaParola(struct word_node *characterNode) {


    if (characterNode == NULL) {
        return;
    }
    liberaParola(characterNode->left);
    liberaParola(characterNode->right);

    free(characterNode->c);
    free(characterNode);

}

void liberaAlberi_informazione(struct information_node *characterNode){



    if (characterNode == NULL) {
        return;
    }
    liberaAlberi_informazione(characterNode->left);
    liberaAlberi_informazione(characterNode->right);

    free(characterNode->position);
    free(characterNode->noposition);
    free(characterNode);

}
void read_command() {
    char temp = getchar_unlocked();
    if (temp == 'n') {
        prova++;
        for (int i = 0; i < 13; i++) {
            temp = getchar_unlocked();
        }
        free(filter_dictionary);
        if(word_to_search!=NULL){
            liberaAlberi(word_to_search->root);
            free(word_to_search);
            word_to_search=NULL;
        }


        if(word_to_check!=NULL){
            liberaAlberi(word_to_check->root);
            free(word_to_check);

            word_to_check = NULL;
        }

        if(information!=NULL){
            liberaAlberi_informazione(information->root);
            free(information);
            information = NULL;
        }
        if(dictionary_filter!=NULL){
            liberaParola(dictionary_filter->root);
            free(dictionary_filter);
            dictionary_filter = NULL;

        }
        free(position_word_filtarted);
        number = 0;
        end_game = 0;
        number_word_filtated = 0;
        position_word_filtarted = NULL;

        new_game();
    } else if (temp == 's') {


        ordina2();
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
            if (buffer % 5 == 0) {
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
void ordina2(){
    heapSort();
    if(position_word_filtarted!=0){
        int i = 0;
        while (i<number_word_filtated){
            int k = 0;

            while (k<length_words){
                putchar_unlocked(dictionary[position_word_filtarted[i]+k]);
                //printf("%c",word_node->c[k]);
                k++;
            }
            putchar_unlocked('\n');
            i++;
        }
    }else{
        int i = 0;
        while (i<number_of_words_into_dictionary){
            int k = 0;

            while (k<length_words){
                putchar_unlocked(dictionary[i*length_words+k]);
                //printf("%c",word_node->c[k]);
                k++;
            }
            putchar_unlocked('\n');
            i++;
        }
    }
}
void ordina(){

    struct word_tree* word_tree = malloc(sizeof (struct word_tree));
    //word_tree->root = malloc(sizeof (struct word_node));
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
            putchar_unlocked(word_node->c[k]);
            //printf("%c",word_node->c[k]);
            k++;
        }
        putchar_unlocked('\n');
        //printf("\n");

        word_node = tree_successor_word_node(word_node);
    }

    if(word_tree!=NULL){
        liberaParola(word_tree->root);
        free(word_tree);

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
        struct information_node* node_info = NULL;
        if (node == NULL) {
            node_info = malloc(sizeof(struct information_node));
            node_info->c = node_check->c;
            node_info->counter_position=0;
            node_info->counter_noposition = 0;
            node_info->noposition = NULL;
            node_info->position = NULL;
            node_info->p=NULL;
            node_info->right=NULL;
            node_info->left = NULL;
            node_info->min = 0;
            node_info->number_correct = -1;
            tree_insert_information_node(information,node_info);
        }else{
            node_info = node;
        }
        char temp = node_check->c;
        while (node_check!=NULL && temp == node_check->c) {
            if (outpi[node_check->position] == '+') {
                int check = 1;
                for(int k = 0;k<node_info->counter_position;k++){
                    if(node_info->position[k] == node_check->position){
                        check = 0;
                    }
                }
                numeri_piu++;

                if(check==1){
                    node_info->counter_position++;
                    node_info->position = realloc(node_info->position, node_info->counter_position * sizeof(int));
                    node_info->position[node_info->counter_position - 1] = node_check->position;
                }

            } else if (outpi[node_check->position] == '|') {
                int check = 1;
                for(int k = 0;k<node_info->counter_noposition;k++){
                    if(node_info->noposition[k] == node_check->position){
                        check = 0;
                    }
                }
                numeri_tarttino++;

                if(check==1) {
                    node_info->counter_noposition++;
                    node_info->noposition = realloc(node_info->noposition,
                                                    node_info->counter_noposition * sizeof(int));

                    node_info->noposition[node_info->counter_noposition - 1] = node_check->position;
                }
            } else if (outpi[node_check->position] == '/') {
                int check = 1;
                for(int k = 0;k<node_info->counter_noposition;k++){
                    if(node_info->noposition[k] == node_check->position){
                        check = 0;
                    }
                }
                numeri_sbarra++;

                if(check==1) {

                    node_info->counter_noposition++;
                    node_info->noposition = realloc(node_info->noposition,
                                                    node_info->counter_noposition * sizeof(int));
                    node_info->noposition[node_info->counter_noposition - 1] = node_check->position;
                }
            }
            temp = node_check->c;
            node_check = tree_successor_character_node(node_check);
            //TODO
            x++;

        }
        int min = 0;
        int esatto = -1;
        if(numeri_sbarra>0){

            esatto = numeri_piu+numeri_tarttino;
            min = esatto;
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

    if(correct_word==length_words){

        printf("ok\n");
        end_game = 1;
        return;
    }else{
        for (int i = 0; i < length_words; ++i) {
            putchar_unlocked(outpi[i]);
            //printf("%c", outpi[i]);
        }
        putchar_unlocked('\n');

        //printf("\n");
        printf("%d\n",number_word_filtated);

    }




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

int confronto_stringhe_heap(int pos1,int pos2,int len){
    int i = 0;
    while(i<len){
        if(dictionary[pos1 + i]>dictionary[pos2 + i]){
            return 1;
        } else if(dictionary[pos1 + i]<dictionary[pos2 + i]){
            return 0;
        }
        i++;
    }
    return 2;
}
void confronto() {
    int i = 0;


    struct information_node *node = NULL;
    if(information!=NULL && information->root!=NULL){
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
                        if(position_word_filtarted!=NULL){
                            free(position_word_filtarted);
                            position_word_filtarted=NULL;
                        }
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
                        if(new_position_filtrated!=NULL){
                            free(new_position_filtrated);
                            new_position_filtrated=NULL;
                        }
                        new_position_filtrated = malloc( sizeof(int) * new_number_word_filtrated);

                    }else{
                        new_position_filtrated = realloc(new_position_filtrated, sizeof(int) * new_number_word_filtrated);

                    }
                    new_position_filtrated[new_number_word_filtrated - 1] = position_word_filtarted[i];

                }
                i++;

            }
            free(position_word_filtarted);
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
    if(information!=NULL && information->root!=NULL){
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
            if(position_word_filtarted!=NULL){
                free(position_word_filtarted);
            }
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
        number_of_words_into_dictionary++;
        buffer++;
        if (buffer % 5 == 0) {
            dictionary = realloc(dictionary, (sizeof(char) * length_words * buffer));
        }
        //insert tree characters into tree words
        temp = getchar_unlocked();
    }
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

int parent(int i){
    return (i-1)/2;
}
int left(int i){
    return 2*i + 1;
}
int right(int i){
    return 2*i + 2;
}
void swap(int pos1, int pos2, int length){
    char temp[length];
    int i = 0;
    while (i<length){
        temp[i] = dictionary[pos1 + i];
        dictionary[pos1 + i] = dictionary[pos2 + i];
        dictionary[pos2 + i] = temp[i];
        i++;
    }
}

//0 first string is less
//1 second string is less
//2 equal
void max_heapify(int i){
    if(number_word_filtated!=0){
       int l = left(i);
       int r = right(i);
       int max = 0;
       if(l<heap_size && confronto_stringhe_heap(position_word_filtarted[l],position_word_filtarted[i],length_words)==1 ){
           max = l;
       } else{
           max = i;
       }
       if(r< heap_size && confronto_stringhe_heap(position_word_filtarted[r],position_word_filtarted[max],length_words)==1){
           max = r;
       }
       if(max!=i){
           swap(position_word_filtarted[i],position_word_filtarted[max],length_words);
           max_heapify(max);
       }
    } else{
        int l = left(i);
        int r = right(i);
        int max = 0;
        if(l<heap_size && confronto_stringhe_heap(l*length_words,i*length_words,length_words)==1 ){
            max = l;
        } else{
            max = i;
        }
        if(r< heap_size && confronto_stringhe_heap(r*length_words,max*length_words,length_words)==1){
            max = r;
        }
        if(max!=i){
            swap(i*length_words,max*length_words,length_words);
            max_heapify(max);
        }
    }
}
void build_max(){
    if(number_word_filtated!=0){
        heap_size = number_word_filtated;
        for(int i = number_word_filtated/2;i>=0;i--){
            max_heapify(i);
        }
    } else{
        heap_size = number_of_words_into_dictionary;
        for(int i = number_of_words_into_dictionary/2;i>=0;i--){
            max_heapify(i);
        }
    }

}

void heapSort(){
    if(number_word_filtated!=0){
       build_max();
        for(int i = number_word_filtated-1;i>=1;i--){
            swap(position_word_filtarted[0],position_word_filtarted[i],length_words);
            heap_size = heap_size-1;
            max_heapify(0);
        }
    } else{
        build_max();
        for(int i = number_of_words_into_dictionary-1;i>=1;i--){
            swap(0*length_words,i*length_words,length_words);
            heap_size = heap_size-1;
            max_heapify(0);
        }
    }
}

