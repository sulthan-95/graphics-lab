
%: %.cpp
	g++ $^ -o $@ -lgraph
	./$@
