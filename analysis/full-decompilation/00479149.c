
undefined4 __thiscall FUN_00479149(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 < 0) || (1 < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x58 + param_2 * 4);
  }
  return uVar1;
}

