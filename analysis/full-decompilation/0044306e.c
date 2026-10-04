
int FUN_0044306e(void)

{
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  uint uVar1;
  undefined2 extraout_var_02;
  int iVar2;
  undefined2 uVar3;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -100) = extraout_ECX;
  *(int *)(unaff_EBP + -0x68) = (int)*(short *)(unaff_EBP + 8);
  if (*(int *)(unaff_EBP + -0x68) == 0x85) {
    FUN_004434d9();
    uVar3 = extraout_var_01;
  }
  else if (*(int *)(unaff_EBP + -0x68) == 0xf2) {
    *(undefined4 *)(unaff_EBP + -0x48) = 0;
    if (0 < *(int *)(unaff_EBP + 0xc)) {
      *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -100) + 0x18;
      *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x54) + 4);
      *(undefined4 *)(unaff_EBP + -0x50) = **(undefined4 **)(unaff_EBP + -0x54);
      if (*(uint *)(unaff_EBP + 0xc) <
          (*(int *)(unaff_EBP + -0x4c) - *(int *)(unaff_EBP + -0x50) >> 2) + 1U) {
        *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(*(int *)(unaff_EBP + -100) + 0x18);
        *(undefined4 *)(unaff_EBP + -0x48) =
             *(undefined4 *)(*(int *)(unaff_EBP + -0x58) + -4 + *(int *)(unaff_EBP + 0xc) * 4);
      }
    }
    uVar1 = *(uint *)(unaff_EBP + -0x48);
    *(uint *)(unaff_EBP + -0x20) = uVar1;
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      *(undefined2 *)(unaff_EBP + -0x5c) = *(undefined2 *)(*(int *)(unaff_EBP + -0x20) + 0x84);
      uVar1 = (uint)*(ushort *)(unaff_EBP + -0x5c);
      if (uVar1 != 0xfffb) {
        *(undefined2 *)(unaff_EBP + -0x60) = *(undefined2 *)(*(int *)(unaff_EBP + -0x20) + 0x84);
        uVar1 = FUN_0040766a(0xf1,*(undefined2 *)(unaff_EBP + -0x60));
      }
    }
    uVar3 = (undefined2)(uVar1 >> 0x10);
  }
  else if (*(int *)(unaff_EBP + -0x68) == 0xf6) {
    iVar2 = FUN_00445724();
    if (iVar2 == 0) {
      FUN_00445e8a();
      iVar2 = FUN_0040766a(0xe4,0);
    }
    uVar3 = (undefined2)((uint)iVar2 >> 0x10);
  }
  else if (*(int *)(unaff_EBP + -0x68) == 0x101) {
    FUN_00444804();
    uVar3 = extraout_var_02;
  }
  else if (*(int *)(unaff_EBP + -0x68) == 0x105) {
    FUN_00442bdf();
    uVar3 = extraout_var_00;
  }
  else {
    if (*(int *)(unaff_EBP + -0x68) != 0x10b) {
      iVar2 = (uint)(ushort)(*(short *)(unaff_EBP + 8) >> 0xf) << 0x10;
      goto LAB_0044321f;
    }
    *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -100) + 0x9c;
    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 4);
    *(undefined4 *)(unaff_EBP + -0x28) = **(undefined4 **)(unaff_EBP + -0x44);
    FUN_004487d4(*(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + -0x24));
    *(undefined4 *)(unaff_EBP + -0x10) =
         *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -100) + 0x14) + 0x2c);
    FUN_0046e3d5(*(undefined4 *)(unaff_EBP + -0x10),0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0046e3ed(100,0,*(int *)(unaff_EBP + -100) + 0x9c,0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046e52f();
    uVar3 = extraout_var;
  }
  iVar2 = CONCAT22(uVar3,1);
LAB_0044321f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

