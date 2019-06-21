function y = mystep(H)
    
    [num, den] = tfdata(H, 'v');
    
    syms s
    Hs = simplify( poly2sym(num, s) / poly2sym(den, s) );
    
    Y = 1/s * Hs;
    y = simplify( ilaplace(Y) );
end