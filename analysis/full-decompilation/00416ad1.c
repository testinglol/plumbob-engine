
void FUN_00416ad1(void)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(int *)(extraout_ECX + 0x110) == 0) && (*(int *)(extraout_ECX + 0x114) != 0)) {
    puVar2 = operator_new(0x6c);
    *(undefined4 **)(unaff_EBP + -0x10) = puVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      FUN_0046fca5();
      *puVar2 = &PTR_FUN_0066643c;
    }
    iVar1 = *(int *)(extraout_ECX + 0x114);
    *(undefined4 **)(extraout_ECX + 0x110) = puVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470383(*(undefined4 *)(DAT_006e486c + 0xc),
                 CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 6)),0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

