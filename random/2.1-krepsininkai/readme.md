CSV formato faile (duomenys.csv) yra įvykusių rungtynių statistikos sąrašas: žaidėjo vardas, komanda, pelnytų taškų skaičius (PTS), žaidimo metu atliktų metimų kiekis (FGA) ir mestų baudų kiekis (FTA). Tikrasis žaidėjo taiklumas (TS) apskaičiuojamas pagal formulę: TS = PTS / (2 * (FGA + 0.44 * FTA)). Parašykite programą, kuri nuskaitytų duomenis, kiekvienam žaidėjui suskaičiuotų tikrojo taiklumo parametrą, surikiuotų duomenis pagal komandą ir taiklumą bei juos išvestų csv formatu į failą rezultatai.csv (formatas: žaidėjas, komanda, PTS, FGA, FTA, TS).

duomenys.csv:

```
LeBron James,Los Angeles Lakers,25,18,7
Klay Thompson,Golden State Warriors,18,14,2
Austin Reaves,Los Angeles Lakers,15,10,5
D'Angelo Russell,Los Angeles Lakers,17,12,4
Rui Hachimura,Los Angeles Lakers,12,8,3
Stephen Curry,Golden State Warriors,30,20,8
Anthony Davis,Los Angeles Lakers,22,16,6
Draymond Green,Golden State Warriors,8,6,3
Andrew Wiggins,Golden State Warriors,16,11,4
Chris Paul,Golden State Warriors,9,7,2
```

rezultatai.csv:

```
Stephen Curry,Golden State Warriors,30,20,8,0.64
Andrew Wiggins,Golden State Warriors,16,11,4,0.63
Klay Thompson,Golden State Warriors,18,14,2,0.6
Chris Paul,Golden State Warriors,9,7,2,0.57
Draymond Green,Golden State Warriors,8,6,3,0.55
Rui Hachimura,Los Angeles Lakers,12,8,3,0.64
D'Angelo Russell,Los Angeles Lakers,17,12,4,0.62
Austin Reaves,Los Angeles Lakers,15,10,5,0.61
LeBron James,Los Angeles Lakers,25,18,7,0.59
Anthony Davis,Los Angeles Lakers,22,16,6,0.59
```
