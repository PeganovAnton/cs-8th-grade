Program Evclid1;
var
  n, resul:integer;
begin;
  read(n);
  resul:=n;
  while n>2 do
  begin
    n-=1;
    resul*=n;
  end;
  writeln(resul);
end.