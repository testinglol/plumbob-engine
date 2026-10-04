
undefined4 FUN_0057c3be(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  do {
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    if (*(int *)(unaff_EBP + -0x14) == *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return 1;
    }
    piVar1 = (int *)**(int **)(unaff_EBP + -0x14);
  } while (piVar1 == (int *)0x0);
  iVar2 = *piVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar3 = (**(code **)(iVar2 + 0x14))();
  *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
  iVar2 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0xc4);
  FUN_00601485(unaff_EBP + -0x24,unaff_EBP + -0x20);
  if (*(int *)(unaff_EBP + -0x24) != iVar2) {
    (**(code **)(*piVar1 + 0x84))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10));
  }
  *(undefined4 *)(unaff_EBP + -4) = 1;
  uVar3 = FUN_0057c3be();
  return uVar3;
}

