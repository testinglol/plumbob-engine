
undefined4 __thiscall FUN_00465300(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((int)param_2 < 0) || ((uint)(param_1[1] - *param_1 >> 2) <= param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(*param_1 + param_2 * 4) + 0xc);
  }
  return uVar1;
}

