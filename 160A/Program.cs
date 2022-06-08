int anzahl = int.Parse(Console.ReadLine()), gesamt, brudereins, genommen = 0, taken = 0;

string zeile = Console.ReadLine();
string[] gesplittet = zeile.Split(' ');

List<int> coins = new List<int>();

foreach (string x in gesplittet)
    coins.Add(int.Parse(x));

gesamt = coins.Sum();

brudereins = (gesamt / 2) + 1;

coins.Sort();

for (int i = coins.Count - 1; i >= 0; i--)
{
    genommen += coins[i];
    taken++;
    if (genommen >= brudereins)
        break;
}

Console.WriteLine(taken);
