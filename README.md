# Решение задачи коммивояжера с использованием генетического алгоритма

## Инструкция по сборке проекта

Для сборки проекта используестя утилита cmake. Для корректной сборки проекта необходимо установить фреймворк Qt.

### Загрузка на MacOS:

1. Загрузить дополнительное ПО MacPorts
2. для работы GUI необходимо установить Qt5, для этого в терминале необходимо выполнить следующую команду:  
   `sudo port install qt5`

### Загрузка на Linux:

1. Для дистрибутива Ubuntu прописать в командной строке:  
   `sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools`

Далее в файле `CMakeLists.txt` необходимо добавить строчку:  
`set(Qt5_DIR "<путь до директории в которой находится Qt5>")`

### Установка библиотеки QCustomPlot на Linux:

Прописать в командной строке:  
   `sudo apt-get install qcustomplot`
    

## Сылка на отчет:

https://docs.google.com/document/d/1FDKi4nCUjbyEB758uf7fs1w82_JF8-jv/edit?usp=share_link&ouid=107918932963085391831&rtpof=true&sd=true
