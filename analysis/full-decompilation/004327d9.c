
void FUN_004327d9(void)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pcVar1 = *(char **)(unaff_EBP + 8);
  if (*pcVar1 == '\0') {
    FUN_00432984();
  }
  uVar2 = *(undefined4 *)(pcVar1 + 0x14);
  *(char *)(unaff_EBP + 8) = (char)(*(int *)(pcVar1 + 8) >> 4);
  *(char *)(unaff_EBP + 9) = (char)(*(int *)(pcVar1 + 4) >> 4);
  *(char *)(unaff_EBP + 10) = (char)uVar2;
  iVar3 = *(int *)(pcVar1 + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar3 == 0) {
    if (*pcVar1 == '\0') goto LAB_00432877;
    FUN_00432888(unaff_EBP + 8,
                 CONCAT22((short)((uint)uVar2 >> 0x10),*(undefined2 *)(extraout_ECX + 0xf0)));
    *(undefined2 *)(extraout_ECX + 0x66) = 0xffff;
    *(undefined2 *)(extraout_ECX + 0x7e) = 0;
  }
  else {
    iVar4 = *(int *)(pcVar1 + 0x10);
    *(undefined2 *)(*(int *)(iVar3 + 0x130) + 0x10 + iVar4 * 0x24) =
         *(undefined2 *)(extraout_ECX + 0xf0);
    *(short *)(extraout_ECX + 0x66) = (short)iVar4;
    *(undefined2 *)(extraout_ECX + 0x7e) = *(undefined2 *)(*(int *)(pcVar1 + 0xc) + 0xf0);
  }
  uVar2 = *(undefined4 *)(pcVar1 + 0x14);
  *(undefined4 *)(extraout_ECX + 0x110) = uVar2;
  *(char *)(extraout_ECX + 0xfe) = (char)uVar2;
LAB_00432877:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

