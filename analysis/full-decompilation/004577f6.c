
void FUN_004577f6(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  short sVar3;
  int unaff_EBP;
  short sVar4;
  
  FUN_00634c24();
  if ((*(byte *)(extraout_ECX + 0x2d) & 1) == 0) {
    *(undefined4 *)(unaff_EBP + -0x10) = *extraout_ECX;
    sVar3 = *(short *)(extraout_ECX[0x18] + 6);
    sVar4 = *(short *)(extraout_ECX[0x18] + 8) + sVar3;
    for (; sVar3 <= (short)(sVar4 + -1); sVar3 = sVar3 + 1) {
      pvVar1 = operator_new(0x58);
      *(void **)(unaff_EBP + -0x18) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar1 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_00457882();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
      FUN_0040780c(*(undefined4 *)(unaff_EBP + -0x10),sVar3);
      FUN_00458287(unaff_EBP + -0x14);
    }
    extraout_ECX[0x2d] = extraout_ECX[0x2d] | 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

