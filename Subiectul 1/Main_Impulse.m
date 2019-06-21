clc
H = zpk([], [-2 -5], 5);
ystep = myimpulse(H);


figure(1)
[ystepH, tstepH] = impulse(H);
plot(tstepH, ystepH)
title('Step response using Impulse function')
ylabel('Amplitude')

%Calculam step pentru acelasi interal, luand valoarea maxima a timpului

y = [];
for i = 1:length(tstepH)
    y(i) = subs(ystep, 't', tstepH(i));
end

figure(2)
plot(tstepH, y)
lsim(H, y, tstepH)
title('Step response using MyImpulse function')
ylabel('Amplitude')