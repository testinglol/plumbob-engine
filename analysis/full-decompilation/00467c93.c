
void FUN_00467c93(void)

{
  int *piVar1;
  ushort uVar2;
  short sVar3;
  char *pcVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int extraout_ECX;
  int *piVar10;
  int unaff_EBP;
  int *piVar11;
  int iVar12;
  
  FUN_00634c24();
  iVar7 = FUN_004790b4();
  pcVar4 = *(char **)(unaff_EBP + 8);
  if (*(byte *)(*(int *)(*(int *)(iVar7 + 0x10) + *pcVar4 * 4) + (int)pcVar4[1]) < 0x10) {
    *(int *)(extraout_ECX + 0x54) = *(int *)(extraout_ECX + 0x54) + 1;
  }
  cVar6 = FUN_00468851();
  if (cVar6 == '\0') {
    FUN_00479737(unaff_EBP + -0x44,pcVar4);
    uVar5 = *(uint *)(unaff_EBP + -0x44);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (uVar5 == 0) {
      *(int *)(extraout_ECX + 0x38) = *(int *)(extraout_ECX + 0x38) + 2;
      if (*(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x20 + pcVar4[2] * 4) + 0xc) +
                             *pcVar4 * 4) + pcVar4[1] * 2) != 0) {
        *(int *)(extraout_ECX + 0x3c) = *(int *)(extraout_ECX + 0x3c) + 2;
      }
    }
    else if ((uVar5 & 0x30) == 0) {
      *(int *)(extraout_ECX + 0x38) = *(int *)(extraout_ECX + 0x38) + 2;
      if (*(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x20 + pcVar4[2] * 4) + 0xc) +
                             *pcVar4 * 4) + pcVar4[1] * 2) != 0) {
        *(int *)(extraout_ECX + 0x3c) = *(int *)(extraout_ECX + 0x3c) + 2;
      }
      uVar8 = 1;
      if (((byte)uVar5 & 1) != 1) {
        do {
          uVar8 = uVar8 * 2;
        } while ((uVar8 & uVar5) != uVar8);
      }
      do {
        if (uVar8 == 0) break;
        uVar9 = FUN_00467ece(uVar8);
        cVar6 = FUN_00467c56(uVar9);
        if (cVar6 != '\0') {
          *(int *)(extraout_ECX + 0x60) = *(int *)(extraout_ECX + 0x60) + 1;
          iVar7 = FUN_00467e89(uVar8,0);
          if (iVar7 != 0) {
            *(int *)(extraout_ECX + 100) = *(int *)(extraout_ECX + 100) + 1;
          }
        }
        do {
          uVar8 = uVar8 * 2;
          if ((uVar8 & *(uint *)(unaff_EBP + -0x44)) == uVar8) break;
        } while ((int)uVar8 < 0x20);
      } while ((int)uVar8 < 0x20);
    }
    else {
      *(int *)(extraout_ECX + 0x38) = *(int *)(extraout_ECX + 0x38) + 1;
      piVar11 = (int *)&DAT_006c4760;
      if ((DAT_006c4760 & uVar5) != DAT_006c4760) {
        piVar11 = &DAT_006c4774;
      }
      iVar7 = FUN_00435221(*piVar11,0);
      uVar2 = *(ushort *)(unaff_EBP + -0x3c + iVar7 * 2);
      *(undefined1 *)(unaff_EBP + 0xb) = 0;
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      *(uint *)(unaff_EBP + -0x18) = (uint)uVar2;
      *(undefined4 *)(unaff_EBP + -0x14) = 2;
      piVar10 = piVar11;
      do {
        piVar10 = piVar10 + 1;
        iVar7 = *piVar11;
        iVar12 = *piVar10;
        if (iVar7 == 0x10) {
          if (iVar12 == 0) {
            iVar12 = 4;
          }
        }
        else if ((iVar7 == 0x20) && (iVar12 == 0)) {
          iVar12 = 1;
        }
        iVar7 = FUN_00435221(iVar7,iVar12);
        if (*(short *)(unaff_EBP + -0x30 + iVar7 * 2) != 0) {
          *(undefined1 *)(unaff_EBP + 0xb) = 1;
        }
        if ((*piVar10 == 2) || (sVar3 = *(short *)(unaff_EBP + -0x30), *piVar10 == 1)) {
          sVar3 = *(short *)(unaff_EBP + -0x3c);
        }
        if (sVar3 != 0) {
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
        }
        piVar1 = (int *)(unaff_EBP + -0x14);
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      cVar6 = FUN_00467c56(*(undefined4 *)(unaff_EBP + -0x18));
      if ((cVar6 != '\0') &&
         (*(int *)(extraout_ECX + 0x60) = *(int *)(extraout_ECX + 0x60) + 1,
         *(char *)(unaff_EBP + 0xb) != '\0')) {
        *(int *)(extraout_ECX + 100) = *(int *)(extraout_ECX + 100) + 1;
      }
      if (*(char *)(unaff_EBP + -0xd) != '\0') {
        *(int *)(extraout_ECX + 0x3c) = *(int *)(extraout_ECX + 0x3c) + 1;
      }
    }
  }
  else {
    *(int *)(extraout_ECX + 0x38) = *(int *)(extraout_ECX + 0x38) + 2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

