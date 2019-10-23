#include <stdio.h>
#include <time.h>

#define GIORNI_MESE 30     /* Dichiarazione Macro per i giorni del Mese*/
#define GIORNI_ANNO 360    /* Dichiarazione Macro per i giorni dell'Anno*/

typedef struct {    /* Dichiarazione struttura*/
    int giorno;
    int mese;
    int anno;
    int dataInGiorni;
} Data;

void avviaProgramma();    /* Dichiarazione procedura*/
void confrontaEta(Data d1, Data d2, Data d3);    /* Dichiarazione procedura*/
void stampaEtaPersone(Data d1, Data d2, Data d3, Data dc);    /* Dichiarazione procedura*/
void stampaEta(Data d1, Data d2);    /* Dichiarazione procedura*/
Data acquisisciDataCorrente();    /* Dichiarazione funzione*/
Data acquisisciData();    /* Dichiarazione funzione*/

int main() {

    avviaProgramma();

    return 0;
}

void avviaProgramma() {
    Data dataNascita1; //Data nascita Fabio
    Data dataNascita2; //Data nascita Alessandro
    Data dataNascita3; //Data nascita Federico
    Data dataCorrente; /* Data corrente*/

    dataCorrente = acquisisciDataCorrente();

    dataNascita1 = acquisisciData();
    dataNascita2 = acquisisciData();
    dataNascita3 = acquisisciData();

    stampaEtaPersone(dataNascita1, dataNascita2, dataNascita3, dataCorrente);

    confrontaEta(dataNascita1, dataNascita2, dataNascita3);
}

void confrontaEta(Data d1, Data d2, Data d3){
    if (d1.dataInGiorni < d2.dataInGiorni && d1.dataInGiorni < d3.dataInGiorni)
        printf("\nFabio e\' il piu\' giovane.");
    else if (d2.dataInGiorni < d1.dataInGiorni && d2.dataInGiorni < d3.dataInGiorni)
        printf("\nAlessandro e\' il piu\' giovane.");
    else
        printf("\nFederico e\' il piu\' giovane.");
}

void stampaEtaPersone(Data d1, Data d2, Data d3, Data dc){
    printf("\nFabio");
    stampaEta(d1, dc);
    printf("\nAlessandro");
    stampaEta(d2, dc);
    printf("\nFederico");
    stampaEta(d3, dc);
}

void stampaEta(Data d, Data dc){
    int anni;
    anni = (dc.dataInGiorni - d.dataInGiorni) / GIORNI_ANNO;
    printf(" ha %d anni.", anni);
}

Data acquisisciDataCorrente(){
    Data d;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    d.anno = tm.tm_year + 1900;
    d.mese = tm.tm_mon + 1;
    d.giorno = tm.tm_mday;

    d.dataInGiorni = d.giorno + d.mese * GIORNI_MESE + d.anno * GIORNI_ANNO;

    return d;
}

Data acquisisciData(){
    Data d;

    printf("\nInserisci anno:");
    scanf("%d", &d.anno);
    printf("\nInserisci mese:");
    scanf("%d", &d.mese);
    printf("\nInserisci giorno:");
    scanf("%d", &d.giorno);

    d.dataInGiorni = d.giorno + d.mese * GIORNI_MESE + d.anno * GIORNI_ANNO;
    return d;
}
