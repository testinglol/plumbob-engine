
void FUN_005c0f9b(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,uint param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = param_2;
  while( true ) {
    iVar3 = iVar6 * 2;
    iVar1 = iVar3 + 2;
    if (param_3 <= iVar1) break;
    iVar2 = iVar1 * 0x10 + param_1;
    if (*(uint *)(iVar2 + 0xc) < *(uint *)(iVar2 + -4)) {
      iVar1 = iVar3 + 1;
    }
    puVar4 = (undefined4 *)(iVar1 * 0x10 + param_1);
    puVar5 = (undefined4 *)(iVar6 * 0x10 + param_1);
    *puVar5 = *puVar4;
    puVar5[1] = puVar4[1];
    puVar5[2] = puVar4[2];
    puVar5[3] = puVar4[3];
    iVar6 = iVar1;
  }
  if (iVar1 == param_3) {
    puVar4 = (undefined4 *)(iVar1 * 0x10 + -0x10 + param_1);
    puVar5 = (undefined4 *)(iVar6 * 0x10 + param_1);
    *puVar5 = *puVar4;
    puVar5[1] = puVar4[1];
    puVar5[2] = puVar4[2];
    puVar5[3] = puVar4[3];
    iVar6 = iVar3 + 1;
  }
  while ((iVar1 = (iVar6 + -1) / 2, param_2 < iVar6 &&
         (iVar3 = iVar1 * 0x10, puVar4 = (undefined4 *)(iVar3 + param_1),
         *(uint *)(iVar3 + 0xc + param_1) < param_7))) {
    puVar5 = (undefined4 *)(iVar6 * 0x10 + param_1);
    *puVar5 = *puVar4;
    puVar5[1] = puVar4[1];
    puVar5[2] = puVar4[2];
    puVar5[3] = puVar4[3];
    iVar6 = iVar1;
  }
  puVar4 = (undefined4 *)(iVar6 * 0x10 + param_1);
  *puVar4 = param_4;
  puVar4[1] = param_5;
  puVar4[2] = param_6;
  puVar4[3] = param_7;
  return;
}

