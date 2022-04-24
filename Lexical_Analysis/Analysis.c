#include <stdio.h>
#include <string.h>
char input[100];

void diagram()
{
	int i = 0;
	int cnt = 0;
	
	scanf("%s",input);
	
	while(1)
	{
		switch(cnt)
		{
			case 0:
			{
				if(input[i] == 'f')
				{
					cnt = 1;
				}
				else if(input[i] == 'i')
				{
					cnt = 4;
				}
				else if( isalpha(input[i]) )
				{
					cnt = 8;
				}
				else
				{
					cnt = 9;
				}
				break;
			}
			
			case 1:
			{
				i++;
				if(input[i] == 'o')
				{
					cnt = 2;
				}
	            else if( isalpha(input[i]) || isdigit(input[i]) )
	            {
	               cnt = 8;   
	            }
				else
				{
					cnt = 9;
				}
				break;
			}
			case 2:
			{
				i++;
				if(input[i] == 'r')
				{
					cnt = 3;
				}
	            else if( isalpha(input[i]) || isdigit(input[i]) )
	            {
	               cnt = 8;   
	            }
				else
				{
					cnt = 9;
				}
				break;
				
			}
			case 3:
			{
				i++;
				if(input[i] == '\0')
				{
					printf("1");
					return;
				}
	            else if( isalpha(input[i]) || isdigit(input[i]) )
	            {
	               cnt = 8;   
	            }
				else
				{
					cnt = 9;
				}
				break;
				
			}
			case 4:
			{
				i++;
				if(input[i] == 'f')
				{
					cnt = 5;
				}
				else if(input[i] == 'n')
				{					
					cnt = 6;
				}
	            else if( isalpha(input[i]) || isdigit(input[i]) )
	            {
	               cnt = 8;   
	            }
				else
				{
					cnt = 9;
				}
				break;
			}
			case 5:
			{
				i++;
				if(input[i] == '\0')
				{
					printf("2");
					return;
				}
	            else if( isalpha(input[i]) || isdigit(input[i]) )
	            {
	               cnt = 8;   
	            }
				else
				{
					cnt = 9;
				}
				break;
			}
			case 6:
			{
				i++;
				if(input[i] == 't')
				{
					cnt = 7;
				}
	            else if( isalpha(input[i]) || isdigit(input[i]) )
	            {
	               cnt = 8;   
	            }
				else
				{
					cnt = 9;
				}
				break;
			}
			case 7:
			{
				i++;
				if(input[i] == '\0')
				{
					printf("3");
					return;
				}
	            else if( isalpha(input[i]) || isdigit(input[i]) )
	            {
	               cnt = 8;   
	            }
				else
				{
					cnt = 9;
				}
				break;
			}
			case 8:
			{
				i++;
				if(input[i] == '\0')
				{
					printf("9");
					return;
				}
	            else if( isalpha(input[i]) || isdigit(input[i]) )
	            {
					cnt = 8;
	            }
				break;
			}
			case 9:
			{
            	printf("invalid char \'%c\'",input[i]);
				return;
			}
		}
	}	
	
	
}


void main()
{
	diagram();
	return;
}
