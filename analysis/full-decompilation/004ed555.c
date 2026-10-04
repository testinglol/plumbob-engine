
char FUN_004ed555(void)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*extraout_ECX == 3) || (*extraout_ECX == 4)) {
    FUN_0063365a(1);
    uVar2 = DAT_00689070;
    iVar1 = extraout_ECX[0x8f];
    cVar4 = '\0';
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0063371e(iVar1,0x12,uVar2);
    if (*(int *)(*(int *)(unaff_EBP + -0x68 + *(int *)(*(int *)(unaff_EBP + -0x6c) + 4)) + 0x4c) !=
        -1) {
      iVar1 = extraout_ECX[4];
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (iVar1 != extraout_ECX[3]) {
        do {
          *(undefined1 *)(unaff_EBP + -0x14) =
               *(undefined1 *)(extraout_ECX[3] + *(int *)(unaff_EBP + -0x10));
          FUN_00633760(*(undefined4 *)(unaff_EBP + -0x14));
          iVar1 = extraout_ECX[4];
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(uint *)(unaff_EBP + -0x10) < (uint)(iVar1 - extraout_ECX[3]));
      }
      if ((extraout_ECX[1] == 0) || (*extraout_ECX != 4)) {
        *extraout_ECX = 1;
        cVar4 = '\x01';
      }
      else {
        cVar3 = FUN_004b818c(extraout_ECX[7],extraout_ECX[1],0,extraout_ECX[2],1,0);
        cVar4 = '\0';
        if ((cVar3 != '\0') && (cVar4 = FUN_004ed640(), cVar4 != '\0')) {
          *extraout_ECX = 1;
        }
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0063370b();
    FUN_00632b08();
  }
  else {
    cVar4 = '\x01';
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return cVar4;
}

