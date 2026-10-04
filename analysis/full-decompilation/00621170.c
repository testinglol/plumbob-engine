
void FUN_00621170(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int local_4;
  
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar2 = *(int *)(*param_1 + 0x14);
  uVar5 = FUN_00612fc0(param_1,param_2,param_3);
  iVar6 = FUN_006213f0(uVar5,param_4,param_5,param_1);
  if ((((iVar6 == 0) && (-1 < param_2)) && (param_2 <= iVar1)) &&
     ((-1 < param_3 && (param_3 <= iVar2)))) {
    piVar7 = (int *)FUN_005a9320(160000);
    piVar13 = piVar7;
    if ((piVar7 < piVar7 + 40000) && ((-1 < param_3 + 1 && (param_3 + 1 < iVar2)))) {
      *piVar7 = param_3;
      piVar7[1] = param_2;
      piVar7[2] = param_2;
      piVar7[3] = 1;
      piVar13 = piVar7 + 4;
    }
    if ((piVar13 < piVar7 + 40000) && (param_3 < iVar2)) {
      *piVar13 = param_3 + 1;
      piVar13[1] = param_2;
      piVar13[2] = param_2;
      piVar13[3] = -1;
      piVar13 = piVar13 + 4;
    }
    while (piVar7 < piVar13) {
      iVar3 = piVar13[-1];
      iVar10 = piVar13[-3];
      iVar4 = piVar13[-2];
      piVar12 = piVar13 + -4;
      iVar11 = piVar13[-4] + iVar3;
      iVar6 = iVar10;
      if (iVar10 < 0) goto joined_r0x00621399;
      do {
        uVar8 = FUN_00612fc0(param_1,iVar6,iVar11,uVar5,param_5,param_1);
        iVar9 = FUN_006213f0(uVar8);
        if (iVar9 == 0) break;
        FUN_00613000(param_1,iVar6,iVar11,param_4);
        iVar6 = iVar6 + -1;
      } while (-1 < iVar6);
      if (iVar10 <= iVar6) goto joined_r0x00621399;
      local_4 = iVar6 + 1;
      if ((((local_4 < iVar10) && (piVar12 < piVar7 + 40000)) && (-1 < iVar11 - iVar3)) &&
         (iVar11 - iVar3 < iVar2)) {
        *piVar12 = iVar11;
        piVar13[-3] = local_4;
        piVar13[-2] = iVar10 + -1;
        piVar13[-1] = -iVar3;
        piVar12 = piVar13;
      }
      iVar6 = iVar10 + 1;
      piVar13 = piVar12;
joined_r0x006212ec:
      do {
        if (iVar6 < iVar1) {
          uVar8 = FUN_00612fc0(param_1,iVar6,iVar11,uVar5,param_5,param_1);
          iVar10 = FUN_006213f0(uVar8);
          if (iVar10 != 0) {
            FUN_00613000(param_1,iVar6,iVar11,param_4);
            iVar6 = iVar6 + 1;
            goto joined_r0x006212ec;
          }
        }
        if (((piVar13 < piVar7 + 40000) && (-1 < iVar3 + iVar11)) && (iVar3 + iVar11 < iVar2)) {
          piVar13[1] = local_4;
          *piVar13 = iVar11;
          piVar13[2] = iVar6 + -1;
          piVar13[3] = iVar3;
          piVar13 = piVar13 + 4;
        }
        piVar12 = piVar13;
        if (((iVar4 + 1 < iVar6) && (piVar13 < piVar7 + 40000)) &&
           ((-1 < iVar11 - iVar3 && (iVar11 - iVar3 < iVar2)))) {
          piVar13[1] = iVar4 + 1;
          *piVar13 = iVar11;
          piVar13[2] = iVar6 + -1;
          piVar13[3] = -iVar3;
          piVar12 = piVar13 + 4;
        }
joined_r0x00621399:
        do {
          piVar13 = piVar12;
          iVar6 = iVar6 + 1;
          if (iVar4 < iVar6) break;
          uVar8 = FUN_00612fc0(param_1,iVar6,iVar11,uVar5,param_5,param_1);
          iVar10 = FUN_006213f0(uVar8);
          piVar12 = piVar13;
        } while (iVar10 == 0);
        local_4 = iVar6;
      } while (iVar6 <= iVar4);
    }
    FUN_005a9340(piVar7);
  }
  return;
}

