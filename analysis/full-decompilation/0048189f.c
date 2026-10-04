
void __fastcall FUN_0048189f(int *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[0x14];
  if (uVar1 != 0xffffffff) {
    if (-1 < (int)uVar1) {
      if (uVar1 < (uint)(param_1[1] - *param_1 >> 4)) {
        *(undefined4 *)(uVar1 * 0x10 + 8 + *param_1) = 0;
      }
    }
    param_1[0x14] = -1;
    param_1[0x15] = -1;
  }
  return;
}

