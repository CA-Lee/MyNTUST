module seg7decode(n,seg7);
input [3:0] n;
output reg [7:0] seg7;

always@(n) begin
	case(n)
		0 : seg7 = 8'b11000000;
		1 : seg7 = 8'b11111001;
		2 : seg7 = 8'b10100100;
		3 : seg7 = 8'b10110000;
		4 : seg7 = 8'b10011001;
		5 : seg7 = 8'b10010010;
		6 : seg7 = 8'b10000010;
		7 : seg7 = 8'b11011000;
		8 : seg7 = 8'b10000000;
		9 : seg7 = 8'b10010000;
		default: seg7 = 8'b11111111;
	endcase
end
endmodule