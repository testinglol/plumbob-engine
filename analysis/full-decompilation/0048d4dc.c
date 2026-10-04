
void FUN_0048d4dc(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00492b05();
  uVar4 = FUN_00445724();
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  if ((*(int *)(extraout_ECX + 0x3c) == 2) || (*(int *)(extraout_ECX + 0x3c) == 3)) {
    FUN_0048d601(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 8));
  }
  else {
    piVar1 = (int *)(extraout_ECX + 0x30);
    FUN_0045fcbd(*(undefined4 *)(extraout_ECX + 0x30),*(undefined4 *)(extraout_ECX + 0x34));
    if (((*(int *)(extraout_ECX + 0x3c) == 0) && (*(int *)(unaff_EBP + -0x10) != 0)) &&
       (iVar2 = *(int *)(unaff_EBP + 8), iVar2 != 0)) {
      FUN_00458419(*(undefined4 *)(unaff_EBP + -0x10),iVar2,0);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004586ef(piVar1);
      if ((*(int *)(extraout_ECX + 0x34) - *piVar1) / 0x44 == 0) {
        FUN_0043f371(*DAT_006e486c,iVar2 + 0xfc,0);
        while (iVar3 = *(int *)(unaff_EBP + -0x18), iVar3 != 0) {
          if (((iVar3 != iVar2) && (*(short *)(*(int *)(iVar3 + 0x118) + 0x12) != 8)) &&
             ((*(byte *)(*(int *)(iVar3 + 0x118) + 0xb6) & 1) != 0)) {
            FUN_00458419(*(undefined4 *)(unaff_EBP + -0x10),iVar3,0);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_004586ef(piVar1);
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_00458449();
          }
          FUN_0043f3b9();
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00458449();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

