
undefined4 __thiscall FUN_0046aa90(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  
  if (*(int *)(*(int *)(*param_2 + 4) + 8 + (int)param_2) == 0) {
    puVar4 = &DAT_006c08dc;
    FUN_006321fb(4);
    FUN_006323d0(puVar4);
    FUN_00633280(param_1[3]);
    FUN_00633204(0x20);
    puVar4 = &DAT_006c08dc;
    FUN_00633280(param_1[4]);
    FUN_006323d0(puVar4);
    FUN_006321fb((char)param_1[7] != '\0');
    FUN_00633204(0x20);
    puVar4 = &DAT_006c08dc;
    FUN_00633204(0x20);
    FUN_006323d0(puVar4);
    FUN_006321fb((char)param_1[0xc] != '\0');
    FUN_00633204(0x20);
    puVar4 = &DAT_006c08dc;
    FUN_00633204(0x20);
    FUN_006323d0(puVar4);
    FUN_006321fb((char)param_1[9] != '\0');
    FUN_00633204(0x20);
    FUN_00633204(0x20);
    puVar4 = &DAT_006c08dc;
    FUN_006321fb(param_1[10]);
    FUN_006323d0(puVar4);
    FUN_006321fb(*(char *)((int)param_1 + 0x1d) != '\0');
    FUN_00633204(0x20);
    FUN_00633204(0x20);
    puVar4 = &DAT_006c08dc;
    FUN_006321fb(param_1[8]);
    FUN_006323d0(puVar4);
    FUN_006321fb((char)param_1[5] != '\0');
    FUN_00633204(0x20);
    FUN_00633204(0x20);
    puVar4 = &DAT_006c08dc;
    FUN_006321fb(param_1[6]);
    FUN_006323d0(puVar4);
    puVar4 = &DAT_006c08dc;
    FUN_0063301c((((int *)*param_1)[1] - *(int *)*param_1) / 0x14);
    FUN_006323d0(puVar4);
    piVar2 = (int *)*param_1;
    for (iVar3 = *piVar2; iVar3 != piVar2[1]; iVar3 = iVar3 + 0x14) {
      puVar4 = &DAT_006c08dc;
      FUN_0046aca3(param_2,iVar3,&DAT_006c08dc);
      FUN_006323d0(puVar4);
      piVar2 = (int *)*param_1;
    }
    iVar3 = (((int *)param_1[1])[1] - *(int *)param_1[1]) / 0x14;
    piVar2 = (int *)param_1[2];
    if (piVar2 != (int *)0x0) {
      iVar3 = iVar3 + (piVar2[1] - *piVar2) / 0x14;
    }
    puVar4 = &DAT_006c08dc;
    FUN_006321fb(iVar3);
    FUN_006323d0(puVar4);
    piVar2 = (int *)param_1[1];
    for (iVar3 = *piVar2; iVar3 != piVar2[1]; iVar3 = iVar3 + 0x14) {
      puVar4 = &DAT_006c08dc;
      FUN_0046aca3(param_2,iVar3,&DAT_006c08dc);
      FUN_006323d0(puVar4);
      piVar2 = (int *)param_1[1];
    }
    piVar2 = (int *)param_1[2];
    if (piVar2 != (int *)0x0) {
      for (iVar3 = *piVar2; iVar3 != piVar2[1]; iVar3 = iVar3 + 0x14) {
        puVar4 = &DAT_006c08dc;
        FUN_0046aca3(param_2,iVar3,&DAT_006c08dc);
        FUN_006323d0(puVar4);
        piVar2 = (int *)param_1[2];
      }
    }
    FUN_006321fb(param_1[0xb]);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

