
undefined4 Catch_00474af7(void)

{
  int *piVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  piVar1 = *(int **)(unaff_EBP + -0x18);
  uVar2 = *(undefined4 *)(unaff_EBP + 0x10);
  (**(code **)(*piVar1 + 4))(uVar2);
  *(short *)(piVar1 + 10) = (short)uVar2;
  return 0x474b0f;
}

