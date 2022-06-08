int anzahl, anzahlteams = 0;
string children;
string[] gesplittet;
List<int> programmer = new List<int>();
List<int> mathematician = new List<int>();
List<int> sportler = new List<int>();
List<string> teams = new List<string>();

anzahl = int.Parse(Console.ReadLine());
children = Console.ReadLine();
gesplittet = children.Split(' ');

for (int i = 0; i < gesplittet.Length; i++)
    if (gesplittet[i] == "1")
        programmer.Add(i + 1);
    else if (gesplittet[i] == "2")
        mathematician.Add(i + 1);
    else
        sportler.Add(i + 1);

while(programmer.Count > 0 && mathematician.Count > 0 && sportler.Count > 0)
{
    teams.Add(programmer[0] + " " + mathematician[0] + " " + sportler[0]);
    programmer.RemoveAt(0);
    mathematician.RemoveAt(0);
    sportler.RemoveAt(0);
    anzahlteams++;
}



Console.WriteLine(anzahlteams);

foreach (string team in teams)
    Console.WriteLine(team);
