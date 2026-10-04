
undefined1 FUN_005776a9(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005728f7(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(*(int *)(unaff_EBP + -0x84) + 0x40))();
  uVar2 = FUN_005729b6();
  uVar2 = FUN_0057298c(uVar2);
  uVar2 = FUN_00412ab1(unaff_EBP + -0x30,uVar2);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b86bd(uVar2);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401729();
  uVar2 = FUN_00572a0a();
  uVar2 = FUN_005729e0(uVar2);
  uVar2 = FUN_00412ab1(unaff_EBP + -0x3c,uVar2);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b86bd(uVar2);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_00401729();
  uVar1 = (**(code **)(*extraout_ECX + 100))
                    (unaff_EBP + -0x24,unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 0xc),
                     *(undefined4 *)(unaff_EBP + 0x10));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00572aec();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

