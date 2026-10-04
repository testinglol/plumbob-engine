
undefined4 FUN_00594a9b(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  cVar2 = FUN_005b90c2(unaff_EBP + -0x128,0x100);
  if (cVar2 != '\0') {
    FUN_005b870f(unaff_EBP + -0x128);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d499c(unaff_EBP + -0x1c);
    uVar3 = FUN_00598764(*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0xc) = uVar3;
    FUN_005b8770();
    cVar2 = FUN_005b90c2(unaff_EBP + -0x128,0x100);
    if (cVar2 != '\0') {
      FUN_005b870f(unaff_EBP + -0x128);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d499c(unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      cVar2 = FUN_005b9095(extraout_ECX + 0x20);
      if (cVar2 != '\0') {
        cVar2 = FUN_005b9095(unaff_EBP + -0x10);
        if (cVar2 != '\0') {
          if (*(int *)(extraout_ECX + 0x24) != 0) {
            FUN_005942ab();
          }
          iVar1 = *(int *)(unaff_EBP + -0x10);
          *(undefined4 *)(extraout_ECX + 0x24) = 0;
          if (iVar1 != 0) {
            piVar4 = operator_new(0x10);
            if (piVar4 == (int *)0x0) {
              piVar4 = (int *)0x0;
            }
            else {
              *piVar4 = 0;
              piVar4[1] = 0;
              piVar4[2] = 0;
              piVar4[3] = 0;
            }
            cVar2 = FUN_0059411c(*(undefined4 *)(unaff_EBP + 8));
            if (cVar2 == '\0') {
              if (piVar4 != (int *)0x0) {
                FUN_00594235();
                FUN_006321f0(piVar4);
              }
              goto LAB_00594bbb;
            }
            if (*(int *)(extraout_ECX + 0x24) != 0) {
              FUN_005942ab();
            }
            if (piVar4 != (int *)0x0) {
              *piVar4 = *piVar4 + 1;
            }
            *(int **)(extraout_ECX + 0x24) = piVar4;
          }
          uVar3 = 1;
          goto LAB_00594bd6;
        }
      }
    }
  }
LAB_00594bbb:
  uVar3 = 0;
LAB_00594bd6:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

