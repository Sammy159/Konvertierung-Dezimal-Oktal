#include <stdio.h>
#include <math.h>	
#include <limits.h>

void main(void)
{
	int run = 1;																					/*Variable für eine Loop, welche auf Status 1 bzw. High gesetzt wird*/
	do																								/*Do-Schleife welche für Loop des Programmes sorgt, nach erfoglreicher Berechnung wird das Auswahlmenue wieder ausgegeben*/
	{
		double ausw;
		int Eingabetest;

		printf("****************** AUSWAHLMENUE ******************\n");							/*Hier wird das Auswahlmenü in der Konsole ausgegeben*/
		printf("*                                                *\n");
		printf("*        1.) Konvertierung Dezimal --> Oktal     *\n");
		printf("*        2.) Konvertierung Oktal --> Dezimal     *\n");
		printf("*        3.) Abbruch                             *\n");
		printf("*                                                *\n");
		printf("**************************************************\n");
		printf("AUSWAHL: ");
		printf("\n");
		int rueckAuswahl = scanf("%lf", &ausw);													/*Hier wird die Eingabe eingelesen*/
		printf("\n");
		Eingabetest = ausw;
		if ((rueckAuswahl != 1) || (ausw < 1 || ausw > 4) || ((ausw - Eingabetest) != 0))
		{
			printf("Falsche Eingabe.\n\n");												        	/*Fehlermeldung, sollte kein Integer Datentyp vorliegen*/
			while (getchar() != '\n');
		}
		else if (ausw == 1)																		/*Dezimal in Oktal*/
		{
			double Dezimal;
			int testwert;
			printf("Geben Sie eine ganze positive Dezimalzahl ein: ");
			int rueck = scanf("%lf", &Dezimal);												/*Einlesen der Oktalzahl*/
			printf("\n");
			testwert = Dezimal;

			if (rueck != 1)																	/*Fehlermeldung, sollte kein Integer Datentyp vorliegen*/
			{
				printf("Fehler bei der Eingabe. Geben Sie eine Dezimalzahl ein.\n\n");
				while (getchar() != '\n');
			}
			else if (Dezimal < 0)															/*Fehlermeldung, sollte Dezimalzahl negativ sein*/
			{
				printf("Geben Sie bitte eine positive Dezimalzahl ein.\n\n");
			}
			else if ((Dezimal - testwert) != 0)												/*Fehlermeldung, sollte eine Kommazahl angegeben werden oder Int überlaufen*/
			{
				printf("Geben Sie bitte eine postive ganze Zahl ein, die kleiner als 2.1 Milliarden ist. \n\n");
			}
			else																			/*Bei korrekter Eingabe startet Rechnung*/
			{
				int Quotient = Dezimal;
				int RestPos;
				int Rest[100];

				for (RestPos = 0; Quotient > 0; RestPos++)										/*Reste ermitteln und in Array abspeichern*/
				{
					if (RestPos >= 100)
					{
						printf("Die Zahl ist zu gross.\n\n"); RestPos = 0; break;			/*Fehlermeldung, sollte das Array "Rest" überlaufen*/
					}
					Rest[RestPos] = Quotient % 8;
					Quotient = Quotient / 8;
				}

				printf("Oktalzahl: ");
				for (int x = RestPos - 1; x >= 0; x--)											/*Reste in umgedrehter Reihenfolge auslesen*/
				{
					printf("%d", Rest[x]);
				}
				printf("\n\n");
				run = 1; continue;
			}
		}

		else if (ausw == 2)																				/*Oktal in Dezimal*/
		{
			int DezimalErgebnis = 0;
			int Overflow = 0;
			char Oktal[9];
			int OktalInt[9];
			int OktalAnzahl;

			printf("Geben Sie eine Oktalzahl ein: ");
			int rueck = scanf("%8s", &Oktal);														/*Einlesen der Dezimalzahl*/
			printf("\n");

			while (getchar() != '\n')																/*Eingabepuffer leeren und speichern wieviele Zeichen über 8 Zeichen eingegeben werden */
			{
				Overflow++;
			}
			if (Overflow != 0)																		/*Fehlerprüfung, wenn eingelesene Zahl zu groß ist */
			{
				printf("Die eingebene Zahl ist zu lang. Maximal 8 Stellen.\n\n");
				Overflow = 0;
			}
			else if (rueck != 1)																	/*Fehlerprüfung, wenn scanf nicht funktioniert hat*/
			{
				printf("Fehler bei Eingabe. Die eingegebene Zahl ist zu groß!\n\n");
				while (getchar() != '\n');
			}
			else																					/*Bei korrekter Eingabe startet Rechnung*/
			{
				for (OktalAnzahl = 0; Oktal[OktalAnzahl] != 0; OktalAnzahl++);					/*Anzahl der Oktalstellen ermitteln*/
				for (int i = 0; i < OktalAnzahl; i++)
				{
					if (Oktal[i] == '0' || Oktal[i] == '1' || Oktal[i] == '2' || Oktal[i] == '3' || Oktal[i] == '4' || Oktal[i] == '5' || Oktal[i] == '6' || Oktal[i] == '7')		/*Prüfung, ob jede eingelesene Zahl eine Oktalzahl ist*/
					{
						OktalInt[i] = Oktal[i] - '0';									/*char in Integer umwandeln*/
						int Oktal_von_hinten_lesen = (OktalAnzahl - 1) - i;
						double Hochzahl = pow(8, Oktal_von_hinten_lesen);
						int HochzahlInt = Hochzahl;
						int OktalZwischenwert = OktalInt[i] * HochzahlInt;
						DezimalErgebnis = DezimalErgebnis + OktalZwischenwert;

						if (i == OktalAnzahl - 1)										/*Ausgabe der Dezimalzahl nach erfolgreicher Berechnung*/
						{
							printf("Dezimalzahl: %d\n\n", DezimalErgebnis);
						}
					}

					else																	/*Gibt Fehlermeldung aus sollte es sich um eine negative, nicht ganze Eingabe handeln oder einer Eingabe <=0x<8*/
					{
						printf("Bitte Oktalzahl eingeben (Besteht aus positiven, ganzen Ziffern zwischen '0' und '7').\n\n");
						break;
					}
				}
				run = 1; continue;																/* Neustart des Programmes/Loop*/
			}
		}
		else if (ausw == 3)																				/*Abbruch*/
		{
			printf("Abbruch\n\n");
			run = 0;
		}
	} while (run);
}

