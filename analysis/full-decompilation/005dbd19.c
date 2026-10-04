
void FUN_005dbd19(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_3 < param_2) {
    iVar1 = (param_2 + -1) / 2;
    iVar2 = iVar1 * 0x10;
    puVar4 = (undefined4 *)(iVar2 + param_1);
    if (param_6 <= *(int *)(iVar2 + 8 + param_1)) break;
    puVar3 = (undefined4 *)(param_2 * 0x10 + param_1);
    *puVar3 = *puVar4;
    puVar3[1] = puVar4[1];
    puVar3[2] = puVar4[2];
    puVar3[3] = puVar4[3];
    param_2 = iVar1;
  }
  puVar4 = (undefined4 *)(param_2 * 0x10 + param_1);
  *puVar4 = param_4;
  puVar4[1] = param_5;
  puVar4[2] = param_6;
  puVar4[3] = param_7;
  return;
}

