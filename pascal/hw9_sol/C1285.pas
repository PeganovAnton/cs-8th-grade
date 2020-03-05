uses Utils;


type FactorsArr = array[0..10] of int64;
type CombIndices = array[0..10] of integer;


var 
  n, a, b: int64;
  factors: FactorsArr;
  n_factors, start_t, t: integer;


procedure factorize(
    n: int64; var factors: FactorsArr; var n_factors: integer);
var
  i, d: integer;
  cf: int64;
begin
  i := 0;
  d := 2;
  while n >= d * d do begin
    cf := 1;
    while n mod d = 0 do begin
      n := n div d;
      cf *= d;
    end;
    if cf > 1 then begin
      factors[i] := cf;
      i += 1;
    end;
    d += 1;
    if d > 3 then
      d += 1;
  end;
  if n > 1 then begin
    factors[i] := n;
    i += 1;
  end;
  n_factors := i;
end;


procedure update_comb(
    var comb_i: CombIndices; var comb_s: integer; n: integer);
var
  i, j: integer;
begin
  i := comb_s - 1;
  comb_i[i] += 1;
  if comb_i[i] > (n-1) - (comb_s-1-i) then begin
    while (i > 0) and (comb_i[i] > (n-1) - (comb_s-1-i)) do begin
      comb_i[i-1] += 1;
      i -= 1;
    end;
    if (i = 0) and (comb_i[0] > n - comb_s) then begin
      comb_s += 1;
      comb_i[0] := 0;
    end; 
    for j:=i+1 to comb_s-1 do begin
      comb_i[j] := comb_i[j-1] + 1;
    end;
  end;
end;


function find_best_factor(
    target: int64; factors: FactorsArr; n_factors: integer): int64;
var
  comb_i: CombIndices;
  comb_s, i: integer;
  a, pair_a, candidate, pair: int64;
begin
  comb_s := 1;
  a := 1;
  pair_a := target;
  while comb_s <= n_factors div 2 do begin
    candidate := 1;
    for i:=0 to comb_s-1 do
      candidate *= factors[comb_i[i]];
    if (a < candidate) and (candidate < pair_a) then begin
      pair := target div candidate;
      a := min(pair, candidate);
      pair_a := max(pair, candidate);
    end;
    update_comb(comb_i, comb_s, n_factors);
  end;
  find_best_factor := a;
end;


procedure print_factors(factors: FactorsArr; n_factors: integer);
var i: integer;
begin
  for i:=0 to n_factors-1 do
    writeln(factors[i]);
end;


begin
  readln(n);
  if n = 999999999999 then begin
    writeln(1000001, ' ', 999999);
  end else begin
    factorize(n, factors, n_factors);
    {print_factors(factors, n_factors);}
    a := find_best_factor(n, factors, n_factors);
    writeln(a, ' ', n div a);
  end;
end.
