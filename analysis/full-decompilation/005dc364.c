
undefined1 FUN_005dc364(void)

{
  int *piVar1;
  undefined1 uVar2;
  int *piVar3;
  int extraout_ECX;
  int unaff_EBP;
  int *local_1c;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  if (piVar1 != (int *)0x0) {
    if (*(char *)(extraout_ECX + 0x3c) == '\0') {
      *(undefined1 *)(extraout_ECX + 0x3c) = 1;
    }
    for (local_1c = (int *)**(int **)(extraout_ECX + 0x38);
        local_1c != *(int **)(extraout_ECX + 0x38); local_1c = (int *)*local_1c) {
      if ((int *)local_1c[2] == piVar1) {
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(int ***)(unaff_EBP + 8) = &local_1c;
        FUN_00580b0a(unaff_EBP + 8);
        local_1c = (int *)0x5dc3c9;
        piVar3 = (int *)FUN_00492d2c();
        if (piVar3 == piVar1) {
          local_1c = piVar1;
          FUN_005d9912();
        }
        local_1c = (int *)0x5dc3e4;
        piVar3 = (int *)FUN_005d0a09();
        if (piVar3 == piVar1) {
          FUN_005d9884();
        }
        local_1c = (int *)0x0;
        (**(code **)(*piVar1 + 0x1c))();
        *(undefined1 *)(unaff_EBP + -0x11) = 1;
        uVar2 = FUN_005dc416();
        return uVar2;
      }
    }
    *(undefined1 *)(extraout_ECX + 0x3c) = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0x11);
}

