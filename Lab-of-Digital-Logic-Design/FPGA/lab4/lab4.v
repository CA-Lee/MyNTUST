module my_pll(clk_in,clk_out);
input clk_in;
output clk_out;
reg clk_out;

parameter n = 1_000_000;
reg [19:0] current;

initial begin
clk_out<=1'b0;
current <= n;
end

always@(posedge clk_in)
begin
	if(current==0)
	begin
		current<=n;
		clk_out<=!clk_out;
	end
	else current <= current-1;
end
endmodule