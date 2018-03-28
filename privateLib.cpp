#include "privateLib.hpp"

std::string input::validateInputString (std::string & inputPrompt, const std::string & validChars, const std::string & invalidMsg)
{
		std::string temp = "";
		std::cout << std::endl << inputPrompt;
		std::cin  >> temp;
	while(!validateInput(temp,validChars)){
		temp = "";
		std::cout << std::endl << invalidMsg << std::endl;
		std::cout << inputPrompt;
		std::cin  >> temp;
	}
	return temp;
}

char input::validateInputChar(std::string & inputPrompt, const std::string & validChars, const std::string & invalidMsg)
{
	std::string temp = "";
		std::cout << std::endl << inputPrompt;
		std::cin  >> temp;
	while(!validateInput(temp,validChars) || temp.length() !=1){
		temp = "";
		std::cout << std::endl << invalidMsg << std::endl;
		std::cout << inputPrompt;
		std::cin  >> temp;
	}
	return temp.at(0);
}

int input::validateInputInt (std::string & inputPrompt, const std::string & validChars,  const std::string & invalidMsg)
        {
        std::string temp = "";
		std::cout << std::endl << inputPrompt;
		std::cin  >> temp;
			while(!validateInput(temp,validChars)){
				temp = "";
				std::cout << std::endl << invalidMsg << std::endl;
				std::cout << inputPrompt;
				std::cin  >> temp;
					if(validateInput(temp,validChars) && !(atol(temp.c_str()) <=MAX_SIGNED_INTEGER && atol(temp.c_str())>= MIN_INTEGER))
						temp = "h";
			}
		return atoi(temp.c_str());
        }
        
double input::validateInputDouble (std::string & inputPrompt, const std::string & validChars, const std::string & invalidMsg)
        {
        	std::string temp = "";
			std::cout << std::endl << inputPrompt;
			std::cin  >> temp;
			while(!validateInput(temp,validChars)){
				temp = "";
				std::cout << std::endl << invalidMsg << std::endl;
				std::cout << inputPrompt;
				std::cin  >> temp;
			}
		return static_cast<double>(atof(temp.c_str()));
        }
        
float input::validateInputFloat (std::string & inputPrompt,const std::string & validChars, const std::string & invalidMsg)
        {
        	std::string temp = "";
			std::cout << std::endl << inputPrompt;
			std::cin  >> temp;
			while(!validateInput(temp,validChars)){
				temp = "";
				std::cout << std::endl << invalidMsg << std::endl;
				std::cout << inputPrompt;
				std::cin  >> temp;
			}
		return atof(temp.c_str());
        }
        
long input::validateInputLong (std::string & inputPrompt, const std::string & validChars, const std::string & invalidMsg)
        {
        	std::string temp = "";
			std::cout << std::endl << inputPrompt;
			std::cin  >> temp;
			while(!validateInput(temp,validChars)){
				temp = "";
				std::cout << std::endl << invalidMsg << std::endl;
				std::cout << inputPrompt;
				std::cin  >> temp;
			}
		return atol(temp.c_str());
        }
        
int input::validateRangeInt(std::string& inputPrompt, int low, int high)
{
		std::string temp = "";
			std::cout << std::endl << inputPrompt;
			std::cin  >> temp;
			if(low>high)
			{
				int temp = low;
				low = high;
				high = temp;
			}
			while(!validateInput(temp, DEFAULT_VALID_INPUT_INT) || !(low <= atoi(temp.c_str()) && high >= atoi(temp.c_str()))){
				temp = "";
				std::cout << std::endl << DEFAULT_INVALID_STRING << "Please enter a number between " << low << " and " << high << std::endl;
				std::cout << inputPrompt;
				std::cin  >> temp;
			}
		return atoi(temp.c_str());
}

std::string input::intToString (int i[], int length)
{
	std::string returnstring = "";
	for (int j=0; j < length; j++)
	{	
		returnstring += toString(i[j]);
		returnstring += ", ";
	}
	return returnstring;
}


template<typename ValueType> std::string input::toString(ValueType v)
{
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

int input::menu (std::vector<std::string> choices, std::string& inputMessage)
{
	std::cout <<"\n" + inputMessage << std::endl;
		for(int i = 0 ; i < choices.size() ; i++)
	{
		std::cout << toString(i+1) + ".) " + choices.at(i) +"\n";
	}
	std::string temp = "";
	std::cin >> temp;
	while(!(validateInput(temp,"123456789")) || !validateInputRange(1,choices.size(), atoi(temp.c_str())))
	{
		std::cout << std::endl << DEFAULT_INVALID_STRING << "Please enter a number between 1 and " << toString(choices.size()) << std::endl;
		std::cout <<"\n" + inputMessage << std::endl;
		for(int i = 0 ; i < choices.size() ; i++)
	{
		std::cout << toString(i+1) + ".) " + choices.at(i) +"\n";
	}
	temp = "";
	std::cin  >> temp;
	}
	return atoi(temp.c_str());
}

bool input::validateInput (std::string & str, const std::string & validChars)
{
	return str.find_first_not_of(validChars) == std::string::npos;
}

bool input::validateInputRange(int low, int high, int input)
{
	if(low > high)
	{
		int temp = low;
		low = high;
		high = low;
	}
	return low<=input && high >= input;
}


std::vector<std::string> parse::parseFileText(std::ifstream file)
{
	std::vector<std::string> vect;
	std::string temp;
	
	while(file >> temp)
		vect.push_back(temp);
	return vect;
}

