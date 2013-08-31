CUBE_X = 20;
CUBE_Y = 12;
CUBE_Z = 4;

EDGE_OFFSET = 5;

SQUISH = 0.5;
DETAIL = 50;

// Uncomment only one of the following lines to get
// braces for each of the four corners:

//scale(v = [-1, -1, 1])
//scale(v = [1, -1, 1])
//scale(v = [-1, 1, 1])
scale(v = [1, 1, 1])

    translate(v = [CUBE_X / -2, CUBE_Y / -2, 0])
        difference()
        {
            cube(size = [CUBE_X, CUBE_Y, CUBE_Z]);
            translate(v = [-1, CUBE_Y - EDGE_OFFSET, CUBE_Z])
                scale(v = [1, 1, SQUISH])
                    rotate(a = [0, 90, 0])
                        cylinder(h = 15 + 1, r = 1.5, $fn = DETAIL);
            translate(v = [7, CUBE_Y - EDGE_OFFSET, CUBE_Z])
                scale(v = [1, 1, SQUISH])
                    rotate(a = [0, 90, 0])
                        cylinder(h = 4, r = 3, $fn = DETAIL);
        }
