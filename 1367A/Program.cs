int anzahl = int.Parse(Console.ReadLine()), i;
List<string> tests = new List<string>();
string ausgabe;

for (i = 0; i < anzahl; i++)
    tests.Add(Console.ReadLine());

foreach(string x in tests)
{
    ausgabe = x.Substring(0, 1);
    for (i = 1; i < x.Length; i++)
    {
        if (i % 2 != 0)
            ausgabe = ausgabe + x.Substring(i, 1);
    }
    Console.WriteLine(ausgabe);
}
