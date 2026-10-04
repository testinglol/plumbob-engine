
char FUN_005fe282(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = (**(code **)(iVar1 + 0x48))(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 0xc));
  if (cVar2 != '\0') {
    uVar3 = FUN_004096c2();
    FUN_005d49b7(uVar3);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return cVar2;
}

