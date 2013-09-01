difference()
{
    // Overall boundary
    cube(size=[15, 8, 15]);
    // Carve out slot
    translate(v = [2, 1.5, -1])
        cube(size = [15, 5, 17]);
    // Carve out circle
    translate(v = [7.5 + 1, 3, 7.5])
        rotate(a = [90, 0, 0])
            cylinder(h = 10, r = 4.75, $fn=50);
}