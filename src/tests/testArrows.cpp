/**
 * testArrows.cpp tests displaying the Line class's Arrow and Dotted attributes
 */
#include <tsgl.h>
using namespace tsgl;

void arrowFunction(Canvas& c) {
	ColorGLfloat colors[] = { ColorGLfloat(1,0,0,1), ColorGLfloat(0,1,0,1) };
	Arrow* doubleArrow = new Arrow(0, 0, 0, 2, 0.05,0,0,0, colors, false);
  Arrow* arrow2 = new Arrow(1 ,1 ,-1 ,2 ,0.05,0,0,0,ColorGLfloat(0,0,1,0.65), true);
	c.add(doubleArrow);
  c.add(arrow2);
	// doubleArrow->setCenterX(1);
	// doubleArrow->setRotationPoint(0,0,0);
	// doubleArrow->setYaw(45);
	doubleArrow->setColor(colors);
    float floatVal = 0.0f;
    GLfloat delta = 0.05;
	while( c.isOpen() ) {
		c.sleep();
        // doubleArrow->setCenterX(sin(floatVal/90));
        // doubleArrow->setCenterY(sin(floatVal/90));
        // doubleArrow->setCenterZ(sin(floatVal/90));
        // doubleArrow->setYaw(floatVal);
        // doubleArrow->setPitch(floatVal);
        // doubleArrow->setRoll(floatVal);
        // doubleArrow->setLength(sin(floatVal/90) + 2);
        if (doubleArrow->getLength() > 3 || doubleArrow->getLength() < 1) {
            delta *= -1;
        }
        doubleArrow->changeLengthBy(delta);
        floatVal += 1;
	}

	delete doubleArrow;
}

int main(int argc, char* argv[]) {
  int w = 1000;
  int h = 1000;
  Canvas c(-1, -1, w, h, "Arrows");
  c.run(arrowFunction);
}