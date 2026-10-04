
void FUN_0044a819(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  while (1 < param_2 - (int)param_1 >> 2) {
    uVar1 = *(undefined4 *)(param_2 + -4);
    *(undefined4 *)(param_2 + -4) = *param_1;
    FUN_0044a8e4(param_1,0,(param_2 + -4) - (int)param_1 >> 2,uVar1,param_3);
    param_2 = param_2 + -4;
  }
  return;
}

