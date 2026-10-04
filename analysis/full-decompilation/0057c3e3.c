
undefined4 FUN_0057c3e3(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x20) = extraout_ECX;
  *(undefined4 *)(extraout_ECX + 0xc0) = *(undefined4 *)(unaff_EBP + 8);
  iVar1 = DAT_006f6a78;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  (**(code **)(*(int *)(iVar1 + 0x128) + 4))();
  FUN_0057584f(DAT_006f6a78 + 0x2c);
  iVar1 = DAT_006f6a78;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(*(int *)(iVar1 + 0x128) + 8))();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + -0x2c);
  do {
    if (*(int *)(unaff_EBP + 8) == *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return 1;
    }
    if ((int *)**(int **)(unaff_EBP + 8) != (int *)0x0) {
      iVar1 = *(int *)**(int **)(unaff_EBP + 8);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      uVar2 = (**(code **)(iVar1 + 0x14))();
      iVar1 = *(int *)(extraout_ECX + 0xc4);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
      FUN_00601485(unaff_EBP + -0x1c,unaff_EBP + -0x18);
      if (*(int *)(unaff_EBP + -0x1c) != iVar1) {
        FUN_0057fa52();
        uVar2 = FUN_0057c4a0();
        return uVar2;
      }
      *(undefined4 *)(unaff_EBP + -4) = 1;
    }
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
  } while( true );
}

