
void __thiscall FUN_005d0b17(int param_1,undefined4 *param_2)

{
  float *pfVar1;
  
  *(undefined4 *)(param_1 + 0x20) = *param_2;
  pfVar1 = (float *)(param_1 + 0x30);
  *pfVar1 = *(float *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x1c);
  *pfVar1 = *pfVar1 * *(float *)(param_1 + 0x20);
  *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x20);
  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x20);
  *(float *)(param_1 + 0x3c) = *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x20);
  FUN_005d0b5a();
  return;
}

