
THE PURPOSE OF THIS PROJECT IS TO CODE A SMALL DATA EXCHANGE PROGRAM USING UNIX SIGNALS.

-----------------------------------------------------------------------------------------------------------------------------------------

LIBRERIA  <signal.h>  :

La libreria signal.h in C fornisce le definizioni e le dichiarazioni necessarie per lavorare con i segnali, che sono
meccanismi utilizzati per comunicare eventi o interruzioni tra i processi o all'interno di un singolo processo.
Ecco alcune delle principali componenti della libreria signal.h:

Definizioni di segnali: La libreria signal.h definisce una serie di costanti che rappresentano i segnali, ad esempio SIGINT,
SIGUSR1, SIGUSR2, ecc. Queste costanti vengono utilizzate per identificare i segnali specifici durante la manipolazione dei segnali.

typedef per sig_atomic_t: La libreria signal.h contiene una definizione di tipo sig_atomic_t, che è un tipo di dati intero
garantito come atomico per le operazioni di lettura/scrittura su di esso. Viene spesso utilizzato per la gestione
delle variabili che vengono modificate all'interno dei gestori dei segnali.

struct sigaction: La libreria signal.h definisce la struttura struct sigaction, che viene utilizzata per configurare
l'azione associata a un segnale specifico. Questa struttura contiene campi come sa_handler o sa_sigaction per specificare
la funzione di gestione dei segnali, nonché i flag e l'insieme dei segnali da mascherare durante l'esecuzione del gestore.

Funzioni per la gestione dei segnali: La libreria signal.h fornisce una serie di funzioni per gestire i segnali.
Alcune delle funzioni più comuni includono:

- signal:

La funzione signal viene utilizzata per gestire i segnali in un programma. Prende due argomenti:
signum: È il numero del segnale da gestire. I segnali sono identificati da costanti definite nella libreria;
handler: È un puntatore a una funzione che rappresenta il gestore del segnale. Può essere una funzione
predefinita oppure un puntatore a una funzione personalizzata che viene eseguita quando il segnale viene ricevuto. 
La funzione restituisce il gestore del segnale precedente o SIG_ERR se si verifica un errore.

- usleep:

sospende l'esecuzione del programma per un certo periodo di tempo, misurato in microsecondi.
Durante l'esecuzione della funzione usleep, il programma entra in uno stato di attesa per il periodo di tempo
specificato, permettendo ad altri processi di eseguire il proprio codice. Dopo il completamento del tempo specificato,
l'esecuzione del programma riprende dal punto in cui è stata chiamata la funzione usleep.
Questo, quando stai passando dati tra client e server, può essere utile per consentire al server di elaborare i
segnali inviati dal client e garantire una corretta ricezione dei segnali, dando il tempo al server di rispondere adeguatamente.

- sigemptyset:

La funzione sigemptyset viene utilizzata per inizializzare un insieme di segnali vuoto.
Prende come argomento un puntatore a un insieme di segnali e lo inizializza vuoto.
Questa funzione restituisce 0 se l'inizializzazione dell'insieme è avvenuta con successo,
altrimenti restituisce -1 in caso di errore.

- sigaddset:

La funzione sigaddset viene utilizzata per aggiungere un segnale all'insieme di segnali specificato.
Prende come argomenti un puntatore all'insieme di segnali e il numero del segnale da aggiungere.
Restituisce 0 se l'aggiunta del segnale è avvenuta con successo, altrimenti restituisce -1 in caso di errore.

- sigaction:

La funzione sigaction viene utilizzata per modificare l'azione di un segnale specifico.
Prende tre argomenti: il numero del segnale, una struttura struct sigaction che
specifica la nuova azione da associare al segnale e un puntatore a una struttura
struct sigaction in cui verrà memorizzata l'azione precedente. Restituisce 0 se la modifica
dell'azione del segnale è avvenuta con successo, altrimenti restituisce -1 in caso di errore.

