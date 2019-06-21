H = zpk([], [-2 -4], 1);

omega = input('Introduceti pulsatia: ');
t = 0:.01:9;
u = 1/2*sin(omega*t);

y = lsim(H, u, t);
plot(t, y);grid; title('Raspuns SLIT')

%{
[num, den] = tfdata(H, 'v');
[A, B, C, D] = tf2ss(num, den); % [A,B,C,D] = ss(H);
v = [];

for i = 1:length(t)
    v(i) = C*expm( A*t(i) )*B;
end

yy = []
for i = 1:length(t)
    s = 0;
    for j = 1:i
        s = s+v(j)*u(i-j+1);
    end
    yy(i) = s*0.01+D*u(i);
end

plot(t, yy); grid; title('SLIT cu ecuatia generala')


%}