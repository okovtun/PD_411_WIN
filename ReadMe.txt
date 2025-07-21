﻿https://github.com/okovtun/PD_411_WIN.git
https://www.youtube.com/playlist?list=PLeqyOOqxeiIPLv3EUlwogX7k-Pr1vrOjX

https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/mbstowcs-mbstowcs-l?view=msvc-170

Messages:
https://learn.microsoft.com/en-us/windows/win32/winmsg/windowing
https://learn.microsoft.com/en-us/cpp/mfc/modal-and-modeless-dialog-boxes?view=msvc-170

TOREAD:
https://learn.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues#sending-messages

IEEE-754:
http://www.softelectro.ru/ieee754.html

InstallerProjects:
https://learn.microsoft.com/en-us/visualstudio/deployment/installer-projects-net-core?view=vs-2022
2017:	https://marketplace.visualstudio.com/items?itemName=VisualStudioClient.MicrosoftVisualStudio2017InstallerProjects
2022:	https://marketplace.visualstudio.com/items?itemName=VisualStudioClient.MicrosoftVisualStudio2022InstallerProjects

TODO:
1. Часы должны всегда запускаться в правом верхнем углу, независимо от размера экрана;
2. Обеспечить возможность выбора кастомного шрифта для часов;
3. Обеспечить возможность выбирать цвет текста и фона для часов;

DONE:
1. Сделать COMMIT и создать ветку 'WindowsForms_HW1';
2. Добавить на форму галочку (CheckBox) 'Показать дату'.
   Если она установлена, то под временем должна отображаться дата;
3. Добавить галочку 'Показать день недели', и если она установлена,
   то под датой/временем должен отображаться день недели;

DONE:
1. Разобрать 'SetupWizard';
2. Попробовать другие установщики прилоений;
3. Реализовать текстовые редактор по типу Блокнота (notepad);

DONE:
1. Упаковать несколько шрифтов в DLL, и использовать шрифты из DLL-файла;
2. Сделать подменю для тем и для шрифтов;

DONE:
1. Сделать свои кнопки;	DONE
2. Добавить проект 'LastError', и в этом проекте собрать DONE
   статическую или динамическую библиотеку с функциями FormatLastError() и PrintLastError();
	https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-170
	https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170
3. Добавить свой шрифт из файла;DONE

DONE:
Добить кнопки;

DONE:
1. Прикрутить значки к кнопкам;

DONE:
1. Делаем COMMIT и создаем ветку CalculationsHW;
2. Организовать вычисления;

DONE:
1. Делаем COMMIT и создаем ветку ButtonsHW;
2. В созданной ветке создаем кнопки Калькулятора;

DONE:
1. Окно должно запускаться ровно посередине экрана, как по горизонтали, так и по вертикали,
   и должно занимать ровно 75% экран, незавимо от его разрешения;
2. В строке заголовка окна отобразить размер окна и его положение на экране;

DONE:
1. В Solution 'WinAPI' добавить проект 'ListBox', и в этом проекте реализовать все те же действия,
   которые реализованы в проекте 'ComboBox';
2. В проекте 'ListBox' добавить кнопки 'Добавить' и 'Удалить';
3. При нажатии на кнопку 'Добавить' открывается еще одно окно, в котором можно вписать название элемента;
4. При двойном щелчке мышью на пунте 'ListBox' открывается такое же окно, но на изменение элемента;
5. При нажатии на кнопку 'Удалить' удаляется выбранный элемент 'ListBox-а';

DONE:
При запуске программы в текстовом поле 'Login' отображается приглашение "Введите имя пользователя".
Когда пользователь щелкает на нем мышкой, приглашение пропадает.
Если пользователь ввел свое имя, то при переходе с поля для ввода имени на другие элементы имя остается,
но если пользователь оставил поле устым, то при переходе на другие элементы интерфейса в текстовое поле 'Login'
возвращается приглашение "Введите имя пользователя".