# coolrpg
A cool RPG featuring the best "Map" class I ever coded !

Now programming engine.

Is not playable yet !

Needs SFML to compil.
and..
what more..
ah yeah it's a cool rpg.

Ps: 
Maybe one day there will be an online multiplayer mode.

Ps 2:
Compilation :

Engine :

<code>cd obj/</code>
<code>g++ ../engine/*.cpp -c -L[Your SFML library folder] -I[Your SFML include folder] -lsfml-graphics -lsfml-window -lsfml-system</code>
<code>ar rcs ../librpg.a *.o</code>

Level Editor :

<code>g++ "level editor"/main.cpp -o editor.exe -L../RPG/ -lrpg -L[Your SFML library folder] -I[Your SFML include folder] -lsfml-graphics -lsfml-window -lsfml-system</code>
