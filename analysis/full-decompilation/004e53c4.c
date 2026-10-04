
void FUN_004e53c4(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + -4);
  *(undefined4 *)(param_2 + -4) = *param_1;
  FUN_004e5372(param_1,0,(param_2 - (int)param_1) + -4 >> 2,uVar1);
  return;
}

