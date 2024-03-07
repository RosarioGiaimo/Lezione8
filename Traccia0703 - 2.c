#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMERO_DOMANDE 3 // Numero di domande nel gioco

// Struttura per rappresentare una domanda
typedef struct
{
    char testo[100];       // Testo della domanda
    char risposte[3][50];  // Array per le risposte
    int risposta_corretta; // Indice della risposta corretta
} Domanda;
// Funzione per mostrare il menu iniziale
void mostra_menu()
{
    printf("\nBenvenuto al gioco di domande e risposte!\n");
    printf("Scegli cosa vuoi fare:\n");
    printf("A) Iniziare una nuova partita\n");
    printf("B) Uscire dal gioco\n");
}
// Funzione per iniziare una nuova partita
void nuova_partita()
{
    int punteggio = 0; // Inizializza il punteggio del giocatore

    // Array di domande con relative risposte
    Domanda domande[NUMERO_DOMANDE] = {
        {"Qual e' la capitale dell'Italia?", {"Roma", "Milano", "Firenze"}, 0},
        {"Dove e' nato Giaimo Rosario?", {"Palermo", "Selinunte", "Sciacca"}, 2},
        {"Che giorno e' nato Giaimo Rosario?", {"30", "6", "19"}, 1}
    };
    char nome[50];
    printf("\nInserisci il tuo nome: ");
    scanf("%s", nome);
    printf("\n%s, preparati per le domande!\n", nome);
    for (int i = 0; i < NUMERO_DOMANDE; i++)
    {
        printf("\nDomanda %d: %s\n", i + 1, domande[i].testo);
        // Mostra le opzioni di risposta
        for (int j = 0; j < 3; j++)
        {
            printf("%d) %s\n", j + 1, domande[i].risposte[j]);
        }
        // Chiede all'utente di inserire la risposta
        int risposta_utente;
        printf("Inserisci il numero della risposta: ");
        scanf("%d", &risposta_utente);
       
        // Controlla se la risposta è corretta
        if (risposta_utente - 1 == domande[i].risposta_corretta)
        {
            printf("Esatto!\n");
            punteggio++; // Incrementa il punteggio
        }
        else
        {
            printf("Sbagliato!\n");
        }
    }
    // Alla fine della partita, mostra il punteggio ottenuto
    printf("\n%s, hai totalizzato %d punti!\n", nome, punteggio);
}
int main()
{
    char scelta;
    do
    {
        mostra_menu();
        printf("\nScelta: ");
        scanf(" %c", &scelta);

        switch (scelta)
        {
        case 'A':
        case 'a':
    
            nuova_partita();
            break;
        case 'B':
        case 'b':
        
            printf("\nGrazie per aver giocato!\n");
            break;
        default:
            printf("\nScelta non valida. Riprova.\n");
        }
    } while (scelta != 'B' && scelta != 'b');
    return 0;
}