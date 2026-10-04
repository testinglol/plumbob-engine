
void FUN_004ab376(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int extraout_ECX;
  int iVar7;
  int *piVar8;
  int unaff_EBP;
  int iVar9;
  int iVar10;
  
  FUN_00634c24();
  if ((*(int *)(extraout_ECX + 0x170) != 0) || (*(int *)(extraout_ECX + 0x174) != 0)) {
    FUN_004aad1d(unaff_EBP + -0x1c,unaff_EBP + -0x70);
    *(undefined4 *)(unaff_EBP + -0x30) = DAT_006fe838;
    DAT_006fe838 = DAT_006d6180;
    FUN_005cddcf(unaff_EBP + -0x1c);
    DAT_006fe838 = DAT_006d6180;
    FUN_005cddcf(unaff_EBP + -0x70);
    DAT_006fe838 = *(undefined4 *)(unaff_EBP + -0x30);
  }
  if (DAT_006e4870 == '\0') {
    FUN_005caf36();
    FUN_005cce97();
    uVar3 = FUN_005caf2f();
    FUN_005cf10c(uVar3);
    FUN_005cdecb(uVar3);
    uVar3 = FUN_005caf36();
    FUN_005cf113(uVar3);
    FUN_005cdecb(uVar3);
  }
  else {
    cVar2 = FUN_005cad68();
    if (cVar2 != '\0') {
      uVar3 = FUN_005cad61();
      FUN_005de822(uVar3);
      iVar9 = unaff_EBP + -0x1c;
      FUN_005caf36(iVar9);
      FUN_005cddcf(iVar9);
      iVar9 = *(int *)(extraout_ECX + 0x174);
      iVar7 = *(int *)(extraout_ECX + 0x170);
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar9;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar9;
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + iVar7;
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + iVar7;
      iVar9 = unaff_EBP + -0x1c;
      FUN_005caf36(iVar9);
      FUN_005cddcf(iVar9);
    }
    if (((*(char *)(extraout_ECX + 0x4c0) != '\0') &&
        (FUN_004b16b0(unaff_EBP + -0x1c), *(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x14))
        ) && (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x10))) {
      iVar9 = unaff_EBP + -0x1c;
      FUN_005caf36(iVar9);
      FUN_005cddcf(iVar9);
    }
    *(undefined4 *)(unaff_EBP + -0x4c) = DAT_006fe838;
    DAT_006fe838 = DAT_006d6180;
    FUN_005caf36();
    FUN_005cce97();
    *(int *)(unaff_EBP + -0x34) = extraout_ECX + 0x88;
    uVar3 = FUN_005caf2f();
    FUN_005cdecb(uVar3);
    uVar3 = FUN_005caf36();
    FUN_005cdecb(uVar3);
    iVar9 = *(int *)(extraout_ECX + 0x1c8);
    if (iVar9 != *(int *)(extraout_ECX + 0x1cc)) {
      do {
        FUN_00438fc0(unaff_EBP + -0x1c,1);
        iVar10 = DAT_006f0084;
        iVar7 = DAT_006f0080;
        if ((*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x14)) &&
           (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x10))) {
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + DAT_006f0080;
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar10;
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar10;
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + iVar7;
          if ((*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x14)) &&
             (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x10))) {
            FUN_005cddcf(unaff_EBP + -0x1c);
          }
        }
        iVar9 = iVar9 + 4;
      } while (iVar9 != *(int *)(extraout_ECX + 0x1cc));
    }
    iVar9 = FUN_00415707();
    FUN_005c3650(iVar9 + 0xec);
    piVar5 = DAT_006e486c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar9 = *(int *)(*piVar5 + 0x14);
    *(int *)(unaff_EBP + -0x50) = iVar9;
    piVar8 = *(int **)(iVar9 + 0x18);
    piVar5 = *(int **)(iVar9 + 0x1c);
    *(int **)(unaff_EBP + -0x30) = piVar8;
    if (piVar8 != piVar5) {
      do {
        iVar9 = *piVar8;
        *(int *)(unaff_EBP + -0x48) = iVar9;
        if ((iVar9 != 0) && (*(int *)(iVar9 + 0x15c) != 0)) {
          FUN_00438fc0(unaff_EBP + -0x44,1);
          iVar9 = *(int *)(unaff_EBP + -0x44);
          iVar7 = *(int *)(unaff_EBP + -0x3c);
          iVar10 = *(int *)(unaff_EBP + -0x40);
          iVar4 = *(int *)(unaff_EBP + -0x38);
          *(int *)(unaff_EBP + -0x2c) = iVar9;
          *(int *)(unaff_EBP + -0x28) = iVar10;
          *(int *)(unaff_EBP + -0x24) = iVar7;
          *(int *)(unaff_EBP + -0x20) = iVar4;
          if ((iVar9 < iVar7) && (((iVar10 < iVar4 && (iVar9 < iVar7)) && (iVar10 < iVar4)))) {
            iVar9 = iVar9 + DAT_006f0080;
            iVar10 = iVar10 + DAT_006f0084;
            iVar7 = DAT_006f0080 + iVar7;
            iVar4 = DAT_006f0084 + iVar4;
            *(int *)(unaff_EBP + -0x2c) = iVar9;
            *(int *)(unaff_EBP + -0x28) = iVar10;
            *(int *)(unaff_EBP + -0x24) = iVar7;
            *(int *)(unaff_EBP + -0x20) = iVar4;
            if ((iVar9 < iVar7) && (iVar10 < iVar4)) {
              uVar3 = FUN_004b469d();
              FUN_005cddcf(uVar3);
            }
          }
          piVar5 = *(int **)(unaff_EBP + -0x48);
          cVar2 = (**(code **)(*piVar5 + 0x28))();
          if ((cVar2 != '\0') &&
             (piVar5 = (int *)(**(code **)(*piVar5 + 0x2c))(), piVar5 != (int *)0x0)) {
            (**(code **)(*piVar5 + 0xac))();
            iVar9 = (**(code **)(*piVar5 + 0xb0))();
            *(undefined4 *)(iVar9 + 0x40) = 0;
            iVar7 = FUN_00415707();
            FUN_005a0af0(unaff_EBP + -0x60,iVar9,iVar7 + 0xec);
            puVar6 = (undefined4 *)FUN_00438fc0(unaff_EBP + -0x80,2);
            *(undefined4 *)(unaff_EBP + -0x44) = *puVar6;
            *(undefined4 *)(unaff_EBP + -0x40) = puVar6[1];
            *(undefined4 *)(unaff_EBP + -0x3c) = puVar6[2];
            *(undefined4 *)(unaff_EBP + -0x38) = puVar6[3];
            iVar9 = *(int *)(unaff_EBP + -0x44);
            iVar7 = *(int *)(unaff_EBP + -0x3c);
            iVar10 = *(int *)(unaff_EBP + -0x40);
            iVar4 = *(int *)(unaff_EBP + -0x38);
            *(int *)(unaff_EBP + -0x2c) = iVar9;
            *(int *)(unaff_EBP + -0x28) = iVar10;
            *(int *)(unaff_EBP + -0x24) = iVar7;
            *(int *)(unaff_EBP + -0x20) = iVar4;
            iVar1 = DAT_006f0084;
            if ((iVar9 < iVar7) && (((iVar10 < iVar4 && (iVar9 < iVar7)) && (iVar10 < iVar4)))) {
              iVar7 = DAT_006f0080 + iVar7;
              *(int *)(unaff_EBP + -0x2c) = iVar9 + DAT_006f0080;
              *(int *)(unaff_EBP + -0x28) = iVar1 + iVar10;
              *(int *)(unaff_EBP + -0x20) = iVar1 + iVar4;
              *(int *)(unaff_EBP + -0x24) = iVar7;
              if ((*(int *)(unaff_EBP + -0x60) < *(int *)(unaff_EBP + -0x58)) &&
                 (*(int *)(unaff_EBP + -0x5c) < *(int *)(unaff_EBP + -0x54))) {
                FUN_004b469d();
                FUN_00422698();
              }
              if ((*(int *)(unaff_EBP + -0x2c) < *(int *)(unaff_EBP + -0x24)) &&
                 (*(int *)(unaff_EBP + -0x28) < *(int *)(unaff_EBP + -0x20))) {
                uVar3 = FUN_004b469d();
                FUN_005cddcf(uVar3);
              }
            }
          }
        }
        piVar8 = (int *)(*(int *)(unaff_EBP + -0x30) + 4);
        piVar5 = *(int **)(*(int *)(unaff_EBP + -0x50) + 0x1c);
        *(int **)(unaff_EBP + -0x30) = piVar8;
      } while (piVar8 != piVar5);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005c4890();
    FUN_005cce97();
    DAT_006fe838 = *(undefined4 *)(unaff_EBP + -0x4c);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

