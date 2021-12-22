module ledlighting(clk,led);
input clk;
output reg [9:0] led;
reg d;

initial begin
led[9:1] = 9'b0;
led[0] = 1'b1;
d = 1'b1;
end

always @ (posedge clk) begin

if(led[1] && !d) d <= 1'b1;
if(led[8] && d) d <= 1'b0;

if(d) begin
	led[9:1] <= led[8:0];
	led[0] <= 1'b0;
end
else begin 
	led[8:0] <= led[9:1];
	led[9] <= 1'b0;
	end
	
end
endmodule