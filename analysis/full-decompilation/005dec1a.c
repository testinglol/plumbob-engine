
undefined1 __thiscall FUN_005dec1a(int param_1,uint param_2)

{
  char cVar1;
  
  if (param_2 == 0x10) {
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & 0xffffffef;
  }
  else {
    if (((param_2 & 0xcc) != 0) || ((param_2 & 0x700) != 0)) {
      cVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x10))();
      if (cVar1 == '\0') {
        return 0;
      }
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & ~param_2;
  }
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
  return 1;
}

