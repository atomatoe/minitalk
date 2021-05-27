![Screen](https://raw.githubusercontent.com/atomatoe/minitalk/master/screenshots/signals.jpg)

________________________________________________________________

#### <p align=center> "Это реально ненормальное программирование! :)"</p> ####
________________________________________________________________


### Цель проекта:
Реализовать связь между двумя процессами Client и Server посредством сигналов в С, по стандарту 98 года.
<p>В виде связи выступает передача строки от одного процесса к другому.</p>

### Реализация:
<p>Текущий процесс приостанавливается (pause) и в нем работает обработчик сигнала, который срабатывает при получении сигнала (func my_handler).</p>
<p>Будем отправлять строку посредством сигналов sigusr1 и sigusr2. Один символ - отправка 8 сигналов.</p>
<p>Каждый сигнал будет отправлен в виде 0 или 1, символ будет переведен в ASCII код и далее в двоичную систему счисления.</p>
<p>Использовать будем сигналы sigusr1, означающий 1,  и sigusr2, означающий 0.</p>
<p>Двоичная система счисления имеет 8 байт, следовательно server будет знать, что каждые 8 сигналов - это один символ. В таком случае нужно обратить внимание, что некоторые алгоритмы конвертации dec2bin отсеивают ведущие нули. Если запрос придет меньше 8 сигналов - сервер не обработает его.</p>
<p>Как только сервер принимает запрос (т.е один символ), он его переводит bin2dec и выводит на экран. Таким образом отсылается и выводится вся строка.</p>

### Стек технологий:
* С
* Signals

________________________________________________________________


<details>
<summary>Screenshots</summary>

________________________________________________________________

<p><img src="https://raw.githubusercontent.com/atomatoe/minitalk/master/screenshots/send_signal_1.png" alt="Ссылка"></p>
<p><img src="https://raw.githubusercontent.com/atomatoe/minitalk/master/screenshots/send_signal_2.png" alt="Ссылка"></p>
<p><img src="https://raw.githubusercontent.com/atomatoe/minitalk/master/screenshots/send_signal_3.png" alt="Ссылка"></p>
________________________________________________________________

</details>

<details>
<summary>Полезная информация и ссылки</summary>
<p></p>
<p>Обработка сигналов занимает некоторое время, и если вы посылаете слишком много за один раз, некоторые из них могут быть проигнорированы. Именно поэтому я использую usleep.</p>
<p>Printf нельзя вызывать внутри сигнала. Именно из-за printf не мог понять почему server не принимал сигнал. Советую не использовать его в момент написания проекта или его тестирования.</p>
<p><a href="https://coderoad.ru/39590535/%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D1%81%D0%BA%D0%B8%D0%B5-%D1%81%D0%B8%D0%B3%D0%BD%D0%B0%D0%BB%D1%8B-sigusr1-%D0%B8-sigusr2
">Подробнее о SIGUSR1 и SIGUSR2</a></p>
<p><a href="https://habr.com/ru/post/122823/">Передача файлов сигналами</a></p>
<p><a href="https://www.cyberforum.ru/c-linux/thread833809.html">Как узнать завершился ли процесс-потомок?</a></p>
<p><a href="https://man7.org/linux/man-pages/man7/signal-safety.7.html">Список разрешенных функций внутри обработчика сигнала</a></p>

</details>

</details>

<details>
<summary>bin2dec и dec2bin</summary>

```C
int bin2dec(int n)
{
  int num;
  int dec_value;
  int base;
  int temp;
  int last_digit;
    
  num = n;
  base = 1;
  dec_value = 0;
  temp = num;
  while (temp)
  {
    last_digit = temp % 10;
    temp = temp / 10;
    dec_value += last_digit * base;
    base = base * 2;
  }
  return dec_value;
}

int dec2bin(int server_pid, int num)
{
  int bin = 0;
  int k = 1;
  int i = 0;

  while (num)
  {
    bin += (num % 2) * k;
    k *= 10;
    num /= 2;
    i++;
  }
  return bin;
}
```

</details>

### Если я помог как-то вам, то буду благодарен за звездочку :)

