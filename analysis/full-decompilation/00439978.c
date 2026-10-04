
void FUN_00439978(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_20 [8];
  undefined4 uStack_18;
  int iStack_14;
  int iStack_10;
  
  FUN_00634c24();
  iVar8 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 0xc) = iVar8;
  iVar7 = iVar8 * 2 + 2;
  iVar6 = iVar8;
  if (iVar7 < *(int *)(unaff_EBP + 0x10)) {
    do {
      iStack_14 = iVar7 * 0x10 + iVar2;
      iStack_10 = iStack_14 + -0x10;
      uStack_18 = 0x4399aa;
      cVar3 = (**(code **)(unaff_EBP + 0x24))();
      iVar8 = iVar7;
      if (cVar3 != '\0') {
        iVar8 = iVar7 + -1;
      }
      puVar4 = (undefined4 *)(iVar8 * 0x10 + iVar2);
      puVar5 = (undefined4 *)(iVar6 * 0x10 + iVar2);
      iVar7 = iVar8 * 2 + 2;
      *puVar5 = *puVar4;
      *(undefined1 *)(puVar5 + 1) = *(undefined1 *)(puVar4 + 1);
      *(undefined1 *)((int)puVar5 + 5) = *(undefined1 *)((int)puVar4 + 5);
      iVar1 = *(int *)(unaff_EBP + 0x10);
      *(undefined1 *)((int)puVar5 + 6) = *(undefined1 *)((int)puVar4 + 6);
      puVar5[2] = puVar4[2];
      puVar5[3] = puVar4[3];
      iVar6 = iVar8;
    } while (iVar7 < iVar1);
  }
  iVar6 = iVar8;
  if (iVar7 == *(int *)(unaff_EBP + 0x10)) {
    iVar1 = iVar7 * 0x10 + -0x10 + iVar2;
    iVar6 = iVar7 + -1;
    puVar4 = (undefined4 *)(iVar8 * 0x10 + iVar2);
    *puVar4 = *(undefined4 *)(iVar7 * 0x10 + -0x10 + iVar2);
    *(undefined1 *)(puVar4 + 1) = *(undefined1 *)(iVar1 + 4);
    *(undefined1 *)((int)puVar4 + 5) = *(undefined1 *)(iVar1 + 5);
    *(undefined1 *)((int)puVar4 + 6) = *(undefined1 *)(iVar1 + 6);
    puVar4[2] = *(undefined4 *)(iVar1 + 8);
    puVar4[3] = *(undefined4 *)(iVar1 + 0xc);
  }
  iStack_10 = *(undefined4 *)(unaff_EBP + 0x24);
  *(undefined1 **)(unaff_EBP + 0x10) = auStack_20;
  FUN_004393d9(unaff_EBP + 0x14);
  FUN_00439a58(iVar2,iVar6,*(undefined4 *)(unaff_EBP + 0xc));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

