
undefined1 FUN_004e2b6b(void)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined1 uVar5;
  int unaff_EBP;
  short *psVar6;
  
  FUN_00634c24();
  FUN_00418fea();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004190d3(*(undefined4 *)(unaff_EBP + 8),1);
  cVar3 = FUN_004198f0();
  if (cVar3 != '\0') {
    FUN_004243e9();
    iVar4 = FUN_0042444b(unaff_EBP + -0x6c);
    if (iVar4 == 0) {
      iVar4 = *(int *)(unaff_EBP + 0xc);
      *(undefined1 *)(iVar4 + 400) = *(undefined1 *)(unaff_EBP + -0x28);
      FUN_004100cf(0,0xffffffff);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      cVar3 = FUN_00410398(unaff_EBP + -0x6c,(int)*(short *)(unaff_EBP + -0x26));
      if (cVar3 == '\0') {
        uVar5 = 0;
      }
      else {
        FUN_004e1ca1(unaff_EBP + -0x1d8,iVar4 + 0x13c,0);
        FUN_004e3bfc(*(undefined4 *)(iVar4 + 0x194),*(undefined4 *)(iVar4 + 0x198));
        FUN_005b8680();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_005b8680();
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        psVar6 = (short *)(unaff_EBP + -0x24);
        do {
          if (*psVar6 == 0) break;
          FUN_005b8680();
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_004e3bd4(unaff_EBP + -0x7c);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_005b8770();
          iVar1 = (*(int *)(iVar4 + 0x198) - *(int *)(iVar4 + 0x194) >> 4) * 0x10 + -0x10 +
                  *(int *)(iVar4 + 0x194);
          *(int *)(unaff_EBP + -0x14) = iVar1;
          FUN_0040622a(unaff_EBP + -0x6c,CONCAT22((short)((uint)iVar1 >> 0x10),*psVar6),1);
          FUN_005d499c(unaff_EBP + -0x40);
          FUN_005a55f6(unaff_EBP + -0x6c,(int)*psVar6,*(int *)(unaff_EBP + -0x14) + 0xc,4);
          *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
          psVar6 = psVar6 + 1;
        } while (*(int *)(unaff_EBP + 0xc) < 8);
        *(undefined1 *)(iVar4 + 0x110) = 0;
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
        cVar3 = FUN_004e2795(unaff_EBP + -0x6c,iVar4 + 0x114,*(undefined4 *)(unaff_EBP + 0x10),
                             unaff_EBP + -0xd);
        if (cVar3 != '\0') {
          uVar2 = *(undefined4 *)(unaff_EBP + -200);
          *(undefined1 *)(iVar4 + 0x110) = 1;
          *(undefined4 *)(iVar4 + 0x138) = 0xfffffffe;
          *(undefined4 *)(iVar4 + 0x158) = uVar2;
        }
        FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 8));
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005b8770();
        uVar5 = 1;
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_00410173();
      goto LAB_004e2d4f;
    }
  }
  uVar5 = 0;
LAB_004e2d4f:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0041905d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

