
void FUN_004ea458(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  iVar2 = FUN_004e9744(*(undefined4 *)(unaff_EBP + 8));
  iVar4 = 0;
  if (iVar2 != 0) {
    FUN_004e88bb();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar1 = FUN_004ea33f(*(undefined4 *)(unaff_EBP + 8),iVar2,iVar2 + 0xa48,1,unaff_EBP + -0x28);
    if (cVar1 != '\0') {
      FUN_004eb2de(unaff_EBP + -0x28);
    }
    iVar5 = *(int *)(iVar2 + 0xa44) - *(int *)(iVar2 + 0xa40);
    if (0 < iVar5) {
      do {
        uVar3 = FUN_0045d8f7(iVar4);
        cVar1 = FUN_004ea33f(*(undefined4 *)(unaff_EBP + 8),iVar2,uVar3,0,unaff_EBP + -0x28);
        if (cVar1 != '\0') {
          *(undefined1 *)(unaff_EBP + -0x1f) = 0;
          FUN_004eb2de(unaff_EBP + -0x28);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar5);
    }
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005a5e09();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

