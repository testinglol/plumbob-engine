
void FUN_00618d50(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  
  piVar4 = *(int **)(param_1 + 0xc);
  iVar9 = *piVar4;
  iVar8 = piVar4[1];
  iVar1 = piVar4[2];
  puVar11 = param_2;
  for (iVar5 = 0x300; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  iVar5 = *(int *)(iVar9 + 0x24);
  iVar10 = 0;
  if (0 < iVar5) {
    puVar2 = (undefined1 *)((int)param_2 + 2);
    puVar6 = (undefined1 *)(iVar9 + 0x2a);
    do {
      puVar2[-2] = puVar6[1];
      puVar2[-1] = *puVar6;
      *puVar2 = puVar6[-1];
      puVar2[1] = puVar6[-2];
      *(undefined4 *)(puVar2 + 2) = 0;
      *(int *)(puVar2 + 6) = iVar10;
      iVar10 = iVar10 + 1;
      puVar6 = puVar6 + 4;
      puVar2 = puVar2 + 0xc;
    } while (iVar10 < iVar5);
  }
  param_1 = *(int *)(iVar9 + 0x14);
  if (0 < param_1) {
    iVar10 = *(int *)(iVar9 + 0x10);
    do {
      iVar3 = 0;
      if (0 < iVar10) {
        do {
          param_2[(uint)*(byte *)(iVar8 + iVar3) * 3 + 1] =
               param_2[(uint)*(byte *)(iVar8 + iVar3) * 3 + 1] + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar10);
      }
      iVar8 = iVar8 + iVar1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  if (0 < iVar5) {
    piVar4 = param_2 + 1;
    pcVar7 = (char *)(iVar9 + 0x2b);
    do {
      if (param_3 == 1) {
        if (((pcVar7[-1] == '\0') && (pcVar7[-2] == '\0')) && (pcVar7[-3] == '\0')) {
          if (*pcVar7 != '\0') goto LAB_00618e13;
          iVar9 = *piVar4 + 0x186a1;
          goto LAB_00618e1b;
        }
      }
      else if (param_3 == 2) {
        if (*pcVar7 == '\0') {
          iVar9 = -100000 - *piVar4;
          goto LAB_00618e1b;
        }
      }
      else if ((param_3 == 3) && (*pcVar7 == '\0')) {
LAB_00618e13:
        iVar9 = *piVar4 + 100000;
LAB_00618e1b:
        *piVar4 = iVar9;
      }
      pcVar7 = pcVar7 + 4;
      piVar4 = piVar4 + 3;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return;
}

