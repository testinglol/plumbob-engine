
void __fastcall FUN_00577ce8(int param_1)

{
  if (*(char *)(param_1 + 0x40a9) != '\0') {
    (**(code **)(**(int **)(param_1 + 0x40ac) + 0x18))();
    FUN_005d9133();
    *(undefined1 *)(param_1 + 0x40a9) = 0;
    FUN_005d91f9();
    (**(code **)(**(int **)(param_1 + 0x40ac) + 0x18))();
    FUN_005ed911();
    *(undefined4 *)(param_1 + 0x40ac) = 0;
  }
  return;
}

