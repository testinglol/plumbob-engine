
void FUN_00484aed(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(extraout_ECX + 0x84);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00434ffd(-iVar1 & 3);
  *(undefined1 *)
   (*(int *)(*(int *)(*(int *)(extraout_ECX + 0x1c) + 0xc) + *(char *)(unaff_EBP + 8) * 4) +
   (int)*(char *)(unaff_EBP + 9)) = *(undefined1 *)(unaff_EBP + 0xc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

