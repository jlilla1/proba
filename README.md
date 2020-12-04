# Alfak
Ezt a programot az Alfak csapata készítette a Modern Szoftverfejlesztési Eszközök tantárgy részeként.

##### A program rövid ismertetése:
A charactermeth.cpp a character.h fájl segítségével működik. A character.h tartalmazza a karakterek adatait, azaz a nevüket, az életüket, valamint az ütésük erősségét. A benne található SetHp segítségével állítható a karakter élete, futás közben is ezt hívja meg a program, így amennyiben az érték 0 alá csökkenne, akkor is 0 marad, egyéb esetben pedig az új értéket kapja meg. A toString metódus pedig a könnyebb átláthatóság érdekében kilistázza a karakterek adatait. A gamemeth.cpp a game.h fájlt felhasználva dolgozik. A game.h-ban a Game osztály van definiálva, melyben a Fight metódus lefuttatja a két karakter közti harcot. A példától annyiban tértünk el, hogy ki lehet választani, hogy mely karakter kezdje a támadást. A Fight elindítja a játékot, majd a kezdő karakter kiválasztása után a két karakter addig harcol felváltva egymás ellen, míg valamelyikük meg nem hal, ezzel a játék véget ér. Végezetül a program kiírja a győztes és a vesztes nevét. A main.cpp ellenőrzi a megadott argumentumokat és amennyiben hibásak, egy vicces hibaüzenetet küld, egyéb esetben lefut a játék.


A második feladatrész során annyiban változott meg a program, hogy konkrét fájlokat vár bemenetként, ezek helyessége egyelőre nem ellenőrzött (a feladatnak nem volt része). Viszont, amennyiben a fájl nem létezik, azt hibaüzenet jelzi. Emellett felkerült egy units mappa, melyben a harc során használt karakterek adatai találhatóak, valamint egy .txt, melyben az egymással való ütköztetések végkimenetelei olvashatók.

