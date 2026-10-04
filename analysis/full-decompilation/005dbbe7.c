
void FUN_005dbbe7(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  while (0x10 < (int)((int)param_2 - (int)param_1 & 0xfffffff0U)) {
    puVar5 = param_2 + -4;
    uVar1 = *puVar5;
    uVar2 = param_2[-3];
    uVar3 = param_2[-2];
    uVar4 = param_2[-1];
    *puVar5 = *param_1;
    param_2[-3] = param_1[1];
    param_2[-2] = param_1[2];
    param_2[-1] = param_1[3];
    FUN_005dbc9d(param_1,0,(int)param_2 + (-0x10 - (int)param_1) >> 4,uVar1,uVar2,uVar3,uVar4);
    param_2 = puVar5;
  }
  return;
}

