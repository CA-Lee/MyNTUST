`timescale 1ns/100ps

module SRFF (
    s,r,q,q_
);
    output q, q_;
    input s,r;

    nand #10 a(q,s,q_);
    nand #10 b(q_,r,q);
endmodule

module t_SRFF (
    
);
    wire q,q_;
    reg s,r;

    SRFF sr(s,r,q,q_);

    initial begin
        s=1'b0;r=1'b1;
        #100 s=1'b1;r=1'b0;
        #100 s=1'b1;r=1'b1;
    end
    // initial $dumpvars;
    // initial #300 $finish;
endmodule

module D_latch (
    d,en,q,q_
);
    input d,en;
    output q,q_;

    wire d_,s,r;
    not #5 n(d_,d);
    nand #10 a(s,d,en);
    nand #10 b(r,d_,en);
    SRFF sr(s,r,q,q_);
endmodule

module t_D_latch (
    
);
    wire q,q_;
    reg d,en;

    D_latch d_latch(d,en,q,q_);

    initial begin
        en=1'b1;d=1'b0;
        #100 d=1'b1;
        #100 d=1'b0;
        #100 en=1'b0;
        #100 d=1'b1;
        #100 d=1'b0;
    end
    initial $dumpvars;
    // initial #600 $finish;
endmodule

module msDFF (
    d,clk,q,q_
);
    input d,clk;
    output q,q_;

    wire d_,y;
    not #5 (clk_,clk);
    D_latch m(.d(d),.en(clk),.q(y));
    D_latch s(y,clk_,q,q_);

endmodule

module t_msDFF (
    
);
    wire q,q_;
    reg d,clk;

    msDFF msdff(d,clk,q,q_);

    initial begin
        clk = 1'b0;
        repeat(7)
            #100 clk = clk + 1'b1;
    end
    initial begin
        d = 1'b0;
        #250 d=1'b1;
        #250 d=1'b0;
    end
    initial $dumpvars;
    // initial #600 $finish;
endmodule

module etDFF (
    d,clk,q,q_
);
    input d,clk;
    output q,q_;

    wire w1,ws,wr;

    SRFF sr1(.q_(ws),.s(w1),.r(clk));
    SRFF sr2(ws,wr,q,q_);

    nand #15 (wr,ws,clk,w1);
    nand #10 (w1,d,wr); 
endmodule

module t_etDFF (
    
);
    wire q,q_;
    reg d,clk;

    etDFF etdff(d,clk,q,q_);

    initial begin
        clk = 1'b0;
        repeat(7)
            #100 clk = clk + 1'b1;
    end
    initial begin
        d = 1'b0;
        #250 d=1'b1;
        // #250 d=1'b0;
    end
    initial $dumpvars;
    // initial #600 $finish;
endmodule

module bhDFF (
    d,clk,q,q_
);
    input d,clk;
    output reg q,q_;

    always @(posedge clk ) begin
        q <= d;
        q_ <= ~d;
    end
endmodule

module t_bhDFF (
    
);
    wire q,q_;
    reg d,clk;

    bhDFF bhdff(d,clk,q,q_);

    initial begin
        clk = 1'b0;
        repeat(7)
            #100 clk = clk + 1'b1;
    end
    initial begin
        d = 1'b0;
        #250 d=1'b1;
        // #250 d=1'b0;
    end
    initial $dumpvars;
    // initial #600 $finish;
endmodule

module bhDFF_negedge (
    d,clk,q,q_
);
    input d,clk;
    output reg q,q_;

    always @(negedge clk ) begin
        q <= d;
        q_ <= ~d;
    end
endmodule

module set_up_and_hold_time (
    
);
    wire ms_q,ms_q_,et_q,et_q_,bh_q,bh_q_,bhn_q,bhn_q_;
    reg d,clk;

    msDFF msdff(d,clk,ms_q,ms_q_);
    etDFF etdff(d,clk,et_q,et_q_);
    bhDFF bhdff(d,clk,bh_q,bh_q_);
    bhDFF_negedge bhdff_n(d,clk,bhn_q,bhn_q_);

    initial begin
        clk = 1'b0;
        repeat(20)
            #100 clk = clk + 1'b1;
    end
    initial begin
        d = 1'b0;
        #398 d=1'b1; //ms setup violation
        #352 d=1'b0;
        #51 d=1'b1; //ms hold violation
        #298 d=1'b0; //et setup violation
        #402 d=1'b1; //et hold violation
    end
    initial $dumpvars;
    initial #2100 $finish;

endmodule