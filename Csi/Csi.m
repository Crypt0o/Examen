csi = 0:.01:1;
T = 1;
raspuns = [];
timp = 0:.01:10;

num = 1;

for i = 1:length(csi)
    den = [T^2 2*csi(i)*T 1];
    raspuns(:, i) = step(tf(num, den), timp);
end

val_csi = 1.25

while val_csi < 0 || val_csi > 1
    val_csi = input('Valoare csi: ');
end
index = find(csi == val_csi);
plot(timp, raspuns(:, index))