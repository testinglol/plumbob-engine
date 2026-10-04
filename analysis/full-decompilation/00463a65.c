
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463a65(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  int iVar5;
  undefined2 extraout_var;
  undefined4 uVar6;
  int extraout_ECX;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int unaff_EBP;
  float10 fVar11;
  float10 fVar12;
  
  FUN_00634c24();
  sVar4 = *(short *)(extraout_ECX + 0x56);
  *(uint *)(unaff_EBP + -0x14) = CONCAT22(extraout_var,sVar4);
  if (sVar4 == 0) {
    uVar6 = FUN_00463970(*(undefined4 *)(extraout_ECX + 0xdc));
    *(short *)(extraout_ECX + 0x56) = (short)uVar6;
    iVar5 = *(int *)(extraout_ECX + 0xdc);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
    iVar9 = *(int *)(iVar5 + 0x90);
    *(float *)(unaff_EBP + -0x20) = DAT_00667478;
    for (; iVar9 != *(int *)(iVar5 + 0x94); iVar9 = iVar9 + 4) {
      FUN_00463155(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x20));
    }
  }
  iVar5 = *(int *)(extraout_ECX + 0x1ac);
  uVar7 = (uint)*(short *)(unaff_EBP + -0x14);
  if (uVar7 <= (uint)(*(int *)(extraout_ECX + 0x1b0) - iVar5 >> 2)) {
    if ((*(short *)(unaff_EBP + -0x14) < 1) ||
       ((uint)(*(int *)(extraout_ECX + 0x1b0) - iVar5 >> 2) < uVar7)) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = *(float *)(iVar5 + -4 + uVar7 * 4);
    }
    if (fVar2 != DAT_00667478) goto LAB_00463d8a;
  }
  iVar5 = *(int *)(extraout_ECX + 0xdc);
  *(undefined4 *)(unaff_EBP + -0x20) = DAT_00667474;
  for (iVar9 = *(int *)(iVar5 + 0x90); iVar9 != *(int *)(iVar5 + 0x94); iVar9 = iVar9 + 4) {
    FUN_00463155(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x20));
  }
  FUN_00463155(*(undefined4 *)(unaff_EBP + -0x14),0);
  FUN_0055e4e2(unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  FUN_00448766(unaff_EBP + -0x24);
  while( true ) {
    iVar5 = *(int *)(unaff_EBP + -0x30);
    uVar7 = *(int *)(unaff_EBP + -0x2c) - iVar5;
    if ((uVar7 & 0xfffffffc) == 0) break;
    iVar9 = ((int)uVar7 >> 2) + -1;
    *(int *)(unaff_EBP + -0x18) = iVar9;
    *(int *)(unaff_EBP + -0x20) = iVar9;
    piVar8 = (int *)(unaff_EBP + -0x18);
    *piVar8 = *piVar8 + -1;
    if (-1 < *piVar8) {
      *(int *)(unaff_EBP + -0x1c) = iVar9 * 4;
      do {
        iVar10 = *(int *)(unaff_EBP + -0x18) * 4;
        iVar9 = *(int *)(iVar10 + iVar5);
        if (*(short *)(unaff_EBP + -0x14) < 1) {
LAB_00463bd4:
          fVar2 = 0.0;
        }
        else {
          piVar8 = (int *)(iVar9 + 0x1ac);
          if ((uint)(*(int *)(iVar9 + 0x1b0) - *piVar8 >> 2) <
              (uint)(int)*(short *)(unaff_EBP + -0x14)) goto LAB_00463bd4;
          fVar2 = *(float *)(*piVar8 + -4 + *(short *)(unaff_EBP + -0x14) * 4);
        }
        iVar9 = *(int *)(*(int *)(unaff_EBP + -0x1c) + iVar5);
        if (*(short *)(unaff_EBP + -0x14) < 1) {
LAB_00463c04:
          fVar3 = 0.0;
        }
        else {
          piVar8 = (int *)(iVar9 + 0x1ac);
          if ((uint)(*(int *)(iVar9 + 0x1b0) - *piVar8 >> 2) <
              (uint)(int)*(short *)(unaff_EBP + -0x14)) goto LAB_00463c04;
          fVar3 = *(float *)(*piVar8 + -4 + *(short *)(unaff_EBP + -0x14) * 4);
        }
        if (fVar2 < fVar3) {
          *(int *)(unaff_EBP + -0x1c) = iVar10;
          *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x18);
        }
        piVar8 = (int *)(unaff_EBP + -0x18);
        *piVar8 = *piVar8 + -1;
      } while (-1 < *piVar8);
      iVar9 = *(int *)(unaff_EBP + -0x20);
    }
    iVar10 = *(int *)(iVar5 + iVar9 * 4);
    FUN_004486a3(iVar5 + iVar9 * 4);
    uVar6 = FUN_00463804();
    iVar5 = *(int *)(extraout_ECX + 0xdc);
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar6;
    piVar8 = *(int **)(iVar5 + 0x90);
    while (piVar1 = *(int **)(iVar5 + 0x94), *(int **)(unaff_EBP + -0x18) = piVar8, piVar8 != piVar1
          ) {
      iVar9 = *piVar8;
      if ((*(short *)(iVar9 + 0x84) == *(short *)(iVar10 + 0x84)) ||
         (iVar9 == *(int *)(unaff_EBP + -0x1c))) {
        if (*(short *)(unaff_EBP + -0x14) < 1) {
LAB_00463c9a:
          fVar2 = 0.0;
        }
        else {
          if ((uint)(*(int *)(iVar9 + 0x1b0) - *(int *)(iVar9 + 0x1ac) >> 2) <
              (uint)(int)*(short *)(unaff_EBP + -0x14)) goto LAB_00463c9a;
          fVar2 = *(float *)(*(int *)(iVar9 + 0x1ac) + -4 + *(short *)(unaff_EBP + -0x14) * 4);
        }
        if (*(short *)(unaff_EBP + -0x14) < 1) {
LAB_00463cc4:
          fVar3 = 0.0;
        }
        else {
          if ((uint)(*(int *)(iVar10 + 0x1b0) - *(int *)(iVar10 + 0x1ac) >> 2) <
              (uint)(int)*(short *)(unaff_EBP + -0x14)) goto LAB_00463cc4;
          fVar3 = *(float *)(*(int *)(iVar10 + 0x1ac) + -4 + *(short *)(unaff_EBP + -0x14) * 4);
        }
        if (fVar3 < fVar2) {
          if (*(short *)(unaff_EBP + -0x14) < 1) {
LAB_00463cff:
            uVar6 = 0;
          }
          else {
            if ((uint)(*(int *)(iVar10 + 0x1b0) - *(int *)(iVar10 + 0x1ac) >> 2) <
                (uint)(int)*(short *)(unaff_EBP + -0x14)) goto LAB_00463cff;
            uVar6 = *(undefined4 *)
                     (*(int *)(iVar10 + 0x1ac) + -4 + *(short *)(unaff_EBP + -0x14) * 4);
          }
          *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
          fVar11 = (float10)FUN_004341ed(**(undefined4 **)(unaff_EBP + -0x18));
          fVar11 = fVar11 + (float10)*(float *)(unaff_EBP + -0x20) + (float10)_DAT_00667280;
          if (*(short *)(unaff_EBP + -0x14) < 1) {
LAB_00463d46:
            fVar12 = (float10)0;
          }
          else {
            piVar8 = (int *)(**(int **)(unaff_EBP + -0x18) + 0x1ac);
            if ((uint)(*(int *)(**(int **)(unaff_EBP + -0x18) + 0x1b0) - *piVar8 >> 2) <
                (uint)(int)*(short *)(unaff_EBP + -0x14)) goto LAB_00463d46;
            fVar12 = (float10)*(float *)(*piVar8 + -4 + *(short *)(unaff_EBP + -0x14) * 4);
          }
          if (fVar11 < fVar12) {
            FUN_00463155(*(undefined4 *)(unaff_EBP + -0x14),(float)fVar11);
            FUN_00448766(*(undefined4 *)(unaff_EBP + -0x18));
          }
        }
      }
      piVar8 = (int *)(*(int *)(unaff_EBP + -0x18) + 4);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00448b4d();
LAB_00463d8a:
  FUN_00463da6(*(undefined4 *)(unaff_EBP + -0x14));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

