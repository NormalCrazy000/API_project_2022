while(node_check==NULL){
char temp = node_check->c;
node_search = tree_search_character_node(word_to_search->root,temp);
while (temp!=node_check->c){
if(node_search==NULL){
outpi[node_check->position] = '/';
node_check->correct = 0;
temp = node_check->c;
node_check = tree_successor_character_node(node_check);
}else{
if(node_check->position==node_search->position){
outpi[node_check->position] = '+';
node_check->correct = 1;
temp = node_check->c;
node_check = tree_successor_character_node(node_check);
node_search = tree_successor_character_node(node_search);
}else if(node_check->position>node_search->position){
outpi[node_check->position] = '+';
node_check->correct = 1;
temp = node_check->c;
node_check = tree_successor_character_node(node_check);
node_search = tree_successor_character_node(node_search);
}
}
}
}