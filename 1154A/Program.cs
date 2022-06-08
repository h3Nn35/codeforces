string? eingabe;
eingabe = Console.ReadLine();
string[] zahlen;
zahlen = eingabe.Split(' ');
List<int> zeile = new List<int>();
int a, b, c;

foreach(string x in zahlen)
{
    zeile.Add(int.Parse(x));
}

zeile.Sort();

a = zeile[3] - zeile[0];
b = zeile[3] - zeile[1];
c = zeile[3] - zeile[2];

Console.WriteLine(a + " " + b + " " + c);
