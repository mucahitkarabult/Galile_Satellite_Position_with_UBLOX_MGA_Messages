function [final_unique_sort] = find_position(ephemeris,t)
%FİND_POSİTİON Summary of this function goes here
%   Detailed explanation goes here
GM = 3.986005e14;             % earth's universal gravitational [m^3/s^2]
we = 7.2921151467e-5; % earth's rotation rate (rad/sec)
% read navigation file to get orbit elements
c = 2.99792458e8;   

Week_number=2.165000000000E+03;

GM = 3.986005e14;             % earth's universal gravitational [m^3/s^2]
we = 7.2921151467e-5; % earth's rotation rate (rad/sec)

svid=ephemeris(:,1);
Y=ephemeris(:,2);
M=ephemeris(:,3);
D=ephemeris(:,4);
H=ephemeris(:,5);
min=ephemeris(:,6);
sec=ephemeris(:,7);
af0=ephemeris(:,8);
af1=ephemeris(:,9);
af2=ephemeris(:,10);
iod=ephemeris(:,11);
crs=ephemeris(:,12);
delta_n=ephemeris(:,13);
m0=ephemeris(:,14);
cuc=ephemeris(:,15);
e=ephemeris(:,16);
cus=ephemeris(:,17);
sqrt_a=ephemeris(:,18);
toe=ephemeris(:,19);
cic=ephemeris(:,20);
omege0=ephemeris(:,21);
cis=ephemeris(:,22);
i0=ephemeris(:,23);
crc=ephemeris(:,24);
omega=ephemeris(:,25);
omega_dot=ephemeris(:,26);
idot=ephemeris(:,27);

n=height(ephemeris);
 
for j=1:n
t1 = t;
t1.TimeZone = 'UTCLeapSeconds'; 

tk=galileo_time(t1,toe(j));


n0=sqrt(GM)/(sqrt_a(j)^3);
mk=m0(j)+(n0+delta_n(j))*tk;
E=keplerEq(mk,e(j),1e-10); 


sin_v=sqrt(1-e(j)^2)*sin(E);
cos_v=cos(E)-e(j);
v = atan2(sin_v,cos_v);


phi = v+omega(j);

% Delta_uk(Rad):Argument of lattitude correction
% Delta_rk(meter):Argument of radius correction
% Delta_ik(Rad):Argument of inclination correction

Delta_uk=cus(j)*sin(2*phi)+cuc(j)*cos(2*phi);
Delta_rk=crs(j)*sin(2*phi)+crc(j)*cos(2*phi);
Delta_ik=cis(j)*sin(2*phi)+cic(j)*cos(2*phi);

u= phi + Delta_uk;
r = sqrt_a(j)^2*(1-e(j)*cos(E)) + Delta_rk;
i = i0(j)+idot(j)*tk  + Delta_ik; %dogru birimler

Omega = omege0(j)+(vpa(omega_dot(j))-we)*tk-we*toe(j); %birimler do[ru

x1 = cos(u)*r;
y1 = sin(u)*r;

satp(j,1) = svid(j);
satp(j,2) = x1*cos(Omega)-y1*cos(i)*sin(Omega);
satp(j,3) = x1*sin(Omega)+y1*cos(i)*cos(Omega);
satp(j,4) = y1*sin(i);

time(j,1)={t1};
end
for i=1:n
    lla_position(i,1)=satp(i,1);
    
    lla=ecef2lla([satp(i:i,2:4)]);
    
    lla_position(i,2)=lla(1);  % lat-long-alt
    lla_position(i,3)=lla(2);
    lla_position(i,4)=lla(3);
    time_el=time{i,1};
    time_el.TimeZone='';
    new_t(i,1)=time_el;
end
 
 final = table(new_t, lla_position(:,1:1), lla_position(:,2:2),lla_position(:,3:3), lla_position(:,4:4),'VariableNames', {'time UTC+3', 'sat_number','Latitude','Longitude','Altitude'}); %table


 final_unique = unique(final,'rows');
 final_unique_sort = sortrows(final_unique,[1,2]);


% 'sat_number','Latitude','Longitude','Altitude'

end

