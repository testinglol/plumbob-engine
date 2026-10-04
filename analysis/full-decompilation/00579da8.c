
uint FUN_00579da8(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  uVar3 = FUN_00634c24();
  if ((*(char *)((int)extraout_ECX + 0x16) == '\0') && (extraout_ECX[2] == 0)) {
    iVar1 = *(int *)(unaff_EBP + 8);
    *(undefined1 *)((int)extraout_ECX + 0x15) = 0;
    extraout_ECX[3] = iVar1;
    if (*(char *)(iVar1 + 0x3c) != '\0') {
      extraout_ECX[4] = *(int *)(iVar1 + 0x34);
    }
    piVar2 = *(int **)(*extraout_ECX + 0x38);
    if (piVar2 != (int *)0x0) {
      uVar4 = FUN_00412ab1(unaff_EBP + -0x24,*extraout_ECX + 0x4094,iVar1);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005b86bd(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00401729();
      (**(code **)(*piVar2 + 0x1c))(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    uVar3 = 1;
    extraout_ECX[2] = 1;
  }
  else {
    uVar3 = uVar3 & 0xffffff00;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

