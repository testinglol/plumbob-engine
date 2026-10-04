
void FUN_004235c6(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = (*(int **)(unaff_EBP + 0xc))[1];
  *(char *)(unaff_EBP + 0xd) = (char)(**(int **)(unaff_EBP + 0xc) >> 4);
  *(char *)(unaff_EBP + 0xc) = (char)(iVar1 >> 4);
  *(undefined1 *)(unaff_EBP + 0xe) = *(undefined1 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0043f371(*DAT_006e486c,unaff_EBP + 0xc,0);
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar2 = *(undefined4 *)(unaff_EBP + -0x18);
  puVar2[1] = *(undefined4 *)(unaff_EBP + -0x14);
  puVar2[2] = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

