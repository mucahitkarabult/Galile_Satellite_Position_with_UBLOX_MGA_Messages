function [ephemeris] = read_from_mga(filename)
%READ_FİLE_GPS Summary of this function goes here
%   Detailed explanation goes here

fid = fopen(filename);

if fid == -1
    errordlg(['The file ''' filename ''' does not exist in directory']);
    return;
end

current_line = fgetl(fid);
while isempty(strfind(current_line,'BEGINNING OF DATA'))
    current_line = fgetl(fid);
end
 

datacell = textscan(fid, '%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f', 'delimiter', '\t');
fclose(fid);
ephemeris = cell2mat(datacell);

end

