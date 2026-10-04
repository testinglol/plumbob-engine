
undefined4 FUN_004a1356(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int iVar5;
  int iVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00636080();
  iVar6 = *(int *)(*(int *)(unaff_EBP + 0xc) + 0x10);
  _memset((void *)(unaff_EBP + -0x1015c),0,0xffff);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  do {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    if (0 < iVar6) {
      do {
        iVar5 = 0;
        do {
          *(char *)(unaff_EBP + -0x14) = (char)iVar5;
          *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0x10);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          iVar2 = FUN_00433166(unaff_EBP + -0x14);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          iVar5 = iVar5 + 1;
          *(undefined1 *)(unaff_EBP + -0x1015c + iVar2) = 1;
        } while (iVar5 < iVar6);
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
      } while (*(int *)(unaff_EBP + -0x1c) < iVar6);
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 3);
  piVar1 = extraout_ECX + 6;
  FUN_004a17d3(extraout_ECX[6],extraout_ECX[7]);
  iVar6 = 0x1e;
  *(undefined4 *)(unaff_EBP + 0xc) = 0x1e;
  do {
    if (iVar6 == 0xff) {
      iVar6 = 0x100;
      *(undefined4 *)(unaff_EBP + 0xc) = 0x100;
    }
    if (*(char *)(unaff_EBP + -0x1015c + iVar6) != '\0') {
      *(int *)(unaff_EBP + -0x10) = iVar6;
      FUN_00601485(unaff_EBP + -0x14,unaff_EBP + -0x10);
      iVar5 = *(int *)(unaff_EBP + -0x14);
      if (iVar5 != *extraout_ECX) {
        iVar6 = **(int **)(iVar5 + 0x14);
        for (piVar3 = (int *)*piVar1; piVar3 != (int *)extraout_ECX[7]; piVar3 = piVar3 + 0x47) {
          if (*piVar3 == iVar6) {
            if (piVar3 != (int *)extraout_ECX[7]) goto LAB_004a1483;
            break;
          }
        }
        uVar4 = FUN_004a1e80(iVar6,extraout_ECX[9] + iVar6 * 8);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        FUN_004a16d8(uVar4);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_004a216a();
        iVar5 = *(int *)(unaff_EBP + -0x14);
LAB_004a1483:
        iVar6 = *(int *)(unaff_EBP + 0xc);
        uVar4 = *(undefined4 *)(*(int *)(iVar5 + 0x14) + 0x2c);
        *(short *)(unaff_EBP + -0x1e) = (short)*(undefined4 *)(*(int *)(iVar5 + 0x14) + 4);
        *(short *)(unaff_EBP + -0x20) = (short)iVar6;
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
        FUN_004a177b(unaff_EBP + -0x20);
      }
    }
    iVar6 = iVar6 + 1;
    *(int *)(unaff_EBP + 0xc) = iVar6;
    if (0xfffe < iVar6) {
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      FUN_004a1fe2(unaff_EBP + -0x38,piVar1);
      *(int *)(unaff_EBP + -0x18) = unaff_EBP + -0x38;
      *(undefined4 *)(unaff_EBP + -0x14) = 0x464c526d;
      FUN_004a2893(unaff_EBP + -0x18,0x464c526d);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_00464eab(unaff_EBP + -0x2c,0,*(undefined4 *)(unaff_EBP + 8),0);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00465055();
      *(int **)(unaff_EBP + -0x40) = piVar1;
      *(undefined4 *)(unaff_EBP + -0x3c) = 0x464c526d;
      *(int *)(unaff_EBP + -0x28) = unaff_EBP + -0x40;
      *(undefined4 *)(unaff_EBP + -0x24) = 0x464c526d;
      *(undefined ***)(unaff_EBP + -0x2c) = &PTR_FUN_006686a8;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      uVar4 = FUN_00464eab(unaff_EBP + -0x2c,0,*(undefined4 *)(unaff_EBP + 8),1);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00465055();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004a1740();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar4;
    }
  } while( true );
}

