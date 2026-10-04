
void FUN_004397b7(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_18 [16];
  undefined4 uStack_8;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  puVar2 = *(undefined4 **)(unaff_EBP + 0x10);
  uStack_8 = *(undefined4 *)(unaff_EBP + 0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *puVar2 = *puVar1;
  *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(puVar1 + 1);
  *(undefined1 *)((int)puVar2 + 5) = *(undefined1 *)((int)puVar1 + 5);
  *(undefined1 *)((int)puVar2 + 6) = *(undefined1 *)((int)puVar1 + 6);
  puVar2[2] = puVar1[2];
  puVar2[3] = puVar1[3];
  *(undefined1 **)(unaff_EBP + 8) = auStack_18;
  FUN_004393d9(unaff_EBP + 0x14);
  FUN_00439978(puVar1,0,*(int *)(unaff_EBP + 0xc) - (int)puVar1 >> 4);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

