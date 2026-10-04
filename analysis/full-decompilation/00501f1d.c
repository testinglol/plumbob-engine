
void FUN_00501f1d(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = (int)param_2 - (int)param_1;
  while (4 < (int)(uVar3 & 0xfffffffc)) {
    uVar2 = param_2[-1];
    puVar1 = param_2 + -1;
    *puVar1 = *param_1;
    FUN_00501f69(param_1,0,(int)param_2 + (-4 - (int)param_1) >> 2,uVar2,param_3);
    param_2 = puVar1;
    uVar3 = (int)puVar1 - (int)param_1;
  }
  return;
}

