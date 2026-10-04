
void __thiscall FUN_005d0abe(int param_1,float *param_2,undefined4 *param_3,undefined4 *param_4)

{
  float *pfVar1;
  undefined4 uVar2;
  
  *(float *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = *param_3;
  uVar2 = *param_4;
  *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  pfVar1 = (float *)(param_1 + 0x30);
  *pfVar1 = *(float *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x1c);
  *pfVar1 = *(float *)(param_1 + 0x20) * *pfVar1;
  *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x34);
  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x38);
  *(float *)(param_1 + 0x3c) = *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x3c);
  FUN_005d0b5a();
  return;
}

