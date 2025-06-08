module sn
(
	input [3:0] a,b,c,d,e,f,
	output [3:0] x,y,z,m,n,k
);

wire [3:0] t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17;

comp b0 (.a(a), .b(b), .x(t0), .y(t1));
comp b1 (.a(c), .b(d), .x(t2), .y(t3));
comp b2 (.a(e), .b(f), .x(t4), .y(t5));

comp b3 (.a(t0), .b(t2), .x(t6), .y(t7));
comp b4 (.a(t1), .b(t3), .x(t8), .y(t9));

comp b5 (.a(t7), .b(t8), .x(t10), .y(t11));
comp b6 (.a(t6), .b(t4), .x(x), .y(t12));

comp b7 (.a(t10), .b(t5), .x(t13), .y(t14));

comp b8 (.a(t13), .b(t12), .x(y), .y(t15));
comp b9 (.a(t9), .b(t14), .x(t16), .y(k));

comp b10 (.a(t11), .b(t15), .x(z), .y(t17));

comp b11 (.a(t16), .b(t17), .x(m), .y(n));


endmodule
