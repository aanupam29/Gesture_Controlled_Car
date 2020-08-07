int xPin=0;//Connect x pin of adxl335 to pin A0
int yPin=1;//Connect y pin of adxl335 to pin A1
void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  int xval=analogRead(xPin);
  int yval=analogRead(yPin); 
  Serial.print("xval=");
  Serial.println(xval);//Use xval to determine threshold for different directions
  Serial.print("yval=");
  Serial.println(yval); //Use yval to determine threshold for different directions
  delay(2000);
  Serial.print("\n");
}
