#version 450

// Layout takes a location value, based on how is set up the graphics pipeline the fragment shader is capable to outputing to multiple locations
// The variable t_Color is intented to be an vector 4 output.
layout (location = 0) out vec4 t_Color;

void main()
{
	t_Color = vec4(1.0, 0.0, 0.0, 1.0);
}