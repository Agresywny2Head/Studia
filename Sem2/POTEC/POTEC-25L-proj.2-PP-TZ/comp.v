module comp
(
	input [3:0] a,b,
	// input [3:0] b,
	output [3:0] x,y
);

assign x = (a > b) ? b : a;
assign y = a > b ? a : b;

endmodule
