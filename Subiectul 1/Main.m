clc
H = zpk([], [-2 -5], 5);
ystep = mystep(H);

figure(1)
[ystepH, tstepH] = step(H);
plot(tstepH, ystepH)
title('Step response using step function')
ylabel('Amplitude')

%Calculam step pentru acelasi interal, luand valoarea maxima a timpului
y = [];
for i = 1:length(tstepH)
    y(i) = subs(ystep, 't', tstepH(i));
end

figure(2)
plot(tstepH, y)
title('Step response using MyStep function')
ylabel('Amplitude')

    
