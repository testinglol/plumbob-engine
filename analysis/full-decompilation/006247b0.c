
void FUN_006247b0(int *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_18;
  
  iVar7 = param_3;
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x10);
  iVar3 = *(int *)(iVar1 + 0x14);
  local_18 = 0;
  if (0 < iVar3) {
    do {
      param_3 = 0;
      if (0 < iVar2) {
        iVar4 = param_1[2];
        iVar5 = param_1[1];
        do {
          iVar8 = *(int *)(iVar1 + 0x18);
          iVar8 = FUN_00583543(((int)(iVar8 * param_3 + (iVar8 * param_3 >> 0x1f & 7U)) >> 3) +
                               iVar5 + iVar4 * local_18,(int)(iVar8 + (iVar8 >> 0x1f & 7U)) >> 3);
          if (iVar8 == iVar7) {
            if (0 < param_4) {
              iVar9 = param_3 - param_4;
              iVar8 = param_4;
              do {
                if (iVar9 < 0) break;
                iVar6 = *(int *)(*param_2 + 0x18);
                FUN_00583564(((int)(iVar9 * iVar6 + (iVar9 * iVar6 >> 0x1f & 7U)) >> 3) +
                             param_2[2] * local_18 + param_2[1],iVar7,
                             (int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3);
                iVar8 = iVar8 + -1;
                iVar9 = iVar9 + 1;
              } while (0 < iVar8);
            }
            if (0 < param_4) {
              iVar8 = param_3 + param_4;
              iVar9 = param_4;
              do {
                if (iVar2 <= iVar8) break;
                iVar6 = *(int *)(*param_2 + 0x18);
                FUN_00583564(((int)(iVar8 * iVar6 + (iVar8 * iVar6 >> 0x1f & 7U)) >> 3) +
                             param_2[2] * local_18 + param_2[1],iVar7,
                             (int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3);
                iVar9 = iVar9 + -1;
                iVar8 = iVar8 + -1;
              } while (0 < iVar9);
            }
            if (0 < param_4) {
              iVar9 = local_18 - param_4;
              iVar8 = param_4;
              do {
                if (iVar9 < 0) break;
                iVar6 = *(int *)(*param_2 + 0x18);
                FUN_00583564(param_2[2] * iVar9 +
                             ((int)(iVar6 * param_3 + (iVar6 * param_3 >> 0x1f & 7U)) >> 3) +
                             param_2[1],iVar7,(int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3);
                iVar8 = iVar8 + -1;
                iVar9 = iVar9 + 1;
              } while (0 < iVar8);
            }
            if (0 < param_4) {
              iVar8 = local_18 + param_4;
              iVar9 = param_4;
              do {
                if (iVar3 <= iVar8) break;
                iVar6 = *(int *)(*param_2 + 0x18);
                FUN_00583564(param_2[2] * iVar8 +
                             ((int)(iVar6 * param_3 + (iVar6 * param_3 >> 0x1f & 7U)) >> 3) +
                             param_2[1],iVar7,(int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3);
                iVar9 = iVar9 + -1;
                iVar8 = iVar8 + -1;
              } while (0 < iVar9);
            }
          }
          param_3 = param_3 + 1;
        } while (param_3 < iVar2);
      }
      local_18 = local_18 + 1;
    } while (local_18 < iVar3);
  }
  return;
}

