int d = int.Parse(Console.ReadLine());
int res = (d % 8) == 0 ? 3 : (d % 8) - 5;
Console.Write(res);