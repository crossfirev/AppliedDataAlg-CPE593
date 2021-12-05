/**
 * @file    Dictionary.cpp
 * @author  Matthew Lepis
 * @brief   Reads in a file that contains a dictionary, stores that in a linear chained hash table and/or a trie, then finds non-words within another given file.
 * @version 0.1
 * @date 2021-11-21
 */

// Include Statements
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm> // for string.erase
#include <unordered_map> // for using SOLELY in my Trie implementation, I've implemented my own hash table class below.
// Namespace Statements
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::unordered_map;

int findNextPrime(int n);
bool isPrime(int n);
string& removeChar(string &str);

// Classes
class Node
{
public:
	string word;
	Node* next;

	Node(string inWord)
	{
		word = inWord;
		next = nullptr;
	}
};
class LinkedList
{
public:
	Node* head;
	int size;

	LinkedList()
	{
		head = nullptr;
		size = 0;
	}
	LinkedList(const LinkedList &old_obj)
	{
		head = old_obj.head;
		size = old_obj.size;
	}
	void addEnd(string inWord)
	{
		if(size == 0)
			head = new Node(inWord);
		else
		{
			Node* i = head;
			while(i->next != nullptr)
				i = i->next;
			i->next = new Node(inWord);
		}
		
		size++;
	}
	void addStart(string inWord)
	{
		if(size == 0)
			head = new Node(inWord);
		else
		{
			Node* temp = new Node(inWord);
			temp->next = head;
			head = temp;
		}
		
		size++;
	}
	void displayList()
	{
		int j = 0;
		for(Node* i = head; i != nullptr; i = i->next)
		{
			cout << j << ": \"" << i->word << "\"\n";
			j++;
		}
	}
};
class Hash
{
private:
	unsigned long long numBuckets;
	LinkedList* table;

public:
	Hash(unsigned long long numWords)
	{
		cout << "\tWord Count: " << numWords;

		numBuckets = findNextPrime((int)((double)numWords / 0.7));
		cout << "\n\tHash Table Size: " << numBuckets << "\n";

		table = new LinkedList[numBuckets];
	}

	unsigned long long hashFunction(string const &key)
	{
		long long sum = 0;
		int i = 1;
		for(char c : key)
		{
			sum += pow((c - 'a' + 1), (double)i);
			i++;
		}
		long long hashVal = sum % numBuckets;
		if (hashVal >= numBuckets)
			cout << "DANGERDANGERDANGERDANGERDANGERDANGERDANGERDANGERDANGERDANGER";
		return hashVal;
	}

	void insertItem(string key)
	{
		unsigned long long index = hashFunction(key);
		//cout << index << '\n';
		table[index].addEnd(key);
	}
	void displayHashHistogram()
	{
		int collisionHistogram[9] = {0};

		for (unsigned long long i = 0; i < numBuckets; i++)
		{	
			int collisionCount = 0;
			Node* j = table[i].head;

			//if (table[i].head != nullptr)
			//	cout << i << ": ";
				
			while(j != nullptr)
			{
				if (j->next == nullptr); 	// No Collision
					//cout << j->word;
				else 						// Had a Collision
				{
					//cout << j->word << " --> ";
					collisionCount++;
				}
					
				j = j->next;
			}
			//if (table[i].head != nullptr)
			//	cout << "\n";
			
			if(collisionCount == 0)
				collisionHistogram[0]++;
			else if(collisionCount == 1)
				collisionHistogram[1]++;
			else if(collisionCount == 2)
				collisionHistogram[2]++;
			else if(collisionCount == 3)
				collisionHistogram[3]++;
			else if(collisionCount == 4)
				collisionHistogram[4]++;
			else if(collisionCount == 5)
				collisionHistogram[5]++;
			else if(collisionCount == 6)
				collisionHistogram[6]++;
			else if(collisionCount == 7)
				collisionHistogram[7]++;
			else if(collisionCount == 8)
				collisionHistogram[8]++;
			else if(collisionCount >= 9)
				collisionHistogram[9]++;
		}
		
		cout << "\nDictionary Collision Histogram:\n";
		for(int i = 0; i < 10; i++)
		{
			cout << "\t" << i << ": " << collisionHistogram[i] << "\n";
		}
		
	}
	bool find(string key)
	{
		unsigned long long index = hashFunction(key);
		//cout << "Word: " << key << "\nHash Value: " << index << "\n";
		if(table[index].head != nullptr)
		{
			Node* i = table[index].head;
			while(i->next != nullptr)
			{
				if(i->word == key)
					return true;
				i = i->next;
			}
			if(i != nullptr && i->word == key)
				return true;
		}
		return false;
	}
};
void spaceParser(string &str, LinkedList &wordList);


