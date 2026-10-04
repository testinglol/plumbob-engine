
void FUN_0045efcb(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  uint uVar4;
  
  FUN_00634c24();
  if ((*(short *)(extraout_ECX + 0xb2c) != *(short *)(extraout_ECX + 0x5fc)) ||
     (*(short *)(extraout_ECX + 0xb2e) != *(short *)(extraout_ECX + 0x5fe))) {
    *(undefined2 *)(extraout_ECX + 0xb38) = 0;
    **(undefined1 **)(extraout_ECX + 0xb34) = 0;
    *(undefined2 *)(extraout_ECX + 0xb84) = 0;
    **(undefined1 **)(extraout_ECX + 0xb80) = 0;
    *(undefined2 *)(extraout_ECX + 0xbd0) = 0;
    **(undefined1 **)(extraout_ECX + 0xbcc) = 0;
    iVar1 = FUN_00404ccb((int)*(short *)(extraout_ECX + 0x5fc));
    *(int *)(unaff_EBP + -0x10) = iVar1;
    if (iVar1 != 0) {
      uVar4 = (uint)*(short *)(extraout_ECX + 0x5fe);
      if ((*(short *)(extraout_ECX + 0x600) != 0) && (*(short *)(extraout_ECX + 0x600) < 0x12)) {
        uVar4 = 0;
      }
      if (-1 < (int)uVar4) {
        piVar2 = (int *)FUN_005ed3c4();
        if (uVar4 < (uint)((piVar2[1] - *piVar2) / 0x3c0)) {
          piVar2 = (int *)FUN_005ed3c4();
          iVar1 = uVar4 * 0x3c0 + *piVar2;
          *(byte *)(unaff_EBP + -0x10) = *(byte *)(extraout_ECX + 0x60e) & 1;
          uVar3 = FUN_00403415(*(undefined4 *)(unaff_EBP + -0x10));
          FUN_0046f8e4(uVar3);
          FUN_0046f8e4(iVar1 + 0x31c);
          FUN_0046f8e4(iVar1 + 0x368);
          FUN_00408b9d();
          uVar3 = *(undefined4 *)(extraout_ECX + 0x11c);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_00409377(uVar3,0);
          FUN_0040e630(extraout_ECX + 0xb30);
          FUN_0040e6d6(extraout_ECX + 0xb7c);
          FUN_004094f4(0);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_00408c4f();
        }
      }
    }
    *(undefined2 *)(extraout_ECX + 0xb2c) = *(undefined2 *)(extraout_ECX + 0x5fc);
    *(undefined2 *)(extraout_ECX + 0xb2e) = *(undefined2 *)(extraout_ECX + 0x5fe);
  }
  FUN_0046f8e4(extraout_ECX + 0xb30);
  FUN_0046f8e4(extraout_ECX + 0xb7c);
  FUN_0046f8e4(extraout_ECX + 0xbc8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

