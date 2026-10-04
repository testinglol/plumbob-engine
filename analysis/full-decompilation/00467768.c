
void FUN_00467768(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(int *)(unaff_EBP + -0x14) = (int)*(char *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x18) = (int)*(char *)(unaff_EBP + 0xd);
  uVar1 = *(undefined1 *)(unaff_EBP + 0xe);
  FUN_0047bd91(unaff_EBP + -0x14,unaff_EBP + -0x18,-*(int *)(extraout_ECX + 0x84) & 3,0x40);
  *(undefined1 *)(unaff_EBP + -0xe) = uVar1;
  *(undefined1 *)(unaff_EBP + -0x10) = *(undefined1 *)(unaff_EBP + -0x14);
  *(undefined1 *)(unaff_EBP + -0xf) = *(undefined1 *)(unaff_EBP + -0x18);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00479737(unaff_EBP + -0x44,unaff_EBP + -0x10);
  uVar2 = *(undefined4 *)(extraout_ECX + 0x84);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0053bdad(uVar2);
  puVar4 = (undefined4 *)(unaff_EBP + -0x44);
  puVar5 = *(undefined4 **)(unaff_EBP + 8);
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

