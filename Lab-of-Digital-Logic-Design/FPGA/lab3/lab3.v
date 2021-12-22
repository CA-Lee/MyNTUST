module lab3(sw,seg7);
input [9:0] sw;
output [31:0] seg7;

bin2dec b2d(sw,seg7);
endmodule