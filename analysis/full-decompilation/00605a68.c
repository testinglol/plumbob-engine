
uint FUN_00605a68(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(extraout_ECX + 8);
  if (piVar1 == (int *)0x0) {
    piVar1 = *(int **)(extraout_ECX + 4);
  }
  iVar2 = (**(code **)(*piVar1 + 0x7c))(piVar1,0);
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar3 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
    uVar3 = uVar3 & 0xffffff00;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

