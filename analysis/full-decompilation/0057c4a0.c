
undefined4 FUN_0057c4a0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int unaff_ESI;
  
  do {
    *(undefined4 *)(unaff_EBP + -4) = 1;
    do {
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
      if (*(int *)(unaff_EBP + 8) == *(int *)(unaff_EBP + -0x14)) {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0048c4c9();
        ExceptionList = *(void **)(unaff_EBP + -0xc);
        return 1;
      }
    } while ((int *)**(int **)(unaff_EBP + 8) == (int *)0x0);
    iVar1 = *(int *)**(int **)(unaff_EBP + 8);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar2 = (**(code **)(iVar1 + 0x14))();
    iVar1 = *(int *)(unaff_ESI + 0xc4);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    FUN_00601485(unaff_EBP + -0x1c,unaff_EBP + -0x18);
  } while (*(int *)(unaff_EBP + -0x1c) == iVar1);
  FUN_0057fa52();
  uVar2 = FUN_0057c4a0();
  return uVar2;
}

