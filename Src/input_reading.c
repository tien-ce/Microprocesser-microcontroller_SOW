/*
 * input_reading.c
 *
 *  Created on: Sep 27, 2024
 *      Author: thuyh
 */
#include "input_reading.h"
#define NORMAL_STATE GPIO_PIN_SET // Trạng thái bình thường (nút không nhấn)
#define PRESSED_STATE GPIO_PIN_RESET // Trạng thái nhấn (nút được nhấn)

#define LONG_PRESS_THRESHOLD 100   // Thời gian để nhận diện nhấn đè (1 giây)
#define REPEAT_ACTION_INTERVAL 20   // Khoảng thời gian giữa các lần lặp lại hành động (200ms)
#define DOUBLE_CLICK_THRESHOLD 4   // Ngưỡng thời gian để nhận diện nhấn đôi (40ms)
#define MAX_FOR_LONG_PRESS   300    // Thời gian hoạt động tối đa cho 1 lần nhấn đè (3 giây)
static GPIO_PinState KeyReg1[N0_OF_BUTTONS] = {NORMAL_STATE}; // Bộ đệm chống nhiễu


static GPIO_PinState KeyReg2[N0_OF_BUTTONS] = {NORMAL_STATE};
static GPIO_PinState KeyReg3[N0_OF_BUTTONS] = {NORMAL_STATE};
static GPIO_PinState KeyReg4[N0_OF_BUTTONS] = {NORMAL_STATE};

uint8_t Button1_flag[N0_OF_BUTTONS] = {0};             // Cờ cho nhấn nút
uint8_t double_click_flag[N0_OF_BUTTONS] = {0};        // Cờ cho nhấn đôi

int time_for_one_long_press[N0_OF_BUTTONS] = {0}; // Bộ đếm thời gian tối đa 1 lần nhấn đè
int time_out_input[N0_OF_BUTTONS] = {0};     // Bộ đếm thời gian cho nhấn đè
int repeat_counter[N0_OF_BUTTONS] = {0};     // Bộ đếm thời gian cho lặp lại hành động
uint16_t double_click_timer[N0_OF_BUTTONS] = {0};   // Bộ đếm thời gian cho nhấn đôi
uint8_t single_click_detected[N0_OF_BUTTONS] = {0}; // Cờ cho lần nhấn đơn

void getKeyInput(GPIO_TypeDef* GPIOx[], uint16_t GPIO_Pin[]) {
    for (int i = 0; i < N0_OF_BUTTONS; i++) {
        KeyReg3[i] = KeyReg2[i];
        KeyReg2[i] = KeyReg1[i];
        KeyReg1[i] = HAL_GPIO_ReadPin(GPIOx[i], GPIO_Pin[i]);

        if (KeyReg3[i] == KeyReg2[i] && KeyReg2[i] == KeyReg1[i]) {
            // Không có nhiễu
            if (KeyReg4[i] != KeyReg3[i]) {
                // Trạng thái nút đã thay đổi
                KeyReg4[i] = KeyReg3[i];
                if (KeyReg4[i] == PRESSED_STATE) {
                    // Nút vừa được nhấn
                    Button1_flag[i] = 1;
                    time_out_input[i] = 0;
                    repeat_counter[i] = 0;

                    if (single_click_detected[i] == 1 && double_click_timer[i] > 0) {
                        // Phát hiện nhấn đôi
                        double_click_flag[i] = 1;
                        single_click_detected[i] = 0;
                        double_click_timer[i] = 0;
                        Button1_flag[i] = 0;
                    } else {
                        // Chưa có nhấn đôi, đặt cờ nhấn đơn
                        single_click_detected[i] = 1;
                        double_click_timer[i] = DOUBLE_CLICK_THRESHOLD;
                    }

                } else {
                    // Nút vừa được nhả
                    time_out_input[i] = 0;
                    repeat_counter[i] = 0;
                }
            } else {
                // Trạng thái nút không thay đổi
                if (KeyReg4[i] == PRESSED_STATE) {
                    // Nút đang được nhấn
                    time_out_input[i]++;
                    if (time_out_input[i] >= LONG_PRESS_THRESHOLD) {
                        // Xử lý nhấn đè trong Button1_flag[i]
                    	if(time_for_one_long_press[i] < MAX_FOR_LONG_PRESS){
                    		// Chưa đặt tới giới hạn cho 1 lần nhấn đè
                    		time_for_one_long_press[i]++;
                    		repeat_counter[i]++;
                    	}

                        if (repeat_counter[i] >= REPEAT_ACTION_INTERVAL) {
                            // Đặt cờ để thực hiện hành động
                            Button1_flag[i] = 1;
                            // Đặt lại bộ đếm lặp lại
                            repeat_counter[i] = 0;
                        }
                    }
                } else {
                    // Nút đang được nhả
                    time_out_input[i] = 0;
                    repeat_counter[i] = 0;
                    time_for_one_long_press[i] = 0;
                    // Giảm bộ đếm thời gian cho nhấn đôi
                    if (single_click_detected[i] == 1 && double_click_timer[i] > 0) {
                        double_click_timer[i]--;
                        if (double_click_timer[i] == 0) {
                            // Hết thời gian chờ nhấn đôi, đặt lại cờ
                            single_click_detected[i] = 0;
                        }
                    }
                }

            }
        }
    }
}

unsigned int is_button_pressed(unsigned int index) {
    if (index >= N0_OF_BUTTONS) {
        return 0;
    }
    if (Button1_flag[index] == 1) {
        return 1;
    }
    return 0;
}

unsigned int is_button_double_clicked(unsigned int index) {
    if (index >= N0_OF_BUTTONS) {
        return 0;
    }
    if (double_click_flag[index] == 1) {
        return 1;
    }
    return 0;
}
