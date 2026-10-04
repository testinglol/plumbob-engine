
void FUN_0056f464(void)

{
  int iVar1;
  int extraout_ECX;
  undefined1 *puVar2;
  void *unaff_retaddr;
  undefined4 in_stack_00000014;
  
  FUN_00634c24();
  puVar2 = (undefined1 *)**(undefined4 **)(extraout_ECX + 0xc);
  iVar1 = *(int *)(extraout_ECX + 8) * *(int *)(extraout_ECX + 4);
  if (-1 < iVar1 + -1) {
    do {
      iVar1 = iVar1 + -1;
      *puVar2 = (char)in_stack_00000014;
      puVar2[1] = (char)((uint)in_stack_00000014 >> 8);
      puVar2 = puVar2 + 2;
    } while (iVar1 != 0);
  }
  ExceptionList = unaff_retaddr;
  return;
}

