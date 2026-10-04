
undefined4 * FUN_004d0c4d(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x84) = &PTR_FUN_0066643c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar2 = FUN_0041532c(9,unaff_EBP + -0x84,0);
  cVar1 = FUN_004fff98(0xa1,uVar2);
  if (cVar1 != '\0') {
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
    iVar3 = FUN_0047168f();
    if (0 < iVar3) {
      do {
        if (((*(int *)(unaff_EBP + -0x14) < 0x15) || (0x19 < *(int *)(unaff_EBP + -0x14))) &&
           (*(int *)(unaff_EBP + -0x14) < 0x1d)) {
          pcVar4 = (char *)FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
          pcVar5 = (char *)FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x14),0);
          if ((pcVar4 != (char *)0x0) && (pcVar5 != (char *)0x0)) {
            cVar1 = *pcVar4;
            if (cVar1 != *pcVar5) {
              *(char *)(unaff_EBP + -0xd) = *pcVar5;
              *(char *)(unaff_EBP + -0xe) = cVar1;
              FUN_004d4116(unaff_EBP + -0xe);
            }
          }
        }
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        iVar3 = FUN_0047168f();
      } while (*(int *)(unaff_EBP + -0x14) <= iVar3);
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

