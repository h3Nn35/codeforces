int anzahl = 2 * int.Parse(Console.ReadLine()), anzahlzahlen = 0;
List<string> eingabe = new List<string>();
List<int> nummern = new List<int>();
string zeilen;
bool ergebnis;

for (int i = 0; i < anzahl; i++)
{
    eingabe.Add(Console.ReadLine());
}


for (int i = 0; i < anzahl; i += 2)
{
    ergebnis = true;
    if (eingabe[i] != "1")
    {
        anzahlzahlen = int.Parse(eingabe[i]);
        zeilen = eingabe[i + 1];
        string[] zeile = zeilen.Split(' ');
        for (int x = 0; x < anzahlzahlen; x++)
        {
            nummern.Add(int.Parse(zeile[x]));
        }
        nummern.Sort();
        for (int y = 0; y < anzahlzahlen - 1; y++)
        {
            if (nummern[y+1] - nummern[y] > 1)
            {
                ergebnis = false;
                break;
            }
        }
    }
    if (ergebnis)
        Console.WriteLine("YES");
    else
        Console.WriteLine("NO");

    nummern.Clear();
}

