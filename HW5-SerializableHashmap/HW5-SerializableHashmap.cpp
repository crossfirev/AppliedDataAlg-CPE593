#include <stdint.h>

class SerializableHashMap
{
private:
    char* words;

    struct Node
    {
        uint32_t key;   // offset into words, start of the word
        int val;
        uint32_t next;  // offset into nodes table
    };

    Node** table;
    Node* nodes;
public:

};

int main()
{
    // 1. read a dictionary file
    SerializableHashMap m("dict.txt");

    // read in each word and add to the dictionary

    // store all the strings into words
    // words = "ahh,apple,dove,dictionary,hello,in,testing,words

    // table = {0, 0, 0, 0, 0, 0, 0, 0}
    // inserting nodes into table
    // table = {0, 2, 0, 3, 0, 1, 0, 4}
    // nodes = {zero is empty} {ahh, 1, 0}, {apple, 2, 0}, {dob, 3, 0}


    // Writing out your dictionary:
    //  write out all words [how ever many bytes 'words' is]
        // ahh,apple,...
    //  write out all nodes offset (start of word),
    //  write out table.

    // wtf
}