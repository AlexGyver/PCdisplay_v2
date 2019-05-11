![PROJECT_PHOTO](https://github.com/AlexGyver/PCdisplay_v2/blob/master/proj_img.jpg)
# Моддинг ПК с Ардуино и WS2812b
* [Описание проекта](#chapter-0)
* [Папки проекта](#chapter-1)
* [Схемы подключения](#chapter-2)
* [Материалы и компоненты](#chapter-3)
* [Как скачать и прошить](#chapter-4)
* [FAQ](#chapter-5)
* [Полезная информация](#chapter-6)
[![AlexGyver YouTube](http://alexgyver.ru/git_banner.jpg)](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig?sub_confirmation=1)

<a id="chapter-0"></a>
## Описание проекта
Вывод информации о температуре и загрузке ЦП и ГП на кольца адресных светодиодов
Страница проекта на сайте: https://alexgyver.ru/PCdisplay_v2/  
   
<a id="chapter-1"></a>
## Папки
**ВНИМАНИЕ! Если это твой первый опыт работы с Arduino, читай [инструкцию](#chapter-4)**
- **libraries** - библиотеки проекта. Заменить имеющиеся версии
- **firmware** - прошивки для Arduino
- **schemes** - схемы подключения компонентов
- **software** - программа для компьютера

<a id="chapter-2"></a>
## Схемы
![SCHEME](https://github.com/AlexGyver/PCdisplay_v2/blob/master/schemes/scheme.jpg)

<a id="chapter-3"></a>
## Материалы и компоненты
### Ссылки оставлены на магазины, с которых я закупаюсь уже не один год
Первые ссылки - в основном магазин Great Wall, вторые - WAVGAT. Покупая в одном магазине, вы экономите на доставке!
- Arduino NANO http://ali.ski/qdQCi  http://ali.ski/le6U_R
- Кольца (у меня 40 диодов) http://ali.ski/HmgGyB  http://ali.ski/SytU-K  http://ali.ski/vGTqIg  http://ali.ski/aaAjH
- Фоторезисторы http://ali.ski/cTC-xi
- Резисторы 10k http://ali.ski/_jH-S
- Фото и резисторы можно купить в любом радиомагазине

## Вам скорее всего пригодится
* [Всё для пайки (паяльники и примочки)](http://alexgyver.ru/all-for-soldering/)
* [Недорогие инструменты](http://alexgyver.ru/my_instruments/)
* [Все существующие модули и сенсоры Arduino](http://alexgyver.ru/arduino_shop/)
* [Электронные компоненты](http://alexgyver.ru/electronics/)
* [Аккумуляторы и зарядные модули](http://alexgyver.ru/18650/)

<a id="chapter-4"></a>
## Как скачать и прошить
* [Первые шаги с Arduino](http://alexgyver.ru/arduino-first/) - ультра подробная статья по началу работы с Ардуино, ознакомиться первым делом!
* Скачать архив с проектом
> На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка **Clone or download**, вот её жми, там будет **Download ZIP**
* Установить библиотеки в  
`C:\Program Files (x86)\Arduino\libraries\` (Windows x64)  
`C:\Program Files\Arduino\libraries\` (Windows x86)
* **Подключить внешнее питание 5 Вольт**
* Подключить Ардуино к компьютеру
* Запустить файл прошивки (который имеет расширение .ino)
* Настроить IDE (COM порт, модель Arduino, как в статье выше)
* Настроить что нужно по проекту
* Нажать загрузить
* Пользоваться  

## Настройки в коде
    CP_MODE 0       // режим анимации ЦП: 0 - цветная полоса, 1 - огонь
    GP_MODE 1       // режим анимации ГП: 0 - цветная полоса, 1 - огонь
    TIMEOUT 5000    // таймаут соединения, мс

    // температура
    CP_TEMP_MIN 35
    CP_TEMP_MAX 60
    GP_TEMP_MIN 35
    GP_TEMP_MAX 60

    // яркость
    MIN_BRIGHTNESS 3
    MAX_BRIGHTNESS 100
    MIN_PHOTO 40
    MAX_PHOTO 700

    // лента
    NUM_LEDS 40
    LED_PIN 6       // диоды ГП
    LED2_PIN 7      // диоды ЦП

    // другое
    AUTO_BRIGHT 1   // вкл/выкл автоуправление яркостью. Если выкл, яркость будет установлена в MIN_BRIGHTNESS!
    PHOTO_PIN A0
	
<a id="chapter-5"></a>
## FAQ
### Основные вопросы
В: Как скачать с этого грёбаного сайта?  
О: На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка **Clone or download**, вот её жми, там будет **Download ZIP**

В: Скачался какой то файл .zip, куда его теперь?  
О: Это архив. Можно открыть стандартными средствами Windows, но думаю у всех на компьютере установлен WinRAR, архив нужно правой кнопкой и извлечь.

В: Я совсем новичок! Что мне делать с Ардуиной, где взять все программы?  
О: Читай и смотри видос http://alexgyver.ru/arduino-first/

В: Вылетает ошибка загрузки / компиляции!
О: Читай тут: https://alexgyver.ru/arduino-first/#step-5

В: Сколько стоит?  
О: Ничего не продаю.

### Вопросы по этому проекту

<a id="chapter-6"></a>
## Полезная информация
* [Мой сайт](http://alexgyver.ru/)
* [Основной YouTube канал](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig?sub_confirmation=1)
* [YouTube канал про Arduino](https://www.youtube.com/channel/UC4axiS76D784-ofoTdo5zOA?sub_confirmation=1)
* [Мои видеоуроки по пайке](https://www.youtube.com/playlist?list=PLOT_HeyBraBuMIwfSYu7kCKXxQGsUKcqR)
* [Мои видеоуроки по Arduino](http://alexgyver.ru/arduino_lessons/)