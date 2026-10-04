
void FUN_0060119b(void)

{
  undefined4 uVar1;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  int iVar3;
  
  FUN_00634c24();
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  iVar3 = 0;
  iVar2 = *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (0 < iVar2) {
    do {
      (**(code **)(*extraout_ECX + 0x44))(*(int *)(unaff_EBP + -0x18) + iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  uVar1 = FUN_004096c2();
  FUN_005d49b7(uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

