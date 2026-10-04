
void FUN_0057c05d(void)

{
  int *piVar1;
  int unaff_EBP;
  undefined *puVar2;
  
  FUN_00634c24();
  FUN_005d48d9();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(*piVar1 + 0x8c))(unaff_EBP + -0x1c,unaff_EBP + -0x10);
  puVar2 = &DAT_006c08dc;
  FUN_005bc69b(*(undefined4 *)(unaff_EBP + 0xc));
  FUN_005bc69b(puVar2);
  (**(code **)(*piVar1 + 0x38))();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

