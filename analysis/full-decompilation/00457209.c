
void FUN_00457209(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int *piVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x1c) = extraout_ECX;
  uVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = FUN_006359f2(uVar1,0,&iResFile::RTTI_Type_Descriptor,&ObjResFile::RTTI_Type_Descriptor,0);
  *(int *)(unaff_EBP + -0x18) = iVar3;
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 6;
    *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX + 0x1a;
    do {
      if (**(int **)(unaff_EBP + -0x10) != 0) {
        FUN_00456c3e(**(int **)(unaff_EBP + -0x10));
        **(undefined4 **)(unaff_EBP + -0x10) = 0;
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
      piVar4 = (int *)(unaff_EBP + -0x14);
      *piVar4 = *piVar4 + -1;
    } while (*piVar4 != 0);
  }
  if (extraout_ECX[0x19] != 0) {
    iVar3 = FUN_006359f2(*(undefined4 *)(extraout_ECX[0x19] + 0x14),0,
                         &iResFile::RTTI_Type_Descriptor,&ObjResFile::RTTI_Type_Descriptor,0);
    if (iVar3 != 0) {
      FUN_00456c3e(extraout_ECX[0x19]);
    }
    extraout_ECX[0x19] = 0;
  }
  iVar3 = extraout_ECX[3];
  if (iVar3 != 0) {
    FUN_00401f68();
    FUN_006321f0(iVar3);
    extraout_ECX[3] = 0;
  }
  if ((undefined4 *)extraout_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[4])(1);
    extraout_ECX[4] = 0;
  }
  if ((undefined4 *)extraout_ECX[0x22] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0x22])(1);
    extraout_ECX[0x22] = 0;
  }
  iVar3 = extraout_ECX[0x2e];
  if (iVar3 != 0) {
    *(int *)(unaff_EBP + -0x18) = iVar3;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    FUN_006321f0(iVar3);
    extraout_ECX[0x2e] = 0;
  }
  if (extraout_ECX[0x24] != 0) {
    FUN_004573ba(1);
    extraout_ECX[0x24] = 0;
  }
  piVar4 = (int *)extraout_ECX[0x25];
  if (piVar4 != (int *)extraout_ECX[0x26]) {
    piVar2 = (int *)extraout_ECX[0x26];
    *(int **)(unaff_EBP + -0x14) = piVar2;
    if (piVar4 != piVar2) {
      do {
        iVar3 = *piVar4;
        *(int *)(unaff_EBP + -0x18) = iVar3;
        if (iVar3 != 0) {
          FUN_0043e4e8();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x18));
        }
        piVar4 = piVar4 + 1;
      } while (piVar4 != *(int **)(unaff_EBP + -0x14));
    }
    FUN_0052ea87(extraout_ECX[0x25],extraout_ECX[0x26]);
  }
  if (extraout_ECX[0x18] != 0) {
    FUN_006321f0(extraout_ECX[0x18]);
    extraout_ECX[0x18] = 0;
  }
  uVar1 = extraout_ECX[0x25];
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar1;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

