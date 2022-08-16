#include <iostream>
#include <fstream>
#include<cstring>
#include<vector>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
	

	char ch;
	int size = 2024;
	int pos=0;
	char  buffer[size];
	int i=0;
	std::string str;
	std::string num;
	std::ifstream file("test.lp");

	if(file.is_open())
    {
		while(!file.eof())
        {
			if(file.eof())
			{
				buffer[pos] = '\0';
			}
			else
			{
				file.get(buffer[pos]);
				pos++;
			}
        }
	}
	else
    {
        std::cout << "File Error." <<std::endl;
    }
		file.close();

	while(buffer[i]!='\0')
	{
 	  if(buffer[i]=='{'  || buffer[i]== '}'|| buffer[i]== '[' || buffer[i]== ']' || buffer[i]== '('|| buffer[i]== ')' || buffer[i]== ',' || buffer[i]== ';')
 	  	{
 	  	    str = str + buffer[i];
 	  	    std::cout<<str<<" : Separator\n";
 	  	 	str="";
 	  	}
 	  	else if ( buffer[i] == '+' || buffer[i]== '-' || buffer[i]== '*'  || buffer[i]== '/' ||buffer[i]== '%'  || buffer[i]== '>' ||buffer[i]== '<' || buffer[i]=='=')
		{
 	  		str = str + buffer[i];
 	  	 	std::cout<<str<<" : Operators\n";
 	  	 	str="";
		}
		else if(buffer[i] == '#')
		{
			std::cout<<buffer[i]<<" : Preprocessor\n";
		}
		else if(buffer[i] == '_')
		{
			str+=buffer[i];
			i++;
			while(buffer[i]!= '_')
			{
			    str+=buffer[i];
				i++;
				if(buffer[i] == '_')
				{
					str+=buffer[i];
					std::cout<<str<<" : Identifier\n";
				}
			}
			str = "";
		}
		else if(buffer[i] == '"')
		{
			str+=buffer[i];
			i++;
			while(buffer[i]!= '"')
			{
				str+=buffer[i];
				i++;
				if(buffer[i] == '"')
				{
					str+=buffer[i];
					std::cout<<str<<" : String\n";
				}
			}
			str = "";
		}
		
		else if(buffer[i]== 'h')
		{
			str+=buffer[i];
			i++;
		    if(buffer[i] =='a')
			{
				str+=buffer[i];
				i++;
				if(buffer[i] =='y')
				{
					str+=buffer[i];
                    std::cout<<str<<" : Keyword\n";
				}
			}
		}
		else if(buffer[i]== 'd')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'a')
			{
				str+=buffer[i];
				i++;
				if(buffer[i] =='y')
				{
					str+=buffer[i];
					i++;
					if(buffer[i] =='n')
                    {
                        str+=buffer[i];
                        std::cout<<str<<" : Keyword\n";   
					}
				}
			}
		}
		else if(buffer[i]== 't')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'h')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== 'r')
				{
					str+=buffer[i];
					i++;
					if(buffer[i]== 'a')
					{
						str+=buffer[i];
						i++;
						if(buffer[i]== 'n')
                        {
                            str+=buffer[i];
                            i++;
                            if(buffer[i]== 'g')
                            {
								str+=buffer[i];
								std::cout<<str<<" : Keyword\n";
                            }  
                        }
                    }
				}	
			}
		}
        else if(buffer[i]== 'h')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'l')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== 'a')
				{
					str+=buffer[i];
					i++;
					if(buffer[i]== 'n')
					{
						str+=buffer[i];
						i++;
						if(buffer[i]== 'g')
						{
							str+=buffer[i];
							std::cout<<str<<" : Keyword\n";
						}
					}
				}	
			}
		}
		else if(buffer[i]== 'b')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'l')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== 'a')
				{
					str+=buffer[i];
					i++;
					if(buffer[i]== 'n')
					{
						str+=buffer[i];
						i++;
						if(buffer[i]== 'g')
						{
							str+=buffer[i];
							std::cout<<str<<" : Keyword\n";
						}
					}
				}	
			}
		}
		else if(buffer[i]== 'l')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'a')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== 'p')
				{
					str+=buffer[i];
					i++;
					if(buffer[i]== 'i')
					{
						str+=buffer[i];
						i++;
						if(buffer[i]== 'n')
                        {
                            str+=buffer[i];
                            i++;
                            if(buffer[i]== 'e')
                            {
                                str+=buffer[i];
                                std::cout<<str<<" : Keyword\n";
                            }
						}
					}
				}
			}
		}
		else if(buffer[i]== 'e')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'l')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== '-')
				{
					str+=buffer[i];
					i++;
					if(buffer[i]== 'o')
					{
						str+=buffer[i];
						i++;
						if(buffer[i]== 's')
						{
							str+=buffer[i];
							std::cout<<str<<" : Keyword\n";
						}
					}
				}	
			}
		}
		else if(buffer[i]== 'e')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'l')
			{
				str+=buffer[i];
				std::cout<<str<<" : Keyword\n";
			}
		}
		else if(buffer[i]== 'f')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'i')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== 'x')
				{
				str+=buffer[i];
				std::cout<<str<<" : Keyword\n";
				}
			}
		}
		else if(buffer[i]== 's')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 't')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== 'o')
				{
					str+=buffer[i];
					i++;
					if(buffer[i]== 'p')
					{
						str+=buffer[i];
						std::cout<<str<<" : Keyword\n";
					}
				}
			}
		}
		else if(buffer[i]== 'g')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'o')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== 'O')
				{
					str+=buffer[i];
					i++;
					if(buffer[i]== 'n')
					{
						str+=buffer[i];
						std::cout<<str<<" : Keyword\n";
					}
				}
			}
		}
		else if(buffer[i]== 'g')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'o')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== 'B')
				{
					str+=buffer[i];
					i++;
					if(buffer[i]== 'a')
					{
						str+=buffer[i];
						i++;
						if(buffer[i]== 'c')
						{
							str+=buffer[i];
							i++;
							if(buffer[i]== 'k')
							{
								str+=buffer[i];
								std::cout<<str<<" : Keyword\n";
							}
						}
					}
				}
			}
		}
		else if(buffer[i]== 'a')
		{
			str+=buffer[i];
			i++;
			if(buffer[i]== 'l')
			{
				str+=buffer[i];
				i++;
				if(buffer[i]== 'p')
				{
					str+=buffer[i];
					i++;
					if(buffer[i]== 'h')
					{
						str+=buffer[i];
						i++;
						if(buffer[i]== 'a')
						{
							str+=buffer[i];
							std::cout<<str<<" : Keyword\n";
						}
					}
				}
			}
		}
       str="";
	   if(buffer[i] =='0' || buffer[i] =='1' || buffer[i] =='2' || buffer[i]=='3'||  buffer[i]=='4'|| buffer[i]=='5' || buffer[i]=='6'|| buffer[i]=='7' || buffer[i]=='8' || buffer[i]=='9'|| buffer[i]=='.')
		{
			std::cout<<buffer[i];
			std::cout<<num<<" : Digit\n";
		}
		i++;
	}
	return 0;
}