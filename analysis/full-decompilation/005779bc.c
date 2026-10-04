
undefined4 FUN_005779bc(void)

{
  int *piVar1;
  int *extraout_ECX;
  int iVar2;
  int iVar3;
  int unaff_EBP;
  int *piVar4;
  
  FUN_00634c24();
  (**(code **)(*extraout_ECX + 0x6c))();
  iVar3 = DAT_006f63e8;
  *(int **)(unaff_EBP + -0x18) = &DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  (**(code **)(iVar3 + 4))();
  iVar3 = extraout_ECX[0xd];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if (0 < *(int *)(iVar3 + 0x24)) {
    *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0x25;
    do {
      iVar2 = 0;
      if (0 < *(int *)(iVar3 + 0x28)) {
        piVar4 = *(int **)(unaff_EBP + -0x10);
        do {
          if (*piVar4 != 0) {
            FUN_00579ea3();
          }
          iVar2 = iVar2 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar2 < *(int *)(extraout_ECX[0xd] + 0x28));
      }
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      iVar3 = extraout_ECX[0xd];
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x100;
    } while (*(int *)(unaff_EBP + -0x14) < *(int *)(iVar3 + 0x24));
  }
  if ((char)extraout_ECX[1] != '\0') {
    (**(code **)(*extraout_ECX + 0x20))();
    if ((undefined4 *)extraout_ECX[0xd] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[0xd])(1);
      extraout_ECX[0xd] = 0;
    }
    piVar4 = extraout_ECX + 0x25;
    *(undefined4 *)(unaff_EBP + -0x14) = 0x40;
    do {
      iVar3 = 0x40;
      do {
        if (*piVar4 != 0) {
          FUN_006321f0(*piVar4);
          *piVar4 = 0;
        }
        piVar4 = piVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      piVar1 = (int *)(unaff_EBP + -0x14);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  *(undefined1 *)(extraout_ECX + 0xf) = 0;
  *(undefined1 *)(extraout_ECX + 1) = 0;
  extraout_ECX[0xe] = 0;
  iVar3 = DAT_006f63e8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar3 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

