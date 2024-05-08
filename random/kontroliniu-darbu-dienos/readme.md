# Kontrolinių darbų dienos

Gimnazijos mokytojai kiekvienai klasei iš anksto sudaro kontrolinių darbų grafiką, tačiau grafikas gali šiek tiek keistis, nes atsitinka taip, kad kai kurios temos yra sunkesnės ir kontrolinis darbas perkeliamas į kitą mėnesį, kitos temos yra lengvesnės ir į grafiką gali būti įterpiami nauji kontroliniai darbai. Pradinių duomenų failo duomenys1.txt pirmoje eilutėje įrašytas numatomų per mėnesį parašyti kontrolinių darbų skaičius n. Likusiose n eilučių įrašyta po 2 sveikuosius skaičius, atskirtus tarpais – mėnesio diena ir tą dieną numatomų kontrolinių darbų skaičius (ne daugiau 2 kontrolinių darbų per dieną). 

Mokytojai, norintys perkelti kontrolinius darbus į kitą mėnesį, pateikė sąrašą faile duomenys2.txt, kurio pirmoje eilutėje yra sveikasis skaičius k – perkeliamų į kitą mėnesį darbų skaičius, o likusiose k eilučių – po du sveikuosius skaičius, atskirtus tarpais – mėnesio diena ir tą dieną numatomų perkelti į kitą mėnesį kontrolinių darbų skaičius.

Mokytojai, norintys papildyti kontrolinių darbų sąrašą, pateikė duomenis faile duomenys3.txt. Failo pirmoje eilutėje įrašytas sveikasis skaičius p – papildomų kontrolinių darbų skaičius, o likusiose p eilučių – po du sveikuosius skaičius, atskirtus tarpais – mėnesio diena ir tą dieną numatomų skirti kontrolinių darbų skaičius.

Parenkite programą, kuri:
- iš pradinio sąrašo išbrauktų į kitą mėnesį perkeliamus kontrolinius darbus;
- pradinį sąrašą papildytų naujais kontroliniais darbais (bet ne daugiau kaip 2 kontroliniai darbai per dieną);
- papildomų kontrolinių darbų sąraše išbrauktų, arba pataisytų įrašus (jei visi tos dienos darbai perkelti į pradinį sąrašą, tai ta diena išbraukiama, jei tik dalis – tai diena paliekama ir užrašomas į pradinį sąrašą neperkeltų kontrolinių darbų skaičius).

Rezultatai rašomi faile rezultatai1.txt. Pirmiausiai – galutinis (pataisytas pradinis) sąrašas, po juo – pataisytas papildomų darbų sąrašas. Vienai dienai skiriama 1 eilutė.

duomenys1.txt
```
5
6  2
8  1
12 1
19 2
26 1
```

duomenys2.txt
```
3
8 1
12 1
19 1
```

duomenys3.txt
```
3
6 1
19 1
20 1
```

rezultatai1.txt
```
Galutinis
6 2
19 2
20 1
26 1
Papildomas
6 1
```