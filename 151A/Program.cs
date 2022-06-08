int n, k, l, c, d, p, nl, np;
int drinks, slices, salt, result;
List<int> min = new List<int>();

string eingabe = Console.ReadLine();
string[] gesplittet = eingabe.Split(' ');

n = int.Parse(gesplittet[0]);
k = int.Parse(gesplittet[1]);
l = int.Parse(gesplittet[2]);
c = int.Parse(gesplittet[3]);
d = int.Parse(gesplittet[4]);
p = int.Parse(gesplittet[5]);
nl = int.Parse(gesplittet[6]);
np = int.Parse(gesplittet[7]);

drinks = k * l / nl;
slices = c * d;
salt = p / np;

min.Add(k * l / nl);
min.Add(c * d);
min.Add(p / np);
min.Sort();

result = min[0] / n;

Console.WriteLine(result);
