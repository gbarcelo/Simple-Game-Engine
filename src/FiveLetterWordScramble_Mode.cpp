#include "FiveLetterWordScramble_Mode.hpp"
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <ctime>
// temporary include DEBUG
#include <iostream>
/* This class inherits from GameMode */

#define MINWORDLEN 3
#define MAXWORDLEN 5

FiveLetterWordScramble_Mode::FiveLetterWordScramble_Mode() {
  tick = TickType::Rounds;
  state = new FiveLetterWordScramble_State();
}

/****************************
 * SetUp methods:
 ****************************/

// Build data member "dictionary" from a file "dictoinary.db"
void FiveLetterWordScramble_Mode::loadDictionaryFromFile(){
  std::ifstream infile("data/dictionary.db");
  std::string line;
  while(std::getline(infile, line)){
    int flag = 0;
    line = line.substr(0, line.size()-1);
    for(int i = 0; line[i]!='\0';++i){
      int len = line.size();
      if(len < MINWORDLEN || len > MAXWORDLEN || (!(line[i]>='a'&& line[i]<='z'))){ //!(islower(line[i])||line[i]!='\0')){
        flag = 1;
        // DEBUG
        // std::cout << "Word discarded: " << line << std::endl;
        // std::cout << "conditions: " << len << line[i] <<std::endl;
        break;
      }
    }
    if (!flag){
      // line[line.size()] = '\0';
      dictionary.push_back(line);
      // DEBUG
      // std::cout << line << std::endl;
    }
  }

  // DEBUG
  std::cout << "Dictionary Built: ";
  std::cout << "Size = " << dictionary.size() << std::endl;

}

std::string FiveLetterWordScramble_Mode::randomWordSelector(){
  std::srand(std::time(nullptr));
  auto randIt = dictionary.begin();
  while (randIt == dictionary.begin() || (*randIt).size() < 5){
    // Display chosen word/size DEBUG
    // std::cout << "randIt size: " << (*randIt).size() << std::endl;
    if ((*randIt).size() == 0){ randIt = dictionary.begin();}
    std::advance(randIt, std::rand() % dictionary.size());
  }
  return *randIt;
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
  for(unsigned int i = 0; i < sortedWord.size(); i++){
    // erase that letter and add it to a vector of subwords
    temp = sortedWord;
    temp.erase(temp.begin()+i);
    subWords.push_back(temp);
    // for every letter in that subword
    for(unsigned int j = 0; j < temp.size(); j++){
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
      // and if word is not already in validAnswers
      if(std::find(validAnswers.begin(), validAnswers.end(), *it) == validAnswers.end()){
        // add to vector of valid answers
        // DEBUG
        // std::cout << "word: " << (*it) << " wordsize: " << (*it).size() << " lastchar: " << (*it)[(*it).size()] << std::endl;
        validAnswers.push_back(*it);
      }

    }
  }

  // std::cout << "Number of permutations: " << perms.size() << std::endl;
  // Print everything in the vector of permuations DEBUG
  // std::cout << "All valid answers:" << std::endl;
  // for(auto it = validAnswers.begin(); it != validAnswers.end(); it++){
  //   std::cout << *it << std::endl;
  // }
  // std::cout << "End setValidAnswer" << std::endl; // DEBUG
  return;
}

std::string FiveLetterWordScramble_Mode::wordScrambler(std::string s){
  std::cout << "  Before shuffle: " << s << std::endl;
  std::string temp = s;
  random_shuffle(temp.begin(), temp.end()-1);
  // print shuffle before/after DEBUG
  std::cout << "  After shuffle: " << temp << std::endl;
  return temp;
}

void FiveLetterWordScramble_Mode::displayGamePrompt(){
  int c;
    // while(1){
      std::cout << "" << std::endl;
      std::cout << "= = = = FIVE LETTER WORD-SCRAMBLE GAME = = = =" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "  Five letters will be provided to you; your goal is to come" << std::endl;
      std::cout << "  up with as many words as possible using those letters." << std::endl;
      std::cout << "  You will receive points for each correct answer. If you" << std::endl;
      std::cout << "  can find all the words, you get bonus points! However," << std::endl;
      std::cout << "  you can only make 5 incorrect guesses until its GAME OVER!" << std::endl;
      std::cout << "  Can you get all the answers?" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "Press any key to begin...";
      c = getchar();
      while(getchar() != '\n') {}
      if (c == 'q') {
        std::cout << "Returning to menu" << std::endl;
        return;
      }else {
        std::cout << "" << std::endl;
        std::cout << "LET'S GET SCRAMBLING!!!!" << std::endl;
        std::cout << "" << std::endl;
      }
    // }
}
/****************************
 * Main Game Loop methods:
 ****************************/
void FiveLetterWordScramble_Mode::validateUserGuess(std::string s){
  std::string entry = s;
  entry[entry.size()] = '\0';
  std::cout << "Entered: " << entry << std::endl; // DEBUG
  std::vector<std::string> v = state->getValidGuesses();
  // Check if s is in vector of valid guesses
  if(std::find(v.begin(), v.end(), entry) != v.end()){
    // "You already guessed that", return
    std::cout << "You have already received points for this answer!" << std::endl;
    return;
  } else if (std::find(validAnswers.begin(), validAnswers.end(), entry) != validAnswers.end()) {
    // Else if s is in vector of valid answers
      // add to vector of valid guesses
      state->pushValidGuess(entry);
      // increment user score
      state->incrementScore(entry.size());
      std::cout << "Score!" << std::endl;
  } else {
    // Else
      // Call incrementNumWrongAnswers
      state->incrementNumWrong();
      // "Not a valid word", return
      if (state->getNumWrong()<5){
        std::cout << "Not a valid word - you have " << 5-state->getNumWrong();
        std::cout << " tries remaining!" << std::endl;
        std::cout << "" << std::endl;
      }

  }

}


 /****************************
  * Session Summary methods:
  ****************************/


/****************************
 * Interface Override Methods:
 ****************************/
TickType FiveLetterWordScramble_Mode::getTickType() const {return tick;}
// void setTickType(TickType t) override {tick = t;}

void FiveLetterWordScramble_Mode::setUp() {
  loadDictionaryFromFile();
  state->setCurrWord(randomWordSelector());
  setValidAnswers(state->getCurrWord());
  state->setCurrWord(wordScrambler(state->getCurrWord()));
  // std::cout << "  After shuffler: " << state->getCurrWord() << std::endl; // DEBUG
  displayGamePrompt();
}

void FiveLetterWordScramble_Mode::updatePerTick() {
  std::string input;
  std::cout << "Letters: " << std::endl;
  std::cout << "" << std::endl;
  std::cout << "    " << state->getCurrWord() << std::endl;
  std::cout << "" << std::endl;
  std::cout << "My guess: ";
  getline(std::cin, input);
  input[input.size()] = '\0';
  validateUserGuess(input);

  state->incrementTick();
}

bool FiveLetterWordScramble_Mode::isEndGame() {
  if (state->getNumWrong() > 4){
    std::cout << "" << std::endl;
    std::cout << "You got 5 wrong! Game Over!" << std::endl;
    return 1;
  }
  if (state->getValidGuesses().size() >= validAnswers.size()) {
    state->incrementScore(42);
    std::cout << "" << std::endl;
    std::cout << "You found all the words! (20 bonus points)" << std::endl;
    return 1;
  }
  return 0;
}

void FiveLetterWordScramble_Mode::endSession() {
  //
  std::cout << "" << std::endl;
  std::cout << "Your final score: " << state->getScore() << std::endl;
  std::cout << "" << std::endl;
}
