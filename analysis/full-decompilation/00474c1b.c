
undefined * Catch_00474c1b(void)

{
  int *piVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  uVar2 = *(undefined4 *)(unaff_EBP + -0x18);
  *(short *)(piVar1 + 10) = (short)uVar2;
  (**(code **)(*piVar1 + 4))(uVar2);
  return &DAT_00474c31;
}

