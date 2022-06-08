int anzahl, k, n, x, y, ausgabe;
string eingabe;
string[] gesplittet;

anzahl = int.Parse(Console.ReadLine());


List<string> tests = new List<string>();

for (int i = 0; i < anzahl; i++)
{
    eingabe = Console.ReadLine();
    tests.Add(eingabe);
}

foreach(string zeile in tests) { 
    gesplittet = zeile.Split(' ');
    x = int.Parse(gesplittet[0]);
    y = int.Parse(gesplittet[1]);
    n = int.Parse(gesplittet[2]);
    ausgabe = 0;
    for (k = n; k > 0; k--)
    {
        if (k % x == y)
        {
            ausgabe = k;
            break;
        }
    }
    Console.WriteLine(ausgabe);
}