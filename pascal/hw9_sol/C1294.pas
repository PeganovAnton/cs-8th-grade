type TargetArr =  array[0..2] of integer;


var 
  t, n, i: integer;


function calc_req_nd(n_target, reserve: integer): integer;
begin
  if n_target = 0 then
    calc_req_nd := 6
  else if n_target = 1 then
    if reserve > 0 then
      calc_req_nd := 1
    else 
      calc_req_nd := 3
  else
    calc_req_nd := 1
end;


procedure factorize_1_div(d, req_nd: integer; var n, nd: integer);
begin
  nd := 0;
  while (nd < req_nd) and (n mod d = 0) do begin
    nd += 1;
    n := n div d;
  end;
end;


procedure apply_factor(
    d, nd: integer; 
    var target: TargetArr;
    var reserve: integer;
    var n, n_target: integer);
begin
  if n_target = 0 then begin
    if nd = 6 then begin
      target[0] := d;
      target[1] := d * d;
      target[2] := d * d * d * n;
      n_target := 3;
    end else if nd >= 3 then begin
      target[0] := d;
      target[1] := d * d;
      n_target := 2;
      if n > 1 then begin
        target[2] := n;
        n_target := 3; 
        if nd > 3 then begin
          target[2] *= d;
          if nd > 4 then 
            target[2] *= d;
        end
      end
    end else if nd >= 1 then begin
      target[0] := d;
      n_target := 1;
      if nd > 1 then
        reserve := d;
    end
  end else if n_target = 1 then begin
    if reserve > 0 then begin
      if nd = 1 then begin
        target[1] := d;
        n_target := 2;
        if n > 1 then begin
          target[2] := reserve * n;
          n_target += 1;
        end;
      end
    end else begin
      if nd = 3 then begin
        target[1] := d;
        target[2] := d * d * n;
        n_target := 3
      end else if nd >= 1 then begin
        target[1] := d;
        n_target := 2;
        if n > 1 then begin
          target[2] := n;
          n_target += 1;
          if nd > 1 then begin
            target[2] *= d;
            n_target += 1;
          end
        end
      end
    end
  end
end;


procedure process_number(n: integer);
var
  d, req_nd, n_divs, n_target, reserve: integer;
  target: TargetArr;
begin
  req_nd := calc_req_nd(n_target, reserve);
  factorize_1_div(2, req_nd, n, n_divs);
  apply_factor(2, n_divs, target, reserve, n, n_target);
  d := 3;
  while (n_target < 3) and (n >= d*d) do begin
    req_nd := calc_req_nd(n_target, reserve);
    factorize_1_div(d, req_nd, n, n_divs);
    apply_factor(d, n_divs, target, reserve, n, n_target);
    d += 2;
  end;
  if n_target > 2 then begin
    writeln('YES');
    writeln(target[0], ' ', target[1], ' ', target[2]);
  end else
    writeln('NO');
end;


begin
  readln(t);
  for i:=1 to t do begin
    readln(n);
    process_number(n);
  end;
end.
