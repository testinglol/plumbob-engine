
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0045bb94(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int extraout_ECX;
  int iVar8;
  int *piVar9;
  int *piVar10;
  undefined1 uVar11;
  int unaff_EBP;
  int *piVar12;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  if (*(int *)(unaff_EBP + 8) != 0) {
    if ((DAT_006e5104 & 1) == 0) {
      DAT_006e5104 = DAT_006e5104 | 1;
      DAT_006e50f8 = (int *)0x0;
      DAT_006e50fc = (int *)0x0;
      _DAT_006e5100 = 0;
      FUN_00635543(&LAB_0045bec0);
    }
    FUN_00448aa5(DAT_006e50f8,DAT_006e50fc);
    iVar6 = *(int *)(extraout_ECX + 0xdc);
    piVar9 = *(int **)(iVar6 + 0x84);
    iVar7 = extraout_ECX;
    if (piVar9 != *(int **)(iVar6 + 0x88)) {
      do {
        if (((*piVar9 != iVar7) && (cVar4 = FUN_00481947(*piVar9), cVar4 == '\0')) &&
           (*(short *)(iVar7 + 0x58c) == 0)) {
          for (piVar10 = *(int **)(iVar6 + 0x84); piVar10 != *(int **)(iVar6 + 0x88);
              piVar10 = piVar10 + 1) {
            iVar8 = *(int *)(*piVar10 + 0xaf0);
            iVar1 = *(int *)(*piVar10 + 0xaf4);
            if (iVar8 != iVar1) {
              do {
                if (*(int *)(iVar8 + 0x80) == *piVar9) break;
                iVar8 = iVar8 + 0x9c;
              } while (iVar8 != iVar1);
              iVar7 = *(int *)(unaff_EBP + -0x10);
              if (iVar8 != iVar1) {
                if (piVar10 != *(int **)(iVar6 + 0x88)) goto LAB_0045bc7b;
                break;
              }
            }
          }
          FUN_0042eadb(piVar9);
        }
LAB_0045bc7b:
        piVar9 = piVar9 + 1;
      } while (piVar9 != *(int **)(iVar6 + 0x88));
    }
    if (((int)DAT_006e50fc - (int)DAT_006e50f8 & 0xfffffffcU) != 0) {
      iVar6 = *(int *)(unaff_EBP + 8);
      uVar2 = *(undefined4 *)(iVar6 + 0x48);
      uVar5 = FUN_004818cc();
      FUN_00481798(iVar7,uVar2,uVar5);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0055e4e2(unaff_EBP + -0x21);
      piVar9 = DAT_006e50f8;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (piVar9 != DAT_006e50fc) {
        do {
          FUN_0042ede2(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
          *(int *)(unaff_EBP + -0x54) = *piVar9;
          FUN_004824b8();
          cVar4 = FUN_00482558(unaff_EBP + -0x1c);
          if ((cVar4 != '\0') && (cVar4 = FUN_0045c09a(iVar6,unaff_EBP + -0x1c), cVar4 != '\0'))
          goto LAB_0045bdcb;
          piVar9 = piVar9 + 1;
        } while (piVar9 != DAT_006e50fc);
      }
      FUN_0042ede2(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
      *(undefined4 *)(unaff_EBP + -0x54) = 0;
      *(undefined1 *)(unaff_EBP + -0x42) = 1;
      FUN_004824b8();
      cVar4 = FUN_00482558(unaff_EBP + -0x1c);
      if ((cVar4 == '\0') ||
         (piVar9 = *(int **)(unaff_EBP + -0x1c),
         (uint)(*(int *)(unaff_EBP + -0x18) - (int)piVar9 >> 3) < 2)) {
LAB_0045be90:
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_00542b02();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        uVar11 = 0;
      }
      else {
        piVar10 = piVar9 + 2;
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        piVar3 = DAT_006e50fc;
        if (piVar10 == *(int **)(unaff_EBP + -0x18)) goto LAB_0045be90;
        do {
          if (*(int *)(unaff_EBP + -0x10) != 0) goto LAB_0045be79;
          iVar6 = piVar10[1] - piVar9[1];
          *(int *)(unaff_EBP + -0x28) = piVar9[1];
          *(int *)(unaff_EBP + -0x30) = iVar6;
          if (iVar6 < 0) {
            iVar6 = -iVar6;
          }
          iVar7 = *piVar9;
          iVar8 = *piVar10;
          *(int *)(unaff_EBP + -0x2c) = iVar7;
          iVar8 = iVar8 - iVar7;
          *(int *)(unaff_EBP + -0x34) = iVar8;
          if (iVar8 < 0) {
            iVar8 = -iVar8;
          }
          if (iVar8 < iVar6) {
            *(int *)(unaff_EBP + -0x20) = iVar6 + 1;
          }
          else {
            *(int *)(unaff_EBP + -0x20) = iVar8 + 1;
          }
          do {
            if (*(int *)(unaff_EBP + -0x10) != 0) break;
            iVar6 = __ftol();
            iVar7 = __ftol();
            for (piVar9 = DAT_006e50f8; piVar9 != piVar3; piVar9 = piVar9 + 1) {
              iVar8 = *piVar9;
              if ((((iVar6 < *(int *)(iVar8 + 0x104)) && (*(int *)(iVar8 + 0x10c) <= iVar6)) &&
                  (iVar7 < *(int *)(iVar8 + 0x100))) && (*(int *)(iVar8 + 0x108) <= iVar7)) {
                *(int *)(unaff_EBP + -0x10) = *piVar9;
                break;
              }
            }
          } while (extraout_ST0 + extraout_ST1 < (float10)_DAT_00667280);
          piVar12 = piVar10 + 2;
          piVar9 = piVar10;
          piVar10 = piVar12;
        } while (piVar12 != *(int **)(unaff_EBP + -0x18));
        if (*(int *)(unaff_EBP + -0x10) == 0) goto LAB_0045be90;
LAB_0045be79:
        cVar4 = FUN_0045c09a(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x1c);
        if (cVar4 == '\0') goto LAB_0045be90;
LAB_0045bdcb:
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_00542b02();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        uVar11 = 1;
      }
      FUN_005db425();
      goto LAB_0045beaf;
    }
  }
  uVar11 = 0;
LAB_0045beaf:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar11;
}

