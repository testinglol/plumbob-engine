
void FUN_00439a58(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EBP;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = *(int *)(unaff_EBP + 0xc);
  while (iVar5 = (iVar3 + -1) / 2, *(int *)(unaff_EBP + 0x10) < iVar3) {
    puVar4 = (undefined4 *)(iVar5 * 0x10 + *(int *)(unaff_EBP + 8));
    cVar1 = (**(code **)(unaff_EBP + 0x24))(puVar4,unaff_EBP + 0x14);
    if (cVar1 == '\0') break;
    puVar2 = (undefined4 *)(iVar3 * 0x10 + *(int *)(unaff_EBP + 8));
    *puVar2 = *puVar4;
    *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(puVar4 + 1);
    *(undefined1 *)((int)puVar2 + 5) = *(undefined1 *)((int)puVar4 + 5);
    *(undefined1 *)((int)puVar2 + 6) = *(undefined1 *)((int)puVar4 + 6);
    puVar2[2] = puVar4[2];
    puVar2[3] = puVar4[3];
    iVar3 = iVar5;
  }
  puVar4 = (undefined4 *)(iVar3 * 0x10 + *(int *)(unaff_EBP + 8));
  *puVar4 = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined1 *)(puVar4 + 1) = *(undefined1 *)(unaff_EBP + 0x18);
  *(undefined1 *)((int)puVar4 + 5) = *(undefined1 *)(unaff_EBP + 0x19);
  *(undefined1 *)((int)puVar4 + 6) = *(undefined1 *)(unaff_EBP + 0x1a);
  puVar4[2] = *(undefined4 *)(unaff_EBP + 0x1c);
  puVar4[3] = *(undefined4 *)(unaff_EBP + 0x20);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

