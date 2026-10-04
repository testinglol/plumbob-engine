
undefined4 __fastcall FUN_00525c87(int param_1)

{
  char cVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 != '\0') {
    if (*(int *)(param_1 + 0xd8) != 0) {
      local_14 = *(undefined4 *)(param_1 + 0xdc);
      local_10 = *(undefined4 *)(param_1 + 0xe0);
      local_c = *(undefined4 *)(param_1 + 0xe4);
      local_8 = *(undefined4 *)(param_1 + 0xe8);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(int *)(param_1 + 0xd8),param_1 + 0xdc,&local_14,0);
    }
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  return 1;
}

