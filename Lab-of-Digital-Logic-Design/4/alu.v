module ALU(
    output reg [7:0] y,
    input [2:0] sel,
    input [7:0] a,b
);
    always @(sel,a,b) begin
        case (sel)
            3'b0: y = 8'b0;
            3'b1: y = a & b;
            3'b10: y = a | b;
            3'b11: y = a ^ b;
            3'b100: y = ~a;
            3'b101: y = a - b;
            3'b110: y = a + b;
            3'b111: y = 8'hFF;
            default: 
                y = 8'b0;
        endcase
    end
endmodule

module t_ALU;
    wire [7:0] y;
    reg [2:0] sel;
    reg [7:0] a,b;

    ALU alu(y,sel,a,b);

    initial begin
        a = 8'b10101010; b = 8'b11110000;
        sel = 3'b0;
        $display("time = %d, sel = %b, a = %h, b = %h, y = %h", $time, sel, a, b, y);

        repeat(7)
            #100 sel = sel + 3'b1; 
    end
    initial #800 $finish;
    initial $dumpvars;
    initial begin
        $monitor("time = %d, sel = %b, a = %h, b = %h, y = %h", $time, sel, a, b, y);
    end


endmodule