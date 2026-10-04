
int FUN_005d2d3b(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  (**(code **)(*piVar1 + 4))(0);
  uVar2 = FUN_005cafd7();
  FUN_005d30b8(uVar2);
  iVar3 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + -0x10) != 0) {
    iVar3 = unaff_EBP + -0x14;
  }
  iVar4 = FUN_005c98eb(*(undefined4 *)(unaff_EBP + 8),iVar3,piVar1);
  iVar3 = 0;
  if (iVar4 != 0) {
    iVar3 = iVar4;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d30d8();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}