struct Trie
{
    bool isCompleteWord;
    unordered_map<char, Trie*> children;
}; 
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->isCompleteWord = false;
    return node;
} 
void trieInsert(Trie*& root, const string& str)
{
  
    // If root is null
    if (root == nullptr)
        root = getNewTrieNode();
  
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
  
        // Make a new node if there is no path
        if (temp->children.find(x) == temp->children.end())
            temp->children[x] = getNewTrieNode();
  
        temp = temp->children[x];
    }
  
    // Mark end of word and store the meaning
    temp->isCompleteWord = true;
}
bool trieFind(Trie* root, const string& word)
{
  
    // If root is null i.e. the dictionary is empty
    if (root == nullptr)
        return false;
  
    Trie* temp = root;
  
    // Search a word in the Trie
    for (int i = 0; i < word.length(); i++)
	{
        temp = temp->children[word[i]];
        if (temp == nullptr)
            return false;
    }
  
    // If it is the end of a valid word stored, the word was found, return true.
    if (temp->isCompleteWord)
        return true;
    return false;
}

int main()
{
	ifstream fileDict ("Input_Files/dict.txt");

	// Finding length of file
	cout << "\nCounting number of words in Dictionary...\n";
	int fileSize = 0;
	string temp;
	while(fileDict)
	{
		getline(fileDict, temp);
		fileSize++;
	}
	fileDict.clear();
	fileDict.seekg(0);
	cout << "Done.\n";
	//

	// Grabbing words from dict.txt
	LinkedList dictWords;
	while(fileDict)
	{
		getline(fileDict, temp);
		dictWords.addStart(temp);
	}
	fileDict.clear();
	fileDict.seekg(0);
	//

	// Creating Hash Table and fills it.
	Hash dictionary(fileSize);
	for(Node* i = dictWords.head; i != nullptr; i = i->next)
		dictionary.insertItem(i->word);
	//

	// Printing Histogram of Hash Collisions
	dictionary.displayHashHistogram();
	//

	// Testing to see if the whole dictionary is in the Hash Map
	cout << "\nTesting that all words from source file are in the Hash Map...\n\t\t\t.\n\t\t\t.\n\t\t\t.\n";
	while(fileDict)
	{
		getline(fileDict, temp);
		
		if(!dictionary.find(temp))
		{
			cout << "ERROR\n";
			return 1;
		}
	}
	cout << "\t  All source file words found!\n\n";
	//

	fileDict.close();

	// USER INPUT, FOR SPELL CHECKING
	string fileName;
	cout << "-------------------------------------------------\n";
	cout << "|    Select a text document to spell check\t|\n";
	cout << "-------------------------------------------------\n";
	cout << "|\t1. 	\"aliceinwonderland.txt\"\t\t|\n";
	cout << "|\t2. 	\"modestproposal.txt\"\t\t|\n";
	cout << "|\t3. 	\"prideandprejudice.txt\"\t\t|\n";
	cout << "| Or, type the name of your file instead of a # |\n"; 
	cout << "-------------------------------------------------\n";
	cout << "Input: ";
	cin >> fileName;
	cout << "\n";

	if(atoi(fileName.c_str()) == 1)
		fileName = "aliceinwonderland.txt";
	else if (atoi(fileName.c_str()) == 2)
		fileName = "modestproposal.txt";
	else if (atoi(fileName.c_str()) == 3)
		fileName = "prideandprejudice.txt";
	string fileNameTemp = "Input_Files/";
	fileName = fileNameTemp.append(fileName);
	//

	// Checking file for misspelled words
	cout << "Checking " << "\"" << fileName << "\" for misspelled words.\n";
	ifstream fileToCheck (fileName);

	// Reading in file lines to linked list
	LinkedList fileToCheckLINES;
	if(fileToCheck)
	{
		while(fileToCheck)
		{
			getline(fileToCheck, temp);
			fileToCheckLINES.addStart(temp);
		}
	}
	else
	{
		cout << "ERROR: " << fileName << " File missing.\n";
		return 1;
	}
	cout << ".";
	fileToCheck.close();
	//

	// Cleaning the lines
		// Making lines all lowercase AND Removing punctuation/digits from lines
	for(Node* i = fileToCheckLINES.head; i != nullptr; i = i->next)
	{
		for(int j = 0; j < i->word.size(); j++)
			i->word[j] = (char)(tolower((unsigned char)(i->word[j])));
		i->word = removeChar(i->word);
	}
	cout << ".";
	//

	// Parsing the clean lines by " ", and putting these strings into a linked list
	LinkedList wordList;
	for(Node* i = fileToCheckLINES.head; i != nullptr; i = i->next)
		spaceParser(i->word, wordList);
	cout << ".";
	//
	
	// Checking for misspelled words by finding a word from 'wordlist' in the hashtable dictionary, 'dictionary'
	LinkedList misspelledWordsHash;
	for(Node* i = wordList.head; i != nullptr; i = i->next)
		if(!dictionary.find(i->word))
			misspelledWordsHash.addStart(i->word);
	cout << ".";
	//

	// Printing to file, "outputHash.txt"
	ofstream outputFileHash;
	outputFileHash.open("Output_Files/outputHash.txt");
	for(Node* i = misspelledWordsHash.head; i != nullptr; i = i->next)
		outputFileHash << i->word << "\n";
	outputFileHash.close();
	cout << ".";
	//

	cout << "\nDone. You will find your misspelled words in \"outputHash.txt\".\n\n";
	//

//
//

	// Creating Trie, inserting words from 'dict.txt'
	cout << "Creating Trie...\n";
	Trie* root = nullptr;
	
	// Filling Trie with words from 'dictWords'
	for(Node* i = dictWords.head; i != nullptr; i = i->next)
		trieInsert(root, i->word);
	//

	// Checking for misspelled words by finding a word from 'wordlist' in the Trie dictionary
	LinkedList misspelledWordsTrie;
	for(Node* i = wordList.head; i != nullptr; i = i->next)
		if(!trieFind(root, i->word))
			misspelledWordsTrie.addStart(i->word);
	cout << ".";
	//

	// Printing to file, "outputTrie.txt"
	ofstream outputFileTrie;
	outputFileTrie.open("Output_Files/outputTrie.txt");
	for(Node* i = misspelledWordsTrie.head; i != nullptr; i = i->next)
		outputFileTrie << i->word << "\n";
	outputFileTrie.close();
	cout << "....";
	//

	cout << "\nDone. You will find your misspelled words in \"outputTrie.txt\".\n\n";

	return 0;
}

