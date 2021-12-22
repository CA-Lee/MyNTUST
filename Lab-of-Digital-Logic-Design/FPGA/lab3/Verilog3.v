module bin2dec(sw,seg7);
input [9:0] sw;
output [31:0] seg7;
wire [3:0] n0,n1,n2,n3;

assign n3  = sw /1000;
assign n2 = sw%1000/100;
assign n1 = sw%100/10;
assign n0 = sw%10;

seg7decode s0(n0, seg7[7:0]);
seg7decode s1(n1, seg7[15:8]);
seg7decode s2(n2, seg7[23:16]);
seg7decode s3(n3, seg7[31:24]);
endmodule