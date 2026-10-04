
void FUN_004396dc(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_2c;
  undefined4 *puStack_28;
  undefined4 *puStack_24;
  int iStack_20;
  undefined4 *puStack_1c;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = *puVar1;
  *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(puVar1 + 1);
  *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)((int)puVar1 + 5);
  *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)((int)puVar1 + 6);
  *(undefined4 *)(unaff_EBP + -0x14) = puVar1[2];
  *(undefined4 *)(unaff_EBP + -0x10) = puVar1[3];
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iStack_20 = unaff_EBP + -0x1c;
  puStack_24 = (undefined4 *)0x439720;
  puStack_1c = puVar2;
  cVar3 = (**(code **)(unaff_EBP + 0x14))();
  if (cVar3 == '\0') {
    puStack_1c = *(undefined4 **)(unaff_EBP + 0x14);
    *(undefined4 ***)(unaff_EBP + 0x14) = &puStack_2c;
    FUN_004393d9(unaff_EBP + -0x1c);
    FUN_0043988d(puVar1);
  }
  else {
    puStack_1c = (undefined4 *)0x0;
    puStack_24 = puVar1 + 4;
    iStack_20 = *(undefined4 *)(unaff_EBP + 0x14);
    puStack_2c = puVar2;
    puStack_28 = puVar1;
    FUN_0043954f();
    *puVar2 = *(undefined4 *)(unaff_EBP + -0x1c);
    *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(unaff_EBP + -0x18);
    *(undefined1 *)((int)puVar2 + 5) = *(undefined1 *)(unaff_EBP + -0x17);
    *(undefined1 *)((int)puVar2 + 6) = *(undefined1 *)(unaff_EBP + -0x16);
    puVar2[2] = *(undefined4 *)(unaff_EBP + -0x14);
    puVar2[3] = *(undefined4 *)(unaff_EBP + -0x10);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