La struct sigaction é composta da diverse variabili tra cui : 
sa_handler: é un puntatore a una funzione che specifica il comportamento da eseguire quando viene ricevuto il segnale.
sa_sigaction: é un puntatore a una funzione alternativa che può essere utilizzata al posto di sa_handler se
              il flag SA_SIGINFO è impostato nel campo sa_flags. La funzione alternativa deve avere il
              seguente prototipo: void function_name(int, siginfo_t *, void *) :
              .int signo: questo argomento rappresenta il numero del segnale ricevuto.
              .siginfo_t *info: questo argomento è un puntatore a una struttura siginfo_t che contiene informazioni aggiuntive
                               sul segnale ricevuto. La struttura siginfo_t può includere dettagli come il PID del processo
                               mittente, il valore del segnale, informazioni sulla coda dei segnali, ecc.
              .void *context: questo argomento è un puntatore a una struttura di contesto che può fornire ulteriori
                             informazioni sull'esecuzione del processo al momento della ricezione del segnale.
                             Tuttavia, è spesso possibile ignorare questo argomento nel caso di gestori di segnali semplici.
              SA_SIGINFO indica quindi che la funzione sa_sigaction deve essere utilizzata al posto di sa_handler
              e ricevere informazioni aggiuntive sul segnale.
              L'utilizzo di sa_sigaction al posto di sa_handler offre alcune funzionalità aggiuntive rispetto al semplice sa_handler:
              .Ricezione di informazioni aggiuntive sul segnale: la funzione sa_sigaction può ricevere un puntatore a una
              struttura siginfo_t come secondo argomento. Questa struttura fornisce informazioni dettagliate sul segnale ricevuto,
              come il processo mittente, il numero del segnale e ulteriori dettagli specifici del segnale. Queste
              informazioni possono essere utili in alcune situazioni, ad esempio per la comunicazione tra processi.
              .Gestione di più segnali: utilizzando sa_sigaction, è possibile specificare un gestore di segnale diverso per
              ciascun segnale. Puoi utilizzare la stessa funzione sa_sigaction per gestire segnali diversi in base al tipo di
              segnale ricevuto. Ad esempio, puoi definire un comportamento specifico per SIGUSR1 e un altro per SIGUSR2.
sa_mask: é un insieme di segnali che vengono bloccati (mascherati) mentre viene eseguita la funzione di gestione
         del segnale. Quando la funzione di gestione del segnale viene chiamata, i segnali presenti nell'insieme
         sa_mask vengono temporaneamente bloccati, evitando che vengano interrotti da altri segnali durante l'esecuzione.

- kill:

La funzione kill viene utilizzata per inviare un segnale a un processo o a un gruppo di processi.
Prende due argomenti: il PID (Process ID) del processo a cui inviare il segnale e il numero del segnale da inviare.
Restituisce 0 se l'invio del segnale è avvenuto con successo, altrimenti restituisce -1 in caso di errore.

- getpid:

La funzione getpid restituisce il PID (Process ID) del processo chiamante. Il PID è un identificatore
univoco assegnato a ogni processo in esecuzione nel sistema operativo.

- pause:

La funzione pause sospende l'esecuzione del processo chiamante fino a quando non viene ricevuto un segnale.
Quando un segnale viene ricevuto e viene eseguito il gestore del segnale associato, la funzione pause ritorna.
Restituisce -1 e imposta errno su E.

- sigemptyset :

Viene utilizzata per creare un insieme vuoto di segnali, rimuovendo tutti i segnali da sa_mask. In altre parole,
sa_mask sarà un insieme vuoto e nessun segnale sarà bloccato. Per bloccare effettivamente i segnali, è necessario
utilizzare la funzione sigaddset per aggiungere i segnali desiderati a sa_mask. Ad esempio, se si desidera bloccare
i segnali SIGINT e SIGTERM, è possibile eseguire le seguenti chiamate:
sigemptyset(&handler.sa_mask);
sigaddset(&handler.sa_mask, SIGINT);
sigaddset(&handler.sa_mask, SIGTERM);                 laddove handler é la variabile di tipo struct sigaction.

-----------------------------------------------------------------------------------------------------------------------------------

- Il simbolo << in C rappresenta l'operatore di shift a sinistra. Viene utilizzato per spostare i bit di un
  valore a sinistra di un certo numero di posizioni. Ad esempio se ho l'espressione (1 << 3), equivale a spostare
  il valore binario 00000001 di 3 posizioni a sinistra, ottenendo 00001000, che in decimale rappresenta il valore 8.

- Nella condizione (c & (1 << bit)) viene utilizzato l'operatore bitwise '&'. L'operatore & effettua un'operazione
  bitwise AND tra c e (1 << bit), confrontando bit per bit i due valori. L'operazione di AND restituisce un
  valore che ha i bit impostati a 1 solo nelle posizioni in cui entrambi i valori hanno un bit impostato a 1.
