const int TRIG_PIN = 10;
const int ECHO_PIN = 11;
const int SOUND_PIN = A0;
const int LED_PIN = 13;
const int DISTANCE_THRESHOLD = 30; // 设置距离阈值为30cm
const int SOUND_THRESHOLD = 500; // 设置声音阈值为500

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(SOUND_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(1);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, LOW); // 发射超声波

  long duration = pulseIn(ECHO_PIN, HIGH); // 接收超声波的反射，计算距离
  float distance = duration * 0.034 / 2;
  int sound = analogRead(SOUND_PIN); // 读取声音传感器的数值

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, ");
  Serial.print("Sound: ");
  Serial.println(sound);

  if (distance < DISTANCE_THRESHOLD || sound > SOUND_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // 如果距离小于阈值或声音传感器检测到声音，点亮LED灯
  } else {
    digitalWrite(LED_PIN, LOW); // 否则关闭LED灯
  }

  delay(1000);
}
