
void FUN_00488574(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int extraout_ECX;
  int iVar6;
  int unaff_EBP;
  undefined4 *puVar7;
  
  FUN_00634c24();
  puVar2 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + 8) = *puVar2;
  uVar1 = puVar2[2];
  *(undefined1 *)(unaff_EBP + 9) = puVar2[1];
  *(undefined1 *)(unaff_EBP + 10) = uVar1;
  iVar6 = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00434ffd(-*(int *)(iVar6 + 0x84) & 3);
  puVar5 = (undefined4 *)(unaff_EBP + -0x44);
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  uVar3 = *(undefined4 *)(extraout_ECX + 0x24);
  *(undefined1 *)(unaff_EBP + -0x48) = *(undefined1 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -0x47) = *(undefined1 *)(unaff_EBP + 9);
  *(undefined1 *)(unaff_EBP + -0x46) = *(undefined1 *)(unaff_EBP + 10);
  uVar4 = *(undefined4 *)(extraout_ECX + 0x28);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  puVar5 = (undefined4 *)FUN_00489eb1(uVar3,uVar4,unaff_EBP + -0x48);
  if (puVar5 == *(undefined4 **)(extraout_ECX + 0x28)) {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    uVar3 = *(undefined4 *)(unaff_EBP + 0x18);
    puVar5 = *(undefined4 **)(unaff_EBP + 0x10);
    puVar7 = (undefined4 *)(unaff_EBP + -0x44);
    for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
    *(undefined1 *)(unaff_EBP + -0xf) = *(undefined1 *)(unaff_EBP + 0x14);
    *(undefined1 *)(unaff_EBP + -0x10) = 1;
    FUN_00489ca6(unaff_EBP + -0x48);
  }
  else {
    puVar5[0xc] = puVar5[0xc] + *(int *)(unaff_EBP + 0x18);
    if (*(char *)(puVar5 + 0xe) == '\0') {
      puVar7 = *(undefined4 **)(unaff_EBP + 0x10);
      *(undefined1 *)(puVar5 + 0xe) = 1;
      for (iVar6 = 0xb; puVar5 = puVar5 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar5 = *puVar7;
        puVar7 = puVar7 + 1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

