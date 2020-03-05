Program A935;
var l, n, i: integer;
begin;
  read(n);
  i:=0;
  for l:=1 to n-1 do begin
    if (n mod l) = 0 then
      i:=i+1
  end;
  write(i);
end.
