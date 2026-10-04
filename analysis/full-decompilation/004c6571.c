
undefined4 __fastcall FUN_004c6571(int *param_1)

{
  undefined4 uVar1;
  int *local_8;
  
  local_8 = param_1;
  FUN_00601485(&local_8,&stack0x00000004);
  if (local_8 == (int *)*param_1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_8[5] + 0x10);
  }
  return uVar1;
}

