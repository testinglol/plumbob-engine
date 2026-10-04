
undefined4 FUN_004f1abe(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0xf7) == '\0') {
LAB_004f1b61:
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
LAB_004f1b64:
    if ((*(char *)(unaff_EBP + -0xd) != '\0') && (DAT_006f2a04 == '\0')) {
      cVar1 = FUN_004f277c();
      if (cVar1 == '\0') goto LAB_004f1b7c;
      *(undefined1 *)(extraout_ECX + 0xf7) = 0;
    }
    uVar3 = 1;
  }
  else {
    iVar2 = FUN_00428886();
    if (iVar2 == 0) goto LAB_004f1b61;
    FUN_005b86bd(&DAT_006f2900);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005b86bd(&DAT_006f28f0);
    iVar2 = *(int *)(extraout_ECX + 0x48);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar2 = (**(code **)(iVar2 + 0x2c))(unaff_EBP + -0x1c,unaff_EBP + -0x28,3,0);
    if (iVar2 != 1) {
      *(bool *)(unaff_EBP + -0xd) = iVar2 == 4;
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      goto LAB_004f1b64;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
LAB_004f1b7c:
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

