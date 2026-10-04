
void FUN_0049363a(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_9c [8];
  undefined4 uStack_7c;
  int iStack_78;
  undefined4 *puStack_74;
  
  FUN_00634c24();
  puVar5 = (undefined4 *)(unaff_EBP + -0x6c);
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + -0x70) = *(undefined1 *)puVar5;
  *(undefined1 *)(unaff_EBP + -0x6f) = *(undefined1 *)((int)puVar5 + 1);
  *(undefined1 *)(unaff_EBP + -0x6e) = *(undefined1 *)((int)puVar5 + 2);
  iStack_78 = unaff_EBP + -0x3c;
  uStack_7c = 0x49367b;
  puStack_74 = puVar5;
  puVar2 = (undefined4 *)FUN_00479737();
  puStack_74 = (undefined4 *)0xb;
  uVar1 = puVar5[0xc];
  puVar4 = (undefined4 *)(unaff_EBP + -0x6c);
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 **)(unaff_EBP + -0x10) = auStack_9c;
  *(undefined4 *)(unaff_EBP + -0x40) = uVar1;
  puVar4 = auStack_9c;
  puVar2 = puVar5;
  for (iVar3 = 0xb; puVar2 = puVar2 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar4 = puVar4 + 1;
  }
  FUN_00479954(puVar5);
  *(undefined1 *)(unaff_EBP + 8) = *(undefined1 *)puVar5;
  *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)((int)puVar5 + 1);
  *(undefined1 *)(unaff_EBP + 10) = *(undefined1 *)((int)puVar5 + 2);
  iVar3 = DAT_006e54d8;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  puStack_74 = *(undefined4 **)(iVar3 + 0x84);
  iStack_78 = 0x4936cf;
  FUN_00434ffd();
  puStack_74 = (undefined4 *)(unaff_EBP + 8);
  iStack_78 = 0x4936d8;
  FUN_00492be0();
  *(undefined1 *)puVar5 = *(undefined1 *)(unaff_EBP + -0x70);
  *(undefined1 *)((int)puVar5 + 1) = *(undefined1 *)(unaff_EBP + -0x6f);
  *(undefined1 *)((int)puVar5 + 2) = *(undefined1 *)(unaff_EBP + -0x6e);
  uVar1 = *(undefined4 *)(unaff_EBP + -0x40);
  puVar4 = (undefined4 *)(unaff_EBP + -0x6c);
  puVar2 = puVar5;
  for (iVar3 = 0xb; puVar2 = puVar2 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = *puVar4;
    puVar4 = puVar4 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  puVar5[0xc] = uVar1;
  return;
}

