
void FUN_004937af(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int extraout_ECX;
  int iVar7;
  int unaff_EBP;
  undefined4 *puVar8;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0x6a) = 0;
  puVar6 = (undefined4 *)(unaff_EBP + -0x68);
  for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar2 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + 8) = *puVar2;
  uVar1 = puVar2[2];
  *(undefined1 *)(unaff_EBP + 9) = puVar2[1];
  *(undefined1 *)(unaff_EBP + 10) = uVar1;
  iVar7 = DAT_006e54d8;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00434ffd(-*(int *)(iVar7 + 0x84) & 3);
  uVar3 = *(undefined4 *)(extraout_ECX + 0x24);
  *(undefined1 *)(unaff_EBP + -0x6c) = *(undefined1 *)(unaff_EBP + 8);
  iVar7 = *(int *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -0x6b) = *(undefined1 *)(unaff_EBP + 9);
  *(undefined1 *)(unaff_EBP + -0x6a) = *(undefined1 *)(unaff_EBP + 10);
  uVar4 = *(undefined4 *)(extraout_ECX + 0x28);
  *(int *)(unaff_EBP + -0x3c) = iVar7;
  iVar5 = FUN_00493e25(uVar3,uVar4,unaff_EBP + -0x6c);
  if (iVar5 == *(int *)(extraout_ECX + 0x28)) {
    puVar6 = (undefined4 *)FUN_00479737(unaff_EBP + -0x38,unaff_EBP + 8);
    puVar8 = (undefined4 *)(unaff_EBP + -0x68);
    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    FUN_00493bcf(unaff_EBP + -0x6c);
  }
  else {
    *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + iVar7;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

