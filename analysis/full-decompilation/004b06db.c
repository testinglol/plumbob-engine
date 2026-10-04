
void FUN_004b06db(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = FUN_004b462b(0,1);
  if (cVar1 == '\0') {
    iVar8 = *param_1;
    local_10 = param_1[1];
    local_c = param_1[2];
    local_8 = param_1[3];
    if (param_4 != (int *)0x0) {
      iVar4 = *param_4;
      iVar3 = iVar4;
      if (iVar4 <= *param_1) {
        iVar3 = iVar8;
      }
      iVar6 = param_4[2] + -1;
      iVar8 = iVar3;
      if (iVar6 < *param_1) {
        iVar8 = iVar6;
      }
      if (param_1[2] < iVar4) {
        local_c = iVar4;
      }
      if (iVar6 < param_1[2]) {
        local_c = iVar6;
      }
      iVar4 = param_4[1];
      if (param_1[1] < iVar4) {
        local_10 = iVar4;
      }
      iVar3 = param_4[3] + -1;
      if (iVar3 < param_1[1]) {
        local_10 = iVar3;
      }
      if (iVar3 < param_1[3]) {
        local_8 = iVar3;
      }
      if (param_1[3] < iVar4) {
        local_8 = iVar4;
      }
    }
    iVar4 = local_c - iVar8;
    if ((0 < iVar4) && (0 < local_8 - local_10)) {
      iVar3 = DAT_006f0bcc + ((DAT_006f0bbc * local_10) / 2) * 2;
      iVar6 = iVar3 + (((local_8 - local_10) * DAT_006f0bbc) / 2) * 2;
      if (*(int *)(DAT_006e486c + 0x34) == 1) {
        uVar2 = FUN_0049f1f4();
      }
      else {
        uVar2 = FUN_0049f21b(param_2);
      }
      if (iVar8 < local_c) {
        puVar5 = (ushort *)(iVar3 + iVar8 * 2);
        iVar7 = iVar4;
        do {
          *puVar5 = *puVar5 ^ uVar2;
          puVar5 = puVar5 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      for (; iVar3 != iVar6; iVar3 = iVar3 + (DAT_006f0bbc / 2) * 2) {
        puVar5 = (ushort *)(iVar3 + iVar8 * 2);
        *puVar5 = *puVar5 ^ uVar2;
        puVar5 = (ushort *)(iVar3 + -2 + local_c * 2);
        *puVar5 = *puVar5 ^ uVar2;
      }
      if (iVar8 < local_c) {
        puVar5 = (ushort *)(iVar6 + (DAT_006f0bbc / 2) * -2 + iVar8 * 2);
        do {
          *puVar5 = *puVar5 ^ uVar2;
          puVar5 = puVar5 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
  }
  return;
}

