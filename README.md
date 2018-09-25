# RTv1 - @WeThinkCode_
RTv1 is a basic raytracer, that render at least a cone, sphere, plane, and cylinder. ALl objects must have shadows, and specuarity.

### What is RTv1?
[RTv1][1] is an individual project at [WeThinkCode_][2] that requires us to recreate a raytracer that uses the principles of computer graphics to render basic shapes in a window. It uses some of the funtions found in the [Libft][3] library. It also uses a graphics library, [Minilibx][4] in this case.

### What is in the Project?

Take a look in the [Project instructions][1]. The project has 2 sections:

1.  **Main Programme:** A basic programme that raytraces and renders basic shapes.
2.  **Bonus Additions:** Adding more features to the raytracer, like multiple harsh spots and reflections.

### The Mechanics behind it all?

The goal is to create a program called RTv1 from the source files, and use that to render out the scenes given.

To create that file, after downloading/cloning this project, **cd** into the project, copy all the files from the sub folders to the root directory and finally, call make:

	git clone https://github.com/pmotala/rtv1
	cd rtv1
	make

You should see a *RTv1* file and some object files (.o).


Now to clean up (removing the .o files and the .c files from the root), call the function:
	make clean

### How do I use the programme?

You have to tell the file where your map file resides, for example:

`RTv1 scenes/scene.txt`

`RTv1` is the name of programme you've compiled. 
`scene/scene.txt` is the directory to your scene files.

You can find scenes files here: [scenes][5].

Enjoy.

[1]: https://github.com/pmotala/rtv1/blob/master/document/rtv1.en.pdf "RTv1 PDF"
[2]: https://www.wethinkcode.co.za "WeThinkCode_"
[3]: https://github.com/pmotala/libft "Libft"
[4]: https://github.com/dannywillems/minilibx "Minilibx"
[5]: https://github.com/pmotala/rtv1/blob/master/scenes/