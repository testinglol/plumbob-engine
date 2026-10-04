
void FUN_0053ef93(void)

{
  undefined4 uVar1;
  char cVar2;
  int extraout_ECX;
  int iVar3;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(extraout_ECX + 4);
  *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(extraout_ECX + 5);
  *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(extraout_ECX + 6);
  iVar4 = DAT_006e486c;
  uVar1 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar4 + 4);
  FUN_0053f472(unaff_EBP + -0x10,unaff_EBP + -0x14,uVar1);
  iVar3 = *(int *)(extraout_ECX + 0x3c);
  for (iVar4 = *(int *)(extraout_ECX + 0x30); iVar4 != *(int *)(extraout_ECX + 0x34);
      iVar4 = iVar4 + 6) {
    cVar2 = FUN_0053f01f(iVar3);
    if (cVar2 == '\0') {
      (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x40))(unaff_EBP + -0x14);
    }
    *(char *)(unaff_EBP + -0x14) = *(char *)(unaff_EBP + -0x14) + *(char *)(extraout_ECX + 10);
    iVar3 = iVar3 + 6;
    *(char *)(unaff_EBP + -0x13) = *(char *)(unaff_EBP + -0x13) + *(char *)(extraout_ECX + 0xb);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

