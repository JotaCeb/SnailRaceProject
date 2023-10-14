# SnailRaceProject
![image](https://github.com/JotaCeb/SnailRaceProject/assets/30213400/dda06591-69cc-4eea-a8ed-397135d2804c)

Each snail has its own will, to move a number of steps in a given amount of time.
This will is acquired by random conditions depending on time.
Each snail can make a particular sound.
The snails sign up for the race.
The race direction puts each snail that is capable of acquiring their position.
There is a race panel that indicates the top 3 in real time.
There are people who bet on which snail will win the race, but this is illegal.

![image](https://github.com/JotaCeb/SnailRaceProject/assets/30213400/c3d9d35d-8622-49cc-941c-a23a00a6b5ca)

TO START A RACE
1. Compile
```
g++ main.cpp race.cpp gui.cpp random.cpp snail.cpp
```

2. Run
```
Snail.Race.exe
```

3. Select the number of snails

5. Select the maximum continuous steps which a snail is able to do

7. Bet which snail will win

8. RACE CONFIGURATIONS
Before to compilation you can modify the length of the racing tread in the main.cpp file
```C++
size_t SPEEDWAY_LENGTH = 60;
```
After this step, the quick start steps will be followed.
