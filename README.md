# EDA #level2: Lequel?

## Integrantes del grupo y contribución al trabajo de cada integrante

* Juan Ignacio Fogolin Lagares:
* Francisco Paredes Alonso:

## Respuestas del enunciado

1. ¿En qué idioma está el siguiente texto?

```
історія земель сучасної України, українського народу та інших національностей, що проживають на території України, від доісторичних часів до сьогодення.
```

Ucraniano.

2. ¿En qué idioma está el siguiente texto?

```
아리랑, 아리랑, 아라리요... 아리랑 고개로 넘어간다. 나를 버리고 가시는 님은 십리도 못가서 발병난다. 청천하늘엔 잔별도 많고, 우리네 가슴엔 희망도 많다. 저기 저 산이 백두산이라지, 동지 섣달에도 꽃만 핀다.
```

Coreano.

3. ¿En qué idioma está el siguiente texto?

```
၁၉၄၀ ခုနှစ်တွင် ဗိုလ်ချုပ်အောင်ဆန်းဦးဆောင်သည့် ရဲဘော်သုံးကျိပ်အဖွဲ့ဝင်တို့သည် ဗမာ့လွတ်မြောက်ရေးတပ်မတော် (ဘီအိုင်အေ) ကို တည်ထောင်ခဲ့ကြသည်။[၂၀][၂၀] ရဲဘော်သုံးကျိပ်သည် ဂျပန်နိုင်ငံတွင် စစ်သင်တန်းများတက်ရောက်ခဲ့ကြသည်။[၂၀]
```

Birmano.

4. ¿En qué idioma está el siguiente texto?

```
Negema wangu binti, mchachefu wa sanati upulike wasiati asa ukanzingatia. Maradhi yamenshika hatta yametimu mwaka sikupata kutamka neno lema kukwambia. Ndoo mbee ujilisi na wino na qaratasi moyoni nina hadithi nimependa kukwambia.
```

Suajili.

5. ¿En qué idioma está el siguiente texto?

```
Այժմ նա յուր կինտոյի արհեստով ժառանգած Ճանճուր մականունը կցելով յուր հոր՝ Օհանեսի անվան հետ, կոչվում է «Թիֆլիսի պատվավոր քաղաքացի Ճանճուր Իվանիչ»։ Այդ անունով ևս մենք պարտավորվում ենք նրան ծանոթացնել մեր ընթերցողներին։
```

Armenio.

6. ¿En qué idioma está el siguiente texto?

```
Belirli bir bölgedeki mevcut hava durumu hava raporu, gelecekte beklenen durumlar ise hava tahmini şeklinde, ilgili meteoroloji otoriteleri tarafından yayımlanır.
```

Turco.

7. ¿En qué idioma está el siguiente texto?

```
ᎤᎵᏍᏔᏴᏗ ᎦᎵᏙᏗ ᏭᎷᏤᎢ, ᎤᏗᏔᎮ ᎦᏁᎲ, ᎤᏲᏏᏍᎩ ᎤᏗᏔᎮ ᎤᏅᏗ ᏃᎴ ᎤᎩᏍᏙᎡ ᏑᎾᎴ ᎠᎩᏍᏗ ᎤᏂᏑᎸᏓ. ᎣᏍᏓ ᏄᎵᏍᏔᏁᎮ ᎤᏩᏌ ᎤᏪᏅᏒ ᎡᏙᎲ. ᎦᏅᏆᎶᏍᏗ ᏭᏴᎮ ᏣᏄᏏ ᏃᎴ ᏣᏁᎳ ᎠᏂᏎᏂᏏ ᏴᎩ, ᎣᏍᏓ ᏄᏩᏁᎴ ᎠᏦᏴ.
```

Cheroqui.

8. ¿En qué idioma está el siguiente texto?

```
ُیعتقد بأن ضابطة في الجیش البریطاني تدعى بریت تشاندي أصبحت أولامرأة من أصول آسیویة ُتكملُ رحلة استكشافیة فردیة عبر .القارة القطبیة الجنوبی  
```

Arabe.

9. ¿En qué idioma está el siguiente texto?

```
ગુજરાતી સંસ્કૃત ભાષામાંથી વિકસિત થયેલી આધુનિક ઈન્ડો-આર્યન ભાષા છે. પરંપરાગત રીતે ૩ ઐતિહાસિક તબક્કાઓ પ્રમાણે ઈન્ડો-આર્યન ભાષાઓ વચ્ચે ભેદ કરાય છે.
```

Guyarati.

10. ¿En qué idioma está el siguiente texto?

```
Al Seicento appartiene il primo trattato dedicato non ai volgari italiani o a uno o più di tali volgari, ma alla lingua italiana in quanto tale: Delle osservazioni della lingua italiana di Marcantonio Mambelli, detto il Cinonio.
```

