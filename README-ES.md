# SnailRaceProject
![image](https://github.com/JotaCeb/SnailRaceProject/assets/30213400/8fea2e96-3c2d-4552-8ec1-d9fa3d83e57a)

Cada caracol tiene voluntad propia, para moverse una cantidad de pasos en una cantidad de tiempo.
Esta voluntad es adquirida por unas condiciones aleatorias en función del tiempo.
Cada caracol puede emitir un sonido particular.
Los caracoles se inscriben a la carrera. 
La dirección de carrera pone a cada caracol que es capaz de adquirir la posición de los mismos.
Hay un panel de carrera que indica el top 3 en tiempo real.
Hay gente que apuesta a qué caracol ganará la carrera, pero esto es ilegal.

![image](https://github.com/JotaCeb/SnailRaceProject/assets/30213400/c647f658-16d3-4e5e-ad3b-7093fb1818ce)

EMPIECE RÁPIDO
1. Compila
```
g++ main.cpp race.cpp gui.cpp random.cpp snail.cpp
```

2. Corre el ejecutable
```
Snail.Race.exe
```

3. Selecciona el número de caracoles en carrera

5. Selecciona los pasos máximos seguidos que puede dar un caracol

7. Apuesta al caracol que crees que ganará

CONFIGURACIONES DE CARRERA
Previo a la compilación se pueden modificar la longitud de la pisa de carreras en el archivo main.cpp
```C++
size_t SPEEDWAY_LENGTH = 60;
```
Posterior a este paso se seguirán los pasos del empiece rápido
