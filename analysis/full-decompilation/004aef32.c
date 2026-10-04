
undefined1 * FUN_004aef32(void)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar3 = *(int *)(extraout_ECX + 0x84);
  cVar2 = *(char *)(unaff_EBP + 0xe);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00434ffd(-iVar3 & 3);
  uVar4 = *(undefined4 *)(extraout_ECX + 0x84);
  puVar1 = (undefined1 *)
           (**(int **)(extraout_ECX + 0x68 + (cVar2 + -1) * 4) +
           (*(char *)(unaff_EBP + 0xd) * 0x40 + (int)*(char *)(unaff_EBP + 0xc)) * 4);
  *(undefined1 *)(unaff_EBP + -0x10) = *puVar1;
  *(undefined1 *)(unaff_EBP + -0xf) = puVar1[1];
  *(undefined1 *)(unaff_EBP + -0xe) = puVar1[2];
  *(undefined1 *)(unaff_EBP + -0xd) = puVar1[3];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  puVar5 = (undefined1 *)FUN_004aefd1(uVar4);
  puVar1 = *(undefined1 **)(unaff_EBP + 8);
  *puVar1 = *puVar5;
  puVar1[1] = puVar5[1];
  puVar1[2] = puVar5[2];
  puVar1[3] = puVar5[3];
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar1;
}

