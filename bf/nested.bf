++++++              init cell(0) = 6
[                   loop
    > ++++++            init cell(1) = 6
    [                   loop
        > +                 inc cell(2)
        < -                 dec cell(1)
    ]                   end
    < -                 dec cell(0)
]                   end

>> .                hopefully print out $
<< +++++ +++++ .    print a newline
