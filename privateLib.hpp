#ifndef PRIVATELIB_HPP
#define PRIVATELIB_HPP

#include <iostream>  
#include <string> 
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>

#define DEFAULT_VALID_INPUT_FLOAT DEFAULT_VALID_INPUT_DOUBLE
#define DEFAULT_VALID_INPUT_LONG DEFAULT_VALID_INPUT_INT
#define MAX_SIGNED_INTEGER 2147483647
#define MIN_INTEGER -2147483648
#define MAX_UNSIGNED_INTEGER 4294967295
#define MIN_UNSIGNED_INTEGER 0

#define DEFAULT_VALID_INPUT_INT  "1234567890"
#define DEFAULT_VALID_INPUT_DOUBLE  "1234567890."
#define DEFAULT_INVALID_NUM  "Error! Non numerical character found!"
#define DEFAULT_INVALID_STRING  "Error!"
#define DEFAULT_VALID_INPUT_STRING "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz "
#define DEFAULT_VALID_INPUT_CHAR "YyNn"
#define DEFAULT_INVALID_CHAR "Error! Enter Y or N!"


class input {



	private:
    	static bool validateInput(std::string& input,
                              const std::string& validChars);
    public:
    
    	
    	static std::string validateInputString(std::string& inputPrompt,
            	                               const std::string& validChars=DEFAULT_VALID_INPUT_STRING, 
											   const std::string& invalidMsg=DEFAULT_INVALID_STRING);
    	static char validateInputChar(std::string& inputPrompt,
									  const std::string& validChars=DEFAULT_VALID_INPUT_CHAR,
									  const std::string& invalidMsg=DEFAULT_INVALID_CHAR);
		static int validateInputInt(std::string& inputPrompt,
            	                    const std::string& validChars=DEFAULT_VALID_INPUT_INT,
									const std::string& invalidMsg=DEFAULT_INVALID_NUM);
		static unsigned int validateInputUnsignedInt(std::string& inputPrompt,
            	                    const std::string& validChars=DEFAULT_VALID_INPUT_INT,
									const std::string& invalidMsg=DEFAULT_INVALID_NUM);
   		static double validateInputDouble(std::string& inputPrompt,
            	                          const std::string& validChars=DEFAULT_VALID_INPUT_DOUBLE,
										  const std::string& invalidMsg=DEFAULT_INVALID_NUM);
    	static float validateInputFloat(std::string& inputPrompt,
            	                        const std::string& validChars=DEFAULT_VALID_INPUT_FLOAT,
										const std::string& invalidMsg=DEFAULT_INVALID_NUM);
    	static long validateInputLong(std::string& inputPrompt,
            	                      const std::string& validChars=DEFAULT_VALID_INPUT_LONG,
									  const std::string& invalidMsg=DEFAULT_INVALID_NUM);
		static int validateRangeInt(std::string& inputPrompt, int low, int high);
		                     
		static int menu(std::vector<std::string> choices, std::string& inputMessage);
		
		template<typename ValueType>  static std::string toString(ValueType v);
		
		static bool validateInputRange(int low, int high, int input);
		
		static std::string intToString(int i[], int length);
};

class parse {
	
	public:
		static std::vector<std::string> parseFileText(std::ifstream file);	
};
#endif
