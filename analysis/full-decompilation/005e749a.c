
undefined4 __thiscall FUN_005e749a(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int local_8;
  
  local_8 = param_1;
  FUN_005e76d4(&local_8,&param_2);
  if (local_8 == *(int *)(param_1 + 4)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_8 + 0x14);
  }
  return uVar1;
}

