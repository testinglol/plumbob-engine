
void FUN_00438d9d(undefined2 *param_1,int param_2,int *param_3,int param_4,int param_5,int param_6)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = DAT_006f0bbc / 2;
  iVar6 = *param_3;
  iVar2 = DAT_006f0bd4 / 2;
  puVar5 = (undefined2 *)(DAT_006f0bcc + (iVar4 * param_2 + (int)param_1) * 2);
  param_2 = DAT_006f0bd0 + (iVar2 * param_2 + (int)param_1) * 2;
  iVar7 = param_6 * param_3[1] + iVar6;
  if (*(int *)(DAT_006e486c + 0x34) == 1) {
    for (; iVar6 != iVar7; iVar6 = iVar6 + param_3[1]) {
      param_6 = 0;
      if (0 < param_5) {
        param_1 = puVar5;
        do {
          if ((*(short *)((param_2 - (int)puVar5) + (int)param_1) == -1) &&
             (iVar3 = (uint)*(byte *)(param_6 + iVar6) + param_4, iVar3 < 0xff)) {
            FUN_00438f76(CONCAT22((short)((uint)iVar3 >> 0x10),*param_1));
            uVar1 = FUN_00438f12();
            *param_1 = uVar1;
          }
          param_6 = param_6 + 1;
          param_1 = param_1 + 1;
        } while (param_6 < param_5);
      }
      puVar5 = puVar5 + iVar4;
      param_2 = param_2 + iVar2 * 2;
    }
  }
  else {
    for (; iVar6 != iVar7; iVar6 = iVar6 + param_3[1]) {
      param_6 = 0;
      if (0 < param_5) {
        param_1 = puVar5;
        do {
          if ((*(short *)((int)param_1 + (param_2 - (int)puVar5)) == -1) &&
             (iVar3 = (uint)*(byte *)(param_6 + iVar6) + param_4, iVar3 < 0xff)) {
            FUN_00438f9b(CONCAT22((short)((uint)iVar3 >> 0x10),*param_1));
            uVar1 = FUN_00438f12();
            *param_1 = uVar1;
          }
          param_6 = param_6 + 1;
          param_1 = param_1 + 1;
        } while (param_6 < param_5);
      }
      puVar5 = puVar5 + iVar4;
      param_2 = param_2 + iVar2 * 2;
    }
  }
  return;
}

