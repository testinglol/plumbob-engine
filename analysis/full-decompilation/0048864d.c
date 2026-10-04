
void FUN_0048864d(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  
  FUN_00634c24();
  puVar2 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + 8) = *puVar2;
  uVar1 = puVar2[2];
  *(undefined1 *)(unaff_EBP + 9) = puVar2[1];
  *(undefined1 *)(unaff_EBP + 10) = uVar1;
  iVar5 = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00434ffd(-*(int *)(iVar5 + 0x84) & 3);
  puVar6 = (undefined4 *)(unaff_EBP + -0x44);
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  uVar3 = *(undefined4 *)(extraout_ECX + 0x24);
  *(undefined1 *)(unaff_EBP + -0x48) = *(undefined1 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -0x47) = *(undefined1 *)(unaff_EBP + 9);
  *(undefined1 *)(unaff_EBP + -0x46) = *(undefined1 *)(unaff_EBP + 10);
  uVar4 = *(undefined4 *)(extraout_ECX + 0x28);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar5 = FUN_00489eb1(uVar3,uVar4,unaff_EBP + -0x48);
  if (iVar5 == *(int *)(extraout_ECX + 0x28)) {
    *(undefined1 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0x14);
    *(undefined1 *)(unaff_EBP + -0xf) = *(undefined1 *)(unaff_EBP + 0x10);
    FUN_00489ca6(unaff_EBP + -0x48);
  }
  else {
    *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + *(int *)(unaff_EBP + 0x14);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

