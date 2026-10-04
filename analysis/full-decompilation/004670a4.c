
undefined4 __fastcall FUN_004670a4(int param_1)

{
  undefined4 uVar1;
  int local_8;
  
  local_8 = param_1;
  FUN_0046913f(&local_8,&stack0x00000004);
  if (local_8 == *(int *)(param_1 + 4)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_8 + 0x14);
  }
  return uVar1;
}

