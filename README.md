# Fish shoal

This is a multi-agent system that simulates a fish shoal.

There are two "modes" : 

- One with big and little fish, little fish are afraid and steer away from the big ones.
- One with variable fish, variable sizes and speeds. 

That type of multi-agent is usefull to expose some primary animal instincts: such as forming a shoal of fish. 
The mode with little and big fish exposes that when some individuals in a group run from a danger the entire group follows without even seeing the danger: like a flock of sheep.

You can switch mode and change main settings in the config file.

Result with the big and little mode. Here we can see that little fish are afraid from the big ones.
![little_big](little_big.gif)

Result with the variable sizes mode. We can see that the fish tend to make different shoals organized by their speed. The smaller they are, the faster they are.
![variable](variable.gif)