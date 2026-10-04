
undefined1 FUN_0057fe8f(void)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  (**(code **)(*extraout_ECX + 8))();
  iVar2 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x14) = 2;
  iVar2 = (**(code **)(iVar2 + 0x88))(0x26);
  if (iVar2 != 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
  }
  iVar2 = (**(code **)(*extraout_ECX + 0x88))(0x1a);
  if (iVar2 == 0) {
    FUN_005d4c15(unaff_EBP + -0x24,4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d4d82();
    *(undefined1 *)(extraout_ECX + 0x37) = 0;
    iVar2 = (**(code **)(*(int *)*DAT_006f6a78 + 0x5c))
                      (extraout_ECX + 0x2f,*(undefined4 *)(unaff_EBP + -0x14));
    extraout_ECX[0x39] = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x38] = iVar2;
    FUN_005b8770();
  }
  else {
    iVar2 = (**(code **)(*extraout_ECX + 0x88))(0x1b);
    *(bool *)(unaff_EBP + -0x18) = iVar2 != 0;
    piVar3 = (int *)(**(code **)(*(int *)*DAT_006f6a78 + 0x70))
                              (extraout_ECX + 0x2f,*(undefined4 *)(unaff_EBP + -0x14),
                               *(undefined4 *)(unaff_EBP + -0x18));
    extraout_ECX[0x39] = (int)piVar3;
    iVar2 = *piVar3;
    uVar4 = (**(code **)(*extraout_ECX + 0x88))(0x1c);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
    (**(code **)(iVar2 + 0xec))((float)*(int *)(unaff_EBP + -0x18));
    iVar2 = *(int *)extraout_ECX[0x39];
    uVar4 = (**(code **)(*extraout_ECX + 0x88))(0x1d);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
    (**(code **)(iVar2 + 0xf4))((float)*(int *)(unaff_EBP + -0x18));
    extraout_ECX[0x38] = extraout_ECX[0x39];
  }
  iVar2 = (**(code **)(*extraout_ECX + 0x88))(0x2b);
  if (iVar2 != 0) {
    uVar1 = (**(code **)(*extraout_ECX + 0x60))();
    *(undefined1 *)(unaff_EBP + -0xd) = uVar1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0xd);
}

