
undefined4 __thiscall FUN_004577bb(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 0xb4) & 1) == 0) {
    FUN_004577f6();
  }
  if (((int)param_2 < 0) ||
     ((uint)(*(int *)(param_1 + 0x98) - *(int *)(param_1 + 0x94) >> 2) <= param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x94) + param_2 * 4);
  }
  return uVar1;
}

