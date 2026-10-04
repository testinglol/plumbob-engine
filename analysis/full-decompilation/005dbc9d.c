
void FUN_005dbc9d(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar3 = param_2;
  while( true ) {
    iVar1 = iVar3 * 2;
    iVar2 = iVar1 + 2;
    if (param_3 <= iVar2) break;
    iVar4 = iVar2 * 0x10 + param_1;
    if (*(int *)(iVar4 + 8) < *(int *)(iVar4 + -8)) {
      iVar2 = iVar1 + 1;
    }
    puVar5 = (undefined4 *)(iVar2 * 0x10 + param_1);
    puVar6 = (undefined4 *)(iVar3 * 0x10 + param_1);
    *puVar6 = *puVar5;
    puVar6[1] = puVar5[1];
    puVar6[2] = puVar5[2];
    puVar6[3] = puVar5[3];
    iVar3 = iVar2;
  }
  if (iVar2 == param_3) {
    puVar5 = (undefined4 *)(iVar2 * 0x10 + -0x10 + param_1);
    puVar6 = (undefined4 *)(iVar3 * 0x10 + param_1);
    *puVar6 = *puVar5;
    puVar6[1] = puVar5[1];
    puVar6[2] = puVar5[2];
    puVar6[3] = puVar5[3];
    iVar3 = iVar1 + 1;
  }
  FUN_005dbd19(param_1,iVar3,param_2,param_4,param_5,param_6,param_7);
  return;
}

