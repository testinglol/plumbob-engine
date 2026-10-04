
void FUN_0057d230(void)

{
  char cVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  cVar1 = *(char *)(extraout_ECX + 0x60);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd8;
  if (cVar1 != '\0') {
    (**(code **)(*(int *)(extraout_ECX + 0x104) + 4))();
    *(int *)(extraout_ECX + 0x150) = *(int *)(extraout_ECX + 0x150) + 1;
    if (*(char *)(extraout_ECX + 0x54) != '\0') {
      *(int *)(extraout_ECX + 0x58) = *(int *)(extraout_ECX + 0x58) + 1;
    }
    (**(code **)(*(int *)(extraout_ECX + 0x128) + 4))();
    FUN_0057584f(extraout_ECX + 0x2c);
    iVar2 = *(int *)(extraout_ECX + 0x128);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    (**(code **)(iVar2 + 8))();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x24);
    while (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + -0x1c)) {
      if ((int *)**(int **)(unaff_EBP + -0x14) != (int *)0x0) {
        iVar2 = *(int *)**(int **)(unaff_EBP + -0x14);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        (**(code **)(iVar2 + 0x1c))();
        FUN_0057d2cc();
        return;
      }
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    }
    iVar2 = *(int *)(extraout_ECX + 0x104);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    (**(code **)(iVar2 + 8))();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0048c4c9();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

