
undefined4 FUN_0040780c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar2 = (**(code **)(*piVar1 + 0x38))(0x44475250,*(undefined4 *)(unaff_EBP + 0xc),0);
  if (iVar2 == 0) {
    uVar3 = FUN_00401f6f();
  }
  else {
    (**(code **)(*piVar1 + 0x48))(iVar2,extraout_ECX + 0xc);
    uVar3 = FUN_00420096(iVar2);
    *(undefined4 *)(unaff_EBP + 8) = uVar3;
    uVar3 = FUN_00420048(iVar2);
    FUN_004644dc(uVar3,*(undefined4 *)(unaff_EBP + 8),0,0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004078d2(unaff_EBP + -0x34);
    FUN_00465a06(iVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046453f();
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

