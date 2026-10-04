
void FUN_004a4b03(void)

{
  short sVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  int iVar3;
  undefined4 uVar4;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + 0xe) = 0;
  *(undefined1 *)(unaff_EBP + 0xc) = *(undefined1 *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + 0xd) = *(undefined1 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar4 = 1;
  uVar2 = FUN_00492d2c(1);
  iVar3 = unaff_EBP + 0xc;
  FUN_004cebb0(iVar3,uVar2);
  sVar1 = FUN_004c9f9a(iVar3,uVar2,uVar4);
  sVar1 = sVar1 + 0x50;
  uVar2 = *(undefined4 *)(DAT_006e54d8 + 0x78);
  *(char *)(unaff_EBP + 0xc) =
       *(char *)(unaff_EBP + 0xc) - (char)*(undefined4 *)(DAT_006e54d8 + 0x70);
  *(char *)(unaff_EBP + 0xd) = *(char *)(unaff_EBP + 0xd) - (char)uVar2;
  *(undefined4 *)(extraout_ECX + 0xc) =
       *(undefined4 *)
        (*(int *)(*(int *)(extraout_ECX + 8) + *(char *)(unaff_EBP + 0xc) * 4) +
        *(char *)(unaff_EBP + 0xd) * 4);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(short *)(extraout_ECX + 0x18) = sVar1;
  *(short *)(extraout_ECX + 0x1a) = sVar1;
  *(short *)(extraout_ECX + 0x1c) = sVar1;
  *(short *)(extraout_ECX + 0x1e) = sVar1;
  return;
}

