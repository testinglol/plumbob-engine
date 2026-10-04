
undefined4 __thiscall FUN_00484901(int *param_1,short param_2)

{
  undefined4 uVar1;
  
  if ((param_2 < 0) || (0xb < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*param_1 + param_2 * 4);
  }
  return uVar1;
}

