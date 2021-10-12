function tk = galileo_time(t,toe)
GPS0 = datetime(1999 ,8,22,00,00,05,'TimeZone','UTCLeapSeconds');
deltaT = t - GPS0; 
deltaT.Format = 's';

tNumeric = time2num(deltaT,"seconds");
tk=tNumeric-toe;

while tk>302400
    if tk>302400
        tk=tk-604800;
    end
end
if tk<-302400
    tk=tk+604800;
end

end

