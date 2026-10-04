
void FUN_00431b5e(void)

{
  undefined2 uVar1;
  short sVar2;
  void *pvVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00474927((int)*(short *)(*(int *)(extraout_ECX[0x47] + 0x60) + 4),(int)extraout_ECX + 0x3a);
  FUN_0046dfaf();
  FUN_00435b8c(unaff_EBP + -0x44);
  if (*(short *)(extraout_ECX[0x46] + 0x28) != 0) {
    FUN_0046e3d5(*(undefined4 *)extraout_ECX[0x47],0);
    iVar4 = extraout_ECX[0x46];
    uVar1 = *(undefined2 *)(iVar4 + 0x28);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0046e3ed(CONCAT22((short)((uint)iVar4 >> 0x10),uVar1),extraout_ECX + 0x4c,
                 extraout_ECX + 0x4f,extraout_ECX + 0x52);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046e52f();
  }
  *(undefined2 *)((int)extraout_ECX + 0x66) = 0xffff;
  *(undefined2 *)(extraout_ECX + 0x14) = 0xffff;
  *(short *)(extraout_ECX + 0x34) = (short)((extraout_ECX[0x4d] - extraout_ECX[0x4c]) / 0x24) + -1;
  *(undefined4 *)(unaff_EBP + -0x10) = 0xfffffff0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0xfffffff0;
  FUN_00433ef5(unaff_EBP + -0x14,1,0);
  sVar2 = *(short *)(extraout_ECX[0x46] + 0x82);
  *(short *)(extraout_ECX + 0xe) = sVar2;
  if (sVar2 == 0) {
    extraout_ECX[0xd] = 0;
  }
  else {
    pvVar3 = operator_new((int)sVar2 << 1);
    extraout_ECX[0xd] = (int)pvVar3;
  }
  iVar4 = 0;
  if (0 < (short)extraout_ECX[0xe]) {
    do {
      *(undefined2 *)(extraout_ECX[0xd] + iVar4 * 2) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (short)extraout_ECX[0xe]);
  }
  iVar4 = FUN_00457553();
  extraout_ECX[0x61] = iVar4;
  (**(code **)(*extraout_ECX + 0x1c))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

