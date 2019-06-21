R1 = 1000;
R2 = 1500;

C1 = 10^-6;
C2 = 1.24* 10^-6;

global a b
a = [-(R1+R2)/(R1*R2*C1), 1/(R2*C2); 1/(R2*C1), - 1/(R2*C2)];
b = [1/R1 0]';
c = [0  1/C2];
d = 0;

sys = ss(a,b,c,d);
figure(1); 
step(sys);
hold on

[t, x] = ode15s(@reteaRC2, [0 0.03], [0 0]);
y = x/C2;
%figure(2);
plot(t, y, '--r');