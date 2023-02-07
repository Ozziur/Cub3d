mappa bonus accetta porte sui bordi e non dovrebbe. trovare la fantasia per scrivere una storia divertente

*----------------- TESTIMONIANZE DEL MAGO ------------------*

Giorno 1:
Ho visto e scoperto che alcuni, molti cub3d sono penosi, buggati e poco magici. non mi trasmettono niente e io con uno schiocco di dita lo potrei fare in un attimo, ma per non far sentire stupidi quei poveri senza-magia mi asterrò.
il piano di battaglia è innanzitutto il check dell'input, fatto con una formula magica chiamata arg_check();
successivamente si andrà a parsare la mappa, per farlo ho bisogno di alcuni ingredenti segreti tra i quali lacrime di drago, supporto di un pirata e tanta voglia.
Parsing: parso le prime 8 righe dove salvo i dati dei muri, pavimento e cielo.
Successivamente, ogni 0 che trovo nella mappa controllo che sia circondato da qualcosa, quindi controllo che la mappa è chiusa.


*------ Diario di bordo del Capitano ------*

Giorno 4:
A quanto pare il giorno della nuova missione è arrivato. A dirla tutta mi sarei preso qualche giorno in più per studiare la rotta, capire il percorso e fare rifornimento di rum e vettovaglie ma la maga era già partita. Il giorno in cui una maga sarà più volenterosa e ambiziosa di un vero lupo di mare come me sarà il giorno in cui dovrò affrontare l'ira di Nettuno e fare i conti con tutti i miei creditori e sono troppi. Davvero troppi. Quindi ho raccolto quattro cianfrusaglie e due vestiti e a bordo del Sea's Boar siamo salpati. Spero di aver portato abbastanza mutande... o almeno una in più.
Fratello Claudio ci raggiungerà dopo aver finito di trascrivere un trattoto su C++. Credo che in un paio di giorni riuscirà a raggiungerci.
Il viaggio procede bene, ieri abbiamo pescato un bel ft_parsing. all'inizio ha fatto un pò di capricci ma con l'eleganza e l'acume di un marinaio che ne ha viste troppe gli ho fatto capire chi comanda mentre raccontavo a chi stava assistendo alle mie gesta di come mio patre guida una Clio e mia madre porta una gonna.
Il viaggio è appena iniziato ma la ciurma mi sembra motivata e contenta. Spero che il morale sia così alto per tutto il viaggio e che i tre condottieri di questa missione, Fratello Claudio, Maga Alice e il sottoscritto, riusciranno a chidere questa avventura nel modo pi celere possibile.

Giorno 5:
Allora: abbiamo trovato delle antiche mappe sciamaniche che fanno robe e stiamo provando a seguirle.
Abbiamo anche usato anche strumenti Geniali Potenti Taumaturgici ma c'é della matematica. 
Quindi bho, male che va navighiamo verso nord e dobbiamo andare verso sud, ci consoleremo pensando che su 360° ne abbiamo sbagliati solo la metá.

*-------------------- TESTIMONIANZA SECONDA DEL MAGO (perche il mago è più plateale) ----------------------*
In realtà la magia è scienza e matematica, e mi piace. La magia oscura, però, mi risulta incomprensibile e la sua base sono seni e coseni.
Fuoriesce della magia dal check e dalla "cattura" dei tasti, sono semplici e incantesimi di basso livello. Il mago ha ancora tanto da imparare, diventare il più potente del mondo non è una scelta che si può permettere di fare ma un vincolo, un patto fatto col sangue alla sua nascita e ora si trova col peso di essere il secondo mago più potente della terra, secondo solo a seno e coseno.
E allora con grande rammarico lascerà questa faccenda della magia oscura al pirata e al fratello in viaggio con lei, sperando riescano a superare i segfault e vari errori che incontreranno nella strada e lei intanto si darà a cose più magia-friendly.
quindi cercherà di capire come non far sbattere il nostro giocatore ai muri, che in gergo tecnico si dice "flashare sul muro" (che ha comunque magia oscura).

*------ Diario di bordo del Capitano ------*
Giorno 6:
Oggi é stata una giornata fruttosa e finalmente vediamo qualcosa.Non qualcosa di troppo bello ma io sono un pirata, non un pittore.
Stiamo riuscendo a chiudere le giornate con dei risultati ogni volta, il cantante e lo sciamano fanno salti puntuali dandoci spesso una mano e tutto prosegue per il meglio. Probabilmente la legnata sta prendendo la rincorsa per farci sputare i denti piú tardi.

*-------------------- TESTIMONIANZA TERZA DEL MAGO ----------------------*
Si sa, la magia non ha confini, e nemmeno l'uso della RAM. Attualmente ho sperimentato, sulla pelle del computer, che a 100 GB ci arriva senza crashare.
Diversi giorni dopo...
Tutto ok, il pirata ha risolto diversi problemi mentre io, la maga, combattevo contro altri mostri come exam03.
Oggi proveremo a dare vita al nostro estro artistico disegnando i muri con le idee che ho buttato in pentola per fare il parsing... avrei dovuto tenermene almeno una. 
Il pirata sembra ubriaco e mi chiede di fare cose impossibili per un mago, penso che paghero' un paio di essenze blu (LEAGUE OF LEGEND VALUE) a qualche artista.

