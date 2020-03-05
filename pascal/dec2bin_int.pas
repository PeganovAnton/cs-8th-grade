Program Dec2bin;
begin;
  var dec, bin, i, exp: real;
  exp:=1;
  read(dec);
  while dec>0 do
  begin
      i:=dec mod 2;
      dec:=dec div 2;
      bin+=exp*i;
      exp*=10;
  end;
  write(bin);
end.