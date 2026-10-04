
undefined4 __thiscall FUN_005439f6(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_005e3bfd(param_2);
  if ((DAT_006f4f6c != 0) && (*(int **)(param_1 + 0x5c) != (int *)0x0)) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar1 != '\0') {
      local_14 = *(undefined4 *)(DAT_006f4f6c + 0x14);
      local_10 = *(undefined4 *)(DAT_006f4f6c + 0x18);
      local_c = *(undefined4 *)(DAT_006f4f6c + 0x1c);
      local_8 = *(undefined4 *)(DAT_006f4f6c + 0x20);
      FUN_004ba5ac(param_1 + 0x1c);
      FUN_004ba5ac(&DAT_006f4f28);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(DAT_006f4f6c,DAT_006f4f6c + 0x14,&local_14,0)
      ;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return 1;
}

