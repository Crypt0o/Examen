Fosc=2^26; %64*(10^6)=(2^6)*(2^20); % cristal 64 MHz
Tosc=1/Fosc;
Tsim=Tosc/2; % Fsim = 128 MHz
F_out_pwm=2^10; %1 KHz
% PWM on 8 bits
% F_in_pwm / 2^8 = F_out_pwm
% F_in_pwm = (2^8)*F_out_pwm = 2^18
% we have to divide Fosc with 2^14