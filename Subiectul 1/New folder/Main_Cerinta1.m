%generam functia de transfer a sistemului continuu in timp
sys_c=tf(1,conv([1,1],[1,5]));

%generam un timp de 11 secunde cu un pas de o sutime de secunda
t=0:.01:11; 

% generam vectorul de intrare u (calculele se fac vectorial!)
u= 1;

% se determina numaratorul (num) si numitorul (den) 
% ale functiei de transfer
[num,den]=tfdata(sys_c,'v');

% se determina reprezentarea de stare
[A,B,C,D]=tf2ss(num,den);
v=[];

% se calculeaza la fiecare moment de timp vectorul C*expm(A*t)*B
for i=1:length(t)
    v(i)=C*expm(A*t(i))*B;
end

% se calculeaza integrala din produsul de convolutie dat de formula 
yy=[];
for i=1:length(t)
    s=0;
    for j=1:i
        s=s+v(j)*u;
    end
    yy(i)=s*0.01+D*u;
end

figure(2)
plot(t,yy);grid;
title('Calcul raspuns SLIT cu ecuatia generala')