//given a number n, find the next closest prime number above n
int findNextPrime(int n)
{
    int nextPrime = n;
    bool found = false;

    //loop continuously until isPrime returns true for a number above n
    while (!found)
    {
        nextPrime++;
        if (isPrime(nextPrime))
            found = true;
    }

    return nextPrime;
}
//given a number n, determine if it is prime
bool isPrime(int n)
{
    //loop from 2 to n/2 to check for factors
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)     //found a factor that isn't 1 or n, therefore not prime
            return false;
    }

    return true;
}
//given a string str, and a char array c; remove all instance of the chars in the char array from str.
string& removeChar(string &str) 
{
	for (int i = 0, len = str.size(); i < len; i++)
	{
		if(ispunct(str[i]) || isdigit(str[i]))
		{
			str.erase(i--, 1);
            len = str.size();
		}
	}
	return str;
}
void spaceParser(string &str, LinkedList &wordList)
{
	int len = str.size();
	// Replaces consecutive spaces with 1 space
	for (int i = 1, len = str.size(); i < len; i++)
	{
		if(str[i-1] == ' ' && str[i] == ' ')
		{
			str.erase(i--, 1);
            len = str.size();
		}
	}

	// Adds words to a linked list, delimited by spaces
	int i = 0;
	int j = 0;
	while(i < str.size())
	{
		if(str[i] != ' ')
		{
			i++;
		}
		else
		{
			wordList.addStart(str.substr(j,i-j));
			i++;
			j = i;
		}
	}
}
