#include <cfloat>
#include <climits>
#include <cstdio>
#include <cstring>

#define N 16

namespace {
float ma_val = 0.f;
int ma_cnt = 0;
unsigned long ma_tot = 0;
}  // namespace

float Moving_avg_samples(int sensor_data) {
  if (ma_tot == ULONG_MAX) {
    std::printf("Warning: sample counter overflow, resetting\n");
    ma_val = 0.f;
    ma_cnt = 0;
    ma_tot = 0;
  }
  if (ma_val > FLT_MAX / 2.f || ma_val < -FLT_MAX / 2.f) {
    std::printf("Warning: moving average near overflow, resetting\n");
    ma_val = 0.f;
    ma_cnt = 0;
    ma_tot = 0;
  }
  if (ma_cnt < N) {
    ma_val += ((float)sensor_data - ma_val) / (ma_cnt + 1);
    ma_cnt++;
  } else {
    ma_val += ((float)sensor_data - ma_val) / (float)N;
  }
  ma_tot++;
  return ma_val;
}

void reset_moving_average(void) {
  std::printf("Resetting moving average\n");
  ma_val = 0.f;
  ma_cnt = 0;
  ma_tot = 0;
}

typedef struct {
  int buffer[N];
  int head;
  int count;
  float sum;
  unsigned long total_samples;
} MovingAvgRing;

static MovingAvgRing ring{};

float true_moving_average(int sensor_data) {
  if (ring.total_samples == ULONG_MAX) {
    std::printf("Ring buffer overflow, resetting\n");
    std::memset(&ring, 0, sizeof(ring));
  }
  if (ring.sum > FLT_MAX / 2.f || ring.sum < -FLT_MAX / 2.f) {
    std::printf("Sum overflow detected, recalculating\n");
    ring.sum = 0.f;
    for (int i = 0; i < ring.count; i++) ring.sum += (float)ring.buffer[i];
  }
  if (ring.count < N) {
    ring.buffer[ring.head] = sensor_data;
    ring.sum += sensor_data;
    ring.count++;
    ring.head = (ring.head + 1) % N;
  } else {
    ring.sum -= ring.buffer[ring.head];
    ring.buffer[ring.head] = sensor_data;
    ring.sum += sensor_data;
    ring.head = (ring.head + 1) % N;
  }
  ring.total_samples++;
  return ring.sum / (float)ring.count;
}

void reset_ring_buffer(void) {
  std::memset(&ring, 0, sizeof(ring));
  std::printf("Ring buffer reset\n");
}

void sample_test_moving_avg() {
  reset_moving_average();
  reset_ring_buffer();
  int test_data[] = {10, 20, 30, 40, 50};
  for (int i = 0; i < 5; i++) {
    float a = Moving_avg_samples(test_data[i]);
    float b = true_moving_average(test_data[i]);
    std::printf("i=%d val=%d EMA=%.2f MA=%.2f\n", i, test_data[i], a, b);
  }
}

#if defined(SAMPLE_TEST_MAIN)
int main() {
  sample_test_moving_avg();
  return 0;
}
#endif
