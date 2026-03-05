CC      = cc
CFLAGS  = -Wall -Wextra -std=c11 -g

PROGS = q1_reverse_string \
        q2_power_of_two \
        q3_circular_buffer \
        q4_find_single \
        q5_my_atoi \
        q6_swap \
        q7_cycle_detection \
        q8_count_set_bits \
        q9_strtok_r \
        q10_rotate_array \
        q11_indexes \
        q12_clock_angle \
        q13_basic_calculator \
        q14_coin_change \
        q15_top_k_frequent \
        q16_valid_parentheses

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

q12_clock_angle: q12_clock_angle.c
	$(CC) $(CFLAGS) -o $@ $< -lm

clean:
	rm -f $(PROGS)

.PHONY: all clean
