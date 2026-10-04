
void FUN_00554f58(void)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  size_t sVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(char *)(extraout_ECX + 0x1c0) == '\0') && (*(char *)(extraout_ECX + 0x12a) != '\0')) {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004f2baf(unaff_EBP + -0x18);
    pcVar4 = (char *)FUN_0041532c(0x58);
    sVar5 = _strlen(pcVar4);
    FUN_00412d8a(pcVar4,pcVar4 + sVar5);
    sVar5 = _strlen(s___mtl_006cddac);
    FUN_00412d8a(s___mtl_006cddac,s___mtl_006cddac + sVar5);
    bVar2 = FUN_005d8a11(unaff_EBP + -0x18);
    FUN_004f2baf(unaff_EBP + -0x18);
    pcVar4 = (char *)FUN_0041532c(0x58);
    sVar5 = _strlen(pcVar4);
    FUN_00412d8a(pcVar4,pcVar4 + sVar5);
    sVar5 = _strlen(s___mtf_006cdda4);
    FUN_00412d8a(s___mtf_006cdda4,s___mtf_006cdda4 + sVar5);
    bVar3 = FUN_005d8a11(unaff_EBP + -0x18);
    piVar1 = *(int **)(extraout_ECX + 0x17c);
    if (*(byte *)(piVar1 + 0x5a) != (bVar2 | bVar3)) {
      *(byte *)(piVar1 + 0x5a) = bVar2 | bVar3;
      (**(code **)(*piVar1 + 0x168))();
    }
    *(undefined1 *)(extraout_ECX + 0x1c0) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

