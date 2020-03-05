Program hw9_ex1;

var n, result: integer;

begin
  readln(n);
  result := n;
  while n > 2 do begin
    n -= 1;
    result *= n;
  end;
  writeln(result);
end.
    
