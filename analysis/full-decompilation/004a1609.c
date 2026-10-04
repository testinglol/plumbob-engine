
uint __fastcall FUN_004a1609(int *param_1)

{
  uint uVar1;
  int *local_8;
  
  local_8 = param_1;
  FUN_00601485(&local_8,&stack0x00000004);
  if (local_8 == (int *)*param_1) {
    uVar1 = 2;
  }
  else {
    uVar1 = *(uint *)(local_8[5] + 0x2c) & 0xff;
  }
  return uVar1;
}

