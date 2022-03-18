#include "wordCollection.h"

std::string getRandomWord() //todo: convert to constructor and make a function that returns radon, and one that returns the whole deque.
{
	
	srand((unsigned int)time(NULL)); //cast to unsigned int since I got memory leak warnings.

	//used deque as container since the use of the index when randomizing and the push back for adding in the while loop.
	//the deque container could add all the words at almost twice the speed compared to a vector (30ms avarage compared to 55ms)
	//getting a random word was a bit slower, about 0.0015ms when using deque compared to vector (total 0.0070ms)
	//I think it works this way since the deque doesn't have to move around and keep the index connected in memory like the some other containers.
	//If I wanted to search the container if the guessed word is in the deck I would switch to a vector since indexing is much faster.
	
	static std::deque<std::string> s_words;

	if (s_words.size() == 0)
	{
		std::ifstream file("words.txt");
		std::string tempString;
		while (std::getline(file, tempString))
			s_words.push_back(tempString);
	}
	if (s_words.size() != 0)
	{
		std::string randomizedWord{};
		randomizedWord = s_words[rand() % s_words.size()];
		return randomizedWord;
	}
	else
	{
		system("cls");
		std::cerr << "Words.txt didn't load correctly. Please check your project folder.\n";
		system("pause");
		exit(EXIT_FAILURE); //exits the program early to avoid crashing later in the gameLoop if .txt failed.
	}
}
