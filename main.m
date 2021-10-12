%this version of code find the position of satellite current time also url
%generator add to download gps brodcast data 
% also add brodcast rinex file reader for gps. Broadcast rinex file reader solve
% the problem same data come more than once also came earlier than expected





% % merge_file('all_rinex_data.rnx','Data'); % to merge ephemeris file data.
% % Data stands for directory  contain ephemeris data files
% %



time_now=datetime('now');
remainder=2000;
year=rem(year(time_now),remainder);
hour=hour(time_now);
month=month(time_now);
day=day(time_now);
% 
% if rem(hour,3)
% end

system('python data_download.py');


filename='result_gal_'+string(year)+'_'+string(month)+'_'+string(day)+'.'+string(hour)+'.ubx';
filename = fullfile('Data_gal', filename);
ephemeris=read_from_mga(filename);
Plot(ephemeris,10);

% s
% [url,time,ref_day]=get_URL(); % time stands for 21 for 2021  to achive correct nasa url
% 
% gps_code=strcat(time,'n');
% 
% filename='brdc';
% ref_day=strcat(ref_day,'0.');
% filename=strcat(filename,ref_day);
% filename=strcat(filename,gps_code);
% 
% 
% filename=strcat(filename,'.gz');
% url=strcat(url,gps_code);
% url=strcat(url,'/');
% url=strcat(url,filename);
% 


