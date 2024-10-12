#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Работа с файлом
FILE *fptr;

//Tasks
//1 - Печатает введенную строку и выходит - DONE
//2 - Печатает введенную строку в цикле и выходит по Ctrl+D - DONE
//3 - Добавить команду для выхода (exit, \q) -  DONE
//4 - Добавить историю команд и сохранить в файл  - DONE
//5 - Добавить команду echo - DONE
//6 - Проверка введенной команды - DONE
//7 - Добавить команду по выводу переменной окружения (\e $PATH) - DONE
//8 - Выполнить указанный бинарный файл - запуск по "./" - not executed back
//9 - По сигналу SIGHUP вывести "Configuration reloaded" - не знаю что это
//10 - По '\l /dev/sda' получить информацию о разделах в системе - 
//11 - По '\cron' подключить VFS в /tmp/vfs со списком задач в планировщике
//12 - По  '\mem <procid>' получить дамп памяти процесса



int main() {
   char input[100];
   fptr = fopen("app/history", "a");
   bool is_command = false;
   
   while (!feof(stdin)) { //отлов ctrl+D через пустую строку
   is_command = false;
     printf("$ ");
     fflush(stdout);
     fgets(input, 100, stdin);  
     int n = strlen(input);
     input[n - 1] = '\0';
     fprintf(fptr, "%s\n", input);
     
 //Выходы по условиям
     if (!strcmp(input, "exit")){
       exit(0);
     }
     if (!strcmp(input, "\\q")){
       exit(0);
	}
//Вывод переменных окружения 
	if (strncmp(input, "\\e", strlen("\\e")) == 0){
		const char* s = getenv(input+3);
		printf("env :%s\n", (s != NULL) ? s : "getenv returned NULL");
		is_command = true;
		continue;	
	}
		
//Запуск бинарника по ./
	if (strncmp(input, "./", strlen("./")) == 0){
	printf("%s: try to execute\n", input + 2);
	execv(input + 2, NULL);
	is_command = true;
	}

//Команда echo
     if (strncmp(input, "echo", strlen("echo")) == 0){
        printf("%s\n", input + 5);
        is_command = true;
        continue;
      } 
      
      if (!is_command) {printf("%s: command not found\n", input);} 
    
// команда \l /dev/sda
	if (strncmp(input, "\\l /dev/sda", strlen("\\l /dev/sda")) == 0){
	
	
	}
     
   }
   return 0;
}

