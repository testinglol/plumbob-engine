
void FUN_004883af(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int unaff_EBP;
  char *pcVar8;
  undefined4 *puVar9;
  undefined4 auStack_a0 [8];
  undefined4 uStack_80;
  int iStack_7c;
  int iStack_78;
  
  FUN_00634c24();
  puVar5 = (undefined4 *)(unaff_EBP + -0x70);
  for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  pcVar4 = *(char **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar7 = DAT_006e54dc;
  cVar1 = *pcVar4;
  *(char *)(unaff_EBP + -0x73) = pcVar4[1];
  cVar2 = pcVar4[2];
  *(char *)(unaff_EBP + -0x72) = cVar2;
  *(char *)(unaff_EBP + -0x74) = cVar1;
  cVar3 = pcVar4[0x38];
  *(uint *)(unaff_EBP + -0x40) =
       (uint)*(ushort *)
              (*(int *)(*(int *)(*(int *)(iVar7 + 0x20 + cVar2 * 4) + 0xc) + cVar1 * 4) +
              *(char *)(unaff_EBP + -0x73) * 2);
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(pcVar4 + 0x30);
  if (cVar3 == '\0') {
    *(undefined1 *)(unaff_EBP + -0x3c) = 0;
  }
  else {
    iStack_78 = unaff_EBP + -0x74;
    iStack_7c = unaff_EBP + -0x38;
    uStack_80 = 0x48841a;
    puVar5 = (undefined4 *)FUN_00479737();
    puVar9 = (undefined4 *)(unaff_EBP + -0x70);
    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    *(undefined1 *)(unaff_EBP + -0x3c) = 1;
  }
  iStack_78 = 0x488439;
  iVar6 = FUN_004790b4();
  iVar7 = DAT_006e54dc;
  *(bool *)(unaff_EBP + -0x3b) =
       *(char *)(*(int *)(*(int *)(iVar6 + 0x10) + *pcVar4 * 4) + (int)pcVar4[1]) == '\x10';
  *(short *)(*(int *)(*(int *)(*(int *)(iVar7 + 0x20 + *(char *)(unaff_EBP + -0x72) * 4) + 0xc) +
                     *(char *)(unaff_EBP + -0x74) * 4) + *(char *)(unaff_EBP + -0x73) * 2) =
       (short)*(undefined4 *)(pcVar4 + 0x34);
  if (pcVar4[0x38] != '\0') {
    *(undefined4 **)(unaff_EBP + 8) = auStack_a0;
    puVar5 = auStack_a0;
    pcVar8 = pcVar4;
    for (iVar7 = 0xb; pcVar8 = pcVar8 + 4, iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar5 = *(undefined4 *)pcVar8;
      puVar5 = puVar5 + 1;
    }
    FUN_00479954(unaff_EBP + -0x74);
  }
  if (pcVar4[0x39] != '\0') {
    iStack_78 = 0x4884ac;
    iVar7 = FUN_004790b4();
    *(undefined1 *)
     (*(int *)(*(int *)(iVar7 + 0x10) + *(char *)(unaff_EBP + -0x74) * 4) +
     (int)*(char *)(unaff_EBP + -0x73)) = 0x10;
  }
  cVar1 = *(char *)(unaff_EBP + -0x74);
  if ((((-1 < cVar1) && ((int)cVar1 < *(int *)(DAT_006e54dc + 0x10))) &&
      (cVar2 = *(char *)(unaff_EBP + -0x73), -1 < cVar2)) &&
     ((int)cVar2 < *(int *)(DAT_006e54dc + 0x10))) {
    *(char *)(unaff_EBP + 9) = cVar2;
    *(char *)(unaff_EBP + 8) = cVar1;
    *(undefined1 *)(unaff_EBP + 10) = *(undefined1 *)(unaff_EBP + -0x72);
    iVar7 = DAT_006e54d8;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iStack_78 = *(undefined4 *)(iVar7 + 0x84);
    iStack_7c = 0x48850a;
    FUN_00434ffd();
    iStack_78 = unaff_EBP + 8;
    iStack_7c = 0x488513;
    FUN_004a6a15();
    *(undefined1 *)(unaff_EBP + -4) = 0;
  }
  iStack_78 = unaff_EBP + -0x74;
  iStack_7c = 0x488523;
  FUN_00488534();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

