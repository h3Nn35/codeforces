int anzahltests = int.Parse(Console.ReadLine()), a, b, c, moves;
List<string> tests = new List<string>();

for (int i = 0; i < anzahltests; i++)
    tests.Add(Console.ReadLine());

foreach (string x in tests)
{
    moves = 0;
    string[] split = x.Split(' ');
    a = int.Parse(split[0]);
    b = int.Parse(split[1]);
    if (a > b)
        (a, b) = (b, a);

    if (a == b)
    {
        Console.WriteLine(moves);
        continue;
    }

    c = b - a;

    if (c % 10 != 0)
        moves++;
    
    moves = moves + c / 10;
    Console.WriteLine(moves);
}
