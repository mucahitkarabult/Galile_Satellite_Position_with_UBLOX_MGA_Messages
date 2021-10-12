function Plot(ephemeris,epoch)
%PLOTTTİNG Summary of this function goes here
%   Detailed explanation goes here
k=1;
name='gal ';

i=1;

figure;
gx=geoaxes;
gx.MapCenterMode ='manual';
gx.MapCenter=[0,90]; 
gx.ZoomLevel=1.7;
while 1
  
    dtLCL = datetime('now', 'TimeZone','local');                 % Current Local Time
    time = datetime(dtLCL, 'TimeZone','Z');                     % Current UTC Time
    
    positions_satellite=find_position(ephemeris,time);
   
    
   
      
   
    time=datestr(time);
    sat_num=table2array(positions_satellite(:,2));
    latitude=table2array(positions_satellite(:,3));
    longitude=table2array(positions_satellite(:,4));



    geoscatter([latitude], [longitude], '^', "filled");
  
    dx = 0.3; dy = 0.2;
    
    geolimits('manual');
    geolimits([-75 75], [-180 180]);

    sat_num=num2str(sat_num);
    
    
    name_mat{1,1}=name;
        
    for l=2:height(sat_num)
        name_mat{l,1}=name;
    end
    
   
    sat_num = cellstr(sat_num);
    sat_num=strcat(name_mat,sat_num);
    clearvars name_mat;
   
    text(latitude+dx, longitude+dy, sat_num); 
    title(time);
    i=i+1;
    hold off
    pause(epoch);
   
end 
end

