
void FUN_0048aff8(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int iVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  FUN_00634c24();
  puVar5 = *(undefined4 **)(unaff_EBP + 0x14);
  *(undefined4 *)(extraout_ECX + 0x38) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0x3c) = *(undefined4 *)(unaff_EBP + 0xc);
  puVar6 = (undefined4 *)(extraout_ECX + 0x40);
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  uVar3 = FUN_0048b777();
  *(undefined4 *)(extraout_ECX + 0x6c) = uVar3;
  FUN_0048b9f3(uVar3);
  FUN_0048b857(unaff_EBP + 8);
  uVar1 = FUN_00492b26();
  *(undefined1 *)(unaff_EBP + 0x16) = uVar1;
  *(char *)(unaff_EBP + 0x14) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
  *(char *)(unaff_EBP + 0x15) = (char)(*(int *)(unaff_EBP + 8) >> 4);
  iVar4 = *(int *)(extraout_ECX + 0x5c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar4 != 0) {
    cVar2 = FUN_00496e92(unaff_EBP + 0x14,0);
    if (cVar2 != '\0') {
      FUN_0048b8b2(unaff_EBP + 0x14);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

