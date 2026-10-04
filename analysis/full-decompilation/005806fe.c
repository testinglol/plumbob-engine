
undefined4 __fastcall FUN_005806fe(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_00580875(&stack0x00000004);
  if (*(char *)(param_1 + 0x10) == '\0') {
    iVar1 = FUN_0060783f();
    iVar2 = FUN_0060783f();
    *(uint *)(param_1 + 0xc) = (uint)(iVar1 + iVar2) >> 1;
  }
  return 1;
}

