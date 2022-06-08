string eingabe = Console.ReadLine();
string[] gesplittet = eingabe.Split(' ');
List<int> zahlen = new List<int>();
int a, b, c;

foreach (string x in gesplittet) {
    zahlen.Add(int.Parse(x));
}

zahlen.Sort();
a = zahlen[0];
b = zahlen[1];
c = zahlen[2];

Console.WriteLine((c-b)+(b-a));
