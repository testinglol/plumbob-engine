
undefined4 __thiscall
FUN_004d21e3(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  
  if (*(int **)(param_1 + 0x174) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x174) + 8))(param_2,param_3,param_4);
  }
  iVar2 = FUN_00401f6f();
  if (iVar2 == 0) {
    cVar1 = FUN_004d3d3d(param_2,param_3);
    if (cVar1 == '\0') {
      (**(code **)(**(int **)(*(int *)(DAT_006f2a08 + 0x88) + 0xe8) + 0x19c))();
    }
  }
  return 1;
}

