
undefined4 __thiscall FUN_00487be9(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2 - param_1[3];
  if (((int)uVar1 < 0) || ((uint)(param_1[1] - *param_1 >> 2) <= uVar1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0043acf5(*(undefined4 *)(*param_1 + uVar1 * 4));
  }
  return uVar2;
}