Italiano.

11. El siguiente texto fue escrito por Robert Burns en escocés. ¿Qué dice Lequel? ¿Qué falla? Justifica por qué ocurre lo que ocurre.

```
And there's a hand, my trusty fiere! and gie's a hand o' thine! And we’ll tak' a right gude-willie waught, for auld lang syne.
```

Lequel predice que el idioma es inglés. El programa falla principalmente por la diferencia enorme de trigramas coincidientes entre el texto con cada idioma, es decir, al comparar con el inglés se encuentran 74 coincidencias (con uno duplicado, es decir 73 elementos)
mientras que con el escocés se encuentran 47. La intersección de estos dos conjuntos da una cantidad de 44 elementos, por lo que se puede deducir que el programa realiza el cálculo de la
similitud por coseno con 44 elementos para ambos idiomas, pero con el inglés ademas realiza el cálculo con 29 elementos extra, mientras que con el escocés lo realiza con 3 extra
esta enorme diferencia de trigramas comunes por cada lenguaje es lo que le da la ventaja al inglés y por eso el programa termina prediciendo este idioma.
Aquí figuran los datos recaudados con el programa:

```
Predicción de Lequel: Inglés

Inglés:
Cosine similarity with eng: 0.359569
Number of trigram matches: 74

Escocés:
Cosine similarity with gla: 0.16191
Number of trigram matches: 47
```

12. El siguiente texto está en inglés. ¿Qué dice Lequel? ¿Qué falla? Justifica por qué ocurre lo que ocurre.

```
IT WAS THE BEST OF TIMES, IT WAS THE WORST OF TIMES,
IT WAS THE AGE OF WISDOM, IT WAS THE AGE OF FOOLISHNESS,
IT WAS THE EPOCH OF BELIEF, IT WAS THE EPOCH OF INCREDULITY,
IT WAS THE SEASON OF LIGHT, IT WAS THE SEASON OF DARKNESS,
IT WAS THE SPRING OF HOPE, IT WAS THE WINTER OF DESPAIR,
WE HAD EVERYTHING BEFORE US, WE HAD NOTHING BEFORE US,
WE WERE ALL GOING DIRECT TO HEAVEN, WE WERE ALL GOING DIRECT THE OTHER WAY
– IN SHORT, THE PERIOD WAS SO FAR LIKE THE PRESENT PERIOD, THAT SOME OF ITS NOISIEST AUTHORITIES INSISTED ON ITS BEING RECEIVED, FOR GOOD OR FOR EVIL, IN THE SUPERLATIVE DEGREE OF COMPARISON ONLY.
```

Lequel predice que el idioma es afrikáans. El programa falla porque si bien el texto tiene la misma cantidad de trigramas coincidientes en cada idioma (inglés y afrikáans)
la diferencia se encuentra en las frecuencias normalizadas de los trigramas por cada lenguaje. Estas frecuencias se pueden apreciar en los siguientes datos recolectados:

```
Predicción de Lequel: Afrikáans

Afrikáans:
Cosine similarity with afr: 0.00404994
Number of trigram matches: 5
Trigram matches: {
 HE | Frequency: 0.030375
E,  | Frequency: 0.00465323
ERE | Frequency: 0.0306019
HER | Frequency: 0.030593
RE  | Frequency: 0.0216202
}

Inglés:
Cosine similarity with eng: 0.00235885
Number of trigram matches: 5
Trigram matches: {
 GO | Frequency: 0.00127841
, I | Frequency: 0.00825796
, T | Frequency: 0.00560598
, W | Frequency: 0.00371525
D,  | Frequency: 0.0058749
}
```

Como se puede apreciar, para el idioma afrikáans 4 de los 5 trigramas coincidientes tienen frecuencias de 1 orden superior a las del inglés, es esta la diferencia que 
favorece a afrikáans como el mejor candidato para la predicción. 
   Sin embargo, se realizó la prueba nuevamente pero convirtiendo el texto original a letra minúscula y el resultado fue el siguiente:

```
Predicción de Lequel: Inglés

Afrikáans:
Cosine similarity with afr: 0.167594
Number of trigram matches: 196

Inglés:
Cosine similarity with eng: 0.60698
Number of trigram matches: 275
```

Esto muestra que el idioma afrikáans se veía favorecido en cuanto a los trigramas formados por mayúsculas ya que al realizar el experimento mencionado, la cantidad de trigramas coincidientes
con el inglés fue mucho más abundante.

## Bonus points

## Extra de similitud coseno.

[Completar]

## Identificacion del cuello de botella ante un texto muy grande.

[Completar]

## Lenguajes extra.

[guaraní, catalán, asturiano, e incluso ¡lenguaje C, lenguaje C++ y Python!]

