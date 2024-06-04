/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Key.hpp
*/

#pragma once

namespace Raylib {
    #include <raylib.h>
}

namespace Cereal {
    enum InputType {
        Keyboard_T,
        Gamepad_T,
        Mouse_T,
        Unknown,
    };

    typedef enum {
        KeyRight = Raylib::KEY_RIGHT,
        KeyLeft = Raylib::KEY_LEFT,
        KeyUp = Raylib::KEY_UP,
        KeyDown = Raylib::KEY_DOWN,
        KeySpace = Raylib::KEY_SPACE,
        KeyEnter = Raylib::KEY_ENTER,
        KeyEscape = Raylib::KEY_ESCAPE,
        KeyBackspace = Raylib::KEY_BACKSPACE,
        KeyShift = Raylib::KEY_LEFT_SHIFT,
        KeyControl = Raylib::KEY_LEFT_CONTROL,
        KeyAlt = Raylib::KEY_LEFT_ALT,
        KeyTab = Raylib::KEY_TAB,
        KeyA = Raylib::KEY_A,
        KeyB = Raylib::KEY_B,
        KeyC = Raylib::KEY_C,
        KeyD = Raylib::KEY_D,
        KeyE = Raylib::KEY_E,
        KeyF = Raylib::KEY_F,
        KeyG = Raylib::KEY_G,
        KeyH = Raylib::KEY_H,
        KeyI = Raylib::KEY_I,
        KeyJ = Raylib::KEY_J,
        KeyK = Raylib::KEY_K,
        KeyL = Raylib::KEY_L,
        KeyM = Raylib::KEY_M,
        KeyN = Raylib::KEY_N,
        KeyO = Raylib::KEY_O,
        KeyP = Raylib::KEY_P,
        KeyQ = Raylib::KEY_Q,
        KeyR = Raylib::KEY_R,
        KeyS = Raylib::KEY_S,
        KeyT = Raylib::KEY_T,
        KeyU = Raylib::KEY_U,
        KeyV = Raylib::KEY_V,
        KeyW = Raylib::KEY_W,
        KeyX = Raylib::KEY_X,
        KeyY = Raylib::KEY_Y,
        KeyZ = Raylib::KEY_Z,
        KeyF1 = Raylib::KEY_F1,
        KeyF2 = Raylib::KEY_F2,
        KeyF3 = Raylib::KEY_F3,
        KeyF4 = Raylib::KEY_F4,
        KeyF5 = Raylib::KEY_F5,
        KeyF6 = Raylib::KEY_F6,
        KeyF7 = Raylib::KEY_F7,
        KeyF8 = Raylib::KEY_F8,
        KeyF9 = Raylib::KEY_F9,
        KeyF10 = Raylib::KEY_F10,
        KeyF11 = Raylib::KEY_F11,
        KeyF12 = Raylib::KEY_F12,
    } KeyBoard;

    typedef enum {
        MouseLeft = Raylib::MOUSE_LEFT_BUTTON,
        MouseRight = Raylib::MOUSE_RIGHT_BUTTON,
        MouseMiddle = Raylib::MOUSE_MIDDLE_BUTTON,
    } Mouse;

    typedef enum {
        LeftTrigger = Raylib::GAMEPAD_BUTTON_LEFT_TRIGGER_1,
        RightTrigger = Raylib::GAMEPAD_BUTTON_RIGHT_TRIGGER_1,
        LeftBumper = Raylib::GAMEPAD_BUTTON_LEFT_TRIGGER_2,
        RightBumper = Raylib::GAMEPAD_BUTTON_RIGHT_TRIGGER_2,
        DPadUp = Raylib::GAMEPAD_BUTTON_LEFT_FACE_UP,
        DPadRight = Raylib::GAMEPAD_BUTTON_LEFT_FACE_RIGHT,
        DPadDown = Raylib::GAMEPAD_BUTTON_LEFT_FACE_DOWN,
        DPadLeft = Raylib::GAMEPAD_BUTTON_LEFT_FACE_LEFT,
        ButtonUp = Raylib::GAMEPAD_BUTTON_RIGHT_FACE_UP,
        ButtonRight = Raylib::GAMEPAD_BUTTON_RIGHT_FACE_RIGHT,
        ButtonDown = Raylib::GAMEPAD_BUTTON_RIGHT_FACE_DOWN,
        ButtonLeft = Raylib::GAMEPAD_BUTTON_RIGHT_FACE_LEFT,
        LeftThumb = Raylib::GAMEPAD_BUTTON_LEFT_THUMB,
        RightThumb = Raylib::GAMEPAD_BUTTON_RIGHT_THUMB,
        Start = Raylib::GAMEPAD_BUTTON_MIDDLE_RIGHT,
        Select = Raylib::GAMEPAD_BUTTON_MIDDLE_LEFT,
    } GamePad;
}