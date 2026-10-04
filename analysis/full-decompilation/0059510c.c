
undefined1 FUN_0059510c(void)

{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  int extraout_ECX;
  undefined1 uVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  cVar2 = FUN_005b90c2(unaff_EBP + -300,0x100);
  uVar5 = 0;
  if (cVar2 == '\0') {
    uVar5 = 0;
    goto LAB_00595279;
  }
  FUN_005b870f(unaff_EBP + -300);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b88c2();
  FUN_005d499c(unaff_EBP + -0x28);
  FUN_005b88c2();
  cVar2 = FUN_005b9095(unaff_EBP + -0x10);
  if (cVar2 != '\0') {
    *(undefined4 *)(extraout_ECX + 0x14) = *(undefined4 *)(unaff_EBP + -0x10);
    cVar2 = FUN_005b9095(unaff_EBP + -0x1c);
    if (cVar2 != '\0') {
      if (*(int *)(unaff_EBP + -0x1c) != 0) {
        piVar3 = operator_new(0x10);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          *piVar3 = 0;
          piVar3[1] = 0;
          piVar3[2] = 0;
          piVar3[3] = 0;
        }
        cVar2 = FUN_0059411c(*(undefined4 *)(unaff_EBP + 8));
        if (cVar2 == '\0') {
          if (piVar3 != (int *)0x0) {
            FUN_00594235();
LAB_005951de:
            FUN_006321f0(piVar3);
          }
          goto LAB_0059526a;
        }
        if (*(int *)(extraout_ECX + 0x18) != 0) {
          FUN_005942ab();
        }
        if (piVar3 != (int *)0x0) {
          *piVar3 = *piVar3 + 1;
        }
        *(int **)(extraout_ECX + 0x18) = piVar3;
      }
      cVar2 = FUN_005b9095(unaff_EBP + -0x10);
      if (cVar2 != '\0') {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        if (0 < *(int *)(unaff_EBP + -0x10)) {
          do {
            pvVar4 = operator_new(0x2c);
            *(void **)(unaff_EBP + -0x2c) = pvVar4;
            *(undefined1 *)(unaff_EBP + -4) = 1;
            if (pvVar4 == (void *)0x0) {
              piVar3 = (int *)0x0;
            }
            else {
              piVar3 = (int *)FUN_00594f5f();
            }
            uVar1 = *(undefined4 *)(unaff_EBP + 8);
            *(undefined1 *)(unaff_EBP + -4) = 0;
            piVar3[10] = extraout_ECX;
            cVar2 = FUN_00594a9b(uVar1);
            if (cVar2 == '\0') {
              if (piVar3 == (int *)0x0) goto LAB_0059526a;
              FUN_00594d07();
              goto LAB_005951de;
            }
            *(int **)(unaff_EBP + -0x18) = piVar3;
            piVar3[10] = extraout_ECX;
            FUN_0059b07c(unaff_EBP + -0x18);
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x10));
        }
        uVar5 = 1;
      }
    }
  }
LAB_0059526a:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_00595279:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}

