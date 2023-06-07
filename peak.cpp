//ARAM ISIKBAY

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//Input integers from filename into the vector, catch and report errors
void getInput(std::vector<int>& inputList) {
	//Open file
	std::ifstream inputStream;
	std::string fileName = "peak.txt";
	inputStream.open(fileName);
	//Catch if file cannot be located:
	if (inputStream.fail()) {
		std::cout << "Unable to locate \"" << fileName << "\"" << std::endl;
		exit(1);
	}
	//Catch if file contains any non-integer (non-valid) input
	std::string str;
	while (std::getline(inputStream, str)) {
		try {
			int num = std::stoi(str);
			//Push input to vector
			inputList.push_back(num);
		}
		catch (...) {
			std::cout << "Non-integer data \"" << str << "\" is invalid." << std::endl;
			exit(1);
		}
	}
	inputStream.close();
}

//Returns index of the peak of numberList
int search(int lBound, int rBound, std::vector<int> numberList) {
	//If the bounds of the search are adjacent to each other, the peak has been found
	//This is also the base case of having one element: when rBound = 1 & lBound = 0, the peak is numberList[0] (the only element)
	if (rBound - lBound <= 1) {
		return rBound - 1;
	}
	//Compute middle index
	int mid = lBound + (rBound - lBound) / 2;
	//Compare middle element and it's previous element. Change the bound according to the result (WORK UNIT)
	if (numberList[mid] - numberList[mid - 1] > 0) {
		//If mid is greater than it's previous element, the peak must be mid itself or on the right side of mid
		lBound = mid;
	}
	else {
		//If mid is less than it's previous element, the peak must be on the left side of mid
		rBound = mid;
	}
	//If the peak hasn't been found, rerun the function on the half decided above
	return search(lBound, rBound, numberList);
}

int main() {
	//Input to vector
	std::vector<int> inputList;
	getInput(inputList);
	//Initialization
	int lBound = 0;
	int rBound = inputList.size();
	//Determine peak
	int pIndex = search(lBound, rBound, inputList);
	std::cout << "Peak of " << inputList[pIndex] << " found at index " << pIndex << "." << std::endl;
	return(0);
}