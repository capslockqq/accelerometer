clear;
close all;
 delete(instrfind);
  
s = serial('COM3'); %assigns the object s to serial port

set(s, 'InputBufferSize', 1024); %number of bytes in inout buffer
set(s, 'FlowControl', 'hardware');
set(s, 'BaudRate', 115200);
set(s, 'Parity', 'none');
set(s, 'DataBits', 8);
set(s, 'StopBit', 1);
set(s, 'Timeout',0.5);
%clc;
 
disp(get(s,'Name'));
prop(1)=(get(s,'BaudRate'));
prop(2)=(get(s,'DataBits'));
prop(3)=(get(s, 'StopBit'));
prop(4)=(get(s, 'InputBufferSize'));
 
disp(['Port Setup Done!!',num2str(prop)]);
 
         %opens the serial port
disp('Running');
fopen(s);

tolerance = 200;
c = 0;
b = 0;
    


%figure;
%plot(a);

t = 1;
x = 0 ;
y = 0;
z = 0;
v = 0;
output_integral = 0;
startSpot = 0;
interv = 10000 ; % considering 1000 samples
step = 0.1 ; % lowering step has a number of cycles and then acquire more data

M = 5;
midlings_filter = ones(1, M);
output = zeros(1,1);
velocity = zeros(1, interv);
integral = zeros(1,interv);


 while ( t <interv )
    z = 1;
    c = 0;
    b = 0;
    while z < 100
       c(z) = fscanf(s, '%d', 1);
       if c(z) == 95 
       
        z = 100;
       else
          b(z) = c(z);
       end
       z = z + 1;
    end
signed = 1;
signed_true = 0;
if b(1) == 45
    signed = -1;
    N = length(b)-1;
    signed_true = 1;
    
else
    N = length(b);
end
k = 0;
for i = 1: N
   k = 10 * k + b(i+signed_true);
end
k = k*signed;
      if (t <= M) 
          midlings_filter(t) = k   
      elseif (t+1 == M)
          for q = 1:M
              output = output + midlings_filter(M);
          end
              
      elseif (t+1 > M)
          for q = 2:M+1
              if (q == M+1) 
                  midlings_filter(M) = k;
                  output = output + midlings_filter(M);
                  
              else
                  midlings_filter(q-1) = midlings_filter(q);
                  output = output + midlings_filter(q-1);
              end
              
          end    
      end
     
      
      x = [ x, k ];
      output = output/M;
      
      if output < tolerance && output > -tolerance
         output = 0; 
      end
      y = [y, output];
      
      subplot(2,1,1);
      plot(y) ;
      drawnow;
      
     
      if t > 1
         velocity(t) = velocity(t-1) + y(t)+((y(t)+y(t-1))/2)*t;
         v = [v, velocity(t)];
         subplot(2,1,2);    
         plot(v);
         
     
      end
      
      t = t + 1;
  
end
 fclose(s); %close the serial port

