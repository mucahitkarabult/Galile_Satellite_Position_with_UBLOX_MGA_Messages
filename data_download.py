# -*- coding: utf-8 -*-
"""
Created on Thu Jul 29 14:11:19 2021

@author: PC_663_ADMIN
"""

from datetime import datetime
import time
import requests
import subprocess
# datetime object containing current date and time

now = datetime.now()
flag=1

year=now.year%2000
month=now.month
day=now.day
hour=now.hour
filename='gal_'+str(year)+'_'+str(month)+'_'+str(day)+'.'+str(hour)+'.ubx'
filename
if flag:
  print('Download Starting...')

  url = 'https://online-live1.services.u-blox.com/GetOnlineData.ashx?token=6EvFXIDSTvKZ5rcNO7CN9A;gnss=gal;datatype=eph;'
  
  r =  requests.get(url)
  
  
  with open(filename,'wb') as output_file:
      output_file.write(r.content)
  
  print('Download Completed!!!')

  subprocess.run(["Matlab_mga.exe"])


  
  