
void FUN_004fbaaa(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int extraout_ECX;
  undefined4 *puVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  (**(code **)(*(int *)(extraout_ECX + 0x14) + 4))();
  iVar5 = 0;
  if (DAT_006ca0a4 != -1) {
    puVar4 = &DAT_006ca0a4;
    iVar1 = DAT_006ca0a4;
    do {
      if (iVar1 == *(int *)(unaff_EBP + 8)) break;
      iVar1 = puVar4[1];
      puVar4 = puVar4 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar1 != -1);
  }
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (((&DAT_006ca0a4)[iVar5] != -1) && (*(int *)(extraout_ECX + 0x114) != 0)) {
    iVar5 = iVar5 + 1;
    iVar1 = FUN_004705f2(iVar5,0xffffffff);
    if (iVar1 != 0) {
      pcVar2 = (char *)FUN_00470631(iVar5,0xffffffff);
      if ((pcVar2 == (char *)0x0) || (*pcVar2 != '!')) {
        uVar3 = FUN_004705f2(iVar5,0xffffffff);
        FUN_005d4bbf(uVar3);
      }
    }
  }
  if ((*(int *)(extraout_ECX + 0x110) != 0) &&
     (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + -0x18))) {
    FUN_005ee8e1(*(undefined4 *)(unaff_EBP + -0x18));
  }
  (**(code **)(*(int *)(extraout_ECX + 0x14) + 8))();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