*--------------------------- SPIEGAZIONI RAYCAST CALC -------------------------------*

/*Questa funzione statica definisce i valori del raggio e dell'offset per un raggio che colpisce i muri verticali. La funzione prende in input un puntatore alla struttura dati "t_rules", un puntatore alla struttura dati "t_ray", un valore double chiamato "n_tan" e un array di float chiamato "xy".
La funzione utilizza una condizione if per determinare se l'angolo del raggio è inferiore a M_PI/2 o maggiore di 3M_PI/2. In caso affermativo, imposta il valore x del raggio come la posizione x del giocatore più la larghezza del blocco (che è l'altezza del muro) meno il valore restituito dalla funzione "our_modulo" (che fornisce il resto della divisione tra la posizione x del giocatore e la larghezza del blocco).
Imposta il valore y del raggio come la posizione y del giocatore meno (la posizione x del giocatore meno il valore x del raggio) moltiplicato per la tangente negativa.
Imposta i valori dell'offset x e y come la larghezza del blocco e la larghezza del blocco moltiplicato per la tangente negativa.
In caso contrario, se l'angolo del raggio è maggiore o uguale a M_PI/2 e minore o uguale a 3M_PI/2, imposta il valore x del raggio come la posizione x del giocatore meno il valore restituito dalla funzione "our_modulo" (che fornisce il resto della divisione tra la posizione x del giocatore e la larghezza del blocco).
Imposta il valore y del raggio come la posizione y del giocatore meno (la posizione x del giocatore meno il valore x del raggio) moltiplicato per la tangente negativa.
Imposta i valori dell'offset x e y come -larghezza del blocco e -larghezza del blocco moltiplicato per la tangente negativa.
Infine, la funzione restituisce 0 in caso di angolo del raggio inferiore a M_PI/2 o maggiore di 3*M_PI/2 e 1 in caso contrario.
In sintesi, questa funzione calcola la posizione iniziale di un raggio virtuale che colpisce i muri verticali, e definisce i valori dell'offset x e y utilizzati per aggiornare la posizione del raggio durante il controllo delle collisioni.*/

/*Questo codice rappresenta una funzione statica che controlla le linee verticali per il calcolo del raggio. La funzione prende in input un angolo double chiamato "angle", un puntatore a una struttura dati chiamata "t_rules" e un array di float chiamato "ret" che verrà utilizzato per archiviare i punti calcolati.
La funzione utilizza una struttura dati chiamata "t_ray" per archiviare informazioni sul raggio, come l'angolo.
La funzione calcola anche il valore tangente negativo dell'angolo del raggio e utilizza una funzione chiamata "define_ver_ray_and_offset" per definire i valori del raggio e dell'offset.
Quindi, utilizza un ciclo while per controllare se il raggio sta andando a collidere con un muro virtuale utilizzando la funzione "virtual_vertical_colliding". Se non c'è collisione e l'angolo del raggio non è M_PI/2 o 3*M_PI/2 e l'ascissa non è INT_MAX, allora il ciclo continua e aggiorna la posizione del raggio utilizzando i valori dell'offset.
Infine, la funzione assegna i valori finali di x e y del raggio all'array di float "ret" e restituisce l'array come risultato.
In sintesi, questa funzione calcola i punti in cui un raggio virtuale colpisce i muri verticali della mappa.*/

/*Questo codice rappresenta una funzione statica che controlla le linee orizzontali per il calcolo del raggio. La funzione prende in input un angolo double chiamato "angle", un puntatore a una struttura dati chiamata "t_rules" e un array di float chiamato "ret" che verrà utilizzato per archiviare i punti calcolati.
La funzione utilizza una struttura dati chiamata "t_ray" per archiviare informazioni sul raggio, come l'angolo.
La funzione calcola anche il valore tangente inverso dell'angolo del raggio e utilizza una funzione chiamata "define_hor_ray_and_offset" per definire i valori del raggio e dell'offset.
Quindi, utilizza un ciclo while per controllare se il raggio sta andando a collidere con un muro virtuale utilizzando la funzione "virtual_horizontal_colliding". Se non c'è collisione e l'angolo del raggio non è 0 o M_PI e l'ascissa non è INT_MAX, allora il ciclo continua e aggiorna la posizione del raggio utilizzando i valori dell'offset.
Infine, la funzione assegna i valori finali di x e y del raggio all'array di float "ret" e restituisce l'array come risultato.*/


/*Questo codice rappresenta una funzione che calcola un raggio per un gioco o un'applicazione di tipo "raycasting". La funzione prende in input tre parametri: un puntatore a una struttura dati chiamata "t_bres_data", un puntatore a una struttura dati chiamata "t_rules" e due puntatori a una struttura dati chiamata "t_image", uno per la visualizzazione e l'altro per la mappa minima.
La funzione utilizza due array di float chiamati "f_pts" e "s_pts" per archiviare i punti calcolati dalle funzioni "horizontal_lines_check" e "vertical_lines_check".
Successivamente, la funzione imposta i valori x e y del giocatore come i valori x e y per il primo punto del raggio.
Quindi, utilizza una condizione if per determinare quale dei due array di punti (f_pts o s_pts) è più vicino al giocatore e utilizza quel punto come il secondo punto del raggio.
Infine, la funzione utilizza la funzione "bresenham" per tracciare il raggio e decrementa l'angolo del raggio di 1.*/