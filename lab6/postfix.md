prefix notation: in this notation opr is written before opds it is also knowm as polish notation.
postfix notation: in this notation the opr is written after the operand. it is also known as reversed polish notation.
ab+c*d-
-*+abcd

ab/cd/+
/ad/cd

parsing
-------
to parse any arithm. exp. we need to take care of operator prec. and associativity

which opr will take the opd first is decided by the prec. of the opr. over others.

it describes the rule where oprs. with the same precedence appear in an exp.

operator      precedence     associativity
--------      ----------     -------------
^ or \uparrow highest        right
*, /, %       second highest left
+ and -       lowest         left
