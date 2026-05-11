#include <cstdint>
#include <cstdio>

// Extract fields using bit shifting (example register layout)
void sample_test_bitfields() {
  uint32_t reg_value = 0xdeadbeefu;

  uint32_t field_a = (reg_value >> 0) & 0xF;    // bits 0-3
  uint32_t field_b = (reg_value >> 4) & 0xFF;   // bits 4-11
  uint32_t field_c = (reg_value >> 12) & 0x1;   // bit 12
  uint32_t field_d = (reg_value >> 13) & 0x7FF; // bits 13-23

  std::printf(
      "reg=0x%08x fields: a=%u b=%u c=%u d=%u\n",
      static_cast<unsigned>(reg_value),
      static_cast<unsigned>(field_a),
      static_cast<unsigned>(field_b),
      static_cast<unsigned>(field_c),
      static_cast<unsigned>(field_d));

#define SET_BIT(reg, bit) ((reg) |= (1U << (bit)))
#define CLEAR_BIT(reg, bit) ((reg) &= ~(1U << (bit)))
#define TOGGLE_BIT(reg, bit) ((reg) ^= (1U << (bit)))
#define READ_BIT(reg, bit) (((reg) >> (bit)) & 1U)

  uint32_t r = 0u;
  SET_BIT(r, 3);
  std::printf("after SET bit 3: r=%u READ=%u\n", static_cast<unsigned>(r),
              READ_BIT(r, 3));
  CLEAR_BIT(r, 3);
  TOGGLE_BIT(r, 0);
  std::printf("after CLEAR 3, TOGGLE 0: r=%u\n", static_cast<unsigned>(r));
#undef SET_BIT
#undef CLEAR_BIT
#undef TOGGLE_BIT
#undef READ_BIT
}

#if defined(SAMPLE_TEST_MAIN)
int main() {
  sample_test_bitfields();
  return 0;
}
#endif
