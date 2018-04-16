#include "privateLib.hpp"

std::string input::getString (std::string & inputPrompt, const std::string & validChars, const std::string & invalidMsg)
{
		std::string temp = "";
		std::cout << std::endl << inputPrompt;
		std::cin  >> temp;
	while(!parse::validateInput(temp,validChars)){
		temp = "";
		std::cout << std::endl << invalidMsg << std::endl;
		std::cout << inputPrompt;
		std::cin  >> temp;
	}
	return temp;
}

char input::getChar(std::string & inputPrompt, const std::string & validChars, const std::string & invalidMsg)
{
	std::string temp = "";
		std::cout << std::endl << inputPrompt;
		std::cin  >> temp;
	while(!parse::validateInput(temp,validChars) || temp.length() !=1){
		temp = "";
		std::cout << std::endl << invalidMsg << std::endl;
		std::cout << inputPrompt;
		std::cin  >> temp;
	}
	return temp.at(0);
}

int input::getInt (std::string & inputPrompt, const std::string & validChars,  const std::string & invalidMsg)
{
        std::string temp = "";
		std::cout << std::endl << inputPrompt;
		std::cin  >> temp;
		bool neg = false;
		bool overflow = false;
			while(!parse::validateInput(temp,validChars) || (!parse::validNegative(temp) && parse::containsChar(temp,'-'))){
				temp = "";
				neg = parse::containsChar(temp, '-') && !parse::validNegative(temp);
				overflow = !(atol(temp.c_str()) <=MAX_SIGNED_INTEGER && atol(temp.c_str())>= MIN_INTEGER);
				if(neg || overflow)
					{
					if(neg)
						{
							std::cout << std::endl << "Error! Invalid negative!" << std::endl;
							neg = false;
						}
					if(overflow)
						{
							std::cout << std::endl << "Error! Number entered caused an integer overflow!";
							overflow = false;
						}
					}
					
				else	
				std::cout << std::endl << invalidMsg << std::endl;
				std::cout << inputPrompt;
				std::cin  >> temp;
					if(parse::validateInput(temp,validChars) && !(atol(temp.c_str()) <=MAX_SIGNED_INTEGER && atol(temp.c_str())>= MIN_INTEGER))
					{
						temp = "h";
						overflow = true;
					}
			}
		return atoi(temp.c_str());
}
        
unsigned int input::getUnsignedInt(std::string& inputPrompt, const std::string& validChars, const std::string& invalidMsg)
{
	 	std::string temp = "";
		std::cout << std::endl << inputPrompt;
		std::cin  >> temp;
		bool overflow = false;
		while(!parse::validateInput(temp,validChars) || parse::containsChar(temp,'-')){
				temp = "";
				overflow = !(atol(temp.c_str()) <=MAX_UNSIGNED_INTEGER && atol(temp.c_str())>= 0);
				if(overflow)
					{
						std::cout << std::endl << "Error! Number entered caused an integer overflow!";
						overflow = false;
					}
				else
				std::cout << std::endl << invalidMsg << std::endl;
				std::cout << inputPrompt;
				std::cin  >> temp;
					if(parse::validateInput(temp,validChars) && !(atol(temp.c_str()) <=MAX_UNSIGNED_INTEGER && atol(temp.c_str())>= 0))
					{
						temp = "h";
						overflow = true;
					}					
			}
		return (unsigned int)atol(temp.c_str());
        }
        
double input::getDouble (std::string & inputPrompt, const std::string & validChars, const std::string & invalidMsg)
{
        	std::string temp = "";
			std::cout << std::endl << inputPrompt;
			std::cin  >> temp;
			bool point = false;
			bool neg = false;
			while(!parse::validateInput(temp,validChars) || parse::countChar(temp,'.') > 1 || (!parse::validNegative(temp) && parse::containsChar(temp,'-')))
			{
			neg = parse::containsChar(temp, '-') && !parse::validNegative(temp);
			point =  parse::containsChar(temp,'.') && parse::countChar(temp,'.') > 1;
				if(point || neg)
				{
					if(point)
					{
						std::cout << std::endl << "Error! More than 1 decimal point in number!" << std::endl;
						point = false;
					}
					if(neg)
					{
						std::cout << std::endl << "Error! Invalid negative!" << std::endl;
						neg = false;
					}
				}
				else
				std::cout << std::endl << invalidMsg << std::endl;
				std::cout << inputPrompt;
				temp = "";
				std::cin  >> temp;

			}
		return static_cast<double>(atof(temp.c_str()));
        }
        
float input::getFloat (std::string & inputPrompt,const std::string & validChars, const std::string & invalidMsg)
{
        	std::string temp = "";
			std::cout << std::endl << inputPrompt;
			std::cin  >> temp;
			bool point = false;
			bool neg = false;
			while(!parse::validateInput(temp,validChars) || parse::countChar(temp,'.') > 1 || (!parse::validNegative(temp) && parse::containsChar(temp,'-')))
			{
				neg = parse::containsChar(temp, '-') && !parse::validNegative(temp);
				point =  parse::containsChar(temp,'.') && parse::countChar(temp,'.') > 1;
				temp = "";
				if(point || neg)
				{
					if(point)
					{
						std::cout << std::endl << "Error! More than 1 decimal point in number!" << std::endl;
						point = false;
					}
					if(neg)
					{
						std::cout << std::endl << "Error! Invalid negative!" << std::endl;
						neg = false;
					}
				}
				else
				std::cout << std::endl << invalidMsg << std::endl;
				std::cout << inputPrompt;
				std::cin  >> temp;
			}
		return atof(temp.c_str());
        }
        
long input::getLong (std::string & inputPrompt, const std::string & validChars, const std::string & invalidMsg)
{
        	std::string temp = "";
			std::cout << std::endl << inputPrompt;
			std::cin  >> temp;
			bool neg =false;
			while(!parse::validateInput(temp,validChars) || (!parse::validNegative(temp) && parse::containsChar(temp,'-'))){
				neg = parse::containsChar(temp, '-') && !parse::validNegative(temp);
					if(neg)
					{
						std::cout << std::endl << "Error! Invalid negative!" << std::endl;
						neg = false;
					}
					temp = "";
				std::cout << std::endl << invalidMsg << std::endl;
				std::cout << inputPrompt;
				std::cin  >> temp;
			}
			
		return atol(temp.c_str());
        }
        
int input::getRangeInt(std::string& inputPrompt, int low, int high)
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
			while(!parse::validateInput(temp, DEFAULT_VALID_INPUT_INT) || !(low <= atoi(temp.c_str()) && high >= atoi(temp.c_str()))){
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
	while(!(parse::validateInput(temp,"123456789")) || !parse::validateInputRange(1,choices.size(), atoi(temp.c_str())))
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
	return atoi(temp.c_str())-1;
}

bool parse::validateInput (std::string & str, const std::string & validChars)
{
	return str.find_first_not_of(validChars) == std::string::npos;
}

bool parse::validateInputRange(int low, int high, int input)
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

int parse::countChar(std::string& string, char c)
{
  int count = 0;

  for (int i = 0; i < string.size(); i++)
    if (string[i] == c) count++;

  return count;
}

bool parse::containsChar(std::string& string, char c)
{
	return countChar(string,c) != 0;
}

bool parse::validNegative(std::string& number)
{
	return number[0] == '-' && countChar(number, '-') == 1;
}
