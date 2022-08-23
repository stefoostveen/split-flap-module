#include <SplitFlapModule.h>

SplitFlapModule sfm(10, 11, 12, 13, 8, 18);

void setup()
{
    Serial.begin(9600);
    delay(100);

    Serial.println("Device starting");
    // create the steppers
    sfm.home();

    Serial.println("SFM at home position");
    delay(5000);
}

void loop()
{
    Serial.println("Picking random positions");
    int nextpos = random(0, 18);
    Serial.println(nextpos);

    sfm.set(random(0, 18), true);
    delay(1000);
}