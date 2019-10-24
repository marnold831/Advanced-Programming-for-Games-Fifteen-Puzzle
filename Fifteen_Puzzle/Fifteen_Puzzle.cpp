/* Author: Michael Arnold
   Last Edited: 24/10/19
   Description: This is the main cpp file and controller of the soluton
*/

#include <iostream>
#include "PuzzleFactory.h"
#include "OutputHandler.h"
#include <string>
#include <fstream>
#include <sstream>

char getCharacterInput(std::string message) {
	std::string userInput;
	char charInput = ' ';
	bool validInput = true;
	while (validInput) {
		std::cout << message << std::endl;
		std::getline(std::cin, userInput);
		validInput = (std::stringstream(userInput) >> charInput) ? false : true;

	}
	return charInput;
}
char validateYesNo(std::string message) {
	char userInput = ' ';
	while (true) {
		userInput = getCharacterInput(message);
		if (userInput == 'y' || userInput == 'Y' || userInput == 'n' || userInput == 'N')
			break;
	}
	return userInput;
}

void saveSolutions(int option, std::vector<Puzzle> puzzles) {
	char userinput = validateYesNo("Do you wish to save solution? [y/n]");
	if (userinput == 'Y' || userinput == 'y') {
		int partial = 0;
		
		std::cout << "Enter file name to save solutuions" << std::endl;
		std::string filename;
		std::getline(std::cin, filename);
		filename.append(".txt");
		if (option == 1) 
			OutputHandler::partialToFile(puzzles, filename, 2);
	
		if(option == 2)
			OutputHandler::partialToFile(puzzles, filename, 3);
		
		if(option == 3)
			OutputHandler::partialToFile(puzzles, filename, 4);
		
		if (option == 4)
			OutputHandler::printSolutionPuzzleToFile(puzzles, filename);

	}
}


