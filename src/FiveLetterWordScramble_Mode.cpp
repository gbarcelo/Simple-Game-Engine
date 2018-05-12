#include "FiveLetterWordScramble_Mode.hpp"
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>
// temporary include DEBUG
#include <iostream>
/* This class inherits from GameMode */

#define MINWORDLEN 3
#define MAXWORDLEN 5

FiveLetterWordScramble_Mode::FiveLetterWordScramble_Mode() {
  tick = TickType::Rounds;
  // FiveLetterWordScramble_State *s = new FiveLetterWordScramble_State();
  // state = dynamic_cast<GameState*>(s);
  // state = std::move(s);
  state = new FiveLetterWordScramble_State();
}

// Build data member "dictionary" from a file "dictoinary.db"
void FiveLetterWordScramble_Mode::loadDictionaryFromFile(){
  std::ifstream infile("data/dictionary.db");
  std::string line;
  while(std::getline(infile, line)){
    // std::cout << line << std::endl;
    int i = 0;
    int flag = 0;
    for(int i = 0; line[i]!='\0';++i){
      int len = line.size();
      if(len < MINWORDLEN || len > MAXWORDLEN || (!(line[i]>='a'&& line[i]<='z'))){
        flag = 1;
        break;
      }
    }
    if (!flag){
      dictionary.push_back(line);
      // DEBUG
      std::cout << line << std::endl;
    }
  }

  // DEBUG
  std::cout << "Dictionary Built: ";
  std::cout << "Size = " << dictionary.size() << std::endl;

}

std::string FiveLetterWordScramble_Mode::randomWordSelector(){
  puts("Not yet implemented");
}

void FiveLetterWordScramble_Mode::setValidAnswers(std::string s){
  std::string unsortedWord, sortedWord, temp, temp2;
  std::vector<std::string> perms, subWords;
  unsortedWord = s;
  sortedWord = unsortedWord;

  // Sorts words because next_permutation is in order
  std::sort(sortedWord.begin(), sortedWord.end());

  // Places first word into vector
  subWords.push_back(sortedWord);
  // For every letter in the word,
  for(int i = 0; i < sortedWord.size(); i++){
    // erase that letter and add it to a vector of subwords
    temp = sortedWord;
    temp.erase(temp.begin()+i);
    subWords.push_back(temp);
    // for every letter in that subword
    for(int j = 0; j < temp.size(); j++){
      // erase that letter and also add it to the vector of subwords
      temp2 = temp;
      temp2.erase(temp2.begin()+j);
      subWords.push_back(temp2);
    }
  }

  // For every word in the subwords vector
  for(auto it = subWords.begin(); it != subWords.end(); it++){
    // Add that word into a vector of permutations
    perms.push_back(*it);
    // then find every permutation of that word and add that too
    while(std::next_permutation(it->begin(), it->end())){
      perms.push_back(*it);
    }
  }

  // For each word in vector of permutations
  for(auto it = perms.begin(); it!= perms.end(); it++){
    // if word exists in dictionary
    if(std::find(dictionary.begin(), dictionary.end(), *it) != dictionary.end()){
      // add to vector of valid answers
      validAnswers.push_back(*it);
    }

  }


  // std::cout << "Number of permutations: " << perms.size() << std::endl;

  // Print everything in the vector of permuations
  for(auto it = validAnswers.begin(); it != validAnswers.end(); it++){
    std::cout << *it << std::endl;
  }

  return;
}

/****************************
 * Interface Override Methods:
 ****************************/
TickType FiveLetterWordScramble_Mode::getTickType() const {return tick;}
// void setTickType(TickType t) override {tick = t;}

void FiveLetterWordScramble_Mode::setUp() {
  loadDictionaryFromFile();
}

void FiveLetterWordScramble_Mode::updatePerTick() {
  //
  state->incrementTick();
}

bool FiveLetterWordScramble_Mode::isEndGame() {
  if (state->getCurrentTick() > 100000000) {
    return 1;
  }
  return 0;
}

void FiveLetterWordScramble_Mode::endSession() {
  //
}
