#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Работа с файлом
FILE *fptr;



int main() 
{
   char input[100];
   fptr = fopen("history", "a");
   bool is_command = false;
   
   while (!feof(stdin)) //отлов ctrl+D через пустую строку 
//	while(true) 
{ 
     is_command = false;
     printf("$ ");
     fflush(stdout);
     fgets(input, 100, stdin);  
     int n = strlen(input);
     input[n - 1] = '\0';
     fprintf(fptr, "%s\n", input); //запись истории команд
     
//Выходы по условиям выхода з териманала
     if (!strcmp(input, "exit")){exit(0);}
     if (!strcmp(input, "\\q")){exit(0);}
//Команда echo
     if (strncmp(input, "echo", strlen("echo")) == 0)
     {
        printf("%s\n", input + 5);
        is_command = true;
        continue;
      } 
//Вывод переменных окружения \e
	if (strncmp(input, "\\e", strlen("\\e")) == 0){
		const char* s = getenv(input+3);
		printf("env :%s\n", (s != NULL) ? s : "getenv returned NULL");
		is_command = true;
		continue;	
	}
//Запуск бинарника по ./
	if (strncmp(input, "./", strlen("./")) == 0){
	printf("Starting program %s", input+2);
	
	
	is_command = true;
	continue;
}
//По \l получает информацию о разделах системы

	if (strncmp(input, "\\l", strlen("\\l")) == 0){

	is_command = true;
	continue;
}

    
// не команда  
      if (!is_command) {printf("%s: command not found\n", input);} 
    
     
  }
   return 0;
}

