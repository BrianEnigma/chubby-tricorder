difference()
{
    cube(size=[15, 8, 15]);
    translate(v = [2, 1.5, -1])
        cube(size = [15, 4, 17]);
    translate(v = [7.5 + 1, 3, 7.5])
        rotate(a = [90, 0, 0])
            cylinder(h = 10, r = 4.25, $fn=50);
}