void SolvePuzzle(std::vector<Puzzle> puzzles) {
	while (true) {
		char userinput = validateYesNo("Do you wish to solve the puzzles? [y/n]");
		if (userinput == 'n' || userinput == 'N')
			break;
		std::cout << "Select one of the following options" << std::endl;
		std::cout << "1. 2-partial" << std::endl;
		std::cout << "2. 3-Partial" << std::endl;
		std::cout << "3. 4-Partial" << std::endl;
		std::cout << "4. Complete Solution" << std::endl;
		

		int userOption = 0;
		int optionMin = 1;
		int optionMax = 4;
		std::cin >> userOption;

		while (std::cin.fail() || userOption < optionMin || userOption >optionMax) {
			std::cout << "You have not entered valid option! Please Enter a valid option!" << std::endl;
			std::cin.clear();
			std::cin.ignore(512, '\n');
			std::cin >> userOption;
		}
		if (userOption == 1) {
			for (auto it : puzzles) {
				std::cout << it;
				std::cout << "partial 2: " << it.calculateSolution(2) << std::endl;

			}
		}
		if (userOption == 2) {
			for (auto it : puzzles) {
				std::cout << it;
				if (it.getDimension() < 3)
					std::cout << "Puzzle to small for partial size" << std::endl;
				else {
					std::cout << "partial 3: " << it.calculateSolution(3) << std::endl;
				}
				
			}
		}
		if (userOption == 3) {
			for (auto it : puzzles) {
	
				std::cout << it;
				if (it.getDimension() < 4)
					std::cout << "Puzzle to small for partial size" << std::endl;
				else {
					std::cout << "partial 4: " << it.calculateSolution(4) << std::endl;
				}
				

			}
		}
		if (userOption == 4) {
			OutputHandler::printSolutionToScreen(puzzles);
		}
		saveSolutions(userOption, puzzles);
		char exit = validateYesNo("Do you wish to solve again? [y/n]");
		if (exit == 'n' || exit == 'N')
			break;
	}
}
void optionOne() {

	std::vector<Puzzle> puzzles;
	while (true) {
		int dimension, numberRange;
		std::cout << "Please enter the dimension you wish the puzzle to be! Mininum dimension 2" << std::endl;
		std::cin.clear();
		std::cin.ignore(512, '\n');
		std::cin >> dimension;
		while (std::cin.fail() || dimension < 2) {
			std::cout << "You have not entered valid dimension! Please Enter a valid dimension!" << std::endl;
			std::cin.clear();
			std::cin.ignore(512, '\n');
			std::cin >> dimension;
		}
		std::cout << "Please enter the maximum number you wish to have within the puzzle" << std::endl;
		std::cin.clear();
		std::cin.ignore(512, '\n');
		std::cin >> numberRange;
		while (std::cin.fail()) {
			std::cout << "You have not entered valid maximum! Please Enter a valid maximum!" << std::endl;
			std::cin.clear();
			std::cin.ignore(512, '\n');
			std::cin >> numberRange;
		}

		Puzzle p(PuzzleFactory::createManualPuzzle(dimension, numberRange));
		puzzles.push_back(p);

		char userinput = validateYesNo("Do you wish to create another puzzle? [y/n]");
		
		if (userinput == 'n' || userinput == 'N') {
			
			char saveInput = validateYesNo("Do you wish the save the current puzzle(s)? [y/n]");;
			
			if (saveInput == 'y' || saveInput == 'Y') {
				std::cout << "Enter the file name you wish to save to" << std::endl;
		
				std::string filename;
				std::getline(std::cin, filename);
				
				filename.append(".txt");
				OutputHandler::printConfigurationToFile(puzzles, filename);
			}
			SolvePuzzle(puzzles);
			break;
		}
		
	}
}
void optionTwo() {
	std::cout << "Please enter the number of puzzles you wish to create" << std::endl;
	int numberPuzzles = 0;
	std::cin >> numberPuzzles;
	while (std::cin.fail() || numberPuzzles < 1) {
		std::cout << "You have not entered valid number! Please Enter a valid option!" << std::endl;
		std::cin.clear();
		std::cin.ignore(512, '\n');
		std::cin >> numberPuzzles;
	}
	std::vector<Puzzle> puzzles;
	for (int i = 0; i < numberPuzzles; i++) {
		int dimension, numberRange;
		std::cout << "Please enter the dimension you wish the puzzle to be! Mininum dimension 2" << std::endl;
		std::cin.clear();
		std::cin.ignore(512, '\n');
		std::cin >> dimension;
		while (std::cin.fail() || dimension < 2) {
			std::cout << "You have not entered valid dimension! Please Enter a valid dimension!" << std::endl;
			std::cin.clear();
			std::cin.ignore(512, '\n');
			std::cin >> dimension;
		}
		std::cout << "Please enter the maximum number you wish to have within the puzzle" << std::endl;
		std::cin.clear();
		std::cin.ignore(512, '\n');
		std::cin >> numberRange;
		while (std::cin.fail()) {
			std::cout << "You have not entered valid maximum! Please Enter a valid maximum!" << std::endl;
			std::cin.clear();
			std::cin.ignore(512, '\n');
			std::cin >> numberRange;
		}
		Puzzle p(PuzzleFactory::createRandomPuzzle(dimension, numberRange));
		puzzles.push_back(p);
	}
	char saveInput = validateYesNo("Do you wish the save the current puzzle(s)? [y/n]");;

	if (saveInput == 'y' || saveInput == 'Y') {
		std::cout << "Enter the file name you wish to save to" << std::endl;

		std::string filename;
		std::getline(std::cin, filename);

		filename.append(".txt");
		OutputHandler::printConfigurationToFile(puzzles, filename);
	}
	SolvePuzzle(puzzles);
	
	
}
void optionThree() {
	while (true)
	{
		std::cout << "Enter the configurations file" << std::endl;
		std::string filename;
		while (filename.empty()) {
			std::getline(std::cin, filename);
		}

		filename.append(".txt");
		std::vector<Puzzle> puzzles;
		PuzzleFactory::ReadConfigurationsFromFile(filename, puzzles);
		if (puzzles.size() < 1) {
			char saveInput = validateYesNo("File was empty, Do you wish to try again? [y/n]");

			if (saveInput == 'N' || saveInput == 'N')
				break;
		}
		else {

			SolvePuzzle(puzzles);
			char saveInput = validateYesNo("Do you wish to read another file? [y/n]");
			if (saveInput == 'N' || saveInput == 'N')
				break;
		}

	}
	
}
void optionFour() {
	exit(0);
}
int main()
{
	int optionMin = 1;
	int optionMax = 4;
	while (true) {
		std::cout << "Chose and option with the relevant number!" << std::endl;
		std::cout << "1. Manual Puzzle Creation" << std::endl;
		std::cout << "2. Random Puzzle Creation" << std::endl;
		std::cout << "3. Read from file Creation" << std::endl;
		std::cout << "4. Exit program" << std::endl;

		int userOption = 0;
		std::cin >> userOption;

		while (std::cin.fail() || userOption < optionMin || userOption >optionMax) {
			std::cout << "You have not entered valid option! Please Enter a valid option!" << std::endl;
			std::cin.clear();
			std::cin.ignore(512, '\n');
			std::cin >> userOption;
		}
		if (userOption == 1) {
			optionOne();
		}
		if (userOption == 2) {
			optionTwo();
		}
		if (userOption == 3) {
			optionThree();
		}
		if (userOption == 4) {
			optionFour();
		}
	}
	
	
	
}

