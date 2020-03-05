var
  n, d, first_divisor: int64;
  found_second: boolean;

begin
  readln(n);
  first_divisor := 1;
  d := 2;
  while (d * d <= n) and not found_second do begin
    while n mod d = 0 do begin
      n := n div d;
      if first_divisor = 1 then
        first_divisor := d
      else 
        if first_divisor <> d then
          found_second := true;
    end;
    d += 1;
    if d > 3 then
      d += 1;
  end;
  if n > 1 then begin
    if first_divisor > 1 then
      found_second := true
    else
      first_divisor := n
  end;
  if found_second then
    writeln(1)
  else
    writeln(first_divisor);
end.
