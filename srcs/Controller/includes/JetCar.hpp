#ifndef JETCAR_HPP
#define JETCAR_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <pigpio.h>

class JetCar {
public:
    JetCar();
    ~JetCar();

    void setMotorSpeed(int speed);
    void setServoAngle(int angle);

    void sequence();

    int servo_handle;
    int motor_handle;

    void setPWM(int device_handle, int channel, int on_value, int off_value);

    // Constantes
    static const int SERVO_ADDR = 0x40;
    static const int MOTOR_ADDR = 0x60;
    static const int STEERING_CHANNEL = 0;

    // A constante MAX_ANGLE é 'constexpr' para permitir uso direto em tempo de compilação
    static constexpr int MAX_ANGLE = 45;

    static const int SERVO_LEFT_PWM = 205;
    static const int SERVO_CENTER_PWM = 307;
    static const int SERVO_RIGHT_PWM = 410;
};

#endif

