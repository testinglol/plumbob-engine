
void FUN_004a6cc9(void)

{
  int *piVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d48d9();
  piVar1 = DAT_006fe8bc;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piVar1 = (int *)(**(code **)(*piVar1 + 4))();
  (**(code **)(*piVar1 + 0x80))(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 0xc),0,0,0);
  uVar2 = FUN_004096c2();
  FUN_005d49b7(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

