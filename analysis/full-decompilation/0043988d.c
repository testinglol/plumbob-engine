
void FUN_0043988d(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  puVar5 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar3 = (**(code **)(unaff_EBP + 0x1c))(unaff_EBP + 0xc,puVar5 + -4);
  if (cVar3 != '\0') {
    puVar6 = (undefined1 *)((int)puVar5 + -10);
    puVar2 = puVar5 + -4;
    puVar4 = puVar5;
    do {
      puVar5 = puVar2;
      *puVar4 = *puVar5;
      *(undefined1 *)(puVar4 + 1) = puVar6[-2];
      *(undefined1 *)((int)puVar4 + 5) = puVar6[-1];
      *(undefined1 *)((int)puVar4 + 6) = *puVar6;
      puVar4[2] = *(undefined4 *)(puVar6 + 2);
      puVar4[3] = *(undefined4 *)(puVar6 + 6);
      puVar6 = puVar6 + -0x10;
      cVar3 = (**(code **)(unaff_EBP + 0x1c))(unaff_EBP + 0xc,puVar5 + -4);
      puVar2 = puVar5 + -4;
      puVar4 = puVar5;
    } while (cVar3 != '\0');
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *puVar5 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined1 *)(puVar5 + 1) = *(undefined1 *)(unaff_EBP + 0x10);
  *(undefined1 *)((int)puVar5 + 5) = *(undefined1 *)(unaff_EBP + 0x11);
  *(undefined1 *)((int)puVar5 + 6) = *(undefined1 *)(unaff_EBP + 0x12);
  puVar5[2] = *(undefined4 *)(unaff_EBP + 0x14);
  puVar5[3] = *(undefined4 *)(unaff_EBP + 0x18);
  *unaff_FS_OFFSET = uVar1;
  return;
}

