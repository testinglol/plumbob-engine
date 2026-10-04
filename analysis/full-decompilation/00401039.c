
int FUN_00401039(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  size_t sVar6;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined1 *puVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_004703f1(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  if (iVar2 == 0) {
    iVar2 = 1;
    iVar3 = FUN_0046fbe5(0xffffffff);
    if (0 < iVar3) {
      do {
        uVar4 = FUN_004705f2(iVar2,0xffffffff);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
        pcVar5 = (char *)FUN_004705f2(iVar2,0xffffffff);
        if ((pcVar5 == (char *)0x0) || (sVar6 = _strlen(pcVar5), sVar6 == 0)) {
          while( true ) {
            iVar3 = FUN_0046fbe5(0xffffffff);
            uVar4 = 0xffffffff;
            if (iVar2 + -1 <= iVar3) break;
            puVar7 = &DAT_006de560;
            iVar3 = FUN_0046fbe5(0xffffffff);
            FUN_004704a5(iVar3 + 1,puVar7,uVar4);
          }
          FUN_004704a5(iVar2,*(undefined4 *)(unaff_EBP + 0xc),0xffffffff);
          pcVar5 = (char *)FUN_004705f2(iVar2,0xffffffff);
          if (pcVar5 != (char *)0x0) {
            for (; cVar1 = *pcVar5, cVar1 != '\0'; pcVar5 = pcVar5 + 1) {
              if (('@' < cVar1) && (cVar1 < '[')) {
                *pcVar5 = cVar1 + ' ';
              }
            }
          }
        }
        iVar2 = iVar2 + 1;
        iVar3 = FUN_0046fbe5(0xffffffff);
      } while (iVar2 <= iVar3);
    }
    iVar2 = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

