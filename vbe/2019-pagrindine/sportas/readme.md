# Sportas

Sporto stovykloje populiari nauja sporto rungtis – vasaros biatlonas. Tai kroso lenktynės su šaudymu į taikinius. Tose pačiose varžybose dalyvauja ir vaikinai, ir merginos. Visi startuoja pagal atrankos etapo rezultatus. Merginos trasą bėga vieną kartą, vaikinai – du. Varžybų startas 9 val. Finišas uždaromas 17 val. Trasoje yra dvi šaudyklos po penkis taikinius. Netikslus šūvis vertinamas viena baudos minute, kuri pridedama prie trasos įveikimo laiko.

Parašykite programą, kuri pateiktų atskirai vaikinų ir merginų rezultatų sąrašus pagal trasos įveikimo rezultatą didėjančiai. Jei sportininkų rezultatas vienodas, jie turi būti rašomi abėcėliškai pagal simbolių eilutę, kurioje yra sportininką identifikuojanti informacija (naudojami tik lotynų abėcėlės simboliai).

## Pradiniai duomenys

Duomenys pateikiami tekstiniame faile U2.txt. Visi skaičiai yra sveikieji.
Duomenų faile įrašyta:
- Pirmoje eilutėje užrašytas startuojančiųjų skaičius n (1 <= n <= 30).
- Tolesnėse n eilučių atsitiktine tvarka surašyti sportininkų starto duomenys. Kiekvieno sportininko duomenys užrašyti atskiroje eilutėje: pirmose 20 pozicijų yra simbolių eilutė, kurioje pateikta sportininką identifikuojanti informacija; starto numeris (triženklis skaičius); tarpo simbolis ir po to starto laikas: valanda, minutė ir sekundė, atskirtos vienu tarpo simboliu. Merginų starto numeriai prasideda vienetu, vaikinų – dvejetu.
- Toliau užrašytas finišavusiųjų skaičius m (1 <= m <= 30).
- Tolesnėse m eilučių surašyti sportininkų finišo duomenys. Kiekvieno sportininko duomenys užrašyti atskiroje eilutėje: starto numeris; finišo laikas: valanda, minutė ir sekundė; ir kiekvienoje šaudykloje taiklių šūvių skaičiai. Visi duomenys atskirti vienu tarpo simboliu. Sąraše yra tik finišavusiųjų duomenys.

## Rezultatai

Rezultatus įrašykite tekstiniame faile U2rez.txt.
- Rezultatai turi būti surikiuoti pagal trasos įveikimo rezultatą (trasos įveikimo laikas kartu su baudos minutėmis) didėjančiai. Jei sportininkų rezultatas vienodas, jie turi būti rašomi abėcėliškai pagal simbolių eilutę, kurioje yra sportininką identifikuojanti informacija (naudojami tik lotynų abėcėlės simboliai).
- Iš pradžių turi būti pateikiamas merginų rezultatų sąrašas, po to – vaikinų. Prieš atitinkamą sąrašą nuo eilutės pradžios užrašykite žodį „Merginos“ arba „Vaikinai“, net jeigu sąrašas bus tuščias.
- Vienoje eilutėje užrašykite vieno sportininko duomenis: starto numerį; tolesnėse 20 pozicijų – simbolių eilutę, kurioje pateikta sportininką identifikuojanti informacija; po to sportininko rezultatą: valandos, minutės ir sekundės. Visi duomenys atskirti vienu tarpo simboliu. Jeigu sportininko nėra finišavusiųjų sąraše, tai rezultatų sąraše jo neturi būti.

## Nurodymai

- Sukurkite ir parašykite funkciją, kuri surikiuoja rezultatus.
- Sukurkite ir parašykite funkciją, kuri spausdina vieno sąrašo rezultatus tekstiniame faile. 
- Programoje nenaudokite sakinių, skirtų darbui su ekranu.

![img.png](img.png)
![img_1.png](img_1.png)