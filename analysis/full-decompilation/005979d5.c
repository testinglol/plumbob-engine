
undefined4 __thiscall FUN_005979d5(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((((*param_1 == 1) && ((char)param_1[0x1f] == '\0')) && (param_1[0x1e] != 0)) &&
     (((param_1[0x1c] - param_1[0x1b] & 0xfffffffcU) == 0 &&
      ((uint)(param_1[0x1e] + DAT_006d1a4c) < param_2)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

