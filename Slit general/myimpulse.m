function y = myimpulse(H)
    
    [num, den] = tfdata(H, 'v');
    
    syms s
    Hs = simplify( poly2sym(num, s) / poly2sym(den, s) );
 
    
    Y = 1/(s^2) * Hs
    y = simplify( ilaplace(Y) );
end

%{
function y = myImpulse(A, B, C, D)
    
    syms s
    H = simplify ( C* inv( s* eye(size(A, 1)) - A) * B + D );
    
    Y = 1/s^2 * H;
    y = simplify(ilaplace(Y))

%}