# Silnik Elektryczny
Przykładowy model silnika:
![alt zdjęcie prostego modelu silnika elektrycznego](img/silnikdc.gif)
1- kierunek prądu, 
2- szczotka węglowa, 
3- komutator, 
4- kierunek prądu w wirniku, 
5- biegun północny pola magnetycznego wytwarzanego przez uzwojenie, 
6- biegun południowy pola magnetycznego wytwarzanego przez uzwojenie, 
7- linie pola magnetycznego, 
8- wirnik, 
9- kierunek obrotu wirnika, 
10- siła elektrodynamiczna

## Dane do modeulu silnika w programie
| Kategoria                           | Parametr                   |   Symbol   | Jednostka (SI) | Opis fizyczny                                           |
|:------------------------------------|:---------------------------|:----------:|:--------------:|:--------------------------------------------------------|
| **Geometria i masa ramki**          | Szerokość ramki            |    $a$     |   $\text{m}$   | Bok prostopadły do osi obrotu (wpływa na ramię siły)    |
|                                     | Długość ramki              |    $b$     |   $\text{m}$   | Bok równoległy do osi obrotu (działa na niego siła $F$) |
|                                     | Pole powierzchni ramki     |    $S$     |  $\text{m}^2$  | Powierzchnia pętli ($S = a \cdot b$)                    |
|                                     | Masa całkowita ramki       |    $m$     |  $\text{kg}$   | Całkowita masa drutu tworzącego ramkę ($20\text{ g}$)   |
| **Parametry elektromagnetyczne**    | Liczba zwojów              |    $N$     |      $-$       | Liczba nawiniętych pętli przewodu                       |
|                                     | Natężenie prądu            |    $I$     |   $\text{A}$   | Prąd płynący przez uzwojenie                            |
|                                     | Indukcja magnetyczna       |    $B$     |   $\text{T}$   | Wartość zewnętrznego pola magnetycznego stojana         |
| **Parametry symulacji numerycznej** | Krok czasowy               | $\Delta t$ |   $\text{s}$   | Skok czasu całkowania metodą Eulera ($1\text{ ms}$)     |
|                                     | Całkowity czas symulacji   | $t_{\max}$ |   $\text{s}$   | Horyzont czasowy symulacji                              |
| **Warunki początkowe ($t = 0$)**    | Kąt początkowy             | $\alpha_0$ |  $\text{rad}$  | Położenie startowe wirnika (poziomo w polu)             |
|                                     | Początkowa prędkość kątowa | $\omega_0$ | $\text{rad/s}$ | Prędkość obrotowa na starcie (silnik stoi)              |

## Użyte wzory
### Moment siły
$M(\alpha) = N \cdot I \cdot S \cdot B \cdot \sin(\alpha)$

### Moment bezwładności ramki
-Dwa boki o długości \ (b\) znajdują się w stałej odległości \ (r = \frac {a} {2} \) od osi obrotu:

$$
J_b = 2 \cdot \left (m_b \cdot \left (\frac {a} {2} \right) ^2\right)
$$

-Dwa boki o długości \ (a\) obracają się wokół swojego środka (dla pręta o masie \ (m_a\) i długości \ (a\)):

$$
J_a = 2 \cdot \left (\frac {1} {12} m_a^2\right)
$$

-Całkowity moment bezwładności jest sumą momentów obu par boków:

$$
J = J_a + J_b
$$
### Dynamika ruchu obrotowego:
$$
\varepsilon = \frac{M_{\text{wyp}}}{J}
$$