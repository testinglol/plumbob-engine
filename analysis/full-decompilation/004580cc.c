
int FUN_004580cc(void)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(short *)(extraout_ECX[0x18] + 0x12) == 2) {
    if ((*(char *)(unaff_EBP + 8) != '\0') || (iVar2 = extraout_ECX[0x22], iVar2 == 0)) {
      if (extraout_ECX[0x22] == 0) {
        pvVar3 = operator_new(0x6c);
        *(void **)(unaff_EBP + -0x10) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar3 == (void *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_00587670();
        }
        iVar2 = extraout_ECX[0x18];
        uVar1 = *extraout_ECX;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x22] = uVar4;
        FUN_00587b7b(uVar1,CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(iVar2 + 0x26)));
      }
      if ((*(char *)(unaff_EBP + 8) != '\0') && (((byte)extraout_ECX[0x2d] & 0xc) == 4)) {
        uVar4 = FUN_004705f2(3,0xffffffff);
        *(undefined4 *)(unaff_EBP + 8) = uVar4;
        FUN_0046f824(unaff_EBP + -0x2b4,0,0x100);
        *(undefined ***)(unaff_EBP + -0x2c0) = &PTR_FUN_00666524;
        FUN_0046f847(*(undefined4 *)(unaff_EBP + 8),0xffffffff);
        FUN_00408b9d();
        *(undefined4 *)(unaff_EBP + -4) = 1;
        FUN_00409377(extraout_ECX,0);
        FUN_0040ede5(extraout_ECX[0x20] + 0x127c);
        FUN_004094f4(1);
        uVar4 = FUN_004705f2(3,0xffffffff);
        *(undefined4 *)(unaff_EBP + 8) = uVar4;
        FUN_0046f824(unaff_EBP + -0x1a8,0,0x100);
        *(undefined ***)(unaff_EBP + -0x1b4) = &PTR_FUN_00666524;
        FUN_0046f847(*(undefined4 *)(unaff_EBP + 8),0xffffffff);
        iVar2 = FUN_0046f973(unaff_EBP + -0x1b4);
        if (iVar2 != 0) {
          FUN_004eb227(*(undefined4 *)(extraout_ECX[0x18] + 0x1c));
          FUN_004e885e();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00408c4f();
      }
      iVar2 = extraout_ECX[0x22];
    }
  }
  else {
    iVar2 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

