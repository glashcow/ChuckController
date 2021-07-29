adc => PitShift pitch => dac;
1234 => int port;

0.5 => dac.gain;
0.6 => pitch.mix;

OscIn oin;
OscMsg msg;
port => oin.port;

oin.addAddress("/freq");

while ( true ) { 
    oin => now; 
    while(oin.recv(msg) != 0) {
        msg.getFloat(0) => pitch.shift;
    }    
}   



