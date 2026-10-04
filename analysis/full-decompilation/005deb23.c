
undefined1 __fastcall FUN_005deb23(int param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x34))
                    (*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),param_1 + 8,
                     *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44));
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(**(int **)(param_1 + 0x48) + 0x14))(param_1 + 0x24);
  return 1;
}

