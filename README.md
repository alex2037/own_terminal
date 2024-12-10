# own_terminal

## Task
Создать собственный терминал на основе https://app.codecrafters.io/courses/shell/overview
И выполнить функционал:

[x] 1 Печатает введённую строку и выходит

[x] 2 Печатает введённую строку в цикле и выходит по Ctrl+D

[x] 3 Добавим команду для выхода (exit и \q)

[x] 4 Добавим историю введённых команд и её сохранения в файл

[x] 5 Добавим команду echo

[x] 6 Добавим проверку введённой команды

[x] 7 Добавим команду по выводу переменной окружения (\e $PATH)

[ ] 8 Выполняем указанный бинарник

[ ] 9 По сигналу SIGHUP вывести "Configuration reloaded"

[ ] 10 По `\l /dev/sda` получить информацию о разделах в системе

[ ] 11 По `\cron` подключить VFS в /tmp/vfs со списком задач в планировщике

[ ] 12 По `\mem <procid>` получить дамп памяти процесса

  ## Usage

get and run:
	Clone
	RUN by ./your_terminal.sh
OR docker run
	Clone
	docker build . -t terminal
	docker run -it terminal bash
	./terminal

