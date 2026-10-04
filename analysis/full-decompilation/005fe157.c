
undefined1 FUN_005fe157(void)

{
  char cVar1;
  int iVar2;
  int *extraout_ECX;
  undefined1 uVar3;
  uint uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  iVar2 = extraout_ECX[5];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  (**(code **)(iVar2 + 0x48))(unaff_EBP + -0x18);
  uVar4 = 1;
  do {
    cVar1 = (**(code **)(*extraout_ECX + 0x3c))(unaff_EBP + -0x24,uVar4);
    if (cVar1 != '\0') {
      (**(code **)(extraout_ECX[5] + 0x48))(unaff_EBP + -0x18);
      iVar2 = FUN_0043017f(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14),
                           *(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
      if (iVar2 == 0) {
        **(uint **)(unaff_EBP + 0xc) = uVar4;
        uVar3 = 1;
        goto LAB_005fe1da;
      }
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x16);
  uVar3 = 0;
  **(undefined4 **)(unaff_EBP + 0xc) = 1;
LAB_005fe1da:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

