int nums[3][4] =
[
    [0, 1, 2, 3],
    [4, 5, 6, 7],
    [8, 9, 10, 11]
]

2: nums[0][2]
7: nums[1][3]

int one[3] = [12, 13, 14]

              start of nums[1]
              |
[ 0, 1, 2, 3, 4, 5, 6, 7, ... ]
  ^           
  start of nums[0]

&nums = 100
&nums[1][3] = &nums + 7*4
            = &nums + 28
            = 128

sizeof([1, 2, 3, 4]) = 4 * 4 = 16

type 4_ELEM_ARRAY is 16 bytes

4_ELEM_ARRAY nums[3]

recalculate &nums[1][3]

&nums[1] = &nums + 1*sizeof(4_ELEM_ARRAY)
         = &nums + 16
         = 116

&nums[1][3] = &nums[1] + 3*sizeof(int)
            = &nums[1] + 12
            = 116 + 12
            = 128

&nums[2][1] = &nums + 2*sizeof(4_ELEM_ARRAY) + 1*sizeof(int)
            = &nums + 2*16 + 1*4
            = 100 + 32 + 4
            = 136
