#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
        int contpal; //Contatore per immagazzinare la lunghezza della stringa argv[2]
        int contvoc; //Contatore per immagazzinare il numero di vocali
        int contcon; //Contatore per immagazzinare il numero di consonanti
        int contstrnor; //Contatore che va da 0 fino alla fine della parola, 
        int contstrinv; //Contatore che va dalla fine della parola a 0, utilizzato per il calcolo della parola palindroma e per il calcolo della parola inversa
	char strinv[30];
        contpal = 0; //Da riga 10 a riga 12 si resettano le variabili "contpal", "contvoc", e "contcon"
        contvoc = 0;
        contcon = 0;

        if(argc < 2 && argc > 3){  //Prima verifica dell'input, il programma controlla se il numero di argomenti passati da terminale è corretto, i quali devono essere sempre 2 o 3.
            printf("Numero di opzioni non corretto, digita ./estring -h per il manuale\n"); //Mette a schermo la seguente frase se la verifica dell'input risulta vera
            return 1; //Il programma termina perchè il numero di opzioni non è corretto
        }
	if(argc == 2 && argv[1][1] != 'h'){
		printf("Numero di opzioni non corretto, digita ./estring -h per il manuale\n"); //Mette a schermo la seguente frase se la verifica dell'input risulta vera
        	return 1; //Il programma termina perchè il numero di opzioni non è corretto
	}
        switch(argv[1][0]){ //Seconda verifica dell'input, un case switch che controlla il primo carattere del primo argomento è "-"
            case '-': //Il programma prosegue con l'esecuzione se il primo carattere del primo argomento è "-"
                switch(argv[1][1]){ //Terza e ultima verifica dell'input, il programma controlla il secondo carattere del primo argomento
                    case 'p': //Il programma esegue il codice presente da linea 24 fino a linea 35 se il secondo carattere del primo argomento è "p"
                        //INIZIO CONTROLLO PAROLA PALINDROMA
                        for(contstrnor = 0, contstrinv = strlen(argv[2]) - 1; contstrnor < strlen(argv[2]), contstrinv >= 0; contstrnor++, contstrinv--){ //Ciclo for che: 1) Assegna alla variabile contstrnor il valore 0; 2) Assegna alla variabile contstrinv il valore di "strlen(argv[2]) - 1" (la lunghezza della parola inserita in input decrementata di 1, questo perchè in C si include lo 0 negli array); 3) Verifica se contstrnor è minore di "strlen(argv[2])" (quindi verifica se contstrnor è minore della lunghezza della parola inserita in input); 4) Verifica se contstrinv è maggiore o uguale di 0; 5) Incrementa contstrnor e decrementa contstrinv al termine del codice (fino a linea 28)
                            if(argv[2][contstrnor] == argv[2][contstrinv]){ //Il programma verifica se argv[2][contstrnor] è uguale a argv[2][contstrinv]
                                contpal++; //Se la verifica risulta vera, incrementa questa variabile
                            }
                        }
                        if(contpal == strlen(argv[2])){ //Il programma verifica se "contpal" è uguale alla lunghezza di argv[2] (la parola in input)
                            printf("La parola %s è un palindromo\n", argv[2]); //Se la verifica è vera, visualizza questa frase inserendo al posto di %s il contenuto di argv[2] (la parola in input)
                        }
                        else{
                            printf("La parola %s non è un palindromo\n", argv[2]); //Se la verifica risulta falsa, visualizza quest'altra frase inserendo al posto di %s il contenuto di argv[2] (la parola in input)
                        }
                        break;
                        //FINE CONTROLLO PAROLA PALINDROMA
                    case 'v': //Il programma esegue il codice presente da linea 39 fino a linea 48 se il secondo carattere del primo argomento è "v"
                        //INIZIO CONTROLLO VOCALI E CONSONANTI
                        for(contstrnor = 0; contstrnor < strlen(argv[2]); contstrnor++){ //Ciclo for che: 1) Assegna a contstrnor il valore di 0; 2) Controlla se contstrnor è minore a "strlen(argv[2])" (la lunghezza della parola inserita in input); 3) Incrementa contstrnor di 1 al termine del codice (fino a linea 46)
                            if(argv[2][contstrnor] == 'A' || argv[2][contstrnor] == 'E' || argv[2][contstrnor] == 'I' || argv[2][contstrnor] == 'O' || argv[2][contstrnor] == 'U' || argv[2][contstrnor] == 'a' || argv[2][contstrnor] == 'e' || argv[2][contstrnor] == 'i' || argv[2][contstrnor] == 'o' || argv[2][contstrnor] == 'u'){ //Il programma verifica se "argv[2][contstrnor]" (la lettera puntata dal contatore "contstrnor") è una vocale maiuscola o minuscola
                                contvoc++; //Se la verifica è vera, incrementa questa variabile
                            }
                            else{
                                contcon++; //Se la verifica è falsa, incrementa quest'altra variabile
                            }
                        }
                        printf("Nella parola %s sono presenti %d vocali e %d consonanti\n", argv[2], contvoc, contcon);  //Visualizza questa frase inserendo al posto di %s %d e %d il contenuto delle variabili argv[2], contvoc, e contcon rispettivamente (quindi visualizza la parola in input, il numero di vocali e il numero di consonanti)
                        break;
                        //FINE CONTROLLO VOCALI E CONSONANTI
                    case 'i': //Il programma esegue il codice presente da linea 52 fino a linea 56 se il secondo carattere del primo argomento è "i"
                        //INIZIO CALCOLO PAROLA INVERSA
                        printf("L'inverso della stringa %s e' ", argv[2]); //Visualizza questa frase inserendo al posto di %s il valore di argv[2] quindi visualizza la parola in input)
                        for(contstrinv = strlen(argv[2]) - 1; contstrinv >= 0; contstrinv--){ //Ciclo for che: 1) Assegna a contstrinv il valore di "strlen(argv[2])" - 1 (la lunghezza della parola inserita in input decrementata di 1, questo perchè in C si include lo 0 negli array); 2) Controlla se contstrinv è minore o uguale a 0 (la lunghezza della parola inserita in input); 3) Decrementa contstrinv di 1 al termine del codice (fino a linea 55)
                            printf("%c", argv[2][contstrinv]); //Visualizza il carattere presente in argv[2][contstrinv] (la lettera puntata da contstrinv)
                        }
			printf("\n");
                        break;
                        //FINE CALCOLO PAROLA INVERSA
                    case 'h': //Il programma esegue il codice presente da linea 60 fino a linea 61 se il secondo carattere del primo argomento è "h"
                        //INIZIO MANUALE
                        printf("eString e' un programma scritto in C che puo':\n1) Controllare se una parola e' palindroma o no\n2) Contare vocali e consonanti\n3) Calcolare l'inverso di una parola\n\nSintassi programma: ./estring <opzione> <parola>\n\nOpzioni disponibili: \n-p\t Verifica se una parola e' palindroma\n-v\t Conta le vocali e le consonanti in una parola\n-i\t Calcola l'inverso di una parola\n"); //Visualizza il manuale
                        break;
                        //FINE MANUALE
                    default: //Il programma esegue il codice presente da linea 64 a linea 65 se il secondo carattere del primo argomento è diverso da "p", "v", "i", "h"
                        printf("Opzione non valida, digita ./estring -h per il manuale\n"); //Visualizza la seguente frase
                        break;
                }
                break;
            default: //Il programma esegue queste linee di codice se il primo carattere dell'opzione non è un "-"
                printf("Input non valido, digita ./estring -h per il manuale\n"); //Visualizza questa frase
                return 1;
                break;
        }
}
