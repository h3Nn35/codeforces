int anzahl = int.Parse(Console.ReadLine()), sum = 0;
string zeile = Console.ReadLine();
string[] gesplittet = zeile.Split(' ');
List<int> citizen = new List<int>();

foreach (string x in gesplittet)
    citizen.Add(int.Parse(x));

citizen.Sort();

for (int i = 0; i < anzahl; i++)
{
    sum += citizen[anzahl - 1] - citizen[i];
}

Console.WriteLine(sum);
