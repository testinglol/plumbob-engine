
void __thiscall FUN_0062e939(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar3 = param_2;
  iVar5 = param_1 + param_3 * 0xa0;
  iVar6 = iVar5 + 0x34e4 + param_4 * 0x48;
  if ((*(int *)(iVar5 + 0x34f4 + param_4 * 0x48) == 0) || (*(int *)(iVar6 + 0x14) != 2)) {
    param_2 = param_2 - (int)param_5;
    iVar6 = 0x240;
    do {
      *param_5 = *(undefined4 *)((int)param_5 + param_2);
      param_5 = param_5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  else {
    puVar2 = param_5;
    for (iVar5 = 0x240; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    if (*(int *)(iVar6 + 0x18) == 0) {
      iVar6 = 0;
      do {
        iVar3 = (uint)*(byte *)(param_1 + 0x4a0f) * 0x240 + iVar6;
        iVar6 = iVar6 + 1;
        *param_5 = *(undefined4 *)(param_2 + *(short *)(&DAT_00685ff4 + iVar3 * 2) * 4);
        param_5 = param_5 + 1;
      } while (iVar6 < 0x240);
    }
    else {
      iVar6 = 0x24;
      puVar2 = param_5;
      do {
        *puVar2 = *(undefined4 *)((param_2 - (int)param_5) + (int)puVar2);
        puVar2 = puVar2 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar6 = (uint)*(byte *)(param_1 + 0x4a0f) * 0x4a;
      param_2 = 3;
      iVar5 = (int)*(short *)(&DAT_0067d7ac + iVar6);
      param_3 = *(short *)(&DAT_0067d7ae + iVar6) - iVar5;
      do {
        if (param_3 != 0) {
          puVar2 = (undefined4 *)(iVar3 + iVar5 * 0xc);
          puVar7 = param_5 + iVar5 * 3 + 1;
          puVar8 = (undefined4 *)(iVar3 + (iVar5 * 3 + param_3) * 4);
          puVar4 = (undefined4 *)(iVar3 + (iVar5 * 3 + param_3 * 2) * 4);
          do {
            uVar1 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar7[-1] = uVar1;
            *puVar7 = *puVar8;
            puVar7[1] = *puVar4;
            puVar8 = puVar8 + 1;
            puVar4 = puVar4 + 1;
            puVar7 = puVar7 + 3;
            param_3 = param_3 + -1;
          } while (param_3 != 0);
        }
        param_2 = param_2 + 1;
        iVar6 = ((uint)*(byte *)(param_1 + 0x4a0f) * 0x25 + param_2) * 2;
        iVar5 = (int)*(short *)(&DAT_0067d7a6 + iVar6);
        param_3 = *(short *)(&DAT_0067d7a8 + iVar6) - iVar5;
      } while (param_2 < 0xd);
    }
  }
  return;
}

