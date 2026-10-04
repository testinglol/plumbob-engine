
undefined4 * FUN_0041f010(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  float10 fVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  extraout_ECX[7] = *(undefined4 *)(unaff_EBP + 0x14);
  extraout_ECX[1] = *(undefined4 *)(unaff_EBP + 8);
  iVar2 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = 0;
  extraout_ECX[0x10] = 0;
  if (iVar2 == 0) {
    extraout_ECX[4] = 0xffffffff;
    extraout_ECX[2] = 0;
    extraout_ECX[3] = 0;
  }
  else {
    extraout_ECX[2] = iVar2;
    extraout_ECX[3] = iVar2;
    extraout_ECX[4] = *(undefined4 *)(unaff_EBP + 0x10);
  }
  *(undefined2 *)(extraout_ECX + 5) = 0;
  *(undefined2 *)((int)extraout_ECX + 0x16) = 0;
  *(undefined2 *)(extraout_ECX + 6) = 0;
  *(undefined2 *)((int)extraout_ECX + 0x1a) = 0;
  extraout_ECX[0xf] = 0;
  iVar2 = FUN_0041f101();
  if (iVar2 == 0) {
    extraout_ECX[0x10] = extraout_ECX[0x10] & 0xfffffffe;
    *(undefined2 *)(extraout_ECX + 8) = 0;
    extraout_ECX[9] = 0;
  }
  else {
    *(undefined2 *)(extraout_ECX + 8) = *(undefined2 *)(iVar2 + 2);
    fVar3 = (float10)FUN_0047603d(CONCAT31((int3)((uint)extraout_ECX[1] >> 8),
                                           *(short *)(extraout_ECX[1] + 0x5cc) != 0));
    extraout_ECX[9] = (float)fVar3;
    uVar1 = *(uint *)(iVar2 + 0x14);
    extraout_ECX[0x10] = extraout_ECX[0x10] & 0xfffffffe;
    if ((uVar1 & 0x100) != 0) {
      extraout_ECX[0x10] = extraout_ECX[0x10] | 1;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

