
undefined4 FUN_0057c2f7(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = DAT_006f6a78;
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  (**(code **)(*(int *)(iVar2 + 0x128) + 4))();
  FUN_0057584f(DAT_006f6a78 + 0x2c);
  iVar2 = DAT_006f6a78;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(*(int *)(iVar2 + 0x128) + 8))();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x30);
  while( true ) {
    if (*(int *)(unaff_EBP + -0x14) == *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return 1;
    }
    piVar1 = (int *)**(int **)(unaff_EBP + -0x14);
    if (piVar1 != (int *)0x0) break;
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
  }
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

