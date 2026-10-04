
void FUN_0049f41c(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5,int param_6,
                 int *param_7,int param_8,int param_9,int param_10,int param_11,uint *param_12,
                 int param_13,undefined4 *param_14)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int local_8;
  
  if (0 < (int)param_12[1]) {
    (**(code **)(*param_7 + 0xc))(param_12[1]);
    (**(code **)(*param_5 + 0xc))(param_12[1]);
    param_8 = param_8 + param_12[1] * param_9 * 2;
    param_10 = param_10 + param_12[1] * param_11 * 2;
  }
  iVar2 = FUN_004cebb0();
  iVar3 = FUN_00492d2c();
  iVar7 = param_3 - param_12[2];
  iVar3 = *(int *)(iVar2 + (7 - iVar3) * 4) + DAT_006f0084 * -4;
  iVar2 = *(int *)(iVar3 + param_2 * 4);
  uVar4 = param_12[1];
  if ((int)uVar4 < (int)(param_4 - param_12[3])) {
    piVar8 = (int *)(iVar3 + (param_2 + uVar4) * 4);
    param_3 = (param_4 - param_12[3]) - uVar4;
    do {
      cVar1 = (**(code **)(*param_7 + 8))(&DAT_006c6730,&param_14);
      if (cVar1 == '\0') {
        (**(code **)(*param_5 + 0xc))(1);
      }
      else {
        (**(code **)(*param_5 + 8))(&DAT_006efbdc,&local_8);
        uVar4 = *param_12;
        iVar3 = (*piVar8 - iVar2) + param_13;
        if ((int)uVar4 < iVar7) {
          puVar6 = (ushort *)(param_10 + uVar4 * 2);
          do {
            if ((*(char *)((int)param_14 + uVar4) != -1) &&
               (*(char *)((int)param_14 + uVar4) = -1, iVar3 <= (int)(uint)*puVar6)) {
              *(undefined2 *)((param_8 - param_10) + (int)puVar6) =
                   *(undefined2 *)(param_6 + (uint)*(byte *)(uVar4 + local_8) * 2);
              *puVar6 = (ushort)iVar3;
            }
            uVar4 = uVar4 + 1;
            puVar6 = puVar6 + 1;
          } while ((int)uVar4 < iVar7);
        }
        uVar4 = *param_12;
        if (uVar4 != 0) {
          puVar9 = param_14;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar9 = 0xffffffff;
            puVar9 = puVar9 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar9 = 0xff;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
        }
        uVar4 = param_12[2];
        if (uVar4 != 0) {
          puVar9 = (undefined4 *)((int)param_14 + iVar7);
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar9 = 0xffffffff;
            puVar9 = puVar9 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar9 = 0xff;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
        }
      }
      param_8 = param_8 + param_9 * 2;
      piVar8 = piVar8 + 1;
      param_3 = param_3 + -1;
      param_10 = param_10 + param_11 * 2;
    } while (param_3 != 0);
  }
  return;
}

