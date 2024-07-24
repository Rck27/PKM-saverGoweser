#if defined(EEZ_FOR_LVGL)
#include <eez/core/vars.h>
#endif

#include "ui.h"
#include "screens.h"
#include "images.h"
#include "actions.h"
#include "vars.h"

// ASSETS DEFINITION
const uint8_t assets[1660] = {
    0x7E, 0x45, 0x45, 0x5A, 0x03, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00,
    0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF0, 0x00, 0xF0, 0x00, 0x01, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00,
    0x08, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0x10, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x34, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x64, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x65, 0x66, 0x61,
    0x75, 0x6C, 0x74, 0x00, 0xFF, 0xFF, 0x08, 0x42, 0x44, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x00, 0x98, 0x00, 0x00, 0x00, 0xB4, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00,
    0xEC, 0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x24, 0x01, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00,
    0x5C, 0x01, 0x00, 0x00, 0x78, 0x01, 0x00, 0x00, 0x94, 0x01, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00,
    0xCC, 0x01, 0x00, 0x00, 0xE8, 0x01, 0x00, 0x00, 0xF4, 0x01, 0x00, 0x00, 0x20, 0x4E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x21, 0x4E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xDC, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x22, 0x4E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xC8, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x23, 0x4E, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0xBC, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xB8, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x20, 0x4E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xA8, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x23, 0x4E, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x9C, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x98, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x20, 0x4E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x88, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x23, 0x4E, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x7C, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x78, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x20, 0x4E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x68, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xE9, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x4C, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xEE, 0x03, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x01, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x38, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xF6, 0x03, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x30, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x28, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xEE, 0x03, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x1C, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x18, 0x01, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x14, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xEE, 0x03, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x0C, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xF6, 0x03, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0xF4, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00,
    0xD0, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00,
    0xD0, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00,
    0xCC, 0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00,
    0x04, 0x01, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00,
    0x04, 0x01, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00,
    0x08, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0C, 0x01, 0x00, 0x00, 0x0C, 0x01, 0x00, 0x00,
    0x14, 0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x18, 0x01, 0x00, 0x00, 0x18, 0x01, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00, 0x1C, 0x01, 0x00, 0x00, 0x20, 0x01, 0x00, 0x00, 0x28, 0x01, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x30, 0x01, 0x00, 0x00, 0x38, 0x01, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x3C, 0x01, 0x00, 0x00, 0x3C, 0x01, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x20, 0x3F, 0xC0,
    0x02, 0x00, 0x0C, 0xC0, 0x03, 0x00, 0x00, 0x20, 0x3F, 0xC0, 0x00, 0xC0, 0x00, 0x20, 0x3F, 0xC0,
    0x16, 0xC0, 0x00, 0x20, 0x41, 0xC0, 0x04, 0x00, 0x04, 0xC0, 0x05, 0x00, 0x06, 0x00, 0x16, 0xC0,
    0x00, 0xC0, 0x00, 0x20, 0x40, 0xC0, 0x02, 0x00, 0x0C, 0xC0, 0x03, 0x00, 0x00, 0x20, 0x40, 0xC0,
    0x00, 0xC0, 0x00, 0x20, 0x40, 0xC0, 0x16, 0xC0, 0x00, 0xC0, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x01, 0x20, 0x07, 0x00, 0x00, 0xC0, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x02, 0x20, 0x08, 0x00, 0x00, 0xC0, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x22, 0xC0, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x01, 0x40, 0x0A, 0x00, 0x00, 0xC0, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x40, 0x0B, 0x00, 0x00, 0xC0, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0C, 0x00, 0x00, 0xE0, 0x02, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00,
    0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00,
    0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x03, 0x00,
    0x0E, 0x00, 0x04, 0x00, 0x0B, 0x00, 0x05, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x03, 0x00,
    0x0E, 0x00, 0x04, 0x00, 0x05, 0x00, 0x01, 0x00, 0x0E, 0x00, 0x04, 0x00, 0x07, 0x00, 0x02, 0x00,
    0x0C, 0x00, 0x06, 0x00, 0x0D, 0x00, 0x07, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00,
    0x54, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x6C, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
    0x84, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x9C, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00,
    0xB4, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x01, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5C, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9A, 0x99, 0x99, 0x99,
    0x99, 0x99, 0xD9, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF4, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x3A, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00,
    0x20, 0x42, 0x50, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x20, 0x4B, 0x4D, 0x00
};

native_var_t native_vars[] = {
    { NATIVE_VAR_TYPE_NONE, 0, 0 },
};


ActionExecFunc actions[] = {
    0
};


#if defined(EEZ_FOR_LVGL)

void ui_init() {
    eez_flow_init(assets, sizeof(assets), (lv_obj_t **)&objects, sizeof(objects), images, sizeof(images), actions);
}

void ui_tick() {
    eez_flow_tick();
    tick_screen(g_currentScreen);
}

#else

static int16_t currentScreen = -1;

static lv_obj_t *getLvglObjectFromIndex(int32_t index) {
    if (index == -1) {
        return 0;
    }
    return ((lv_obj_t **)&objects)[index];
}

static const void *getLvglImageByName(const char *name) {
    for (size_t imageIndex = 0; imageIndex < sizeof(images) / sizeof(ext_img_desc_t); imageIndex++) {
        if (strcmp(images[imageIndex].name, name) == 0) {
            return images[imageIndex].img_dsc;
        }
    }
    return 0;
}

void loadScreen(enum ScreensEnum screenId) {
    currentScreen = screenId - 1;
    lv_obj_t *screen = getLvglObjectFromIndex(currentScreen);
    lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0, false);
}

void ui_init() {
    create_screens();
    loadScreen(SCREEN_ID_MAIN);
}

void ui_tick() {
    tick_screen(currentScreen);
}

#endif
