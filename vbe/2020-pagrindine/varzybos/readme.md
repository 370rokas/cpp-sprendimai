# Varžybos

Vyko metų žvejo varžybos. Sugautos žuvys buvo vertinamos pagal masę ir pagal pavadinimą. Lengvesnė kaip 200 gramų žuvis buvo vertinama 10 taškų, o sverianti 200 gramų ir daugiau – 30 taškų. Žuvis pagal pavadinimą buvo vertinama, skiriant atitinkamą taškų skaičių. Kiekvienas žvejys vertintojams pristatė ne daugiau kaip penkias savo nuožiūra pasirinktas žuvis, esančias vertinamų žuvų pavadinimų sąraše.

Parašykite programą, kuri suskaičiuotų žvejų gautus įvertinimus ir vertintojams pristatytų žuvų bendrą masę pagal pavadinimus.

## Pradiniai duomenys

Duomenys pateikiami tekstiniame faile U2.txt.

Duomenų faile įrašyta:
- pirmoje eilutėje užrašytas žvejų skaičius n (1 <= n <= 30);
- tolesnėje eilutėje pirmose 20 pozicijų užrašyti žvejo vardas ir pavardė (gali būti trys ir daugiau
žodžių), toliau – vertintojams pristatytų žuvų skaičius;
- po to atskirose eilutėse pateikiami to žvejo duomenys apie vertintojams pristatytas žuvis: pirmose
20 pozicijų užrašytas žuvies pavadinimas, toliau – žuvies masė gramais;
- po to tokia pačia tvarka pateikti visų kitų žvejų duomenys.

Toliau pateikiami varžybų vertinimo duomenys:
- vertinamų žuvų pavadinimų skaičius k (1 <= k <= 30);
- toliau atskirose k eilutėse pirmose 20 pozicijų užrašytas vertinamos žuvies pavadinimas, toliau – už jį skiriamų taškų skaičius.

Visi skaičiai yra sveikieji. Žuvų pavadinimuose, taip pat žvejų varduose ir pavardėse naudojamos tik
lotyniškos abėcėlės raidės.

## Rezultatai

Rezultatus pateikite tekstiniame faile U2rez.txt.
- Pirmoje eilutėje parašykite žodį „Dalyviai“.
- Toliau atskirose eilutėse užrašykite žvejų duomenis: pirmose 20 pozicijų – vardą ir pavardę, paskui po tarpo simbolio – žvejui skirtų taškų skaičių. Sąrašą pateikite surikiuotą mažėjančiai pagal žvejų gautų taškų skaičių. Jeigu taškų skaičius vienodas – pagal žvejo vardą ir pavardę (simbolių eilutę) abėcėliškai.
- Toliau atskiroje eilutėje parašykite žodį „Laimikis“.
- Toliau atskirose eilutėse užrašykite duomenis apie vertinamas žuvis: pirmose 20 pozicijų – žuvies pavadinimas, paskui po tarpo simbolio – visų žvejų pristatytų to pavadinimo žuvų bendra masė.Laikykite, kad vertinamų, bet nesugautų žuvų bendra masė lygi nuliui.
- Sąrašą pateikite surikiuotą mažėjančiai pagal žuvų bendrą masę. Jeigu masė vienoda – pagal žuvies pavadinimą (simbolių eilutę) abėcėliškai.

## Reikalavimai

- Parašykite funkciją, kuri rikiuoja duotą sąrašą pagal skaičius mažėjančiai. Jeigu skaičiai vienodi – pagal simbolių eilutę abėcėliškai.
- Parašytą funkciją panaudokite žvejų sąrašui rikiuoti ir žuvų sąrašui rikiuoti.
- Programoje nenaudokite sakinių, skirtų darbui su ekranu.

## Duomenų ir rezultatų pavyzdžiai

![img.png](img.png)

## Programos vertinimas

![img_1.png](img_1.png)