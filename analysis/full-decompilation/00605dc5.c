
uint FUN_00605dc5(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + 8);
  piVar1 = *(int **)(extraout_ECX + 8);
  if (piVar1 == (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(extraout_ECX + 4) + 0x74))
                      (*(int **)(extraout_ECX + 4),8,unaff_EBP + -0x14);
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x74))(piVar1,8,unaff_EBP + -0x14);
  }
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar3 = (**(code **)(*(int *)(unaff_EBP + -0x20) + 0x10))();
    uVar3 = uVar3 & 0xffffff00;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

