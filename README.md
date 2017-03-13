# The Snake Game
The notorious **Snake** Game. Celebrating the "relaunch" of Nokia 3310!

## How to play?
Run the game as below:
```{r, engine='bash', count_lines}
g++ -o snake snake_linux.cpp
./snake
```

Use the following keys:
<kbd>w</kbd> -- for going up
<kbd>s</kbd> -- for going down
<kbd>a</kbd> -- for going left
<kbd>d</kbd> -- for going right
and eat the food represented by "**$**" to increase your score ie. the length of the snake

PS: Press the key and wait for a second. 

The game is over when: The head of the snake hits any part of the snake. 

Enjoy!

Want to stop the game in between? Use <kbd>Ctrl</kbd>+<kbd>z</kbd> just in case.


## Known Issues?
* Render food everytime. Disappears when food appears on snake 
* Solve the length=2 snake length problem (Turns back on its head, then the game isn't over!. Logical problem)

Apart from these issues please report any otherissues in the issue section. Thanks!

## Possible Improvements or Addition of Features
* Make the game fast (The sleep is annoying but helpful for debugging. Reduce it if you want)
* Add a more random rand() function. The seed can specified and srand can be used.
* Add obstacles ie. add different game modes.
* The simple do-while for play again :P
* Add a section for high scores and corresponding names.

Open for suggestions!
