
undefined4 __thiscall FUN_005955bb(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((((*param_1 == 1) && (param_1[0xd] != 0)) && ((param_1[0xb] - param_1[10] & 0xfffffffcU) == 0)
      ) && ((uint)(param_1[0xd] + DAT_006d1a54) < param_2)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

