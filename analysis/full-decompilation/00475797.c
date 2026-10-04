
undefined4 __thiscall FUN_00475797(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) || (*(short *)(param_1 + 0x18) == 0)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_004757ba(*(int *)(param_1 + 0x14),*(short *)(param_1 + 0x18),param_2);
  }
  return uVar1;
}

